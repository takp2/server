/**
 * DO NOT MODIFY THIS FILE
 *
 * This repository was automatically generated and is NOT to be modified directly.
 * Any repository modifications are meant to be made to the repository extending the base.
 * Any modifications to base repositories are to be made by the generator only
 *
 * @generator ./utils/scripts/generators/repository-generator.pl
 * @docs https://eqemu.gitbook.io/server/in-development/developer-area/repositories
 */

#ifndef EQEMU_BASE_ZONE_POINTS_REPOSITORY_H
#define EQEMU_BASE_ZONE_POINTS_REPOSITORY_H

#include "../../database.h"
#include "../../strings.h"
#include <ctime>


class BaseZonePointsRepository {
public:
	struct ZonePoints {
		int32_t     id;
		std::string zone;
		uint16_t    number;
		float       y;
		float       x;
		float       z;
		float       heading;
		float       target_y;
		float       target_x;
		float       target_z;
		float       target_heading;
		uint32_t    target_zone_id;
		uint32_t    client_version_mask;
	};

	static std::string PrimaryKey()
	{
		return std::string("id");
	}

	static std::vector<std::string> Columns()
	{
		return {
			"id",
			"zone",
			"number",
			"y",
			"x",
			"z",
			"heading",
			"target_y",
			"target_x",
			"target_z",
			"target_heading",
			"target_zone_id",
			"client_version_mask",
		};
	}

	static std::vector<std::string> SelectColumns()
	{
		return {
			"id",
			"zone",
			"number",
			"y",
			"x",
			"z",
			"heading",
			"target_y",
			"target_x",
			"target_z",
			"target_heading",
			"target_zone_id",
			"client_version_mask",
		};
	}

	static std::string ColumnsRaw()
	{
		return std::string(Strings::Implode(", ", Columns()));
	}

	static std::string SelectColumnsRaw()
	{
		return std::string(Strings::Implode(", ", SelectColumns()));
	}

	static std::string TableName()
	{
		return std::string("zone_points");
	}

	static std::string BaseSelect()
	{
		return fmt::format(
			"SELECT {} FROM {}",
			SelectColumnsRaw(),
			TableName()
		);
	}

	static std::string BaseInsert()
	{
		return fmt::format(
			"INSERT INTO {} ({}) ",
			TableName(),
			ColumnsRaw()
		);
	}

	static ZonePoints NewEntity()
	{
		ZonePoints e{};

		e.id                  = 0;
		e.zone                = "";
		e.number              = 1;
		e.y                   = 0;
		e.x                   = 0;
		e.z                   = 0;
		e.heading             = 0;
		e.target_y            = 0;
		e.target_x            = 0;
		e.target_z            = 0;
		e.target_heading      = 0;
		e.target_zone_id      = 0;
		e.client_version_mask = 4294967295;

		return e;
	}

	static ZonePoints GetZonePoints(
		const std::vector<ZonePoints> &zone_pointss,
		int zone_points_id
	)
	{
		for (auto &zone_points : zone_pointss) {
			if (zone_points.id == zone_points_id) {
				return zone_points;
			}
		}

		return NewEntity();
	}

	static ZonePoints FindOne(
		Database& db,
		int zone_points_id
	)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"{} WHERE {} = {} LIMIT 1",
				BaseSelect(),
				PrimaryKey(),
				zone_points_id
			)
		);

		auto row = results.begin();
		if (results.RowCount() == 1) {
			ZonePoints e{};

			e.id                  = static_cast<int32_t>(atoi(row[0]));
			e.zone                = row[1] ? row[1] : "";
			e.number              = static_cast<uint16_t>(strtoul(row[2], nullptr, 10));
			e.y                   = strtof(row[3], nullptr);
			e.x                   = strtof(row[4], nullptr);
			e.z                   = strtof(row[5], nullptr);
			e.heading             = strtof(row[6], nullptr);
			e.target_y            = strtof(row[7], nullptr);
			e.target_x            = strtof(row[8], nullptr);
			e.target_z            = strtof(row[9], nullptr);
			e.target_heading      = strtof(row[10], nullptr);
			e.target_zone_id      = static_cast<uint32_t>(strtoul(row[11], nullptr, 10));
			e.client_version_mask = static_cast<uint32_t>(strtoul(row[12], nullptr, 10));

			return e;
		}

		return NewEntity();
	}

	static int DeleteOne(
		Database& db,
		int zone_points_id
	)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"DELETE FROM {} WHERE {} = {}",
				TableName(),
				PrimaryKey(),
				zone_points_id
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int UpdateOne(
		Database& db,
		const ZonePoints &e
	)
	{
		std::vector<std::string> v;

		auto columns = Columns();

		v.push_back(columns[1] + " = '" + Strings::Escape(e.zone) + "'");
		v.push_back(columns[2] + " = " + std::to_string(e.number));
		v.push_back(columns[3] + " = " + std::to_string(e.y));
		v.push_back(columns[4] + " = " + std::to_string(e.x));
		v.push_back(columns[5] + " = " + std::to_string(e.z));
		v.push_back(columns[6] + " = " + std::to_string(e.heading));
		v.push_back(columns[7] + " = " + std::to_string(e.target_y));
		v.push_back(columns[8] + " = " + std::to_string(e.target_x));
		v.push_back(columns[9] + " = " + std::to_string(e.target_z));
		v.push_back(columns[10] + " = " + std::to_string(e.target_heading));
		v.push_back(columns[11] + " = " + std::to_string(e.target_zone_id));
		v.push_back(columns[12] + " = " + std::to_string(e.client_version_mask));

		auto results = db.QueryDatabase(
			fmt::format(
				"UPDATE {} SET {} WHERE {} = {}",
				TableName(),
				Strings::Implode(", ", v),
				PrimaryKey(),
				e.id
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static ZonePoints InsertOne(
		Database& db,
		ZonePoints e
	)
	{
		std::vector<std::string> v;

		v.push_back(std::to_string(e.id));
		v.push_back("'" + Strings::Escape(e.zone) + "'");
		v.push_back(std::to_string(e.number));
		v.push_back(std::to_string(e.y));
		v.push_back(std::to_string(e.x));
		v.push_back(std::to_string(e.z));
		v.push_back(std::to_string(e.heading));
		v.push_back(std::to_string(e.target_y));
		v.push_back(std::to_string(e.target_x));
		v.push_back(std::to_string(e.target_z));
		v.push_back(std::to_string(e.target_heading));
		v.push_back(std::to_string(e.target_zone_id));
		v.push_back(std::to_string(e.client_version_mask));

		auto results = db.QueryDatabase(
			fmt::format(
				"{} VALUES ({})",
				BaseInsert(),
				Strings::Implode(",", v)
			)
		);

		if (results.Success()) {
			e.id = results.LastInsertedID();
			return e;
		}

		e = NewEntity();

		return e;
	}

	static int InsertMany(
		Database& db,
		const std::vector<ZonePoints> &entries
	)
	{
		std::vector<std::string> insert_chunks;

		for (auto &e: entries) {
			std::vector<std::string> v;

			v.push_back(std::to_string(e.id));
			v.push_back("'" + Strings::Escape(e.zone) + "'");
			v.push_back(std::to_string(e.number));
			v.push_back(std::to_string(e.y));
			v.push_back(std::to_string(e.x));
			v.push_back(std::to_string(e.z));
			v.push_back(std::to_string(e.heading));
			v.push_back(std::to_string(e.target_y));
			v.push_back(std::to_string(e.target_x));
			v.push_back(std::to_string(e.target_z));
			v.push_back(std::to_string(e.target_heading));
			v.push_back(std::to_string(e.target_zone_id));
			v.push_back(std::to_string(e.client_version_mask));

			insert_chunks.push_back("(" + Strings::Implode(",", v) + ")");
		}

		std::vector<std::string> v;

		auto results = db.QueryDatabase(
			fmt::format(
				"{} VALUES {}",
				BaseInsert(),
				Strings::Implode(",", insert_chunks)
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static std::vector<ZonePoints> All(Database& db)
	{
		std::vector<ZonePoints> all_entries;

		auto results = db.QueryDatabase(
			fmt::format(
				"{}",
				BaseSelect()
			)
		);

		all_entries.reserve(results.RowCount());

		for (auto row = results.begin(); row != results.end(); ++row) {
			ZonePoints e{};

			e.id                  = static_cast<int32_t>(atoi(row[0]));
			e.zone                = row[1] ? row[1] : "";
			e.number              = static_cast<uint16_t>(strtoul(row[2], nullptr, 10));
			e.y                   = strtof(row[3], nullptr);
			e.x                   = strtof(row[4], nullptr);
			e.z                   = strtof(row[5], nullptr);
			e.heading             = strtof(row[6], nullptr);
			e.target_y            = strtof(row[7], nullptr);
			e.target_x            = strtof(row[8], nullptr);
			e.target_z            = strtof(row[9], nullptr);
			e.target_heading      = strtof(row[10], nullptr);
			e.target_zone_id      = static_cast<uint32_t>(strtoul(row[11], nullptr, 10));
			e.client_version_mask = static_cast<uint32_t>(strtoul(row[12], nullptr, 10));

			all_entries.push_back(e);
		}

		return all_entries;
	}

	static std::vector<ZonePoints> GetWhere(Database& db, const std::string &where_filter)
	{
		std::vector<ZonePoints> all_entries;

		auto results = db.QueryDatabase(
			fmt::format(
				"{} WHERE {}",
				BaseSelect(),
				where_filter
			)
		);

		all_entries.reserve(results.RowCount());

		for (auto row = results.begin(); row != results.end(); ++row) {
			ZonePoints e{};

			e.id                  = static_cast<int32_t>(atoi(row[0]));
			e.zone                = row[1] ? row[1] : "";
			e.number              = static_cast<uint16_t>(strtoul(row[2], nullptr, 10));
			e.y                   = strtof(row[3], nullptr);
			e.x                   = strtof(row[4], nullptr);
			e.z                   = strtof(row[5], nullptr);
			e.heading             = strtof(row[6], nullptr);
			e.target_y            = strtof(row[7], nullptr);
			e.target_x            = strtof(row[8], nullptr);
			e.target_z            = strtof(row[9], nullptr);
			e.target_heading      = strtof(row[10], nullptr);
			e.target_zone_id      = static_cast<uint32_t>(strtoul(row[11], nullptr, 10));
			e.client_version_mask = static_cast<uint32_t>(strtoul(row[12], nullptr, 10));

			all_entries.push_back(e);
		}

		return all_entries;
	}

	static int DeleteWhere(Database& db, const std::string &where_filter)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"DELETE FROM {} WHERE {}",
				TableName(),
				where_filter
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int Truncate(Database& db)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"TRUNCATE TABLE {}",
				TableName()
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int64 GetMaxId(Database& db)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"SELECT COALESCE(MAX({}), 0) FROM {}",
				PrimaryKey(),
				TableName()
			)
		);

		return (results.Success() && results.begin()[0] ? strtoll(results.begin()[0], nullptr, 10) : 0);
	}

	static int64 Count(Database& db, const std::string &where_filter = "")
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"SELECT COUNT(*) FROM {} {}",
				TableName(),
				(where_filter.empty() ? "" : "WHERE " + where_filter)
			)
		);

		return (results.Success() && results.begin()[0] ? strtoll(results.begin()[0], nullptr, 10) : 0);
	}

};

#endif //EQEMU_BASE_ZONE_POINTS_REPOSITORY_H
