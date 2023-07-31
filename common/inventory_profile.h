#ifndef COMMON_INVENTORY_PROFILE_H
#define COMMON_INVENTORY_PROFILE_H

#include "item_instance.h"

#include <list>

// FatherNitwit: location bits for searching specific
// places with HasItem() and HasItemByUse()
enum {
	invWhereWorn = 0x01,
	invWherePersonal = 0x02,  // in the character's inventory
	invWhereBank = 0x04,
	invWhereUnused = 0x08,
	invWhereTrading = 0x10,
	invWhereCursor = 0x20
};

// ########################################
// Class: Queue
//	Queue that allows a read-only iterator
class ItemInstQueue {
   public:
	~ItemInstQueue();
	/////////////////////////
	// Public Methods
	/////////////////////////

	inline std::list<EQ::ItemInstance*>::const_iterator cbegin() {
		return m_list.cbegin();
	}
	inline std::list<EQ::ItemInstance*>::const_iterator cend() {
		return m_list.cend();
	}

	inline int size() {
		return static_cast<int>(m_list.size());
	}  // TODO: change to size_t
	inline bool empty() { return m_list.empty(); }

	void push(EQ::ItemInstance* inst);
	void push_front(EQ::ItemInstance* inst);
	EQ::ItemInstance* pop();
	EQ::ItemInstance* peek_front() const;

   protected:
	/////////////////////////
	// Protected Members
	/////////////////////////

	std::list<EQ::ItemInstance*> m_list;
};

// ########################################
// Class: EQ::InventoryProfile
//	Character inventory
namespace EQ {
class InventoryProfile {
	friend class ItemInstance;

   public:
	///////////////////////////////
	// Public Methods
	///////////////////////////////

	InventoryProfile() {
		m_mob_version = EQ::versions::MobVersion::Unknown;
		m_mob_version_set = false;
	}
	~InventoryProfile();

	bool SetInventoryVersion(versions::MobVersion inventory_version);
	bool SetInventoryVersion(EQ::versions::ClientVersion client_version) {
		return SetInventoryVersion(
		    EQ::versions::ConvertClientVersionToMobVersion(client_version));
	}

	EQ::versions::MobVersion MobVersion() { return m_mob_version; }

	const inventory::LookupEntry* GetLookup() const { return m_lookup; }

	static void CleanDirty();
	static void MarkDirty(ItemInstance* inst);

	// Retrieve a writable item at specified slot
	ItemInstance* GetItem(int16 slot_id) const;
	ItemInstance* GetItem(int16 slot_id, uint8 bagidx) const;

	inline std::list<ItemInstance*>::const_iterator cursor_cbegin() {
		return m_cursor.cbegin();
	}
	inline std::list<ItemInstance*>::const_iterator cursor_cend() {
		return m_cursor.cend();
	}

	inline int CursorSize() { return m_cursor.size(); }
	inline bool CursorEmpty() { return (m_cursor.size() == 0); }

	// Retrieve a read-only item from Mob
	inline const ItemInstance* operator[](int16 slot_id) const {
		return GetItem(slot_id);
	}

	// Add item to Mob
	int16 PutItem(int16 slot_id, const ItemInstance& inst);
	int16 RefPutItem(int16 slot_id, ItemInstance* inst);

	// Add item to cursor queue
	int16 PushCursor(const ItemInstance& inst, bool push_front = false);

	// Swap items in Mob
	bool SwapItem(int16 slot_a, int16 slot_b);

	// Remove item from Mob
	bool DeleteItem(int16 slot_id, uint8 quantity = 0);

	// Checks All items in a bag for No Drop
	bool CheckNoDrop(int16 slot_id);

	// Remove item from Mob (and take control of memory)
	ItemInstance* PopItem(int16 slot_id);

	// Check whether there is space for the specified number of the specified
	// item.
	bool HasSpaceForItem(const ItemData* ItemToTry, int16 Quantity);

	// Check whether item exists in Mob
	// where argument specifies OR'd list of invWhere constants to look
	int16 HasItem(int16 item_id, uint8 quantity = 0, uint8 where = 0xFF);
	int16 HasArtifactItem();

	// Check whether item exists in Mob
	// where argument specifies OR'd list of invWhere constants to look
	int16 HasItemByUse(uint8 use, uint8 quantity = 0, uint8 where = 0xFF);

	// Locate an available Mob slot
	int16 FindFreeSlot(bool for_bag, bool try_cursor, uint8 min_size = 0,
	                   bool is_arrow = false);
	int16 FindFreeSlotForTradeItem(const ItemInstance* inst);

	// Calculate slot_id for an item within a bag
	static int16 CalcSlotId(int16 slot_id);  // Calc parent bag's slot_id
	static int16 CalcSlotId(int16 bagslot_id,
	                        uint8 bagidx);   // Calc slot_id for item inside bag
	static uint8 CalcBagIdx(int16 slot_id);  // Calc bagidx for slot_id
	static int16 CalcSlotFromMaterial(uint8 material);
	static uint8 CalcMaterialFromSlot(int16 equipslot);

	static bool CanItemFitInContainer(const ItemData* ItemToTry,
	                                  const ItemData* Container);

	//  Test for valid Mob casting slot
	bool SupportsClickCasting(int16 slot_id);

	// Test whether a given slot can support a container item
	static bool SupportsContainers(int16 slot_id);

	int GetSlotByItemInst(ItemInstance* inst);

	uint8 FindBrightestLightType();

	void dumpEntireInventory();
	void dumpInventory();
	void dumpWornItems();
	void dumpMob();
	void dumpBankItems();

	void SetCustomItemData(uint32 character_id, int16 slot_id,
	                       std::string identifier, std::string value);
	void SetCustomItemData(uint32 character_id, int16 slot_id,
	                       std::string identifier, int value);
	void SetCustomItemData(uint32 character_id, int16 slot_id,
	                       std::string identifier, float value);
	void SetCustomItemData(uint32 character_id, int16 slot_id,
	                       std::string identifier, bool value);
	std::string GetCustomItemData(int16 slot_id, std::string identifier);

   protected:
	///////////////////////////////
	// Protected Methods
	///////////////////////////////

	int GetSlotByItemInstCollection(
	    const std::map<int16, ItemInstance*>& collection, ItemInstance* inst);
	void dumpItemCollection(const std::map<int16, ItemInstance*>& collection);
	void dumpBagContents(ItemInstance* inst,
	                     std::map<int16, ItemInstance*>::const_iterator* it);

	// Retrieves item within an Mob bucket
	ItemInstance* _GetItem(const std::map<int16, ItemInstance*>& bucket,
	                       int16 slot_id) const;

	// Private "put" item into bucket, without regard for what is currently in
	// bucket
	int16 _PutItem(int16 slot_id, ItemInstance* inst);

	// Checks an Mob bucket for a particular item
	int16 _HasItem(std::map<int16, ItemInstance*>& bucket, int16 item_id,
	               uint8 quantity);
	int16 _HasItem(ItemInstQueue& iqueue, int16 item_id, uint8 quantity);
	int16 _HasItemByUse(std::map<int16, ItemInstance*>& bucket, uint8 use,
	                    uint8 quantity);
	int16 _HasItemByUse(ItemInstQueue& iqueue, uint8 use, uint8 quantity);

	// Player inventory
	std::map<int16, ItemInstance*> m_worn;  // Items worn by character
	std::map<int16, ItemInstance*>
	    m_inv;                               // Items in character personal inventory
	std::map<int16, ItemInstance*> m_bank;   // Items in character bank
	std::map<int16, ItemInstance*> m_trade;  // Items in a trade session
	ItemInstQueue m_cursor;                  // Items on cursor: FIFO

   private:
	// Active inventory version
	EQ::versions::MobVersion m_mob_version;
	bool m_mob_version_set;
	const inventory::LookupEntry* m_lookup;
};
}  // namespace EQ
#endif /*COMMON_INVENTORY_PROFILE_H*/
