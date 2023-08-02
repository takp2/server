#ifndef COMMON_EMU_VERSIONS_H
#define COMMON_EMU_VERSIONS_H

#include "types.h"

#include <stdlib.h>

namespace EQ {
namespace versions {
enum ClientVersion {
	Unknown = 0,
	RoF2  // Build: 'May 10 2013 23:30:08'
};

enum ClientVersionBit : uint32 {
	bit_Unknown = 0x00000000,
	bit_RoF2 = 0x00000040,
	bit_maskRoF2AndLater = 0xFFFFFFC0,
	bit_AllClients = 0xFFFFFFFF
};

const ClientVersion LastClientVersion = ClientVersion::RoF2;
const size_t ClientVersionCount = (static_cast<size_t>(LastClientVersion) + 1);

bool IsValidClientVersion(ClientVersion client_version);
ClientVersion ValidateClientVersion(ClientVersion client_version);
const char* ClientVersionName(ClientVersion client_version);
uint32 ConvertClientVersionToClientVersionBit(ClientVersion client_version);
ClientVersion ConvertClientVersionBitToClientVersion(uint32 client_version_bit);

enum class MobVersion {
	Unknown = 0,
	RoF2,
	NPC,
	NPCMerchant,
	ClientPet,
	NPCPet,
	OfflineRoF2
};

const MobVersion LastMobVersion = MobVersion::OfflineRoF2;
const MobVersion LastPCMobVersion = MobVersion::RoF2;
const MobVersion LastNonPCMobVersion = MobVersion::NPCPet;
const MobVersion LastOfflinePCMobVersion = MobVersion::OfflineRoF2;
const size_t MobVersionCount = (static_cast<size_t>(LastMobVersion) + 1);

bool IsValidMobVersion(MobVersion Mob_version);
bool IsValidPCMobVersion(MobVersion Mob_version);
bool IsValidNonPCMobVersion(MobVersion Mob_version);
bool IsValidOfflinePCMobVersion(MobVersion Mob_version);

MobVersion ValidateMobVersion(MobVersion Mob_version);
MobVersion ValidatePCMobVersion(MobVersion Mob_version);
MobVersion ValidateNonPCMobVersion(MobVersion Mob_version);
MobVersion ValidateOfflinePCMobVersion(MobVersion Mob_version);

const char* MobVersionName(MobVersion Mob_version);
ClientVersion ConvertMobVersionToClientVersion(MobVersion Mob_version);
MobVersion ConvertClientVersionToMobVersion(ClientVersion client_version);
MobVersion ConvertPCMobVersionToOfflinePCMobVersion(MobVersion Mob_version);
MobVersion ConvertOfflinePCMobVersionToPCMobVersion(MobVersion Mob_version);
ClientVersion ConvertOfflinePCMobVersionToClientVersion(MobVersion Mob_version);
MobVersion ConvertClientVersionToOfflinePCMobVersion(ClientVersion client_version);

}  // namespace versions
}  // namespace EQ

#endif /* COMMON_EMU_VERSIONS_H */