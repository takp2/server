#ifndef EQEMU_LUA_GROUP_H
#define EQEMU_LUA_GROUP_H
#ifdef LUA_EQEMU

#include "lua_ptr.h"

class Group;
class Lua_Mob;
class Lua_Client;
class Lua_NPC;

namespace luabind {
	struct scope;
}

luabind::scope lua_register_group();

class Lua_Group : public Lua_Ptr<Group>
{
	typedef Group NativeType;
public:
	Lua_Group() : Lua_Ptr(nullptr) { }
	Lua_Group(Group *d) : Lua_Ptr(d) { }
	virtual ~Lua_Group() { }

	operator Group*() {
		return reinterpret_cast<Group*>(GetLuaPtrData());
	}
	void DisbandGroup();
	void DisbandGroup(bool alt_msg);
	void DisbandGroup(bool alt_msg, uint32 msg);
	bool IsGroupMember(Lua_Mob mob);
	void CastGroupSpell(Lua_Mob caster, int spell_id);
	void SplitExp(uint32 exp, Lua_Mob other);
	void GroupMessage(Lua_Mob sender, int language, const char *message);
	uint32 GetTotalGroupDamage(Lua_NPC other);
	void SplitMoney(uint32 copper, uint32 silver, uint32 gold, uint32 platinum);
	void SplitMoney(uint32 copper, uint32 silver, uint32 gold, uint32 platinum, Lua_Client splitter);
	void SetLeader(Lua_Mob leader);
	Lua_Mob GetLeader();
	const char *GetLeaderName();
	bool IsLeader(Lua_Mob leader);
	int GroupCount();
	int GetHighestLevel();
	void TeleportGroup(Lua_Mob sender, uint32 zone_id, float x, float y, float z, float h);
	int GetID();
	Lua_Mob GetMember(int index);
};

#endif
#endif
