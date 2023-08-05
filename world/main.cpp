#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>

#include "../common/crash.h"
#include "../common/eq_packet.h"
#include "../common/eq_stream_factory.h"
#include "../common/eq_stream_ident.h"
#include "../common/eqemu_logsys.h"
#include "../common/eqtime.h"
#include "../common/global_define.h"
#include "../common/guilds.h"
#include "../common/opcodemgr.h"
#include "../common/platform.h"
#include "../common/queue.h"
#include "../common/rulesys.h"
#include "../common/seperator.h"
#include "../common/timeoutmgr.h"
#include "../common/timer.h"
#include "../common/version.h"
#include "client.h"
#include "worlddb.h"
#ifdef _WINDOWS
#include <process.h>
#define snprintf _snprintf
#define strncasecmp _strnicmp
#define strcasecmp _stricmp
#include <conio.h>
#else
#include <pthread.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/types.h>

#include "../common/unix.h"
#if not defined(FREEBSD) && not defined(DARWIN)
union semun {
	int val;
	struct semid_ds* buf;
	ushort* array;
	struct seminfo* __buf;
	void* __pad;
};
#endif

#endif

#include "../common/emu_tcp_server.h"
#include "../common/patches/patches.h"
#include "../common/random.h"
#include "clientlist.h"
#include "console.h"
#include "launcher_list.h"
#include "login_server.h"
#include "login_server_list.h"
#include "queryserv.h"
#include "ucs.h"
#include "wguild_mgr.h"
#include "world_config.h"
#include "zonelist.h"
#include "zoneserver.h"

TimeoutManager timeout_manager;
EQStreamFactory eqsf(WorldStream, 9000);
EmuTCPServer tcps;
ClientList client_list;
ZSList zoneserver_list;
LoginServerList loginserverlist;
UCSConnection UCSLink;
QueryServConnection QSLink;
LauncherList launcher_list;
EQ::Random emu_random;
volatile bool RunLoops = true;
uint32 numclients = 0;
uint32 numzones = 0;
const WorldConfig* Config;
EQEmuLogSys LogSys;

extern ConsoleList console_list;

void CatchSignal(int sig_num);

void LoadServerConfig() {
	auto load_result = WorldConfig::LoadConfig();
	if (!load_result.empty()) {
		LogError("{}", load_result);
		std::exit(1);
	}
}

void RegisterLoginservers() {
	LinkedList<LoginConfig*> loginlist = Config->loginlist;
	LinkedListIterator<LoginConfig*> iterator(loginlist);
	iterator.Reset();
	while (iterator.MoreElements()) {
		loginserverlist.Add(iterator.GetData()->LoginHost.c_str(),
		                    iterator.GetData()->LoginPort,
		                    iterator.GetData()->LoginAccount.c_str(),
		                    iterator.GetData()->LoginPassword.c_str(),
		                    iterator.GetData()->LoginType);
		iterator.Advance();
	}
}

int main(int argc, char** argv) {
	RegisterExecutablePlatform(ExePlatformWorld);
	LogSys.LoadLogSettingsDefaults();
	set_exception_handler();
	LogInfo("Starting World v{}", VERSION);
	LoadServerConfig();

	Config = WorldConfig::get();

#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	if (signal(SIGINT, CatchSignal) == SIG_ERR) {
		LogError("Could not set signal handler");
		return 1;
	}
	if (signal(SIGTERM, CatchSignal) == SIG_ERR) {
		LogError("Could not set signal handler");
		return 1;
	}
#ifndef WIN32
	if (signal(SIGPIPE, SIG_IGN) == SIG_ERR) {
		LogError("Could not set signal handler");
		return 1;
	}
#endif

	RegisterLoginservers();

	if (!database.Connect(Config->DatabaseHost.c_str(),
	                      Config->DatabaseUsername.c_str(),
	                      Config->DatabasePassword.c_str(),
	                      Config->DatabaseDB.c_str(), Config->DatabasePort)) {
		LogError("Failed to connect to database");

		std::exit(1);
	}

	if (!DB::Open(Config->DatabaseHost.c_str(),
	              Config->DatabaseUsername.c_str(),
	              Config->DatabasePassword.c_str(),
	              Config->DatabaseDB.c_str(), Config->DatabasePort)) {
		LogError("Failed to connect to database");

		std::exit(1);
	}

	LogSys.LoadLogDatabaseSettings()->StartFileLogs();

	// database.LoadVariables();

	std::string hotfix_name;
	/*if (database.GetVariable("hotfix_name", hotfix_name)) {
	    if (!hotfix_name.empty()) {
	        LogInfo("Current hotfix in use: [{0}]", hotfix_name.c_str());
	    }
	}*/

	database.LoadZoneNames();
	database.ClearGroup();
	database.ClearRaid();
	database.ClearRaidDetails();
	if (!database.LoadItems(hotfix_name)) {
		LogError("Failed to load item data");
		std::exit(1);
	}

	if (!database.LoadSkillCaps(std::string(hotfix_name))) {
		LogError("Failed to load skill caps");
		std::exit(1);
	}

	guild_mgr.LoadGuilds();

	std::string tmp;
	/*if (database.GetVariable("RuleSet", tmp)) {
	    if (!RuleManager::Instance()->LoadRules(&database, tmp.c_str())) {
	        LogError("Failed to load ruleset {0}, falling back to default values", tmp.c_str());
	    }
	} else {*/
	if (!RuleManager::Instance()->LoadRules(&database, "default")) {
		LogInfo("No rule set configured, using default rules");
	}
	//}

	if (RuleB(World, ClearTempMerchantlist)) {
		database.ClearMerchantTemp();
	}

	if (RuleB(World, AdjustRespawnTimes)) {
		database.AdjustSpawnTimes();
	}

	TimeOfDay_Struct eqTime;
	time_t realtime;
	eqTime = database.LoadTime(realtime);
	zoneserver_list.worldclock.setEQTimeOfDay(eqTime, realtime);
	Timer EQTimeTimer(600000);
	EQTimeTimer.Start(600000);

	launcher_list.LoadList();

	tmp = "";
	int delete_count = database.DeleteStalePlayerCorpses();
	if (delete_count > 0) {
		LogInfo("Deleted {0} stale player corpses from database", delete_count);
	}

	database.ClearAllActive();

	database.ClearAllConsented();

	database.LoadCharacterCreateAllocations();
	database.LoadCharacterCreateCombos();

	char errbuf[TCPConnection_ErrorBufferSize];
	if (tcps.Open(Config->WorldTCPPort, errbuf)) {
		LogInfo("TCP listening on {}", Config->WorldTCPPort);
	} else {
		LogInfo("Failed to start TCP listening on {}: {}", Config->WorldTCPPort, errbuf);
		return 1;
	}
	if (eqsf.Open()) {
		LogInfo("UDP istening on {}", 9000);
	} else {
		LogInfo("Failed to start UDP listening on {}", 9000);
		return 1;
	}

	// register all the patches we have avaliable with the stream identifier.
	EQStreamIdentifier stream_identifier;
	RegisterAllPatches(stream_identifier);
	zoneserver_list.shutdowntimer = new Timer(60000);
	zoneserver_list.shutdowntimer->Disable();
	zoneserver_list.reminder = new Timer(20000);
	zoneserver_list.reminder->Disable();
	Timer InterserverTimer(
	    INTERSERVER_TIMER);  // does MySQL pings and auto-reconnect
	InterserverTimer.Trigger();
	uint8 ReconnectCounter = 100;
	EQStream* eqs;
	EQOldStream* eqos;
	EmuTCPConnection* tcpc;
	EQStreamInterface* eqsi;

	while (RunLoops) {
		Timer::SetCurrentTime();

		int i = 5;
		// check the factory for any new incoming streams.
		while ((eqs = eqsf.Pop())) {
			// pull the stream out of the factory and give it to the stream
			// identifier which will figure out what patch they are running, and
			// set up the dynamic structures and opcodes for that patch.
			struct in_addr in {};
			in.s_addr = eqs->GetRemoteIP();
			LogInfo("New connection from {0}:{1}", inet_ntoa(in),
			        ntohs(eqs->GetRemotePort()));
			stream_identifier.AddStream(eqs);  // takes the stream
			i++;
			if (i == 5) break;
		}
		i = 0;
		// check the factory for any new incoming streams.
		while ((eqos = eqsf.PopOld())) {
			// pull the stream out of the factory and give it to the stream
			// identifier which will figure out what patch they are running, and
			// set up the dynamic structures and opcodes for that patch.
			struct in_addr in {};
			in.s_addr = eqos->GetRemoteIP();
			Log(Logs::Detail, Logs::WorldServer, "New connection from %s:%d",
			    inet_ntoa(in), ntohs(eqos->GetRemotePort()));
			stream_identifier.AddOldStream(eqos);  // takes the stream
			i++;
			if (i == 5) break;
		}

		// give the stream identifier a chance to do its work....
		stream_identifier.Process();
		i = 0;
		// check the stream identifier for any now-identified streams
		while ((eqsi = stream_identifier.PopIdentified())) {
			// now that we know what patch they are running, start up their
			// client object
			struct in_addr in {};
			in.s_addr = eqsi->GetRemoteIP();
			if (RuleB(World, UseBannedIPsTable)) {
				// LogInfo("Checking inbound connection [{0}] against BannedIPs table",inet_ntoa(in));
				if (!database.CheckBannedIPs(inet_ntoa(in))) {  // Lieka: Check inbound IP against
					// LogInfo("Connection [{0}] PASSED banned IPs check. Processing connection.", inet_ntoa(in));
					auto client = new Client(eqsi);
					client_list.Add(client);
				} else {
					LogInfo("Connection {} failed banned IPs check, rejecting", inet_ntoa(in));
					eqsi->Close();
				}
			}
			if (!RuleB(World, UseBannedIPsTable)) {
				LogInfo("New connection from {0}:{1}", inet_ntoa(in), ntohs(eqsi->GetRemotePort()));
				auto client = new Client(eqsi);
				client_list.Add(client);
			}
			i++;
			if (i == 5) break;
		}

		client_list.Process();

		i = 0;
		while ((tcpc = tcps.NewQueuePop())) {
			struct in_addr in {};
			in.s_addr = tcpc->GetrIP();
			std::string identifier = "unknown";
			if (tcpc->GetMode() == EmuTCPConnection::modePacket) {
				switch (tcpc->GetPacketMode()) {
					case EmuTCPConnection::packetModeZone:
						identifier = "zone";
						break;
					case EmuTCPConnection::packetModeLauncher:
						identifier = "launcher";
						break;
					case EmuTCPConnection::packetModeUCS:
						identifier = "ucs";
						break;
					case EmuTCPConnection::packetModeQueryServ:
						identifier = "queryserv";
						break;
				}
			}
			LogInfo("New TCP {} connection from {}:{}", identifier, inet_ntoa(in), tcpc->GetrPort());
			console_list.Add(new Console(tcpc));
			i++;
			if (i == 5) break;
		}

		if (EQTimeTimer.Check()) {
			TimeOfDay_Struct tod;
			zoneserver_list.worldclock.getEQTimeOfDay(time(0), &tod);
			if (!database.SaveTime(tod.minute, tod.hour, tod.day, tod.month,
			                       tod.year)) {
				LogError("Failed to save eqtime");
			} else {
				LogDebug("EQTime successfully saved");
			}
		}

		// check for timeouts in other threads
		timeout_manager.CheckTimeouts();
		loginserverlist.Process();
		console_list.Process();
		zoneserver_list.Process();
		launcher_list.Process();
		UCSLink.Process();
		QSLink.Process();

		// WILink.Process();

		if (InterserverTimer.Check()) {
			InterserverTimer.Start();
			database.ping();
			DB::Ping();
			// AsyncLoadVariables(dbasync, &database);
			ReconnectCounter++;
			if (ReconnectCounter >=
			    12) {  // only create thread to reconnect every 10 minutes.
				       // previously we were creating a new thread every 10
				       // seconds
				ReconnectCounter = 0;
				if (loginserverlist.AllConnected() == false) {
#ifdef _WINDOWS
					_beginthread(AutoInitLoginServer, 0, nullptr);
#else
					pthread_t thread;
					pthread_create(&thread, nullptr, &AutoInitLoginServer,
					               nullptr);
#endif
				}
			}
		}
		if (numclients == 0) {
			Sleep(50);
			continue;
		}
		Sleep(20);
	}
	console_list.KillAll();
	zoneserver_list.KillAll();
	LogInfo("TCP listener stopped");
	tcps.Close();
	LogInfo("UDP listener stopped");
	eqsf.Close();
	LogSys.CloseFileLogs();
	LogInfo("World shutdown complete");
	return 0;
}

void CatchSignal(int sig_num) {
	LogInfo("Caught signal {}, Shutting down", sig_num);
	RunLoops = false;
}

void UpdateWindowTitle(char* iNewTitle) {
#ifdef _WINDOWS
	char tmp[500];
	if (iNewTitle) {
		snprintf(tmp, sizeof(tmp), "World: %s", iNewTitle);
	} else {
		snprintf(tmp, sizeof(tmp), "World");
	}
	SetConsoleTitle(tmp);
#endif
}
