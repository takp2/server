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

namespace expansions {
enum class Expansion : uint32 {
	EverQuest = 0,
	RoK,
	SoV,
	SoL,
	PoP,
	LoY,
	LDoN,
	GoD,
	OoW,
	DoN,
	DoD,
	PoR,
	TSS,
	TBS,
	SoF,
	SoD,
	UF,
	HoT,
	VoA,
	RoF,
	CotF
};

enum ExpansionBitmask : uint32 {
	bitEverQuest = 0x00000000,
	bitRoK = 0x00000001,
	bitSoV = 0x00000002,
	bitSoL = 0x00000004,
	bitPoP = 0x00000008,
	bitLoY = 0x00000010,
	bitLDoN = 0x00000020,
	bitGoD = 0x00000040,
	bitOoW = 0x00000080,
	bitDoN = 0x00000100,
	bitDoD = 0x00000200,
	bitPoR = 0x00000400,
	bitTSS = 0x00000800,
	bitTBS = 0x00001000,
	bitSoF = 0x00002000,
	bitSoD = 0x00004000,
	bitUF = 0x00008000,
	bitHoT = 0x00010000,
	bitVoA = 0x00020000,
	bitRoF = 0x00040000,
	bitCotF = 0x00080000,
	maskEverQuest = 0x00000000,
	maskRoK = 0x00000001,
	maskSoV = 0x00000003,
	maskSoL = 0x00000007,
	maskPoP = 0x0000000F,
	maskLoY = 0x0000001F,
	maskLDoN = 0x0000003F,
	maskGoD = 0x0000007F,
	maskOoW = 0x000000FF,
	maskDoN = 0x000001FF,
	maskDoD = 0x000003FF,
	maskPoR = 0x000007FF,
	maskTSS = 0x00000FFF,
	maskTBS = 0x00001FFF,
	maskSoF = 0x00003FFF,
	maskSoD = 0x00007FFF,
	maskUF = 0x0000FFFF,
	maskHoT = 0x0001FFFF,
	maskVoA = 0x0003FFFF,
	maskRoF = 0x0007FFFF,
	maskCotF = 0x000FFFFF
};

const char* ExpansionName(Expansion expansion);
const char* ExpansionName(uint32 expansion_bit);
uint32 ConvertExpansionToExpansionBit(Expansion expansion);
Expansion ConvertExpansionBitToExpansion(uint32 expansion_bit);
uint32 ConvertExpansionToExpansionsMask(Expansion expansion);
Expansion ConvertClientVersionToExpansion(versions::ClientVersion client_version);
uint32 ConvertClientVersionToExpansionBit(versions::ClientVersion client_version);
uint32 ConvertClientVersionToExpansionsMask(versions::ClientVersion client_version);

}  // namespace expansions

}  // namespace EQ

#endif /* COMMON_EMU_VERSIONS_H */