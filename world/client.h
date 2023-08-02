#ifndef CLIENT_H
#define CLIENT_H

#include <string>

// #include "../common/eq_stream.h"
#include "../common/linked_list.h"
#include "../common/timer.h"
// #include "zoneserver.h"

#include "../common/eq_packet_structs.h"
#include "cliententry.h"

#define CLIENT_TIMEOUT 30000

class EQApplicationPacket;
class EQStreamInterface;

class Client {
   public:
	Client(EQStreamInterface *ieqs);
	~Client();

	bool Process();
	void SendCharInfo();
	void EnterWorld(bool TryBootup = true);
	void ZoneUnavail();
	void QueuePacket(const EQApplicationPacket *app, bool ack_req = true);
	void Clearance(int8 response);
	void SendGuildList();
	void SendEnterWorld(std::string name);
	void SendExpansionInfo();
	void SendLogServer();
	void SendApproveWorld();

	inline uint32 GetIP() { return ip; }
	inline uint16 GetPort() { return port; }
	inline uint32 GetZoneID() { return zoneID; }
	inline uint32 WaitingForBootup() { return pwaitingforbootup; }
	inline const char *GetAccountName() {
		if (cle) {
			return cle->AccountName();
		}
		return "NOCLE";
	}
	inline int16 GetAdmin() {
		if (cle) {
			return cle->Admin();
		}
		return 0;
	}
	inline uint32 GetAccountID() {
		if (cle) {
			return cle->AccountID();
		}
		return 0;
	}
	inline uint32 GetWID() {
		if (cle) {
			return cle->GetID();
		}
		return 0;
	}
	inline uint32 GetLSID() {
		if (cle) {
			return cle->LSID();
		}
		return 0;
	}
	inline const char *GetLSKey() {
		if (cle) {
			return cle->GetLSKey();
		}
		return "NOKEY";
	}
	inline uint32 GetCharID() { return charid; }
	inline const char *GetCharName() { return char_name; }
	inline ClientListEntry *GetCLE() { return cle; }
	inline void SetCLE(ClientListEntry *iCLE) { cle = iCLE; }
	inline uint16 GetExpansion() { return expansion; }
	inline uint32 GetClientVersionBit() { return m_ClientVersionBit; }
	inline bool GetSessionLimit();

   private:
	uint32 ip;
	uint16 port;
	uint32 charid;
	char char_name[64];
	uint32 zoneID;
	bool pZoning;
	Timer autobootup_timeout;
	uint32 pwaitingforbootup;

	EQ::versions::ClientVersion m_ClientVersion;
	uint32 m_ClientVersionBit;
	bool OPCharCreate(char *name, CharCreate_Struct *cc);

	void SetClassStartingSkills(PlayerProfile_Struct *pp);
	void SetRaceStartingSkills(PlayerProfile_Struct *pp);
	void SetRacialLanguages(PlayerProfile_Struct *pp);
	void SetClassLanguages(PlayerProfile_Struct *pp);

	ClientListEntry *cle;
	Timer CLE_keepalive_timer;
	Timer connect;
	bool firstlogin;
	bool seencharsel;
	bool realfirstlogin;

	bool HandlePacket(const EQApplicationPacket *app);
	bool HandleNameApprovalPacket(const EQApplicationPacket *app);
	bool HandleSendLoginInfoPacket(const EQApplicationPacket *app);
	bool HandleGenerateRandomNamePacket(const EQApplicationPacket *app);
	bool HandleCharacterCreatePacket(const EQApplicationPacket *app);
	bool HandleEnterWorldPacket(const EQApplicationPacket *app);
	bool HandleDeleteCharacterPacket(const EQApplicationPacket *app);
	bool HandleChecksumPacket(const EQApplicationPacket *app);
	bool ChecksumVerificationCRCEQGame(uint64 checksum);
	bool ChecksumVerificationCRCSkillCaps(uint64 checksum);
	bool ChecksumVerificationCRCBaseData(uint64 checksum);

	EQStreamInterface *const eqs;

	uint16 expansion;
	uint8 charcount;
	bool mule;
};

bool CheckCharCreateInfo(CharCreate_Struct *cc);

#endif
