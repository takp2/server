#include "db_row.h"

DBRow::DBRow(const DBRow& row)
    : m_Result(row.m_Result), m_MySQLRow(row.m_MySQLRow) {}

DBRow::DBRow() : m_Result(nullptr), m_MySQLRow(nullptr) {}

DBRow::DBRow(DBRow&& moveItem) {
	m_Result = moveItem.m_Result;
	m_MySQLRow = moveItem.m_MySQLRow;

	moveItem.m_Result = nullptr;
	moveItem.m_MySQLRow = nullptr;
}

DBRow& DBRow::operator=(DBRow& moveItem) {
	m_Result = moveItem.m_Result;
	m_MySQLRow = moveItem.m_MySQLRow;

	moveItem.m_Result = nullptr;
	moveItem.m_MySQLRow = nullptr;

	return *this;
}

DBRow DBRow::operator*() { return *this; }

DBRow::DBRow(MYSQL_RES* result) : m_Result(result) {
	if (result != nullptr)
		m_MySQLRow = mysql_fetch_row(result);
	else
		m_MySQLRow = nullptr;
}

DBRow& DBRow::operator++() {
	m_MySQLRow = mysql_fetch_row(m_Result);
	return *this;
}

DBRow DBRow::operator++(int) {
	DBRow tmp(*this);
	operator++();
	return tmp;
}

bool DBRow::operator==(const DBRow& rhs) {
	return m_MySQLRow == rhs.m_MySQLRow;
}

bool DBRow::operator!=(const DBRow& rhs) {
	return m_MySQLRow != rhs.m_MySQLRow;
}

char* DBRow::operator[](int index) { return m_MySQLRow[index]; }
