#ifndef WORLDSERVER_H
#define WORLDSERVER_H

#include "../common/eq_packet_structs.h"
#include "../common/worldconn.h"

class WorldServer : public WorldConnection {
   public:
	WorldServer();
	virtual ~WorldServer();
	virtual void Process();

   private:
	virtual void OnConnected();
};
#endif
