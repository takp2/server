#ifndef EQEMU_LUA_INVENTORY_H
#define EQEMU_LUA_INVENTORY_H
#ifdef LUA_EQEMU

#include "lua_ptr.h"

class Lua_ItemInst;
class Lua_Item;

namespace EQ
{
	class InventoryProfile;
}

namespace luabind {
	struct scope;
}

luabind::scope lua_register_inventory();

class Lua_Inventory : public Lua_Ptr<EQ::InventoryProfile>
{
	typedef EQ::InventoryProfile NativeType;
public:
	Lua_Inventory() : Lua_Ptr(nullptr) { }
	Lua_Inventory(EQ::InventoryProfile*d) : Lua_Ptr(d) { }
	virtual ~Lua_Inventory() { }

	operator EQ::InventoryProfile*() {
		return reinterpret_cast<EQ::InventoryProfile*>(GetLuaPtrData());
	}

	Lua_ItemInst GetItem(int slot_id);
	Lua_ItemInst GetItem(int slot_id, int bag_slot);
	int PutItem(int slot_id, Lua_ItemInst item);
	int PushCursor(Lua_ItemInst item);
	bool SwapItem(int slot_a, int slot_b);
	bool DeleteItem(int slot_id);
	bool DeleteItem(int slot_id, int quantity);
	bool CheckNoDrop(int slot_id);
	Lua_ItemInst PopItem(int slot_id);
	int HasItem(int item_id);
	int HasItem(int item_id, int quantity);
	int HasItem(int item_id, int quantity, int where);
	bool HasSpaceForItem(Lua_Item item, int quantity);
	int HasItemByUse(int use);
	int HasItemByUse(int use, uint8 quantity);
	int HasItemByUse(int use, uint8 quantity, uint8 where);
	int FindFreeSlot(bool for_bag, bool try_cursor);
	int FindFreeSlot(bool for_bag, bool try_cursor, int min_size);
	int FindFreeSlot(bool for_bag, bool try_cursor, int min_size, bool is_arrow);
	int CalcSlotId(int slot_id);
	int CalcSlotId(int slot_id, int bag_slot);
	int CalcBagIdx(int slot_id);
	int CalcSlotFromMaterial(int material);
	int CalcMaterialFromSlot(int equipslot);
	bool CanItemFitInContainer(Lua_Item item, Lua_Item container);
	bool SupportsContainers(int slot_id);
	int GetSlotByItemInst(Lua_ItemInst inst);
};

#endif
#endif
