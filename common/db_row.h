#ifndef DB_ROW_H
#define DB_ROW_H

#ifdef _WINDOWS
#include <winsock2.h>
#include <windows.h>
#endif

#include <mysql.h>

#include <iterator>

#include "types.h"

class DBRow
    : public std::iterator<std::input_iterator_tag, MYSQL_ROW> {
   private:
	MYSQL_RES* m_Result;
	MYSQL_ROW m_MySQLRow;

   public:
	DBRow();
	DBRow(MYSQL_RES* result);
	DBRow(const DBRow& row);
	DBRow(DBRow&& moveItem);
	DBRow& operator=(DBRow& moveItem);
	DBRow& operator++();
	DBRow operator++(int);
	bool operator==(const DBRow& rhs);
	bool operator!=(const DBRow& rhs);
	DBRow operator*();
	char* operator[](int index);
};

#endif
