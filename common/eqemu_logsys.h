#ifndef EQEMU_LOGSYS_H
#define EQEMU_LOGSYS_H

#include <iostream>
#include <fstream>
#include <cstdio>
#include <functional>
#include <algorithm>

#ifdef _WIN32
#ifdef utf16_to_utf8
#undef utf16_to_utf8
#endif
#endif

#include <fmt/format.h>
#include "types.h"

namespace Logs {
enum DebugLevel {
	General =
	    1,    /* 1 - Low-Level general debugging, useful info on single line */
	Moderate, /* 2 - Informational based, used in functions, when particular
	             things load */
	Detail,   /* 3 - Use this for extreme detail in logging, usually in extreme
	             debugging in the stack or interprocess communication */
};

/*
    If you add to this, make sure you update LogCategoryName
    NOTE: Only add to the bottom of the enum because that is the type ID
   assignment
*/

enum LogCategory {
	None = 0,
	AA,
	AI,
	Aggro,
	Attack,
	PacketClientServer,
	Combat,
	Commands,
	Crash,
	Debug,
	Doors,
	Error,
	Guilds,
	Inventory,
	Launcher,
	Netcode,
	Normal,
	Object,
	Pathing,
	QSServer,
	Quests,
	Rules,
	Skills,
	Spawns,
	Spells,
	Status,
	TCPConnection,
	Tasks,
	Tradeskills,
	Trading,
	LoginServer,
	UCSServer,
	WebInterfaceServer,
	WorldServer,
	ZoneServer,
	MySQLError,
	MySQLQuery,
	QuestDebug,
	PacketServerClient,
	PacketClientServerUnhandled,
	PacketServerClientWithDump,
	PacketClientServerWithDump,
	Maps,
	Character,
	Faction,
	Group,
	Corpse,
	Bazaar,
	Discs,
	Boats,
	Traps,
	PTimers,
	Nexus,
	Pets,
	Regen,
	Focus,
	Death,
	Info,
	Warning,
	Critical,
	Emergency,
	Alert,
	Notice,
	QuestErrors,
	MaxCategoryID /* Don't Remove this*/
};

/* If you add to this, make sure you update LogCategory */
static const char* LogCategoryName[LogCategory::MaxCategoryID] = {
    "",
    "AA",
    "AI",
    "Aggro",
    "Attack",
    "Packet :: Client -> Server",
    "Combat",
    "Commands",
    "Crash",
    "Debug",
    "Doors",
    "Error",
    "Guilds",
    "Inventory",
    "Launcher",
    "Netcode",
    "Normal",
    "Object",
    "Pathing",
    "QS Server",
    "Quests",
    "Rules",
    "Skills",
    "Spawns",
    "Spells",
    "Status",
    "TCP Connection",
    "Tasks",
    "Tradeskills",
    "Trading",
    "Login Server",
    "UCS Server",
    "WebInterface Server",
    "World Server",
    "Zone Server",
    "MySQL Error",
    "MySQL Query",
    "Quest Debug",
    "Packet :: Server -> Client",
    "Packet :: Client -> Server Unhandled",
    "Packet :: Server -> Client (Dump)",
    "Packet :: Client -> Server (Dump)",
    "Maps",
    "Character",
    "Faction",
    "Group",
    "Corpse",
    "Bazaar",
    "Discs",
    "Boats",
    "Traps",
    "PTimers",
    "Nexus",
    "Pets",
    "Regen",
    "Focus",
    "Death",
    "Info",
    "Warning",
    "Critical",
    "Emergency",
    "Alert",
    "Notice",
    "QuestErrors"};
}  // namespace Logs

#include "eqemu_logsys_log_aliases.h"

class Database;

class EQEmuLogSys {
   public:
	EQEmuLogSys();
	~EQEmuLogSys();

	/**
	 * Close File Logs wherever necessary, either at zone shutdown or entire
	 * process shutdown for everything else. This should be handled on
	 * deconstructor but to be safe we use it anyways.
	 */
	void CloseFileLogs();
	EQEmuLogSys* LoadLogSettingsDefaults();
	EQEmuLogSys* LoadLogDatabaseSettings();

	/**
	 * @param directory_name
	 */
	void MakeDirectory(
	    const std::string&
	        directory_name); /* Platform independent way of performing a
	                            MakeDirectory based on name */
	/*
	    The one and only Logging function that uses a debug level as a
	   parameter, as well as a log_category log_category - defined in
	   Logs::LogCategory::[] log_category name resolution works by passing the
	   enum int ID to Logs::LogCategoryName[category_id]

	    Example: EQEmuLogSys::Out(Logs::General, Logs::Guilds, "This guild has
	   no leader present");
	        - This would pipe the same category and debug level to all output
	   formats, but the internal memory reference of log_settings would be
	   checked against to see if that piped output is set to actually process it
	   for the category and debug level
	*/
	void Out(Logs::DebugLevel debug_level, uint16 log_category,
	         const char* file, const char* func, int line, const char* message,
	         ...);

	/**
	 * Used in file logs to prepend a timestamp entry for logs
	 * @param time_stamp
	 */
	void SetCurrentTimeStamp(char* time_stamp);

	/**
	 * @param log_name
	 */
	void StartFileLogs(const std::string& log_name =
	                       ""); /* Used to declare the processes file log and to
	                               keep it open for later use */

	/*
	    LogSettings Struct

	    This struct is the master reference for all settings for each category,
	   and for each output

	    log_to_file[category_id] = [1-3] - Sets debug level for category to
	   output to file log_to_console[category_id] = [1-3] - Sets debug level for
	   category to output to console log_to_gmsay[category_id] = [1-3] - Sets
	   debug level for category to output to gmsay
	*/

	struct LogSettings {
		uint8 log_to_file;
		uint8 log_to_console;
		uint8 log_to_gmsay;
		uint8 is_category_enabled; /* When any log output in a category > 0, set
		                              this to 1 as (Enabled) */
	};

	/* Internally used memory reference for all log settings per category.
	    These are loaded via DB and have defaults loaded in
	   LoadLogSettingsDefaults. Database loaded via
	   LogSys.SetDatabase(&database)->LoadLogDatabaseSettings();
	*/
	LogSettings log_settings[Logs::LogCategory::MaxCategoryID];

	bool file_logs_enabled = false;

	int log_platform = 0;
	std::string platform_file_name;

	// gmsay
	uint16 GetGMSayColorFromCategory(uint16 log_category);

	EQEmuLogSys* SetGMSayHandler(
	    std::function<void(uint16 log_type, const std::string&)> f) {
		on_log_gmsay_hook = f;
		return this;
	}

	void SetConsoleHandler(
	    std::function<void(uint16 debug_level, uint16 log_type,
	                       const std::string&)>
	        f) {
		on_log_console_hook = f;
	}
	void SilenceConsoleLogging();
	void EnableConsoleLogging();

	// database
	EQEmuLogSys* SetDatabase(Database* db);

   private:
	// reference to database
	Database* m_database;

	std::function<void(uint16 log_category, const std::string&)>
	    on_log_gmsay_hook;
	std::function<void(uint16 debug_level, uint16 log_category,
	                   const std::string&)>
	    on_log_console_hook;

	std::string FormatOutMessageString(uint16 log_category,
	                                   const char* file, const char* func, int line,
	                                   const std::string& in_message);

	void ProcessConsoleMessage(
	    uint16 debug_level, uint16 log_category,
	    const std::string&
	        message); /* ProcessConsoleMessage called via Log.Out */
	void ProcessGMSay(
	    uint16 debug_level, uint16 log_category,
	    const std::string& message); /* ProcessGMSay called via Log.Out */
	void ProcessLogWrite(
	    uint16 debug_level, uint16 log_category,
	    const std::string& message); /* ProcessLogWrite called via Log.Out */
	bool IsRfc5424LogCategory(uint16 log_category);
};

extern EQEmuLogSys LogSys;

#define OutF(ls, debug_level, log_category, file, func, line, formatStr, ...) \
	do {                                                                      \
		ls.Out(debug_level, log_category, file, func, line,                   \
		       fmt::format(formatStr, ##__VA_ARGS__).c_str());                \
	} while (0)

#endif
