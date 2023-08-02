#ifndef COMMON_EMU_CONSTANTS_H
#define COMMON_EMU_CONSTANTS_H

#include <string.h>

#include "bodytypes.h"
#include "emu_versions.h"
#include "eq_limits.h"

namespace EQ {
using RoF2::IINVALID;
using RoF2::INULL;

namespace inventory {}  // namespace inventory

namespace invtype {
using namespace RoF2::invtype::enum_;

using RoF2::invtype::ALT_STORAGE_SIZE;
using RoF2::invtype::ARCHIVED_SIZE;
using RoF2::invtype::BANK_SIZE;
using RoF2::invtype::BAZAAR_SIZE;
using RoF2::invtype::CORPSE_SIZE;
using RoF2::invtype::DELETED_SIZE;
using RoF2::invtype::GUILD_TRIBUTE_SIZE;
using RoF2::invtype::GUILD_TROPHY_TRIBUTE_SIZE;
using RoF2::invtype::INSPECT_SIZE;
using RoF2::invtype::KRONO_SIZE;
using RoF2::invtype::LIMBO_SIZE;
using RoF2::invtype::MAIL_SIZE;
using RoF2::invtype::MERCHANT_SIZE;
using RoF2::invtype::OTHER_SIZE;
using RoF2::invtype::POSSESSIONS_SIZE;
using RoF2::invtype::REAL_ESTATE_SIZE;
using RoF2::invtype::SHARED_BANK_SIZE;
using RoF2::invtype::TRADE_SIZE;
using RoF2::invtype::TRIBUTE_SIZE;
using RoF2::invtype::TROPHY_TRIBUTE_SIZE;
using RoF2::invtype::VIEW_MOD_BANK_SIZE;
using RoF2::invtype::VIEW_MOD_LIMBO_SIZE;
using RoF2::invtype::VIEW_MOD_PC_SIZE;
using RoF2::invtype::VIEW_MOD_SHARED_BANK_SIZE;
using RoF2::invtype::WORLD_SIZE;

using RoF2::invtype::TRADE_NPC_SIZE;

using RoF2::invtype::TYPE_BEGIN;
using RoF2::invtype::TYPE_COUNT;
using RoF2::invtype::TYPE_END;
using RoF2::invtype::TYPE_INVALID;

int16 GetInvTypeSize(int16 inv_type);
using RoF2::invtype::GetInvTypeName;

}  // namespace invtype

namespace invslot {
using namespace RoF2::invslot::enum_;

using RoF2::invslot::SLOT_BEGIN;
using RoF2::invslot::SLOT_INVALID;

using RoF2::invslot::SLOT_TRADESKILL_EXPERIMENT_COMBINE;

const int16 SLOT_AUGMENT_GENERIC_RETURN = 1001;  // clients don't appear to use this method... (internal inventory return value)

using RoF2::invslot::POSSESSIONS_BEGIN;
using RoF2::invslot::POSSESSIONS_COUNT;
using RoF2::invslot::POSSESSIONS_END;

using RoF2::invslot::EQUIPMENT_BEGIN;
using RoF2::invslot::EQUIPMENT_COUNT;
using RoF2::invslot::EQUIPMENT_END;

using RoF2::invslot::GENERAL_BEGIN;
using RoF2::invslot::GENERAL_COUNT;
using RoF2::invslot::GENERAL_END;

using RoF2::invslot::BONUS_BEGIN;
using RoF2::invslot::BONUS_SKILL_END;
using RoF2::invslot::BONUS_STAT_END;

using RoF2::invslot::BANK_BEGIN;
using RoF2::invslot::BANK_END;

using RoF2::invslot::SHARED_BANK_BEGIN;
using RoF2::invslot::SHARED_BANK_END;

using RoF2::invslot::TRADE_BEGIN;
using RoF2::invslot::TRADE_END;

using RoF2::invslot::TRADE_NPC_END;

using RoF2::invslot::WORLD_BEGIN;
using RoF2::invslot::WORLD_END;

using RoF2::invslot::TRIBUTE_BEGIN;
using RoF2::invslot::TRIBUTE_END;

using RoF2::invslot::GUILD_TRIBUTE_BEGIN;
using RoF2::invslot::GUILD_TRIBUTE_END;

const int16 CORPSE_BEGIN = invslot::slotGeneral1;
const int16 CORPSE_END = CORPSE_BEGIN + invslot::slotCursor;

const int16 CURSOR_QUEUE_BEGIN = 8000;
const int16 CURSOR_QUEUE_END = 8999;

using RoF2::invslot::CORPSE_BITMASK;
using RoF2::invslot::CURSOR_BITMASK;
using RoF2::invslot::EQUIPMENT_BITMASK;
using RoF2::invslot::GENERAL_BITMASK;
using RoF2::invslot::POSSESSIONS_BITMASK;

using RoF2::invslot::GetInvPossessionsSlotName;
using RoF2::invslot::GetInvSlotName;

}  // namespace invslot

namespace invbag {
using RoF2::invbag::SLOT_BEGIN;
using RoF2::invbag::SLOT_COUNT;
using RoF2::invbag::SLOT_END;
using RoF2::invbag::SLOT_INVALID;

using RoF2::invbag::GENERAL_BAGS_BEGIN;
const int16 GENERAL_BAGS_COUNT = invslot::GENERAL_COUNT * SLOT_COUNT;
const int16 GENERAL_BAGS_END = (GENERAL_BAGS_BEGIN + GENERAL_BAGS_COUNT) - 1;

const int16 GENERAL_BAGS_8_COUNT = 8 * SLOT_COUNT;
const int16 GENERAL_BAGS_8_END =
    (GENERAL_BAGS_BEGIN + GENERAL_BAGS_8_COUNT) - 1;

const int16 CURSOR_BAG_BEGIN = 330;
const int16 CURSOR_BAG_COUNT = SLOT_COUNT;
const int16 CURSOR_BAG_END = (CURSOR_BAG_BEGIN + CURSOR_BAG_COUNT) - 1;

using RoF2::invbag::BANK_BAGS_BEGIN;
const int16 BANK_BAGS_COUNT = (invtype::BANK_SIZE * SLOT_COUNT);
const int16 BANK_BAGS_END = (BANK_BAGS_BEGIN + BANK_BAGS_COUNT) - 1;

const int16 BANK_BAGS_8_COUNT = 8 * SLOT_COUNT;
const int16 BANK_BAGS_8_END = (BANK_BAGS_BEGIN + BANK_BAGS_8_COUNT) - 1;

using RoF2::invbag::TRADE_BAGS_BEGIN;
const int16 TRADE_BAGS_COUNT = invtype::TRADE_SIZE * SLOT_COUNT;
const int16 TRADE_BAGS_END = (TRADE_BAGS_BEGIN + TRADE_BAGS_COUNT) - 1;

using RoF2::invbag::GetInvBagIndexName;

}  // namespace invbag

namespace invaug {
using RoF2::invaug::SOCKET_BEGIN;
using RoF2::invaug::SOCKET_COUNT;
using RoF2::invaug::SOCKET_END;
using RoF2::invaug::SOCKET_INVALID;

using RoF2::invaug::GetInvAugIndexName;

}  // namespace invaug

namespace constants {
// database
static const EQ::versions::ClientVersion CharacterCreationClient =
    EQ::versions::ClientVersion::RoF2;  // adjust according to starting item
                                        // placement and target client
using RoF2::constants::CHARACTER_CREATION_LIMIT;

const size_t SAY_LINK_OPENER_SIZE = 1;
using RoF2::constants::SAY_LINK_BODY_SIZE;
const size_t SAY_LINK_TEXT_SIZE = 200;
const size_t SAY_LINK_CLOSER_SIZE = 1;
const size_t SAY_LINK_MAXIMUM_SIZE =
    (SAY_LINK_OPENER_SIZE + SAY_LINK_BODY_SIZE + SAY_LINK_TEXT_SIZE +
     SAY_LINK_CLOSER_SIZE);

enum GravityBehavior : int8 { Ground,
	                          Flying,
	                          Levitating,
	                          Water };

enum SpawnAnimations : uint8 { Standing,
	                           Sitting,
	                           Crouching,
	                           Laying,
	                           Looting };

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

using RoF2::spells::SPELL_GEM_COUNT;
using RoF2::spells::SPELL_ID_MAX;
using RoF2::spells::SPELLBOOK_SIZE;

}  // namespace spells

namespace profile {

using RoF2::profile::SKILL_ARRAY_SIZE;

}  // namespace profile

namespace behavior {
using RoF2::behavior::CoinHasWeight;

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

enum WaypointStatus : int { QuestControlNoGrid = -2,
	                        QuestControlGrid = -1 };
}  // namespace EQ

enum ServerLockType : int { List,
	                        Lock,
	                        Unlock };

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