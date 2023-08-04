#ifndef DB_RESULT_H
#define DB_RESULT_H

#ifdef _WINDOWS
#include <winsock2.h>
#include <windows.h>
#include <map>
#include <string>
#include <stack>
#endif

#include <mysql.h>
#include "types.h"
#include "db_row.h"
#include <vector>

#ifdef __FreeBSD__
#include <string>
#include <sstream>
#include <iostream>
#endif

class DBResult {
   private:
	MYSQL_RES* m_Result;
	MYSQL_FIELD* m_Fields;
	char* m_ErrorBuffer;
	unsigned long* m_ColumnLengths;
	DBRow m_CurrentRow;
	DBRow m_OneBeyondRow;

	bool m_Success;
	uint32 m_RowsAffected;
	uint32 m_RowCount;
	uint32 m_ColumnCount;
	uint32 m_LastInsertedID;
	uint32 m_ErrorNumber;

   public:
	DBResult(MYSQL_RES* result, uint32 rowsAffected = 0,
	         uint32 rowCount = 0, uint32 columnCount = 0,
	         uint32 lastInsertedID = 0, uint32 errorNumber = 0,
	         char* errorBuffer = nullptr);
	DBResult();
	DBResult(DBResult&& moveItem);
	~DBResult();

	DBResult& operator=(DBResult&& other);

	bool Success() const { return m_Success; }
	std::string ErrorMessage() const {
		return m_ErrorBuffer ? std::string(m_ErrorBuffer) : std::string("");
	}
	uint32 ErrorNumber() const { return m_ErrorNumber; }
	uint32 RowsAffected() const { return m_RowsAffected; }
	uint32 RowCount() const { return m_RowCount; }
	uint32 ColumnCount() const { return m_ColumnCount; }
	uint32 LastInsertedID() const { return m_LastInsertedID; }
	// default to 0 index since we mostly use it that way anyways.
	uint32 LengthOfColumn(int columnIndex = 0);
	const std::string FieldName(int columnIndex);

	DBRow& begin() { return m_CurrentRow; }
	DBRow& end() { return m_OneBeyondRow; }

   private:
	void FreeInternals();
	void ZeroOut();
};

#endif
