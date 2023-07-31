#ifndef LOGINSERVERLIST_H_
#define LOGINSERVERLIST_H_

#include "../common/emu_tcp_connection.h"
#include "../common/eq_packet_structs.h"
#include "../common/linked_list.h"
#include "../common/mutex.h"
#include "../common/queue.h"
#include "../common/servertalk.h"
#include "../common/timer.h"

#ifdef _WINDOWS
void AutoInitLoginServer(void *tmp);
#else
void *AutoInitLoginServer(void *tmp);
#endif

class LoginServer;

class LoginServerList {
   public:
	LoginServerList();
	~LoginServerList();

	void Add(const char *, uint16, const char *, const char *, uint8);
	void InitLoginServer();

	bool Process();

	bool SendInfo();
	bool SendNewInfo();
	bool SendStatus();

	bool SendPacket(ServerPacket *pack);
	bool SendAccountUpdate(ServerPacket *pack);
	bool Connected();
	bool AllConnected();
	bool CanUpdate();

   protected:
	LinkedList<LoginServer *> list;
};

#endif /*LOGINSERVERLIST_H_*/
