#include <stdio.h>

#include "../common/crash.h"
#include "../common/config.h"
#include "../common/eqemu_exception.h"
#include "../common/eqemu_logsys.h"
#include "../common/global_define.h"
#include "../common/platform.h"
#include "../common/rulesys.h"
#include "../common/shareddb.h"
#include "../common/strings.h"
#include "../common/db.h"
#include "base_data.h"
#include "items.h"
#include "loot.h"
#include "npc_faction.h"
#include "skill_caps.h"
#include "spells.h"
#include <chrono>

EQEmuLogSys LogSys;

int main(int argc, char **argv) {
	auto start = std::chrono::high_resolution_clock::now();

	RegisterExecutablePlatform(ExePlatformSharedMemory);
	LogSys.LoadLogSettingsDefaults();
	set_exception_handler();

	LogInfo("Starting SharedMemory v{}", VERSION);
	auto load_result = Config::LoadConfig();
	if (!load_result.empty()) {
		LogError("{}", load_result);
		return 1;
	}
	auto Config = Config::get();

	SharedDatabase database;
	if (!database.Connect(Config->DatabaseHost.c_str(),
	                      Config->DatabaseUsername.c_str(),
	                      Config->DatabasePassword.c_str(),
	                      Config->DatabaseDB.c_str(), Config->DatabasePort)) {
		LogError("Failed database connection");
		return 1;
	}

	if (!DB::Open(Config->DatabaseHost.c_str(),
	              Config->DatabaseUsername.c_str(),
	              Config->DatabasePassword.c_str(),
	              Config->DatabaseDB.c_str(), Config->DatabasePort)) {
		LogError("Failed database connection");
		return 1;
	}

	// LogSys.LoadLogDatabaseSettings()->StartFileLogs();
	/*database.LoadVariables();
	std::string db_hotfix_name;
	if (database.GetVariable("hotfix_name", db_hotfix_name)) {
	    if (!db_hotfix_name.empty() &&
	        strcasecmp("hotfix_", db_hotfix_name.c_str()) == 0) {
	        Log(Logs::General, Logs::Status,
	            "Current hotfix in variables is the default %s, clearing out "
	            "variable",
	            db_hotfix_name.c_str());
	        std::string query = StringFormat(
	            "UPDATE `variables` SET `value`='' WHERE "
	            "(`varname`='hotfix_name')");
	        database.QueryDatabase(query);
	    }
	}
	*/

	std::string hotfix_name = "";
	bool load_all = true;
	bool load_items = false;
	bool load_factions = false;
	bool load_loot = false;
	bool load_skill_caps = false;
	bool load_spells = false;
	bool load_bd = false;
	if (argc > 1) {
		for (int i = 1; i < argc; ++i) {
			switch (argv[i][0]) {
				case 'b':
					if (strcasecmp("base_data", argv[i]) == 0) {
						load_bd = true;
						load_all = false;
					}
					break;

				case 'i':
					if (strcasecmp("items", argv[i]) == 0) {
						load_items = true;
						load_all = false;
					}
					break;

				case 'f':
					if (strcasecmp("factions", argv[i]) == 0) {
						load_factions = true;
						load_all = false;
					}
					break;

				case 'l':
					if (strcasecmp("loot", argv[i]) == 0) {
						load_loot = true;
						load_all = false;
					}
					break;

				case 's':
					if (strcasecmp("skill_caps", argv[i]) == 0) {
						load_skill_caps = true;
						load_all = false;
					} else if (strcasecmp("spells", argv[i]) == 0) {
						load_spells = true;
						load_all = false;
					}
					break;
				case '-': {
					auto split = Strings::Split(argv[i], '=');
					if (split.size() >= 2) {
						auto command = split[0];
						auto argument = split[1];
						if (strcasecmp("-hotfix", command.c_str()) == 0) {
							hotfix_name = argument;
							load_all = true;
						}
					}
					break;
				}
			}
		}
	}

	if (hotfix_name.length() > 0) {
		Log(Logs::General, Logs::Status, "Writing data for hotfix '%s'",
		    hotfix_name.c_str());
	}

	if (load_all || load_items) {
		try {
			LoadItems(&database, hotfix_name);
		} catch (std::exception &ex) {
			LogError("Failed to load items: {}", ex.what());
			return 1;
		}
	}

	if (load_all || load_factions) {
		try {
			LoadFactions(&database, hotfix_name);
		} catch (std::exception &ex) {
			LogError("Failed to load factions: {}", ex.what());
			return 1;
		}
	}

	if (load_all || load_loot) {
		try {
			LoadLoot(&database, hotfix_name);
		} catch (std::exception &ex) {
			LogError("Failed to load loot: {}", ex.what());
			return 1;
		}
	}

	if (load_all || load_skill_caps) {
		try {
			LoadSkillCaps(&database, hotfix_name);
		} catch (std::exception &ex) {
			LogError("Failed to load skill caps: {}", ex.what());
			return 1;
		}
	}

	if (load_all || load_spells) {
		try {
			LoadSpells(&database, hotfix_name);
		} catch (std::exception &ex) {
			LogError("Failed to load spells: {}", ex.what());
			return 1;
		}
	}

	if (load_all || load_bd) {
		try {
			LoadBaseData(&database, hotfix_name);
		} catch (std::exception &ex) {
			LogError("Failed to load base data: {}", ex.what());
			return 1;
		}
	}

	LogInfo("Finished in {}s", std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - start).count());
	LogSys.CloseFileLogs();
	return 0;
}
