#ifndef COMMON_EMU_CONSTANTS_H
#define COMMON_EMU_CONSTANTS_H

#include <string.h>

#include "bodytypes.h"
#include "emu_versions.h"
#include "eq_limits.h"

namespace EQ {
using Mac::IINVALID;
using Mac::INULL;

namespace inventory {}  // namespace inventory

namespace invtype {
using namespace Mac::invtype::enum_;

using Mac::invtype::BANK_SIZE;
using Mac::invtype::BAZAAR_SIZE;
using Mac::invtype::CORPSE_SIZE;
using Mac::invtype::INSPECT_SIZE;
using Mac::invtype::LIMBO_SIZE;
using Mac::invtype::MERCHANT_SIZE;
using Mac::invtype::POSSESSIONS_SIZE;
using Mac::invtype::TRADE_SIZE;
using Mac::invtype::WORLD_SIZE;

using Mac::invtype::TRADE_NPC_SIZE;

using Mac::invtype::TYPE_BEGIN;
using Mac::invtype::TYPE_COUNT;
using Mac::invtype::TYPE_END;
using Mac::invtype::TYPE_INVALID;

int16 GetInvTypeSize(int16 inv_type);
using Mac::invtype::GetInvTypeName;

}  // namespace invtype

namespace invslot {
using namespace Mac::invslot::enum_;

using Mac::invslot::SLOT_BEGIN;
using Mac::invslot::SLOT_INVALID;

using Mac::invslot::POSSESSIONS_BEGIN;
using Mac::invslot::POSSESSIONS_COUNT;
using Mac::invslot::POSSESSIONS_END;

using Mac::invslot::EQUIPMENT_BEGIN;
using Mac::invslot::EQUIPMENT_COUNT;
using Mac::invslot::EQUIPMENT_END;

using Mac::invslot::GENERAL_BEGIN;
using Mac::invslot::GENERAL_COUNT;
using Mac::invslot::GENERAL_END;

using Mac::invslot::BONUS_BEGIN;
using Mac::invslot::BONUS_SKILL_END;
using Mac::invslot::BONUS_STAT_END;

using Mac::invslot::BANK_BEGIN;
using Mac::invslot::BANK_END;

using Mac::invslot::TRADE_BEGIN;
using Mac::invslot::TRADE_END;

using Mac::invslot::TRADE_NPC_END;

using Mac::invslot::WORLD_BEGIN;
using Mac::invslot::WORLD_END;

const int16 CORPSE_BEGIN = invslot::slotGeneral1;
const int16 CORPSE_END = CORPSE_BEGIN + invslot::slotGeneral8;

const int16 CURSOR_QUEUE_BEGIN = 8000;
const int16 CURSOR_QUEUE_END = 8999;

using Mac::invslot::CORPSE_BITMASK;
using Mac::invslot::POSSESSIONS_BITMASK;

using Mac::invslot::GetInvPossessionsSlotName;
using Mac::invslot::GetInvSlotName;

}  // namespace invslot

namespace invbag {
using Mac::invbag::SLOT_BEGIN;
using Mac::invbag::SLOT_COUNT;
using Mac::invbag::SLOT_END;
using Mac::invbag::SLOT_INVALID;

using Mac::invbag::GENERAL_BAGS_BEGIN;
const int16 GENERAL_BAGS_COUNT = invslot::GENERAL_COUNT * SLOT_COUNT;
const int16 GENERAL_BAGS_END = (GENERAL_BAGS_BEGIN + GENERAL_BAGS_COUNT) - 1;

const int16 GENERAL_BAGS_8_COUNT = 8 * SLOT_COUNT;
const int16 GENERAL_BAGS_8_END =
    (GENERAL_BAGS_BEGIN + GENERAL_BAGS_8_COUNT) - 1;

const int16 CURSOR_BAG_BEGIN = 330;
const int16 CURSOR_BAG_COUNT = SLOT_COUNT;
const int16 CURSOR_BAG_END = (CURSOR_BAG_BEGIN + CURSOR_BAG_COUNT) - 1;

using Mac::invbag::BANK_BAGS_BEGIN;
const int16 BANK_BAGS_COUNT = (invtype::BANK_SIZE * SLOT_COUNT);
const int16 BANK_BAGS_END = (BANK_BAGS_BEGIN + BANK_BAGS_COUNT) - 1;

const int16 BANK_BAGS_8_COUNT = 8 * SLOT_COUNT;
const int16 BANK_BAGS_8_END = (BANK_BAGS_BEGIN + BANK_BAGS_8_COUNT) - 1;

using Mac::invbag::TRADE_BAGS_BEGIN;
const int16 TRADE_BAGS_COUNT = invtype::TRADE_SIZE * SLOT_COUNT;
const int16 TRADE_BAGS_END = (TRADE_BAGS_BEGIN + TRADE_BAGS_COUNT) - 1;

using Mac::invbag::GetInvBagIndexName;

}  // namespace invbag

namespace constants {
// database
static const EQ::versions::ClientVersion CharacterCreationClient =
    EQ::versions::ClientVersion::Mac;  // adjust according to starting item
                                       // placement and target client
using Mac::constants::CHARACTER_CREATION_LIMIT;

const size_t SAY_LINK_OPENER_SIZE = 1;
using Mac::constants::SAY_LINK_BODY_SIZE;
const size_t SAY_LINK_TEXT_SIZE = 200;
const size_t SAY_LINK_CLOSER_SIZE = 1;
const size_t SAY_LINK_MAXIMUM_SIZE =
    (SAY_LINK_OPENER_SIZE + SAY_LINK_BODY_SIZE + SAY_LINK_TEXT_SIZE +
     SAY_LINK_CLOSER_SIZE);

enum GravityBehavior : int8 { Ground, Flying, Levitating, Water };

enum SpawnAnimations : uint8 { Standing, Sitting, Crouching, Laying, Looting };

extern const std::map<int, std::string>& GetLanguageMap();
std::string GetLanguageName(int language_id);

extern const std::map<int8, std::string>& GetFlyModeMap();
std::string GetFlyModeName(int8 flymode_id);

extern const std::map<bodyType, std::string>& GetBodyTypeMap();
std::string GetBodyTypeName(bodyType bodytype_id);

extern const std::map<uint8, std::string>& GetAccountStatusMap();
std::string GetAccountStatusName(uint8 account_status);

extern const std::map<uint8, std::string>& GetConsiderLevelMap();
std::string GetConsiderLevelName(uint8 consider_level);

extern const std::map<uint8, std::string>& GetStuckBehaviorMap();
std::string GetStuckBehaviorName(uint8 behavior_id);

extern const std::map<uint8, std::string>& GetSpawnAnimationMap();
std::string GetSpawnAnimationName(uint8 animation_id);

}  // namespace constants

namespace spells {
enum class CastingSlot : uint32 {
	Gem1 = 0,
	Gem2 = 1,
	Gem3 = 2,
	Gem4 = 3,
	Gem5 = 4,
	Gem6 = 5,
	Gem7 = 6,
	Gem8 = 7,
	MaxGems = 8,
	Ability = 9,
	Item = 10,
	AltAbility = 0xFF
};

using Mac::spells::SPELL_GEM_COUNT;
using Mac::spells::SPELL_ID_MAX;
using Mac::spells::SPELLBOOK_SIZE;

}  // namespace spells

namespace profile {

using Mac::profile::SKILL_ARRAY_SIZE;

}  // namespace profile

namespace behavior {
using Mac::behavior::CoinHasWeight;

}  // namespace behavior

namespace bug {
enum CategoryID : uint32 {
	catOther = 0,
	catVideo,
	catAudio,
	catPathing,
	catQuest,
	catTradeskills,
	catSpellStacking,
	catDoorsPortals,
	catItems,
	catNPC,
	catDialogs,
};

enum OptionalInfoFlag : uint32 {
	infoNoOptionalInfo = 0x0,
	infoCanDuplicate = 0x1,
	infoCrashBug = 0x2,
	infoTargetInfo = 0x4,
	infoCharacterFlags = 0x8,
	infoUnknownValue = 0xFFFFFFF0
};

const char* CategoryIDToCategoryName(CategoryID category_id);
CategoryID CategoryNameToCategoryID(const char* category_name);

}  // namespace bug

enum WaypointStatus : int { QuestControlNoGrid = -2, QuestControlGrid = -1 };
}  // namespace EQ

enum ServerLockType : int { List, Lock, Unlock };

enum AccountStatus : uint8 {
	Player = 0,
	Steward = 10,
	ApprenticeGuide = 20,
	Guide = 50,
	QuestTroupe = 80,
	SeniorGuide = 81,
	GMTester = 85,
	EQSupport = 90,
	GMStaff = 95,
	GMAdmin = 100,
	GMLeadAdmin = 150,
	QuestMaster = 160,
	GMAreas = 170,
	GMCoder = 180,
	GMMgmt = 200,
	GMImpossible = 250,
	Max = 255
};

enum ConsiderLevel : uint8 {
	Ally = 1,
	Warmly,
	Kindly,
	Amiably,
	Indifferently,
	Apprehensively,
	Dubiously,
	Threateningly,
	Scowls
};

#endif /*COMMON_EMU_CONSTANTS_H*/