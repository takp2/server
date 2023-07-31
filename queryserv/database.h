#ifndef CHATSERVER_DATABASE_H
#define CHATSERVER_DATABASE_H

#define AUTHENTICATION_TIMEOUT 60
#define INVALID_ID 0xFFFFFFFF

#include <map>
#include <string>
#include <vector>

#include "../common/dbcore.h"
#include "../common/eqemu_logsys.h"
#include "../common/global_define.h"
#include "../common/linked_list.h"
#include "../common/servertalk.h"
#include "../common/types.h"

// atoi is not uint32 or uint32 safe!!!!
#define atoul(str) strtoul(str, nullptr, 10)

class Database : public DBcore {
   public:
	Database();
	~Database();
	Database(const char* host, const char* user, const char* passwd,
	         const char* database, uint32 port);
	bool Connect(const char* host, const char* user, const char* passwd,
	             const char* database, uint32 port);

	void LogPlayerAARateHourly(QSPlayerAARateHourly_Struct* QS, uint32 items);
	void LogPlayerAAPurchase(QSPlayerAAPurchase_Struct* QS, uint32 items);
	void LogPlayerQGlobalUpdates(QSPlayerQGlobalUpdate_Struct* QS,
	                             uint32 items);
	void LogPlayerTSEvents(QSPlayerTSEvents_Struct* QS, uint32 items);

	void LogMerchantTransaction(QSMerchantLogTransaction_Struct* QS,
	                            uint32 Items);

	void LogPlayerItemDelete(QSPlayerLogItemDelete_Struct* QS, uint32 Items);
	void LogPlayerItemMove(QSPlayerLogItemMove_Struct* QS, uint32 Items);
	void LogPlayerLootRecords(QSPlayerLootRecords_struct* QS, uint32 Items);

	void GeneralQueryReceive(ServerPacket* pack);

	/*
	 * Database Setup for bootstraps only.
	 */
	bool DBSetup();
	bool DBSetup_CheckLegacy();
	bool DBSetup_PlayerAAPurchase();
	bool DBSetup_PlayerDeathBy();
	bool DBSetup_PlayerTSEvents();
	bool DBSetup_PlayerQGlobalUpdates();
	bool DBSetup_PlayerLootRecords();
	bool DBSetup_PlayerItemDesyncs();

	bool Check_Trade_Tables();
	bool Create_Trade_Table();
	bool Copy_Trade_Record();

	bool Check_Handin_Tables();
	bool Create_Handin_Table();
	bool Copy_Handin_Record();

	bool Check_NPCKills_Tables();
	bool Create_NPCKills_Table();
	bool Copy_NPCKills_Record();

	bool Check_Merchant_Tables();
	bool Create_Merchant_Table();
	bool Copy_Merchant_Record();

	bool Check_Delete_Tables();
	bool Create_Delete_Table();
	bool Copy_Delete_Record();

	bool Check_ItemMove_Tables();
	bool Create_ItemMove_Table();
	bool Copy_ItemMove_Record();

   protected:
	void HandleMysqlError(uint32 errnum);

   private:
	void DBInitVars();
};

#endif
