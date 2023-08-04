#ifndef DB_H
#define DB_H

#include "db_result.h"
#include "eqemu_logsys.h"
#include <mutex>
#include <atomic>

class DB {
   public:
	static bool Open(const char* host, const char* user, const char* password,
	                 const char* database, uint32 port, bool is_compressed = false, bool is_ssl = false);
	static DBResult Query(std::string query);
	static DBResult Query(const char* query, uint32 querylen);
	template <typename... Args>
	static DBResult Request(const std::string& statement, Args&&... args);

   private:
	static bool open();
	static std::mutex mu;
	static std::atomic<bool> is_connected;
	static std::atomic<bool> is_initialized;
	static MYSQL* conn;
	static char* host;
	static char* user;
	static char* password;
	static char* database;
	static bool is_compressed;
	static uint32 port;
	static bool is_ssl;
};
#endif