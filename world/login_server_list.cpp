#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iomanip>
#include <iostream>

#include "../common/global_define.h"
#include "../common/version.h"

#define IGNORE_LS_FATAL_ERROR

#include "../common/eq_packet_structs.h"
#include "../common/packet_dump.h"
#include "../common/servertalk.h"
#include "clientlist.h"
#include "login_server.h"
#include "login_server_list.h"
#include "world_config.h"
#include "worlddb.h"
#include "zonelist.h"
#include "zoneserver.h"

extern ZSList zoneserver_list;
extern LoginServerList loginserverlist;
extern ClientList client_list;
extern uint32 numzones;
extern uint32 numplayers;
extern volatile bool RunLoops;

LoginServerList::LoginServerList() {}

LoginServerList::~LoginServerList() {}

void LoginServerList::Add(const char* iAddress, uint16 iPort,
                          const char* Account, const char* Password,
                          uint8 Type) {
	auto loginserver =
	    new LoginServer(iAddress, iPort, Account, Password, Type);
	list.Insert(loginserver);
}

bool LoginServerList::Process() {
	LinkedListIterator<LoginServer*> iterator(list);

	iterator.Reset();
	while (iterator.MoreElements()) {
		iterator.GetData()->Process();
		iterator.Advance();
	}
	return true;
}

#ifdef _WINDOWS
void AutoInitLoginServer(void* tmp) {
#else
void* AutoInitLoginServer(void* tmp) {
#endif
	loginserverlist.InitLoginServer();
#ifndef WIN32
	return 0;
#endif
}

void LoginServerList::InitLoginServer() {
	LinkedListIterator<LoginServer*> iterator(list);

	iterator.Reset();
	while (iterator.MoreElements()) {
		iterator.GetData()->InitLoginServer();
		iterator.Advance();
	}
}

bool LoginServerList::SendInfo() {
	LinkedListIterator<LoginServer*> iterator(list);

	iterator.Reset();
	while (iterator.MoreElements()) {
		iterator.GetData()->SendInfo();
		iterator.Advance();
	}
	return true;
}

bool LoginServerList::SendNewInfo() {
	LinkedListIterator<LoginServer*> iterator(list);

	iterator.Reset();
	while (iterator.MoreElements()) {
		iterator.GetData()->SendNewInfo();
		iterator.Advance();
	}
	return true;
}

bool LoginServerList::SendStatus() {
	LinkedListIterator<LoginServer*> iterator(list);

	iterator.Reset();
	while (iterator.MoreElements()) {
		iterator.GetData()->SendStatus();
		iterator.Advance();
	}
	return true;
}

bool LoginServerList::SendPacket(ServerPacket* pack) {
	LinkedListIterator<LoginServer*> iterator(list);

	iterator.Reset();
	while (iterator.MoreElements()) {
		iterator.GetData()->SendPacket(pack);
		iterator.Advance();
	}
	return true;
}

bool LoginServerList::SendAccountUpdate(ServerPacket* pack) {
	LinkedListIterator<LoginServer*> iterator(list);

	Log(Logs::Detail, Logs::WorldServer,
	    "Requested to send ServerOP_LSAccountUpdate packet to all "
	    "loginservers");
	iterator.Reset();
	while (iterator.MoreElements()) {
		if (iterator.GetData()->CanUpdate()) {
			iterator.GetData()->SendAccountUpdate(pack);
		}
		iterator.Advance();
	}
	return true;
}

bool LoginServerList::Connected() {
	LinkedListIterator<LoginServer*> iterator(list);

	iterator.Reset();
	while (iterator.MoreElements()) {
		if (iterator.GetData()->Connected()) return true;
		iterator.Advance();
	}
	return false;
}

bool LoginServerList::AllConnected() {
	LinkedListIterator<LoginServer*> iterator(list);

	iterator.Reset();
	while (iterator.MoreElements()) {
		if (iterator.GetData()->Connected() == false) return false;
		iterator.Advance();
	}
	return true;
}

bool LoginServerList::CanUpdate() {
	LinkedListIterator<LoginServer*> iterator(list);

	iterator.Reset();
	while (iterator.MoreElements()) {
		if (iterator.GetData()->CanUpdate()) return true;
		iterator.Advance();
	}
	return false;
}
