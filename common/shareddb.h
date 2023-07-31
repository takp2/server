#ifndef SHAREDDB_H_
#define SHAREDDB_H_

#define MAX_ITEM_ID 200000

#include "database.h"
#include "skills.h"
#include "spdat.h"
#include "item_instance.h"
#include "base_data.h"
#include "fixed_memory_hash_set.h"
#include "fixed_memory_variable_hash_set.h"
#include "say_link.h"

#include <list>
#include <memory>

struct NPCFactionList;
struct Faction;
struct LootTable_Struct;
struct LootDrop_Struct;
namespace EQ {
struct ItemData;
class ItemInstance;
class InventoryProfile;
class MemoryMappedFile;
}  // namespace EQ

/*
 * This object is inherited by world and zone's DB object,
 * and is mainly here to facilitate shared memory, and other
 * things which only world and zone need.
 */
class SharedDatabase : public Database {
   public:
	SharedDatabase();
	SharedDatabase(const char* host, const char* user, const char* passwd,
	               const char* database, uint32 port);
	virtual ~SharedDatabase();

	/*
	 * General Character Related Stuff
	 */
	bool SetGMSpeed(uint32 account_id, uint8 gmspeed);
	uint8 GetGMSpeed(uint32 account_id);
	bool SetHideMe(uint32 account_id, uint8 hideme);
	int32 DeleteStalePlayerCorpses();
	bool GetCommandSettings(
	    std::map<std::string, std::pair<uint8, std::vector<std::string>>>&
	        command_settings);
	bool UpdateInjectedCommandSettings(
	    const std::vector<std::pair<std::string, uint8>>& injected);
	bool UpdateOrphanedCommandSettings(
	    const std::vector<std::string>& orphaned);
	uint32 GetTotalTimeEntitledOnAccount(uint32 AccountID);
	bool SetGMInvul(uint32 account_id, bool gminvul);
	bool SetGMFlymode(uint32 account_id, uint8 flymode);
	bool SetGMIgnoreTells(uint32 account_id, uint8 ignoretells);

	/*
	 * Character InventoryProfile
	 */
	bool SaveInventory(uint32 char_id, const EQ::ItemInstance* inst,
	                   int16 slot_id);
	bool DeleteInventorySlot(uint32 char_id, int16 slot_id);
	bool UpdateInventorySlot(uint32 char_id, const EQ::ItemInstance* inst,
	                         int16 slot_id);
	bool GetInventory(uint32 char_id, EQ::InventoryProfile* inv);
	bool GetInventory(uint32 account_id, char* name, EQ::InventoryProfile* inv);
	bool SetStartingItems(PlayerProfile_Struct* pp, EQ::InventoryProfile* inv,
	                      uint32 si_race, uint32 si_class, uint32 si_deity,
	                      uint32 si_current_zone, char* si_name, int admin);

	std::string GetBook(const char* txtfile);

	/*
	 * Item Methods
	 */
	EQ::ItemInstance* CreateItem(uint32 item_id, int8 charges = 0);
	EQ::ItemInstance* CreateItem(const EQ::ItemData* item, int8 charges = 0);
	EQ::ItemInstance* CreateBaseItem(const EQ::ItemData* item,
	                                 int8 charges = 0);

	// Web Token Verification
	bool VerifyToken(std::string token, int& status);

	/*
	    Shared Memory crap
	*/

	// items
	void GetItemsCount(int32& item_count, uint32& max_id);
	void LoadItems(void* data, uint32 size, int32 items, uint32 max_item_id);
	bool LoadItems(const std::string& prefix);
	const EQ::ItemData* IterateItems(uint32* id);
	const EQ::ItemData* GetItem(uint32 id);

	// faction lists
	void GetFactionListInfo(uint32& list_count, uint32& max_lists);
	const NPCFactionList* GetNPCFactionEntry(uint32 id);
	void LoadNPCFactionLists(void* data, uint32 size, uint32 list_count,
	                         uint32 max_lists);
	bool LoadNPCFactionLists(const std::string& prefix);

	// loot
	void GetLootTableInfo(uint32& loot_table_count, uint32& max_loot_table,
	                      uint32& loot_table_entries);
	void GetLootDropInfo(uint32& loot_drop_count, uint32& max_loot_drop,
	                     uint32& loot_drop_entries);
	void LoadLootTables(void* data, uint32 size);
	void LoadLootDrops(void* data, uint32 size);
	bool LoadLoot(const std::string& prefix);
	const LootTable_Struct* GetLootTable(uint32 loottable_id);
	const LootDrop_Struct* GetLootDrop(uint32 lootdrop_id);

	void LoadSkillCaps(void* data);
	bool LoadSkillCaps(const std::string& prefix);
	uint16 GetSkillCap(uint8 Class_, EQ::skills::SkillType Skill, uint8 Level);
	uint8 GetTrainLevel(uint8 Class_, EQ::skills::SkillType Skill, uint8 Level);

	int GetMaxSpellID();
	bool LoadSpells(const std::string& prefix, int32* records,
	                const SPDat_Spell_Struct** sp);
	void LoadSpells(void* data, int max_spells);
	void LoadDamageShieldTypes(SPDat_Spell_Struct* sp, int32 iMaxSpellID);

	int GetMaxBaseDataLevel();
	bool LoadBaseData(const std::string& prefix);
	void LoadBaseData(void* data, int max_level);
	const BaseDataStruct* GetBaseData(int lvl, int cl);

	std::string CreateItemLink(uint32 item_id) {
		EQ::SayLinkEngine linker;
		linker.SetLinkType(EQ::saylink::SayLinkItemData);
		const EQ::ItemData* item = GetItem(item_id);
		linker.SetItemData(item);
		return linker.GenerateLink();
	}

   protected:
	std::unique_ptr<EQ::MemoryMappedFile> skill_caps_mmf;
	std::unique_ptr<EQ::MemoryMappedFile> items_mmf;
	std::unique_ptr<EQ::FixedMemoryHashSet<EQ::ItemData>> items_hash;
	std::unique_ptr<EQ::MemoryMappedFile> faction_mmf;
	std::unique_ptr<EQ::FixedMemoryHashSet<NPCFactionList>> faction_hash;
	std::unique_ptr<EQ::MemoryMappedFile> loot_table_mmf;
	std::unique_ptr<EQ::FixedMemoryVariableHashSet<LootTable_Struct>>
	    loot_table_hash;
	std::unique_ptr<EQ::MemoryMappedFile> loot_drop_mmf;
	std::unique_ptr<EQ::FixedMemoryVariableHashSet<LootDrop_Struct>>
	    loot_drop_hash;
	std::unique_ptr<EQ::MemoryMappedFile> base_data_mmf;
	std::unique_ptr<EQ::MemoryMappedFile> spells_mmf;
};

#endif /*SHAREDDB_H_*/
