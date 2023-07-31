/*	EQEMu: Everquest Server Emulator
    Copyright (C) 2001-2010 EQEMu Development Team (http://eqemulator.net)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; version 2 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY except by those people which sell it, which
    are required to give you total support for your newly bought product;
    without even the implied warranty of MERCHANTABILITY or FITNESS FOR
    A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
#include <stdlib.h>
#include <time.h>

#include <sstream>
#include <string>

#include "../common/crash.h"
#include "../common/eq_stream_factory.h"
#include "../common/eqemu_logsys.h"
#include "../common/global_define.h"
#include "../common/opcodemgr.h"
#include "../common/platform.h"
#include "../common/timer.h"
#include "../common/types.h"
#include "eq_crypto.h"
#include "login_server.h"

TimeoutManager timeout_manager;
LoginServer server;
EQEmuLogSys LogSys;
EQCrypto eq_crypto;
bool run_server = true;

void CatchSignal(int sig_num) {}

int main() {
	RegisterExecutablePlatform(ExePlatformLogin);
	LogSys.LoadLogSettingsDefaults();
	set_exception_handler();
	LogInfo("Starting LoginServer v{}", VERSION);
	LogInfo("Logging System Init.");

	LogSys.log_settings[Logs::Error].log_to_console = Logs::General;

	/* Parse out login.ini */
	server.config = new Config();
	LogInfo("Config System Init.");
	server.config->Parse("login.ini");

	if (server.config->GetVariable("options", "unregistered_allowed")
	        .compare("FALSE") == 0) {
		server.options.AllowUnregistered(false);
	}

	if (server.config->GetVariable("options", "dump_packets_in")
	        .compare("TRUE") == 0) {
		server.options.DumpInPackets(true);
	}

	if (server.config->GetVariable("options", "dump_packets_out")
	        .compare("TRUE") == 0) {
		server.options.DumpOutPackets(true);
	}

	if (server.config->GetVariable("security", "allow_token_login")
	        .compare("TRUE") == 0)  //
		server.options.AllowTokenLogin(true);

	if (server.config->GetVariable("security", "allow_password_login")
	        .compare("FALSE") == 0)  //
		server.options.AllowPasswordLogin(false);

	if (server.config->GetVariable("options", "auto_create_accounts")
	        .compare("TRUE") == 0)  //
		server.options.AutoCreateAccounts(true);

	std::string mode = server.config->GetVariable("security", "mode");
	if (mode.size() > 0) {
		server.options.EncryptionMode(atoi(mode.c_str()));
	}

	std::string local_network =
	    server.config->GetVariable("options", "local_network");
	if (local_network.size() > 0) {
		server.options.LocalNetwork(local_network);
	}

	// Parse local network option.
	std::string mip = server.config->GetVariable("options", "network_ip");
	if (mip.size() > 0) {
		server.options.NetworkIP(mip);
	}

	if (server.config->GetVariable("options", "reject_duplicate_servers")
	        .compare("TRUE") == 0) {
		server.options.RejectDuplicateServers(true);
	}

	local_network = server.config->GetVariable("schema", "account_table");
	if (local_network.size() > 0) {
		server.options.AccountTable(local_network);
	}

	local_network =
	    server.config->GetVariable("schema", "world_registration_table");
	if (local_network.size() > 0) {
		server.options.WorldRegistrationTable(local_network);
	}

	local_network =
	    server.config->GetVariable("schema", "world_admin_registration_table");
	if (local_network.size() > 0) {
		server.options.WorldAdminRegistrationTable(local_network);
	}

	local_network =
	    server.config->GetVariable("schema", "world_server_type_table");
	if (local_network.size() > 0) {
		server.options.WorldServerTypeTable(local_network);
	}

	local_network =
	    server.config->GetVariable("schema", "loginserver_setting_table");
	if (local_network.size() > 0)
		server.options.LoginSettingTable(local_network);

	/* Create database connection */
	if (server.config->GetVariable("database", "subsystem").compare("MySQL") ==
	    0) {
		LogInfo("MySQL Database Init.");
		server.db = (Database*)new Database(
		    server.config->GetVariable("database", "user"),
		    server.config->GetVariable("database", "password"),
		    server.config->GetVariable("database", "host"),
		    server.config->GetVariable("database", "port"),
		    server.config->GetVariable("database", "db"));
	}

	/* Make sure our database got created okay, otherwise cleanup and exit. */
	if (!server.db) {
		LogError("Database Initialization Failure.");
		LogInfo("Config System Shutdown.");
		delete server.config;
		LogInfo("Log System Shutdown.");
		return 1;
	}

	// create our server manager.
	LogInfo("Server Manager Initialize.");
	server.server_manager = new ServerManager();
	if (!server.server_manager) {
		// We can't run without a server manager, cleanup and exit.
		LogError("Server Manager Failed to Start.");

		LogInfo("Database System Shutdown.");
		delete server.db;
		LogInfo("Config System Shutdown.");
		delete server.config;
		return 1;
	}

	// create our client manager.
	LogInfo("Client Manager Initialize.");
	server.client_manager = new ClientManager();
	if (!server.client_manager) {
		// We can't run without a client manager, cleanup and exit.
		LogError("Client Manager Failed to Start.");
		LogInfo("Server Manager Shutdown.");
		delete server.server_manager;

		LogInfo("Database System Shutdown.");
		delete server.db;
		LogInfo("Config System Shutdown.");
		delete server.config;
		return 1;
	}

#ifdef WIN32
#ifdef UNICODE
	SetConsoleTitle(L"EQEmu Login Server");
#else
	SetConsoleTitle("EQEmu Login Server");
#endif
#endif

	LogInfo("Server Started.");
	while (run_server) {
		Timer::SetCurrentTime();
		server.client_manager->Process();
		server.server_manager->Process();
		timeout_manager.CheckTimeouts();
		Sleep(100);
	}

	LogInfo("Server Shutdown.");

	LogInfo("Client Manager Shutdown.");
	delete server.client_manager;

	LogInfo("Server Manager Shutdown.");
	delete server.server_manager;

	LogInfo("Database System Shutdown.");
	delete server.db;

	LogInfo("Config System Shutdown.");
	delete server.config;
	LogSys.CloseFileLogs();

	return 0;
}
