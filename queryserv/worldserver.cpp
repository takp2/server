#include "../common/global_define.h"
#include "../common/eqemu_logsys.h"
#include "../common/md5.h"
#include "../common/packet_dump.h"
#include "../common/packet_functions.h"
#include "../common/servertalk.h"

#include "database.h"
#include "queryservconfig.h"
#include "worldserver.h"
#include <iomanip>
#include <iostream>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

extern WorldServer worldserver;
extern const queryservconfig *Config;
extern Database database;

WorldServer::WorldServer() : WorldConnection(EmuTCPConnection::packetModeQueryServ, Config->SharedKey.c_str())
{
	pTryReconnect = true;
}

WorldServer::~WorldServer() {}

void WorldServer::OnConnected()
{
	Log(Logs::Detail, Logs::QSServer, "Connected to World.");
	WorldConnection::OnConnected();
}

void WorldServer::Process()
{
	WorldConnection::Process(); 
	if (!Connected())
		return;

	ServerPacket *pack = 0; 
	while((pack = tcpc.PopPacket()))
	{
		Log(Logs::Detail, Logs::QSServer, "Received Opcode: %4X", pack->opcode); 
		switch(pack->opcode) {
			case 0: {
				break;
			}
			case ServerOP_KeepAlive: {
				break;
			}
			case ServerOP_QSPlayerLogItemDeletes: {
				if (pack->size < sizeof(QSPlayerLogItemDelete_Struct))
				{
					Log(Logs::Detail, Logs::QSServer, "Received malformed ServerOP_QSPlayerLogItemDeletes");
					break;
				}
				QSPlayerLogItemDelete_Struct *QS = (QSPlayerLogItemDelete_Struct*)pack->pBuffer;
				uint32 Items = QS->char_count;
				if (pack->size < sizeof(QSPlayerLogItemDelete_Struct) * Items)
				{
					Log(Logs::Detail, Logs::QSServer, "Received malformed ServerOP_QSPlayerLogItemDeletes");
					break;
				}
				database.LogPlayerItemDelete(QS, Items);
				break;
			}
			case ServerOP_QSPlayerLogItemMoves: {
				QSPlayerLogItemMove_Struct *QS = (QSPlayerLogItemMove_Struct*)pack->pBuffer;
				uint32 Items = QS->char_count;
				database.LogPlayerItemMove(QS, Items);
				break;
			}
			case ServerOP_QSPlayerLogMerchantTransactions: {
				QSMerchantLogTransaction_Struct *QS = (QSMerchantLogTransaction_Struct*)pack->pBuffer;
				uint32 Items = QS->char_count + QS->merchant_count;
				database.LogMerchantTransaction(QS, Items);
				break; 
			}
			case ServerOP_QSPlayerAARateHourly: {
				QSPlayerAARateHourly_Struct *QS = (QSPlayerAARateHourly_Struct*)pack->pBuffer;
				uint32 Items = QS->charid;
				database.LogPlayerAARateHourly(QS, Items);
				break;
			}
			case ServerOP_QSPlayerAAPurchase: {
				QSPlayerAAPurchase_Struct *QS = (QSPlayerAAPurchase_Struct*)pack->pBuffer;
				uint32 Items = QS->charid;
				database.LogPlayerAAPurchase(QS, Items);
				break;
			}
			case ServerOP_QSPlayerTSEvents: {
				QSPlayerTSEvents_Struct *QS = (QSPlayerTSEvents_Struct*)pack->pBuffer;
				uint32 Items = QS->charid;
				database.LogPlayerTSEvents(QS, Items);
				break;
			}
			case ServerOP_QSPlayerQGlobalUpdates: {
				QSPlayerQGlobalUpdate_Struct *QS = (QSPlayerQGlobalUpdate_Struct*)pack->pBuffer;
				uint32 Items = QS->charid;
				database.LogPlayerQGlobalUpdates(QS, Items);
				break;
			}
			case ServerOP_QSPlayerLootRecords: {
				QSPlayerLootRecords_struct *QS = (QSPlayerLootRecords_struct*)pack->pBuffer;
				uint32 Items = QS->charid;
				database.LogPlayerLootRecords(QS, Items);
				break;
			}
			case ServerOP_QueryServGeneric: {
				/* 
					The purpose of ServerOP_QueryServerGeneric is so that we don't have to add code to world just to relay packets
					each time we add functionality to queryserv.
				
					A ServerOP_QueryServGeneric packet has the following format:
				
					uint32 SourceZoneID
					char OriginatingCharacterName[0] 
						- Null terminated name of the character this packet came from. This could be just
						- an empty string if it has no meaning in the context of a particular packet.
					uint32 Type
				
					The 'Type' field is a 'sub-opcode'. A value of 0 is used for the LFGuild packets. The next feature to be added
					to queryserv would use 1, etc.
				
					Obviously, any fields in the packet following the 'Type' will be unique to the particular type of packet. The
					'Generic' in the name of this ServerOP code relates to the four header fields.
				*/

				char From[64];
				pack->SetReadPosition(8);
				pack->ReadString(From);
				uint32 Type = pack->ReadUInt32();

				switch(Type)
				{
					case 0:
					{
						break;
					}
					default:
					{
						Log(Logs::Detail, Logs::QSServer, "Received unhandled ServerOP_QueryServGeneric", Type);
						break;
					}
				}
				break;
			}
			case ServerOP_QSSendQuery: {
				/* Process all packets here */
				database.GeneralQueryReceive(pack);  
				break;
			}
		}
	} 
	safe_delete(pack);
	return;
}

