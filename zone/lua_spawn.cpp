#ifdef LUA_EQEMU

#include "lua.hpp"
#include <luabind/luabind.hpp>

#include "spawn2.h"
#include "lua_npc.h"
#include "lua_spawn.h"

void Lua_Spawn::LoadGrid() {
	Lua_Safe_Call_Void();
	self->LoadGrid();
}

uint16 Lua_Spawn::GetGrid() {
	Lua_Safe_Call_Int();
	return self->GetGrid();
}

void Lua_Spawn::Enable() {
	Lua_Safe_Call_Void();
	return self->Enable();
}

void Lua_Spawn::Disable() {
	Lua_Safe_Call_Void();
	return self->Disable();
}

void Lua_Spawn::Disable(bool depop) {
	Lua_Safe_Call_Void();
	return self->Disable(depop);
}

bool Lua_Spawn::Enabled() {
	Lua_Safe_Call_Bool();
	return self->Enabled();
}

void Lua_Spawn::Reset() {
	Lua_Safe_Call_Void();
	self->Reset();
}

void Lua_Spawn::Reset(uint32 rtime) {
	Lua_Safe_Call_Void();
	self->Reset(rtime);
}

void Lua_Spawn::Depop() {
	Lua_Safe_Call_Void();
	self->Depop();
}

void Lua_Spawn::Repop() {
	Lua_Safe_Call_Void();
	self->Repop();
}

void Lua_Spawn::Repop(uint32 delay) {
	Lua_Safe_Call_Void();
	self->Repop(delay);
}

void Lua_Spawn::ForceDespawn() {
	Lua_Safe_Call_Void();
	self->ForceDespawn();
}

void Lua_Spawn::ChangeDespawn(uint8 newval) {
	Lua_Safe_Call_Void();
	self->ChangeDespawn(newval);
}

void Lua_Spawn::ChangeDespawn(uint8 newval, uint32 timer) {
	Lua_Safe_Call_Void();
	self->ChangeDespawn(newval, timer);
}

uint32 Lua_Spawn::GetID() {
	Lua_Safe_Call_Int();
	return self->GetID();
}

float Lua_Spawn::GetX() {
	Lua_Safe_Call_Real();
	return self->GetX();
}

float Lua_Spawn::GetY() {
	Lua_Safe_Call_Real();
	return self->GetY();
}

float Lua_Spawn::GetZ() {
	Lua_Safe_Call_Real();
	return self->GetZ();
}

float Lua_Spawn::GetHeading() {
	Lua_Safe_Call_Real();
	return self->GetHeading();
}

void Lua_Spawn::SetRespawnTimer(uint32 newrespawntime) {
	Lua_Safe_Call_Void();
	self->SetRespawnTimer(newrespawntime);
}

void Lua_Spawn::SetVariance(uint32 newvariance) {
	Lua_Safe_Call_Void();
	self->SetVariance(newvariance);
}

uint32 Lua_Spawn::GetVariance() {
	Lua_Safe_Call_Int();
	return self->GetVariance();
}

uint32 Lua_Spawn::RespawnTimer() {
	Lua_Safe_Call_Int();
	return self->RespawnTimer();
}

uint32 Lua_Spawn::SpawnGroupID() {
	Lua_Safe_Call_Int();
	return self->SpawnGroupID();
}

uint32 Lua_Spawn::CurrentNPCID() {
	Lua_Safe_Call_Int();
	return self->CurrentNPCID();
}

void Lua_Spawn::SetCurrentNPCID(uint32 nid) {
	Lua_Safe_Call_Void();
	self->SetCurrentNPCID(nid);
}

uint32 Lua_Spawn::GetSpawnCondition() {
	Lua_Safe_Call_Int();
	return self->GetSpawnCondition();
}

bool Lua_Spawn::NPCPointerValid() {
	Lua_Safe_Call_Bool();
	return self->NPCPointerValid();
}

void Lua_Spawn::SetNPCPointer(Lua_NPC n) {
	Lua_Safe_Call_Void();
	self->SetNPCPointer(n);
}

void Lua_Spawn::SetTimer(uint32 duration) {
	Lua_Safe_Call_Void();
	self->SetTimer(duration);
}

uint32 Lua_Spawn::GetKillCount() {
	Lua_Safe_Call_Int();
	return self->GetKillCount();
}

Lua_NPC Lua_Spawn::GetNPC() {
	Lua_Safe_Call_Class(Lua_NPC);
	return Lua_NPC(self->GetNPCPointer());
}

luabind::scope lua_register_spawn() {
	return luabind::class_<Lua_Spawn>("Spawn")
		.def(luabind::constructor<>())
		.property("null", &Lua_Spawn::Null)
		.property("valid", &Lua_Spawn::Valid)
		.def("LoadGrid", (void(Lua_Spawn::*)(void))&Lua_Spawn::LoadGrid)
		.def("GetGrid", (uint16(Lua_Spawn::*)(void))&Lua_Spawn::GetGrid)
		.def("Enable", (void(Lua_Spawn::*)(void))&Lua_Spawn::Enable)
		.def("Disable", (void(Lua_Spawn::*)(void))&Lua_Spawn::Disable)
		.def("Disable", (void(Lua_Spawn::*)(bool))&Lua_Spawn::Disable)
		.def("Enabled", (bool(Lua_Spawn::*)(void))&Lua_Spawn::Enabled)
		.def("Reset", (void(Lua_Spawn::*)(void))&Lua_Spawn::Reset)
		.def("Reset", (void(Lua_Spawn::*)(uint32))&Lua_Spawn::Reset)
		.def("Depop", (void(Lua_Spawn::*)(void))&Lua_Spawn::Depop)
		.def("Repop", (void(Lua_Spawn::*)(void))&Lua_Spawn::Repop)
		.def("Repop", (void(Lua_Spawn::*)(uint32))&Lua_Spawn::Repop)
		.def("ForceDespawn", (void(Lua_Spawn::*)(void))&Lua_Spawn::ForceDespawn)
		.def("ChangeDespawn", (void(Lua_Spawn::*)(uint8))&Lua_Spawn::ChangeDespawn)
		.def("ChangeDespawn", (void(Lua_Spawn::*)(uint8, uint32))&Lua_Spawn::ChangeDespawn)
		.def("GetID", (uint32(Lua_Spawn::*)(void))&Lua_Spawn::GetID)
		.def("GetX", (float(Lua_Spawn::*)(void))&Lua_Spawn::GetX)
		.def("GetY", (float(Lua_Spawn::*)(void))&Lua_Spawn::GetY)
		.def("GetZ", (float(Lua_Spawn::*)(void))&Lua_Spawn::GetZ)
		.def("GetHeading", (float(Lua_Spawn::*)(void))&Lua_Spawn::GetHeading)
		.def("SetRespawnTimer", (void(Lua_Spawn::*)(uint32))&Lua_Spawn::SetRespawnTimer)
		.def("SetVariance", (void(Lua_Spawn::*)(uint32))&Lua_Spawn::SetVariance)
		.def("GetVariance", (uint32(Lua_Spawn::*)(void))&Lua_Spawn::GetVariance)
		.def("RespawnTimer", (uint32(Lua_Spawn::*)(void))&Lua_Spawn::RespawnTimer)
		.def("SpawnGroupID", (uint32(Lua_Spawn::*)(void))&Lua_Spawn::SpawnGroupID)
		.def("CurrentNPCID", (uint32(Lua_Spawn::*)(void))&Lua_Spawn::CurrentNPCID)
		.def("SetCurrentNPCID", (void(Lua_Spawn::*)(uint32))&Lua_Spawn::SetCurrentNPCID)
		.def("GetSpawnCondition", (uint32(Lua_Spawn::*)(void))&Lua_Spawn::GetSpawnCondition)
		.def("NPCPointerValid", (bool(Lua_Spawn::*)(void))&Lua_Spawn::NPCPointerValid)
		.def("SetNPCPointer", (void(Lua_Spawn::*)(Lua_NPC))&Lua_Spawn::SetNPCPointer)
		.def("SetTimer", (void(Lua_Spawn::*)(uint32))&Lua_Spawn::SetTimer)
		.def("GetKillCount", (uint32(Lua_Spawn::*)(void))&Lua_Spawn::GetKillCount)
		.def("GetNPC", (Lua_NPC(Lua_Spawn::*)(void))&Lua_Spawn::GetNPC);
}

#endif
