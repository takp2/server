#include "world_server_command_handler.h"
#include "../common/eqemu_logsys.h"
#include "../common/json/json.h"
#include "../common/version.h"
#include "../common/database_schema.h"
#include "../common/database/database_dump_service.h"

namespace WorldserverCommandHandler {

	/**
	 * @param argc
	 * @param argv
	 */
	void CommandHandler(int argc, char** argv)
	{
		if (argc == 1) { return; }

		argh::parser cmd;
		cmd.parse(argc, argv, argh::parser::PREFER_PARAM_FOR_UNREG_OPTION);
		EQEmuCommand::DisplayDebug(cmd);

		/**
		 * Declare command mapping
		 */
		auto function_map = EQEmuCommand::function_map;

		/**
		 * Register commands
		 */
		function_map["world:version"] = &WorldserverCommandHandler::Version;
		function_map["database:version"] = &WorldserverCommandHandler::DatabaseVersion;
		function_map["database:schema"] = &WorldserverCommandHandler::DatabaseGetSchema;
		function_map["database:dump"] = &WorldserverCommandHandler::DatabaseDump;

		EQEmuCommand::HandleMenu(function_map, cmd, argc, argv);
	}

	/**
	* @param argc
	 * @param argv
	 * @param cmd
	 * @param description
	 */
	void Version(int argc, char** argv, argh::parser& cmd, std::string& description)
	{
		description = "Shows server version";

		if (cmd[{"-h", "--help"}]) {
			return;
		}

		Json::Value database_version;

		database_version["compile_date"] = COMPILE_DATE;
		database_version["compile_time"] = COMPILE_TIME;
		database_version["database_version"] = CURRENT_BINARY_DATABASE_VERSION;
		database_version["server_version"] = VERSION;

		std::stringstream payload;
		payload << database_version;

		std::cout << payload.str() << std::endl;
	}

	/**
	 * @param argc
	 * @param argv
	 * @param cmd
	 * @param description
	 */
	void DatabaseVersion(int argc, char** argv, argh::parser& cmd, std::string& description)
	{
		description = "Shows database version";

		if (cmd[{"-h", "--help"}]) {
			return;
		}

		Json::Value database_version;

		database_version["database_version"] = CURRENT_BINARY_DATABASE_VERSION;

		std::stringstream payload;
		payload << database_version;

		std::cout << payload.str() << std::endl;
	}

	/**
 * @param argc
 * @param argv
 * @param cmd
 * @param description
 */
	void DatabaseGetSchema(int argc, char** argv, argh::parser& cmd, std::string& description)
	{
		description = "Displays server database schema";


		if (cmd[{"-h", "--help"}]) {
			return;
		}

		Json::Value              player_tables_json;
		std::vector<std::string> player_tables = DatabaseSchema::GetPlayerTables();
		for (const auto& table : player_tables) {
			player_tables_json.append(table);
		}

		Json::Value              content_tables_json;
		std::vector<std::string> content_tables = DatabaseSchema::GetContentTables();
		for (const auto& table : content_tables) {
			content_tables_json.append(table);
		}

		Json::Value              server_tables_json;
		std::vector<std::string> server_tables = DatabaseSchema::GetServerTables();
		for (const auto& table : server_tables) {
			server_tables_json.append(table);
		}

		Json::Value schema;

		schema["content_tables"] = content_tables_json;
		schema["player_tables"] = player_tables_json;
		schema["server_tables"] = server_tables_json;

		std::stringstream payload;
		payload << schema;

		std::cout << payload.str() << std::endl;
	}

	/**
	 * @param argc
	 * @param argv
	 * @param cmd
	 * @param description
	 */
	void DatabaseDump(int argc, char** argv, argh::parser& cmd, std::string& description)
	{
		description = "Dumps server database tables";

		if (cmd[{"-h", "--help"}]) {
			return;
		}

		std::vector<std::string> arguments = {};
		std::vector<std::string> options = {
			"--all",
			"--content-tables",
			//"--login-tables",
			"--player-tables",
			"--state-tables",
			"--system-tables",
			"--query-serv-tables",
			"--table-structure-only",
			"--table-lock",
			"--dump-path=",
			"--dump-output-to-console",
			"--compress"
		};


		if (argc < 3) {
			EQEmuCommand::ValidateCmdInput(arguments, options, cmd, argc, argv);
			return;
		}

		auto database_dump_service = new DatabaseDumpService();
		bool dump_all = cmd[{"-a", "--all"}];

		if (!cmd("--dump-path").str().empty()) {
			database_dump_service->SetDumpPath(cmd("--dump-path").str());
		}

		/**
		 * Set Option
		 */
		database_dump_service->SetDumpContentTables(cmd[{"--content-tables"}] || dump_all);
		//database_dump_service->SetDumpLoginServerTables(cmd[{"--login-tables"}] || dump_all);
		database_dump_service->SetDumpPlayerTables(cmd[{"--player-tables"}] || dump_all);
		database_dump_service->SetDumpStateTables(cmd[{"--state-tables"}] || dump_all);
		database_dump_service->SetDumpSystemTables(cmd[{"--system-tables"}] || dump_all);
		database_dump_service->SetDumpQueryServerTables(cmd[{"--query-serv-tables"}] || dump_all);
		database_dump_service->SetDumpAllTables(dump_all);

		database_dump_service->SetDumpWithNoData(cmd[{"--table-structure-only"}]);
		database_dump_service->SetDumpTableLock(cmd[{"--table-lock"}]);
		database_dump_service->SetDumpWithCompression(cmd[{"--compress"}]);
		database_dump_service->SetDumpOutputToConsole(cmd[{"--dump-output-to-console"}]);

		/**
		 * Dump
		 */
		database_dump_service->Dump();
	}

}
