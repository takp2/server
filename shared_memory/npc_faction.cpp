#include "npc_faction.h"

#include "../common/eqemu_exception.h"
#include "../common/faction.h"
#include "../common/global_define.h"
#include "../common/ipc_mutex.h"
#include "../common/memory_mapped_file.h"
#include "../common/shareddb.h"

void LoadFactions(SharedDatabase *database, const std::string &prefix) {
	EQ::IPCMutex mutex("faction");
	mutex.Lock();

	uint32 lists = 0;
	uint32 max_list = 0;
	database->GetFactionListInfo(lists, max_list);

	uint32 size = static_cast<uint32>(
	    EQ::FixedMemoryHashSet<NPCFactionList>::estimated_size(lists,
	                                                           max_list));

	auto Config = Config::get();
	std::string file_name =
	    Config->SharedMemDir + prefix + std::string("faction");
	EQ::MemoryMappedFile mmf(file_name, size);
	mmf.ZeroFile();

	void *ptr = mmf.Get();
	database->LoadNPCFactionLists(ptr, size, lists, max_list);
	mutex.Unlock();
}
