#include "worldserver.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <iomanip>
#include <iostream>

#include "../common/eqemu_logsys.h"
#include "../common/global_define.h"
#include "../common/md5.h"
#include "../common/misc_functions.h"
#include "../common/packet_functions.h"
#include "../common/servertalk.h"
#include "clientlist.h"
#include "database.h"
#include "ucsconfig.h"

extern WorldServer worldserver;
extern Clientlist *g_Clientlist;
extern const ucsconfig *Config;
extern Database database;

WorldServer::WorldServer()
    : WorldConnection(EmuTCPConnection::packetModeUCS,
                      Config->SharedKey.c_str()) {
	pTryReconnect = true;
}

WorldServer::~WorldServer() {}

void WorldServer::OnConnected() {
	LogInfo("Connected to World.");
	WorldConnection::OnConnected();
}

void WorldServer::Process() {
	WorldConnection::Process();

	if (!Connected()) return;

	ServerPacket *pack = nullptr;

	while ((pack = tcpc.PopPacket())) {
		LogNetcode("Received Opcode: {:#04x}", pack->opcode);

		switch (pack->opcode) {
			case 0: {
				break;
			}
			case ServerOP_KeepAlive: {
				break;
			}
			case ServerOP_UCSMessage: {
				char *Buffer = (char *)pack->pBuffer;

				auto From = new char[strlen(Buffer) + 1];

				VARSTRUCT_DECODE_STRING(From, Buffer);

				std::string Message = Buffer;

				LogInfo("Player: [{0}], Sent Message: [{1}]", From,
				        Message.c_str());

				Client *c = g_Clientlist->FindCharacter(From);

				safe_delete_array(From);

				if (Message.length() < 2) break;

				if (!c) {
					LogInfo("Client not found");
					break;
				}

				if (Message[0] == ';') {
					c->SendChannelMessageByNumber(
					    Message.substr(1, std::string::npos));
				} else if (Message[0] == '[') {
					g_Clientlist->ProcessOPChatCommand(
					    c, Message.substr(1, std::string::npos));
				}

				break;
			}
		}
	}

	safe_delete(pack);
	return;
}
