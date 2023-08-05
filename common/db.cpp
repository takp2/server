#include "db.h"
#include "db_result.h"
#include <mysqld_error.h>
#include <vector>

std::mutex DB::mu;
std::atomic<bool> DB::is_connected = ATOMIC_VAR_INIT(false);
std::atomic<bool> DB::is_initialized = ATOMIC_VAR_INIT(false);
MYSQL* DB::conn = nullptr;
char* DB::host = nullptr;
char* DB::user = nullptr;
char* DB::password = nullptr;
char* DB::database = nullptr;
bool DB::is_compressed = false;
uint32 DB::port = 0;
bool DB::is_ssl = false;

bool DB::Open(const char* host, const char* user, const char* password,
              const char* database, uint32 port, bool is_compressed, bool is_ssl) {
	if (is_initialized) {
		LogError("Failed to Db:Open: DB is already initialized.");
		return false;
	}
	DB::host = const_cast<char*>(host);
	DB::user = const_cast<char*>(user);
	DB::password = const_cast<char*>(password);
	DB::database = const_cast<char*>(database);
	DB::port = port;
	DB::is_compressed = is_compressed;
	DB::is_ssl = is_ssl;
	DB::is_initialized = true;
	return open();
}
// Open creates a connection to the database. It should only be called once during a
bool DB::open() {
	std::lock_guard<std::mutex> lock(mu);

	// Lock is implied since open is private, public functions will guard

	if (is_connected) {
		return true;
	}
	if (conn != nullptr) {
		mysql_close(conn);
	}
	conn = mysql_init(nullptr);  // Initialize structure again
	if (!host) {
		return false;
	}

	uint32 flags = CLIENT_FOUND_ROWS;
	if (is_compressed) flags |= CLIENT_COMPRESS;
	if (is_ssl) flags |= CLIENT_SSL;
	if (mysql_real_connect(conn, host, user, password, database, port, 0, flags)) {
		is_connected = true;
		return true;
	}

	// auto err_number = mysql_errno(conn);

	auto err_message = mysql_error(conn);
	LogError("Failed to connect to database: %s", err_message);
	return false;
}
// Query is an unsafe call to do a simple query without binding parameters. All queries should stop using this
DBResult DB::Query(std::string query) {
	return Query(query.c_str(), query.length());
}

// Query is an unsafe call to do a simple query without binding parameters. All queries should stop using this
DBResult DB::Query(const char* query, uint32 querylen) {
	if (!is_connected) {
		if (!open()) {
			LogError("QueryDatabase() called on an unconnected DB object.");
			return DBResult(nullptr, 0, 0, 0, 0, 0, nullptr);
		}
	}

	auto result_status = mysql_real_query(conn, query, querylen);

	if (result_status != 0) {
		auto error_number = mysql_errno(conn);
		auto error_message = mysql_error(conn);
		if (error_number != CR_SERVER_GONE_ERROR &&
		    error_number != CR_SERVER_LOST) {
			is_connected = false;
			LogError("Database failed: %s", error_message);
			return DBResult(nullptr, 0, 0, 0, 0, 0, nullptr);
		}

		LogError("Database failed, retrying: %s,", error_message);
		return DB::Query(query, querylen);
	}

	auto result = mysql_store_result(conn);
	if (result == nullptr) {
		if (mysql_field_count(conn) == 0) {
			// query does not return data
			// (it was not a SELECT)
			uint32 rowCount = (uint32)mysql_affected_rows(conn);
			uint32 insertId = (uint32)mysql_insert_id(conn);
			return DBResult(nullptr, 0, 0, 0, rowCount, insertId,
			                nullptr);
		} else {
			// error
			LogError("Database failed: %s", mysql_error(conn));
			return DBResult(nullptr, 0, 0, 0, 0, 0, nullptr);
		}
	}
	return DBResult(result, (uint32)mysql_affected_rows(conn),
	                (uint32)mysql_num_rows(result),
	                (uint32)mysql_field_count(conn),
	                (uint32)mysql_insert_id(conn));
}

// Prepare a statement for later execution via Execute() and close it with Finish().
MYSQL_STMT* DB::Prepare(const std::string& statement) {
	if (!is_connected) {
		if (!open()) {
			LogError("Prepare called on an unconnected DB object.");
			return nullptr;
		}
	}

	MYSQL_STMT* stmt = mysql_stmt_init(conn);
	if (!stmt) {
		LogError("Failed to initialize statement: %s", mysql_error(conn));
		return nullptr;
	}

	const char* stmtStr = statement.c_str();
	if (mysql_stmt_prepare(stmt, stmtStr, statement.size()) != 0) {
		LogError("Failed to prepare statement: %s", mysql_stmt_error(stmt));
		return nullptr;
	}
	return stmt;
}

// Request is a shortcut to doing a Prepare(), Execute() and Finish() in one call. It is useful when you only are going to execute a statement once.
template <typename... Args>
DBResult DB::Request(const std::string& statement, Args&&... args) {
	if (!is_connected) {
		if (!open()) {
			LogError("RequestDatabase() called on an unconnected DB object.");
			return DBResult(nullptr, 0, 0, 0, 0, 0, nullptr);
		}
	}

	MYSQL_STMT* stmt = Prepare(statement);
	if (!stmt) {
		return DBResult(nullptr, 0, 0, 0, 0, 0, nullptr);
	}

	auto result = Execute(stmt, std::forward<Args>(args)...);
	mysql_stmt_close(stmt);
	return result;
}

// Execute a prepared statement. Note that stmt will NOT be closed by this function, call DB::Finish(stmt) to do that.
template <typename... Args>
DBResult DB::Execute(MYSQL_STMT* stmt, Args&&... args) {
	int index = 0;
	((mysql_stmt_bind_param(stmt, &index, std::forward<Args>(args)) == 0 ? index++ : void(), false), ...);

	if (mysql_stmt_execute(stmt) != 0) {
		LogError("Failed to execute statement: %s", mysql_stmt_error(stmt));
		mysql_stmt_close(stmt);
		return DBResult(nullptr, 0, 0, 0, 0, 0, nullptr);
	}

	auto result = mysql_store_result(conn);

	if (result == nullptr) {
		if (mysql_field_count(conn) == 0) {
			// query does not return data
			// (it was not a SELECT)
			uint32 rowCount = (uint32)mysql_affected_rows(conn);
			uint32 insertId = (uint32)mysql_insert_id(conn);
			return DBResult(nullptr, 0, 0, 0, rowCount, insertId,
			                nullptr);
		} else {
			// error
			LogError("Database failed: %s", mysql_error(conn));
			return DBResult(nullptr, 0, 0, 0, 0, 0, nullptr);
		}
	}
	return DBResult(result, (uint32)mysql_affected_rows(conn),
	                (uint32)mysql_num_rows(result),
	                (uint32)mysql_field_count(conn),
	                (uint32)mysql_insert_id(conn));
}

// Finish a prepared statement. This will close the statement and free any resources used by it.
void DB::Finish(MYSQL_STMT* stmt) {
	mysql_stmt_close(stmt);
}

void DB::TransactionStart() {
	if (!is_connected) {
		if (!open()) {
			LogError("TransactionStart() called on an unconnected DB object.");
			return;
		}
	}

	Query("START TRANSACTION");
}

void DB::TransactionCommit() {
	if (!is_connected) {
		if (!open()) {
			LogError("TransactionCommit() called on an unconnected DB object.");
			return;
		}
	}

	Query("COMMIT");
}

void DB::TransactionRollback() {
	if (!is_connected) {
		if (!open()) {
			LogError("TransactionRollback() called on an unconnected DB object.");
			return;
		}
	}

	Query("ROLLBACK");
}

void DB::TransactionEnd() {
	if (!is_connected) {
		if (!open()) {
			LogError("TransactionEnd() called on an unconnected DB object.");
			return;
		}
	}

	Query("END");
}