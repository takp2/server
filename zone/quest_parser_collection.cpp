#include "../common/global_define.h"
#include "../common/misc_functions.h"
#include "../common/features.h"

#include "quest_parser_collection.h"
#include "quest_interface.h"
#include "zone.h"
#include "questmgr.h"
#include "zone_config.h"

#include <stdio.h>

extern Zone *zone;
extern void MapOpcodes();

QuestParserCollection::QuestParserCollection() {
	_player_quest_status = QuestUnloaded;
	_global_player_quest_status = QuestUnloaded;
	_global_npc_quest_status = QuestUnloaded;
}

QuestParserCollection::~QuestParserCollection() {
}

void QuestParserCollection::RegisterQuestInterface(QuestInterface *qi, std::string ext) {
	_interfaces[qi->GetIdentifier()] = qi;
	_extensions[qi->GetIdentifier()] = ext;
	_load_precedence.push_back(qi);
}

void QuestParserCollection::ClearInterfaces() {
	_interfaces.clear();
	_extensions.clear();
	_load_precedence.clear();
}

void QuestParserCollection::AddVar(std::string name, std::string val) {
	auto iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		(*iter)->AddVar(name, val);
		++iter;
	}
}

void QuestParserCollection::Init() {
	auto iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		(*iter)->Init();
		++iter;
	}
}

void QuestParserCollection::ReloadQuests(bool reset_timers) {
	if (reset_timers) {
		quest_manager.ClearAllTimers();
	}

	MapOpcodes();
	_npc_quest_status.clear();
	_player_quest_status = QuestUnloaded;
	_global_player_quest_status = QuestUnloaded;
	_global_npc_quest_status = QuestUnloaded;
	_spell_quest_status.clear();
	_item_quest_status.clear();
	_encounter_quest_status.clear();
	auto iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		(*iter)->ReloadQuests();
		++iter;
	}
}

void QuestParserCollection::RemoveEncounter(const std::string name) {
	auto iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		(*iter)->RemoveEncounter(name);
		++iter;
	}
}

bool QuestParserCollection::HasQuestSub(uint32 npcid, QuestEventID evt, bool check_encounters) {
	return HasQuestSubLocal(npcid, evt) || HasQuestSubGlobal(evt) || (check_encounters && NPCHasEncounterSub(npcid, evt));
}

bool QuestParserCollection::NPCHasEncounterSub(uint32 npc_id, QuestEventID evt) {
	std::string package_name = "npc_" + std::to_string(npc_id);
	return HasEncounterSub(evt, package_name);
}

bool QuestParserCollection::HasQuestSubLocal(uint32 npcid, QuestEventID evt) {
	auto iter = _npc_quest_status.find(npcid);

	if (iter != _npc_quest_status.end()) {
		// loaded or failed to load
		if (iter->second != QuestFailedToLoad) {
			auto qiter = _interfaces.find(iter->second);
			if (qiter->second->HasQuestSub(npcid, evt)) {
				return true;
			}
		}
	} else {
		std::string filename;
		QuestInterface *qi = GetQIByNPCQuest(npcid, filename);
		if (qi) {
			_npc_quest_status[npcid] = qi->GetIdentifier();

			qi->LoadNPCScript(filename, npcid);
			if (qi->HasQuestSub(npcid, evt)) {
				return true;
			}
		} else {
			_npc_quest_status[npcid] = QuestFailedToLoad;
		}
	}
	return false;
}

bool QuestParserCollection::HasQuestSubGlobal(QuestEventID evt) {
	if (_global_npc_quest_status == QuestUnloaded) {
		std::string filename;
		QuestInterface *qi = GetQIByGlobalNPCQuest(filename);
		if (qi) {
			qi->LoadGlobalNPCScript(filename);
			_global_npc_quest_status = qi->GetIdentifier();
			if (qi->HasGlobalQuestSub(evt)) {
				return true;
			}
		}
	} else {
		if (_global_npc_quest_status != QuestFailedToLoad) {
			auto qiter = _interfaces.find(_global_npc_quest_status);
			if (qiter->second->HasGlobalQuestSub(evt)) {
				return true;
			}
		}
	}
	return false;
}

bool QuestParserCollection::PlayerHasQuestSub(QuestEventID evt, bool check_encounters) {
	return PlayerHasQuestSubLocal(evt) || PlayerHasQuestSubGlobal(evt) || (check_encounters && PlayerHasEncounterSub(evt));
}

bool QuestParserCollection::PlayerHasEncounterSub(QuestEventID evt) {
	return HasEncounterSub(evt, "player");
}

bool QuestParserCollection::PlayerHasQuestSubLocal(QuestEventID evt) {
	if (_player_quest_status == QuestUnloaded) {
		std::string filename;
		QuestInterface *qi = GetQIByPlayerQuest(filename);
		if (qi) {
			_player_quest_status = qi->GetIdentifier();
			qi->LoadPlayerScript(filename);
			return qi->PlayerHasQuestSub(evt);
		}
	} else if (_player_quest_status != QuestFailedToLoad) {
		auto iter = _interfaces.find(_player_quest_status);
		return iter->second->PlayerHasQuestSub(evt);
	}
	return false;
}

bool QuestParserCollection::PlayerHasQuestSubGlobal(QuestEventID evt) {
	if (_global_player_quest_status == QuestUnloaded) {
		std::string filename;
		QuestInterface *qi = GetQIByGlobalPlayerQuest(filename);
		if (qi) {
			_global_player_quest_status = qi->GetIdentifier();
			qi->LoadGlobalPlayerScript(filename);
			return qi->GlobalPlayerHasQuestSub(evt);
		}
	} else if (_global_player_quest_status != QuestFailedToLoad) {
		auto iter = _interfaces.find(_global_player_quest_status);
		return iter->second->GlobalPlayerHasQuestSub(evt);
	}
	return false;
}

bool QuestParserCollection::SpellHasEncounterSub(uint32 spell_id, QuestEventID evt) {
	std::string package_name = "spell_" + std::to_string(spell_id);
	return HasEncounterSub(evt, package_name);
}

bool QuestParserCollection::SpellHasQuestSub(uint32 spell_id, QuestEventID evt, bool check_encounters) {
	if (check_encounters && SpellHasEncounterSub(spell_id, evt)) {
		return true;
	}

	auto iter = _spell_quest_status.find(spell_id);
	if (iter != _spell_quest_status.end()) {
		// loaded or failed to load
		if (iter->second != QuestFailedToLoad) {
			auto qiter = _interfaces.find(iter->second);
			return qiter->second->SpellHasQuestSub(spell_id, evt);
		}
	} else {
		std::string filename;
		QuestInterface *qi = GetQIBySpellQuest(spell_id, filename);
		if (qi) {
			_spell_quest_status[spell_id] = qi->GetIdentifier();
			qi->LoadSpellScript(filename, spell_id);
			return qi->SpellHasQuestSub(spell_id, evt);
		} else {
			_spell_quest_status[spell_id] = QuestFailedToLoad;
		}
	}
	return false;
}

bool QuestParserCollection::ItemHasEncounterSub(EQ::ItemInstance *item, QuestEventID evt) {
	if (item) {
		std::string package_name = "item_" + std::to_string(item->GetID());
		return HasEncounterSub(evt, package_name);
	}
	return false;
}

bool QuestParserCollection::ItemHasQuestSub(EQ::ItemInstance *itm, QuestEventID evt, bool check_encounters) {
	if (itm == nullptr)
		return false;

	if (check_encounters && ItemHasEncounterSub(itm, evt)) {
		return true;
	}

	std::string item_script;
	item_script = std::to_string(itm->GetID());

	uint32 item_id = itm->GetID();
	auto iter = _item_quest_status.find(item_id);
	if (iter != _item_quest_status.end()) {
		// loaded or failed to load
		if (iter->second != QuestFailedToLoad) {
			auto qiter = _interfaces.find(iter->second);
			return qiter->second->ItemHasQuestSub(itm, evt);
		}
	} else {
		std::string filename;
		QuestInterface *qi = GetQIByItemQuest(item_script, filename);
		if (qi) {
			_item_quest_status[item_id] = qi->GetIdentifier();
			qi->LoadItemScript(filename, itm);
			return qi->ItemHasQuestSub(itm, evt);
		} else {
			_item_quest_status[item_id] = QuestFailedToLoad;
		}
	}
	return false;
}

bool QuestParserCollection::HasEncounterSub(QuestEventID evt, const std::string &package_name) {
	for (auto it = _encounter_quest_status.begin(); it != _encounter_quest_status.end(); ++it) {
		if (it->second != QuestFailedToLoad) {
			auto qit = _interfaces.find(it->second);
			if (qit != _interfaces.end() && qit->second->HasEncounterSub(package_name, evt)) {
				return true;
			}
		}
	}
	return false;
}

int QuestParserCollection::EventNPC(QuestEventID evt, NPC *npc, Mob *init, std::string data, uint32 extra_data,
                                    std::vector<EQ::Any> *extra_pointers) {
	int rd = DispatchEventNPC(evt, npc, init, data, extra_data, extra_pointers);
	int rl = EventNPCLocal(evt, npc, init, data, extra_data, extra_pointers);
	int rg = EventNPCGlobal(evt, npc, init, data, extra_data, extra_pointers);

	// Local quests returning non-default values have priority over global quests
	if (rl != 0) {
		return rl;
	} else if (rg != 0) {
		return rg;
	} else if (rd != 0) {
		return rd;
	}

	return 0;
}

int QuestParserCollection::EventNPCLocal(QuestEventID evt, NPC *npc, Mob *init, std::string data, uint32 extra_data,
                                         std::vector<EQ::Any> *extra_pointers) {
	if (!npc)
		return 0;

	auto iter = _npc_quest_status.find(npc->GetNPCTypeID());
	if (iter != _npc_quest_status.end()) {
		// loaded or failed to load
		if (iter->second != QuestFailedToLoad) {
			auto qiter = _interfaces.find(iter->second);
			return qiter->second->EventNPC(evt, npc, init, data, extra_data, extra_pointers);
		}
	} else {
		std::string filename;
		QuestInterface *qi = GetQIByNPCQuest(npc->GetNPCTypeID(), filename);
		if (qi) {
			_npc_quest_status[npc->GetNPCTypeID()] = qi->GetIdentifier();
			qi->LoadNPCScript(filename, npc->GetNPCTypeID());
			return qi->EventNPC(evt, npc, init, data, extra_data, extra_pointers);
		} else {
			_npc_quest_status[npc->GetNPCTypeID()] = QuestFailedToLoad;
		}
	}
	return 0;
}

int QuestParserCollection::EventNPCGlobal(QuestEventID evt, NPC *npc, Mob *init, std::string data, uint32 extra_data,
                                          std::vector<EQ::Any> *extra_pointers) {
	if (_global_npc_quest_status != QuestUnloaded && _global_npc_quest_status != QuestFailedToLoad) {
		auto qiter = _interfaces.find(_global_npc_quest_status);
		return qiter->second->EventGlobalNPC(evt, npc, init, data, extra_data, extra_pointers);
	} else {
		std::string filename;
		QuestInterface *qi = GetQIByGlobalNPCQuest(filename);
		if (qi) {
			_global_npc_quest_status = qi->GetIdentifier();
			qi->LoadGlobalNPCScript(filename);
			return qi->EventGlobalNPC(evt, npc, init, data, extra_data, extra_pointers);
		} else {
			_global_npc_quest_status = QuestFailedToLoad;
		}
	}
	return 0;
}

int QuestParserCollection::EventPlayer(QuestEventID evt, Client *client, std::string data, uint32 extra_data,
                                       std::vector<EQ::Any> *extra_pointers) {
	int rd = DispatchEventPlayer(evt, client, data, extra_data, extra_pointers);
	int rl = EventPlayerLocal(evt, client, data, extra_data, extra_pointers);
	int rg = EventPlayerGlobal(evt, client, data, extra_data, extra_pointers);

	// Local quests returning non-default values have priority over global quests
	if (rl != 0) {
		return rl;
	} else if (rg != 0) {
		return rg;
	} else if (rd != 0) {
		return rd;
	}

	return 0;
}

int QuestParserCollection::EventPlayerLocal(QuestEventID evt, Client *client, std::string data, uint32 extra_data,
                                            std::vector<EQ::Any> *extra_pointers) {
	if (_player_quest_status == QuestUnloaded) {
		std::string filename;
		QuestInterface *qi = GetQIByPlayerQuest(filename);
		if (qi) {
			_player_quest_status = qi->GetIdentifier();
			qi->LoadPlayerScript(filename);
			return qi->EventPlayer(evt, client, data, extra_data, extra_pointers);
		}
	} else {
		if (_player_quest_status != QuestFailedToLoad) {
			auto iter = _interfaces.find(_player_quest_status);
			return iter->second->EventPlayer(evt, client, data, extra_data, extra_pointers);
		}
	}
	return 0;
}

int QuestParserCollection::EventPlayerGlobal(QuestEventID evt, Client *client, std::string data, uint32 extra_data,
                                             std::vector<EQ::Any> *extra_pointers) {
	if (_global_player_quest_status == QuestUnloaded) {
		std::string filename;
		QuestInterface *qi = GetQIByGlobalPlayerQuest(filename);
		if (qi) {
			_global_player_quest_status = qi->GetIdentifier();
			qi->LoadGlobalPlayerScript(filename);
			return qi->EventGlobalPlayer(evt, client, data, extra_data, extra_pointers);
		}
	} else {
		if (_global_player_quest_status != QuestFailedToLoad) {
			auto iter = _interfaces.find(_global_player_quest_status);
			return iter->second->EventGlobalPlayer(evt, client, data, extra_data, extra_pointers);
		}
	}
	return 0;
}

int QuestParserCollection::EventItem(QuestEventID evt, Client *client, EQ::ItemInstance *item, Mob *mob, std::string data, uint32 extra_data,
                                     std::vector<EQ::Any> *extra_pointers) {
	// needs pointer validation check on 'item' argument

	std::string item_script;
	item_script = std::to_string(item->GetID());

	uint32 item_id = item->GetID();
	auto iter = _item_quest_status.find(item_id);
	if (iter != _item_quest_status.end()) {
		// loaded or failed to load
		if (iter->second != QuestFailedToLoad) {
			auto qiter = _interfaces.find(iter->second);
			int ret = DispatchEventItem(evt, client, item, mob, data, extra_data, extra_pointers);
			int i = qiter->second->EventItem(evt, client, item, mob, data, extra_data, extra_pointers);
			if (i != 0) {
				ret = i;
			}
			return ret;
		}
		return DispatchEventItem(evt, client, item, mob, data, extra_data, extra_pointers);
	} else {
		std::string filename;
		QuestInterface *qi = GetQIByItemQuest(item_script, filename);
		if (qi) {
			_item_quest_status[item_id] = qi->GetIdentifier();
			qi->LoadItemScript(filename, item);
			int ret = DispatchEventItem(evt, client, item, mob, data, extra_data, extra_pointers);
			int i = qi->EventItem(evt, client, item, mob, data, extra_data, extra_pointers);
			if (i != 0) {
				ret = i;
			}
			return ret;
		} else {
			_item_quest_status[item_id] = QuestFailedToLoad;
			return DispatchEventItem(evt, client, item, mob, data, extra_data, extra_pointers);
		}
	}
	return 0;
}

int QuestParserCollection::EventSpell(QuestEventID evt, NPC *npc, Client *client, uint32 spell_id, uint32 extra_data,
                                      std::vector<EQ::Any> *extra_pointers) {
	auto iter = _spell_quest_status.find(spell_id);
	if (iter != _spell_quest_status.end()) {
		// loaded or failed to load
		if (iter->second != QuestFailedToLoad) {
			auto qiter = _interfaces.find(iter->second);
			int ret = DispatchEventSpell(evt, npc, client, spell_id, extra_data, extra_pointers);
			int i = qiter->second->EventSpell(evt, npc, client, spell_id, extra_data, extra_pointers);
			if (i != 0) {
				ret = i;
			}
			return ret;
		}
		return DispatchEventSpell(evt, npc, client, spell_id, extra_data, extra_pointers);
	} else {
		std::string filename;
		QuestInterface *qi = GetQIBySpellQuest(spell_id, filename);
		if (qi) {
			_spell_quest_status[spell_id] = qi->GetIdentifier();
			qi->LoadSpellScript(filename, spell_id);
			int ret = DispatchEventSpell(evt, npc, client, spell_id, extra_data, extra_pointers);
			int i = qi->EventSpell(evt, npc, client, spell_id, extra_data, extra_pointers);
			if (i != 0) {
				ret = i;
			}
			return ret;
		} else {
			_spell_quest_status[spell_id] = QuestFailedToLoad;
			return DispatchEventSpell(evt, npc, client, spell_id, extra_data, extra_pointers);
		}
	}
	return 0;
}

int QuestParserCollection::EventEncounter(QuestEventID evt, std::string encounter_name, std::string data, uint32 extra_data,
                                          std::vector<EQ::Any> *extra_pointers) {
	auto iter = _encounter_quest_status.find(encounter_name);
	if (iter != _encounter_quest_status.end()) {
		// loaded or failed to load
		if (iter->second != QuestFailedToLoad) {
			auto qiter = _interfaces.find(iter->second);
			return qiter->second->EventEncounter(evt, encounter_name, data, extra_data, extra_pointers);
		}
	} else {
		std::string filename;
		QuestInterface *qi = GetQIByEncounterQuest(encounter_name, filename);
		if (qi) {
			_encounter_quest_status[encounter_name] = qi->GetIdentifier();
			qi->LoadEncounterScript(filename, encounter_name);
			return qi->EventEncounter(evt, encounter_name, data, extra_data, extra_pointers);
		} else {
			_encounter_quest_status[encounter_name] = QuestFailedToLoad;
		}
	}
	return 0;
}

QuestInterface *QuestParserCollection::GetQIByNPCQuest(uint32 npcid, std::string &filename) {
	// first look for /quests/zone/npcid.ext (precedence)
	filename = Config->QuestDir;
	filename += zone->GetShortName();
	filename += "/";
	filename += itoa(npcid);
	std::string tmp;
	FILE *f = nullptr;

	auto iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		tmp = filename;
		auto ext = _extensions.find((*iter)->GetIdentifier());
		tmp += ".";
		tmp += ext->second;
		f = fopen(tmp.c_str(), "r");
		if (f) {
			fclose(f);
			filename = tmp;
			return (*iter);
		}

		++iter;
	}

	// second look for /quests/zone/npcname.ext (precedence)
	const NPCType *npc_type = database.GetNPCType(npcid);
	if (!npc_type) {
		return nullptr;
	}
	std::string npc_name = npc_type->name;
	int sz = static_cast<int>(npc_name.length());
	for (int i = 0; i < sz; ++i) {
		if (npc_name[i] == '`') {
			npc_name[i] = '-';
		}
	}

	filename = Config->QuestDir;
	filename += zone->GetShortName();
	filename += "/";
	filename += npc_name;

	iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		tmp = filename;
		auto ext = _extensions.find((*iter)->GetIdentifier());
		tmp += ".";
		tmp += ext->second;
		f = fopen(tmp.c_str(), "r");
		if (f) {
			fclose(f);
			filename = tmp;
			return (*iter);
		}

		++iter;
	}

	// third look for /quests/global/npcid.ext (precedence)
	filename = Config->QuestDir;
	filename += QUEST_GLOBAL_DIRECTORY;
	filename += "/";
	filename += itoa(npcid);
	iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		tmp = filename;
		auto ext = _extensions.find((*iter)->GetIdentifier());
		tmp += ".";
		tmp += ext->second;
		f = fopen(tmp.c_str(), "r");
		if (f) {
			fclose(f);
			filename = tmp;
			return (*iter);
		}

		++iter;
	}

	// fourth look for /quests/global/npcname.ext (precedence)
	filename = Config->QuestDir;
	filename += QUEST_GLOBAL_DIRECTORY;
	filename += "/";
	filename += npc_name;
	iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		tmp = filename;
		auto ext = _extensions.find((*iter)->GetIdentifier());
		tmp += ".";
		tmp += ext->second;
		f = fopen(tmp.c_str(), "r");
		if (f) {
			fclose(f);
			filename = tmp;
			return (*iter);
		}

		++iter;
	}

	// fifth look for /quests/zone/default.ext (precedence)
	filename = Config->QuestDir;
	filename += zone->GetShortName();
	filename += "/";
	filename += "default";
	iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		tmp = filename;
		auto ext = _extensions.find((*iter)->GetIdentifier());
		tmp += ".";
		tmp += ext->second;
		f = fopen(tmp.c_str(), "r");
		if (f) {
			fclose(f);
			filename = tmp;
			return (*iter);
		}

		++iter;
	}

	// last look for /quests/global/default.ext (precedence)
	filename = Config->QuestDir;
	filename += QUEST_GLOBAL_DIRECTORY;
	filename += "/";
	filename += "default";
	iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		tmp = filename;
		auto ext = _extensions.find((*iter)->GetIdentifier());
		tmp += ".";
		tmp += ext->second;
		f = fopen(tmp.c_str(), "r");
		if (f) {
			fclose(f);
			filename = tmp;
			return (*iter);
		}

		++iter;
	}

	return nullptr;
}

QuestInterface *QuestParserCollection::GetQIByPlayerQuest(std::string &filename) {
	if (!zone || !zone->IsLoaded())
		return nullptr;

	// first look for /quests/zone/player_v.ext (precedence)
	filename = Config->QuestDir;
	filename += zone->GetShortName();
	filename += "/";
	filename += "player_v";
	std::string tmp;
	FILE *f = nullptr;

	auto iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		tmp = filename;
		auto ext = _extensions.find((*iter)->GetIdentifier());
		tmp += ".";
		tmp += ext->second;
		f = fopen(tmp.c_str(), "r");
		if (f) {
			fclose(f);
			filename = tmp;
			return (*iter);
		}

		++iter;
	}

	// second look for /quests/zone/player.ext (precedence)
	filename = Config->QuestDir;
	filename += zone->GetShortName();
	filename += "/";
	filename += "player";

	iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		tmp = filename;
		auto ext = _extensions.find((*iter)->GetIdentifier());
		tmp += ".";
		tmp += ext->second;
		f = fopen(tmp.c_str(), "r");
		if (f) {
			fclose(f);
			filename = tmp;
			return (*iter);
		}

		++iter;
	}

	// third look for /quests/global/player.ext (precedence)
	filename = Config->QuestDir;
	filename += QUEST_GLOBAL_DIRECTORY;
	filename += "/";
	filename += "player";
	iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		tmp = filename;
		auto ext = _extensions.find((*iter)->GetIdentifier());
		tmp += ".";
		tmp += ext->second;
		f = fopen(tmp.c_str(), "r");
		if (f) {
			fclose(f);
			filename = tmp;
			return (*iter);
		}

		++iter;
	}

	return nullptr;
}

QuestInterface *QuestParserCollection::GetQIByGlobalNPCQuest(std::string &filename) {
	// simply look for /quests/global/global_npc.ext
	filename = Config->QuestDir;
	filename += QUEST_GLOBAL_DIRECTORY;
	filename += "/";
	filename += "global_npc";
	std::string tmp;
	FILE *f = nullptr;

	auto iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		tmp = filename;
		auto ext = _extensions.find((*iter)->GetIdentifier());
		tmp += ".";
		tmp += ext->second;
		f = fopen(tmp.c_str(), "r");
		if (f) {
			fclose(f);
			filename = tmp;
			return (*iter);
		}

		++iter;
	}

	return nullptr;
}

QuestInterface *QuestParserCollection::GetQIByGlobalPlayerQuest(std::string &filename) {
	// first look for /quests/global/player.ext (precedence)
	filename = Config->QuestDir;
	filename += QUEST_GLOBAL_DIRECTORY;
	filename += "/";
	filename += "global_player";
	std::string tmp;
	FILE *f = nullptr;

	auto iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		tmp = filename;
		auto ext = _extensions.find((*iter)->GetIdentifier());
		tmp += ".";
		tmp += ext->second;
		f = fopen(tmp.c_str(), "r");
		if (f) {
			fclose(f);
			filename = tmp;
			return (*iter);
		}

		++iter;
	}

	return nullptr;
}

QuestInterface *QuestParserCollection::GetQIBySpellQuest(uint32 spell_id, std::string &filename) {
	// first look for /quests/zone/spells/spell_id.ext (precedence)
	filename = Config->QuestDir;
	filename += zone->GetShortName();
	filename += "/spells/";
	filename += itoa(spell_id);
	std::string tmp;
	FILE *f = nullptr;

	auto iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		tmp = filename;
		auto ext = _extensions.find((*iter)->GetIdentifier());
		tmp += ".";
		tmp += ext->second;
		f = fopen(tmp.c_str(), "r");
		if (f) {
			fclose(f);
			filename = tmp;
			return (*iter);
		}

		++iter;
	}

	// second look for /quests/global/spells/spell_id.ext (precedence)
	filename = Config->QuestDir;
	filename += QUEST_GLOBAL_DIRECTORY;
	filename += "/spells/";
	filename += itoa(spell_id);

	iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		tmp = filename;
		auto ext = _extensions.find((*iter)->GetIdentifier());
		tmp += ".";
		tmp += ext->second;
		f = fopen(tmp.c_str(), "r");
		if (f) {
			fclose(f);
			filename = tmp;
			return (*iter);
		}

		++iter;
	}

	// third look for /quests/zone/spells/default.ext (precedence)
	filename = Config->QuestDir;
	filename += zone->GetShortName();
	filename += "/spells/default";

	iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		tmp = filename;
		auto ext = _extensions.find((*iter)->GetIdentifier());
		tmp += ".";
		tmp += ext->second;
		f = fopen(tmp.c_str(), "r");
		if (f) {
			fclose(f);
			filename = tmp;
			return (*iter);
		}

		++iter;
	}

	// last look for /quests/global/spells/default.ext (precedence)
	filename = Config->QuestDir;
	filename += QUEST_GLOBAL_DIRECTORY;
	filename += "/spells/default";

	iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		tmp = filename;
		auto ext = _extensions.find((*iter)->GetIdentifier());
		tmp += ".";
		tmp += ext->second;
		f = fopen(tmp.c_str(), "r");
		if (f) {
			fclose(f);
			filename = tmp;
			return (*iter);
		}

		++iter;
	}

	return nullptr;
}

QuestInterface *QuestParserCollection::GetQIByItemQuest(std::string item_script, std::string &filename) {
	// first look for /quests/zone/items/item_script.ext (precedence)
	filename = Config->QuestDir;
	filename += zone->GetShortName();
	filename += "/items/";
	filename += item_script;
	std::string tmp;
	FILE *f = nullptr;

	auto iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		tmp = filename;
		auto ext = _extensions.find((*iter)->GetIdentifier());
		tmp += ".";
		tmp += ext->second;
		f = fopen(tmp.c_str(), "r");
		if (f) {
			fclose(f);
			filename = tmp;
			return (*iter);
		}

		++iter;
	}

	// second look for /quests/global/items/item_script.ext (precedence)
	filename = Config->QuestDir;
	filename += QUEST_GLOBAL_DIRECTORY;
	filename += "/items/";
	filename += item_script;

	iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		tmp = filename;
		auto ext = _extensions.find((*iter)->GetIdentifier());
		tmp += ".";
		tmp += ext->second;
		f = fopen(tmp.c_str(), "r");
		if (f) {
			fclose(f);
			filename = tmp;
			return (*iter);
		}

		++iter;
	}

	// third look for /quests/zone/items/default.ext (precedence)
	filename = Config->QuestDir;
	filename += zone->GetShortName();
	filename += "/items/default";

	iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		tmp = filename;
		auto ext = _extensions.find((*iter)->GetIdentifier());
		tmp += ".";
		tmp += ext->second;
		f = fopen(tmp.c_str(), "r");
		if (f) {
			fclose(f);
			filename = tmp;
			return (*iter);
		}

		++iter;
	}

	// last look for /quests/global/items/default.ext (precedence)
	filename = Config->QuestDir;
	filename += QUEST_GLOBAL_DIRECTORY;
	filename += "/items/default";

	iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		tmp = filename;
		auto ext = _extensions.find((*iter)->GetIdentifier());
		tmp += ".";
		tmp += ext->second;
		f = fopen(tmp.c_str(), "r");
		if (f) {
			fclose(f);
			filename = tmp;
			return (*iter);
		}

		++iter;
	}

	return nullptr;
}

QuestInterface *QuestParserCollection::GetQIByEncounterQuest(std::string encounter_name, std::string &filename) {
	// first look for /quests/zone/encounters/encounter_name.ext (precedence)
	filename = Config->QuestDir;
	filename += zone->GetShortName();
	filename += "/encounters/";
	filename += encounter_name;
	std::string tmp;
	FILE *f = nullptr;

	auto iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		tmp = filename;
		auto ext = _extensions.find((*iter)->GetIdentifier());
		tmp += ".";
		tmp += ext->second;
		f = fopen(tmp.c_str(), "r");
		if (f) {
			fclose(f);
			filename = tmp;
			return (*iter);
		}

		++iter;
	}

	// second look for /quests/global/encounters/encounter_name.ext (precedence)
	filename = Config->QuestDir;
	filename += QUEST_GLOBAL_DIRECTORY;
	filename += "/encounters/";
	filename += encounter_name;

	iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		tmp = filename;
		auto ext = _extensions.find((*iter)->GetIdentifier());
		tmp += ".";
		tmp += ext->second;
		f = fopen(tmp.c_str(), "r");
		if (f) {
			fclose(f);
			filename = tmp;
			return (*iter);
		}

		++iter;
	}

	return nullptr;
}

void QuestParserCollection::GetErrors(std::list<std::string> &quest_errors) {
	quest_errors.clear();
	auto iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		(*iter)->GetErrors(quest_errors);
		++iter;
	}
}

int QuestParserCollection::DispatchEventNPC(QuestEventID evt, NPC *npc, Mob *init, std::string data, uint32 extra_data,
                                            std::vector<EQ::Any> *extra_pointers) {
	int ret = 0;
	auto iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		int i = (*iter)->DispatchEventNPC(evt, npc, init, data, extra_data, extra_pointers);
		if (i != 0) {
			ret = i;
		}
		++iter;
	}
	return ret;
}

int QuestParserCollection::DispatchEventPlayer(QuestEventID evt, Client *client, std::string data, uint32 extra_data,
                                               std::vector<EQ::Any> *extra_pointers) {
	int ret = 0;
	auto iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		int i = (*iter)->DispatchEventPlayer(evt, client, data, extra_data, extra_pointers);
		if (i != 0) {
			ret = i;
		}
		++iter;
	}
	return ret;
}

int QuestParserCollection::DispatchEventItem(QuestEventID evt, Client *client, EQ::ItemInstance *item, Mob *mob, std::string data,
                                             uint32 extra_data, std::vector<EQ::Any> *extra_pointers) {
	int ret = 0;
	auto iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		int i = (*iter)->DispatchEventItem(evt, client, item, mob, data, extra_data, extra_pointers);
		if (i != 0) {
			ret = i;
		}
		++iter;
	}
	return ret;
}

int QuestParserCollection::DispatchEventSpell(QuestEventID evt, NPC *npc, Client *client, uint32 spell_id, uint32 extra_data,
                                              std::vector<EQ::Any> *extra_pointers) {
	int ret = 0;
	auto iter = _load_precedence.begin();
	while (iter != _load_precedence.end()) {
		int i = (*iter)->DispatchEventSpell(evt, npc, client, spell_id, extra_data, extra_pointers);
		if (i != 0) {
			ret = i;
		}
		++iter;
	}
	return ret;
}
