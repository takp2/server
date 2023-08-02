#include "emu_constants.h"
#include "emu_limits.h"

static const EQ::inventory::LookupEntry
    inventory_lookup_entries[EQ::versions::MobVersionCount] = {
        {// ClientUnknown
         ClientUnknown::INULL, ClientUnknown::INULL, ClientUnknown::INULL,
         ClientUnknown::INULL, ClientUnknown::INULL, ClientUnknown::INULL,
         ClientUnknown::INULL, ClientUnknown::INULL, ClientUnknown::INULL,

         ClientUnknown::INULL, ClientUnknown::INULL, ClientUnknown::INULL,

         false, false, false, false},
        {// RoF2
         EQ::invtype::POSSESSIONS_SIZE, RoF2::invtype::BANK_SIZE,
         RoF2::invtype::TRADE_SIZE, RoF2::invtype::WORLD_SIZE,
         RoF2::invtype::LIMBO_SIZE, RoF2::invtype::MERCHANT_SIZE,
         RoF2::invtype::CORPSE_SIZE, RoF2::invtype::BAZAAR_SIZE,
         RoF2::invtype::INSPECT_SIZE,

         RoF2::invslot::POSSESSIONS_BITMASK, RoF2::invslot::CORPSE_BITMASK,
         RoF2::invbag::SLOT_COUNT,

         RoF2::inventory::AllowEmptyBagInBag,
         RoF2::inventory::AllowClickCastFromBag,
         RoF2::inventory::ConcatenateInvTypeLimbo,
         RoF2::inventory::AllowOverLevelEquipment},
        {// NPC
         EQ::invtype::POSSESSIONS_SIZE, EntityLimits::NPC::INULL,
         EntityLimits::NPC::invtype::TRADE_SIZE, EntityLimits::NPC::INULL,
         EntityLimits::NPC::INULL, EntityLimits::NPC::INULL,
         EntityLimits::NPC::INULL, EntityLimits::NPC::INULL,
         EntityLimits::NPC::INULL,

         EntityLimits::NPC::INULL, EntityLimits::NPC::INULL, 0,

         false, false, false, false},
        {// NPCMerchant
         EQ::invtype::POSSESSIONS_SIZE, EntityLimits::NPCMerchant::INULL,
         EntityLimits::NPCMerchant::invtype::TRADE_SIZE,
         EntityLimits::NPCMerchant::INULL, EntityLimits::NPCMerchant::INULL,
         EntityLimits::NPCMerchant::INULL, EntityLimits::NPCMerchant::INULL,
         EntityLimits::NPCMerchant::INULL, EntityLimits::NPCMerchant::INULL,

         EntityLimits::NPCMerchant::INULL, EntityLimits::NPCMerchant::INULL, 0,

         false, false, false, false},
        {// ClientPet
         EQ::invtype::POSSESSIONS_SIZE, EntityLimits::ClientPet::INULL,
         EntityLimits::ClientPet::invtype::TRADE_SIZE,
         EntityLimits::ClientPet::INULL, EntityLimits::ClientPet::INULL,
         EntityLimits::ClientPet::INULL, EntityLimits::ClientPet::INULL,
         EntityLimits::ClientPet::INULL, EntityLimits::ClientPet::INULL,

         EntityLimits::ClientPet::INULL, EntityLimits::ClientPet::INULL, 0,

         false, false, false, false},
        {// NPCPet
         EQ::invtype::POSSESSIONS_SIZE, EntityLimits::NPCPet::INULL,
         EntityLimits::NPCPet::invtype::TRADE_SIZE, EntityLimits::NPCPet::INULL,
         EntityLimits::NPCPet::INULL, EntityLimits::NPCPet::INULL,
         EntityLimits::NPCPet::INULL, EntityLimits::NPCPet::INULL,
         EntityLimits::NPCPet::INULL,

         EntityLimits::NPCPet::INULL, EntityLimits::NPCPet::INULL, 0,

         false, false, false, false},
        {// OfflineRoF2
         RoF2::INULL, RoF2::INULL, RoF2::invtype::TRADE_SIZE, RoF2::INULL,
         RoF2::INULL, RoF2::invtype::MERCHANT_SIZE, RoF2::INULL,
         RoF2::invtype::BAZAAR_SIZE, RoF2::invtype::INSPECT_SIZE,

         RoF2::INULL, RoF2::INULL, EQ::invbag::SLOT_COUNT,

         false, false, false, false},
};

const EQ::inventory::LookupEntry* EQ::inventory::Lookup(
    versions::MobVersion Mob_version) {
	return &inventory_lookup_entries[static_cast<int>(
	    versions::ValidateMobVersion(Mob_version))];
}

static const EQ::behavior::LookupEntry
    behavior_lookup_entries[EQ::versions::MobVersionCount] = {
        {// Unknown
         true},
        {// RoF2
         RoF2::behavior::CoinHasWeight},
        {
            // NPC
            EQ::behavior::CoinHasWeight /*CoinHasWeight*/
        },
        {
            // NPCMerchant
            EQ::behavior::CoinHasWeight /*CoinHasWeight*/
        },
        {
            // ClientPet
            EQ::behavior::CoinHasWeight /*CoinHasWeight*/
        },
        {
            // NPCPet
            EQ::behavior::CoinHasWeight /*CoinHasWeight*/
        },
        {// OfflineRoF2
         RoF2::behavior::CoinHasWeight}};

const EQ::behavior::LookupEntry* EQ::behavior::Lookup(
    versions::MobVersion Mob_version) {
	return &behavior_lookup_entries[static_cast<int>(
	    versions::ValidateMobVersion(Mob_version))];
}
