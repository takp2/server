#include "eqemu_logsys.h"
#include "platform.h"
#include "strings.h"
#include "database.h"
#include "db.h"
#include "misc.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>
#include <sys/stat.h>
#include <algorithm>
#include <string_view>

std::ofstream process_log;

#ifdef _WINDOWS
#include <direct.h>
#include <conio.h>
#include <iostream>
#include <dos.h>
#include <windows.h>
#include <process.h>
#else
#include <unistd.h>
#include <sys/stat.h>
#endif

namespace Console {
enum Color {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15,
};
}

EQEmuLogSys::EQEmuLogSys() {
	on_log_gmsay_hook = [](uint16 log_type, const std::string&) {};
	on_log_console_hook = [](uint16 debug_level, uint16 log_type,
	                         const std::string&) {};
}

EQEmuLogSys::~EQEmuLogSys() = default;

EQEmuLogSys* EQEmuLogSys::LoadLogSettingsDefaults() {
	/* Get Executable platform currently running this code (Zone/World/etc) */
	log_platform = GetExecutablePlatformInt();

	for (int log_category_id = Logs::AA; log_category_id != Logs::MaxCategoryID;
	     log_category_id++) {
		log_settings[log_category_id].log_to_console = 0;
		log_settings[log_category_id].log_to_file = 0;
		log_settings[log_category_id].log_to_gmsay = 0;
		log_settings[log_category_id].is_category_enabled = 0;
	}

	file_logs_enabled = false;

	/* Set Defaults */
	log_settings[Logs::WorldServer].log_to_console =
	    static_cast<uint8>(Logs::General);
	log_settings[Logs::ZoneServer].log_to_console =
	    static_cast<uint8>(Logs::General);
	log_settings[Logs::QSServer].log_to_console =
	    static_cast<uint8>(Logs::General);
	log_settings[Logs::UCSServer].log_to_console =
	    static_cast<uint8>(Logs::General);
	log_settings[Logs::Crash].log_to_console =
	    static_cast<uint8>(Logs::General);
	log_settings[Logs::MySQLError].log_to_console =
	    static_cast<uint8>(Logs::General);
	log_settings[Logs::LoginServer].log_to_console =
	    static_cast<uint8>(Logs::General);
	log_settings[Logs::QuestErrors].log_to_gmsay =
	    static_cast<uint8>(Logs::General);
	log_settings[Logs::QuestErrors].log_to_console =
	    static_cast<uint8>(Logs::General);

	/**
	 * RFC 5424
	 */
	log_settings[Logs::Emergency].log_to_console =
	    static_cast<uint8>(Logs::General);
	log_settings[Logs::Alert].log_to_console =
	    static_cast<uint8>(Logs::General);
	log_settings[Logs::Critical].log_to_console =
	    static_cast<uint8>(Logs::General);
	log_settings[Logs::Error].log_to_console =
	    static_cast<uint8>(Logs::General);
	log_settings[Logs::Warning].log_to_console =
	    static_cast<uint8>(Logs::General);
	log_settings[Logs::Notice].log_to_console =
	    static_cast<uint8>(Logs::General);
	log_settings[Logs::Info].log_to_console = static_cast<uint8>(Logs::General);

	/**
	 * Set Category enabled status on defaults
	 */
	for (int log_category_id = Logs::AA; log_category_id != Logs::MaxCategoryID;
	     log_category_id++) {
		const bool log_to_console =
		    log_settings[log_category_id].log_to_console > 0;
		const bool log_to_file = log_settings[log_category_id].log_to_file > 0;
		const bool log_to_gmsay =
		    log_settings[log_category_id].log_to_gmsay > 0;
		const bool is_category_enabled =
		    log_to_console || log_to_file || log_to_gmsay;
		if (is_category_enabled) {
			log_settings[log_category_id].is_category_enabled = 1;
		}
	}

	/*	Declare process file names for log writing
	    If there is no process_file_name declared, no log file will be written,
	   simply
	*/
	if (EQEmuLogSys::log_platform == EQEmuExePlatform::ExePlatformWorld) {
		platform_file_name = "world";
	} else if (EQEmuLogSys::log_platform ==
	           EQEmuExePlatform::ExePlatformQueryServ) {
		platform_file_name = "query_server";
	} else if (EQEmuLogSys::log_platform == EQEmuExePlatform::ExePlatformZone) {
		platform_file_name = "zone";
	} else if (EQEmuLogSys::log_platform == EQEmuExePlatform::ExePlatformUCS) {
		platform_file_name = "ucs";
	} else if (EQEmuLogSys::log_platform ==
	           EQEmuExePlatform::ExePlatformLogin) {
		platform_file_name = "login";
	} else if (EQEmuLogSys::log_platform ==
	           EQEmuExePlatform::ExePlatformLogin) {
		platform_file_name = "launcher";
	}

	return this;
}

/**
 * @param log_category
 * @return
 */
bool EQEmuLogSys::IsRfc5424LogCategory(uint16 log_category) {
	return (log_category == Logs::Emergency || log_category == Logs::Alert ||
	        log_category == Logs::Critical || log_category == Logs::Error ||
	        log_category == Logs::Warning || log_category == Logs::Notice ||
	        log_category == Logs::Info || log_category == Logs::Debug);
}

std::string EQEmuLogSys::FormatOutMessageString(uint16 log_category,
                                                const char* file, const char* func, int line,
                                                const std::string& in_message) {
	std::ostringstream out_message;
	if (log_category == Logs::Crash) {
		out_message << in_message;
		return out_message.str();
	}

	out_message << file << ":"
	            << line << " ";
	if (log_category != Logs::Info) {
		out_message << "[" << Logs::LogCategoryName[log_category] << "] ";
	}
	out_message << in_message;
	return out_message.str();
}

void EQEmuLogSys::ProcessGMSay(uint16 debug_level, uint16 log_category,
                               const std::string& message) {
	/* Enabling Netcode based GMSay output creates a feedback loop that
	 * ultimately ends in a crash */
	if (log_category == Logs::LogCategory::Netcode) return;

	/* Check to see if the process that actually ran this is zone */
	if (EQEmuLogSys::log_platform == EQEmuExePlatform::ExePlatformZone)
		on_log_gmsay_hook(log_category, message);
}

void EQEmuLogSys::ProcessLogWrite(uint16 debug_level, uint16 log_category,
                                  const std::string& message) {
	if (log_category == Logs::Crash) {
		char time_stamp[80];
		EQEmuLogSys::SetCurrentTimeStamp(time_stamp);
		std::ofstream crash_log;
		EQEmuLogSys::MakeDirectory("logs/crashes");
		crash_log.open(StringFormat("logs/crashes/crash_%s_%i.log",
		                            platform_file_name.c_str(), getpid()),
		               std::ios_base::app | std::ios_base::out);
		crash_log << time_stamp << " " << message << "\n";
		crash_log.close();
	}

	char time_stamp[80];
	EQEmuLogSys::SetCurrentTimeStamp(time_stamp);

	if (process_log) process_log << time_stamp << " " << message << std::endl;
}

uint16 EQEmuLogSys::GetGMSayColorFromCategory(uint16 log_category) {
	switch (log_category) {
		case Logs::Status:
		case Logs::Normal:
			return 15; /* Yellow */
		case Logs::MySQLError:
		case Logs::QuestErrors:
		case Logs::Error:
			return 13; /* Red */
		case Logs::MySQLQuery:
		case Logs::Debug:
			return 14; /* Light Green */
		case Logs::Quests:
			return 258; /* Light Cyan */
		case Logs::Commands:
			return 5; /* Light Purple */
		case Logs::Crash:
			return 13; /* Red */
		default:
			return 15; /* Yellow */
	}
}

void EQEmuLogSys::ProcessConsoleMessage(uint16 debug_level, uint16 log_category,
                                        const std::string& message) {
#ifdef _WINDOWS
	HANDLE console_handle;
	console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX info = {0};
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = 12;  // leave X as zero
	info.FontWeight = FW_NORMAL;
	wcscpy(info.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(console_handle, NULL, &info);
	std::cout << message << "\n";
#else
	std::cout << message << std::endl;
#endif
}

/**
 * @param str
 * @return
 */
constexpr const char* str_end(const char* str) {
	return *str ? str_end(str + 1) : str;
}

/**
 * @param str
 * @return
 */
constexpr bool str_slant(const char* str) {
	return *str == '/' ? true : (*str ? str_slant(str + 1) : false);
}

/**
 * @param str
 * @return
 */
constexpr const char* r_slant(const char* str) {
	return *str == '/' ? (str + 1) : r_slant(str - 1);
}

/**
 * @param str
 * @return
 */
constexpr const char* base_file_name(const char* str) {
	return str_slant(str) ? r_slant(str_end(str)) : str;
}

/**
 * Core logging function
 *
 * @param debug_level
 * @param log_category
 * @param message
 * @param ...
 */

void EQEmuLogSys::Out(Logs::DebugLevel debug_level, uint16 log_category,
                      const char* file, const char* func, int line,
                      const char* message, ...) {
	bool log_to_console = true;
	if (log_settings[log_category].log_to_console < debug_level) {
		log_to_console = false;
	}

	bool log_to_file = true;
	if (log_settings[log_category].log_to_file < debug_level) {
		log_to_file = false;
	}

	bool log_to_gmsay = true;
	if (log_settings[log_category].log_to_gmsay < debug_level) {
		log_to_gmsay = false;
	}

	const bool nothing_to_log =
	    !log_to_console && !log_to_file && !log_to_gmsay;
	if (nothing_to_log) return;

	std::string prefix;

	va_list args;
	va_start(args, message);
	std::string output_message = vStringFormat(message, args);
	va_end(args);

	std::string output_debug_message =
	    EQEmuLogSys::FormatOutMessageString(log_category, file, func, line, output_message);

	if (log_to_console)
		EQEmuLogSys::ProcessConsoleMessage(debug_level, log_category,
		                                   output_debug_message);
	if (log_to_gmsay)
		EQEmuLogSys::ProcessGMSay(debug_level, log_category,
		                          output_debug_message);
	if (log_to_file)
		EQEmuLogSys::ProcessLogWrite(debug_level, log_category,
		                             output_debug_message);
}

void EQEmuLogSys::SetCurrentTimeStamp(char* time_stamp) {
	time_t raw_time;
	struct tm* time_info;
	time(&raw_time);
	time_info = localtime(&raw_time);
	strftime(time_stamp, 80, "[%m-%d-%Y :: %H:%M:%S]", time_info);
}

void EQEmuLogSys::MakeDirectory(const std::string& directory_name) {
#ifdef _WINDOWS
	struct _stat st;
	if (_stat(directory_name.c_str(), &st) == 0)  // exists
		return;
	_mkdir(directory_name.c_str());
#else
	struct stat st;
	if (stat(directory_name.c_str(), &st) == 0)  // exists
		return;
	mkdir(directory_name.c_str(), 0755);
#endif
}

void EQEmuLogSys::CloseFileLogs() {
	if (process_log.is_open()) {
		process_log.close();
	}
}

void EQEmuLogSys::StartFileLogs(const std::string& log_name) {
	EQEmuLogSys::CloseFileLogs();

	/* When loading settings, we must have been given a reason in category based
	 * logging to output to a file in order to even create or open one... */
	if (!file_logs_enabled) return;

	/**
	 * Zone
	 */
	if (EQEmuLogSys::log_platform == EQEmuExePlatform::ExePlatformZone) {
		if (!log_name.empty()) platform_file_name = log_name;

		if (platform_file_name.empty()) return;

		LogInfo("Logging to logs/{0}_{1}.log",
		        platform_file_name.c_str(), getpid());

		/**
		 * Make directory if not exists
		 */
		EQEmuLogSys::MakeDirectory("logs/zone");

		/**
		 * Open file pointer
		 */
		process_log.open(StringFormat("logs/zone/%s_%i.log",
		                              platform_file_name.c_str(), getpid()),
		                 std::ios_base::app | std::ios_base::out);
	} else {
		/**
		 * All other processes
		 */
		if (platform_file_name.empty()) return;

		LogInfo("Logging to logs/{0}_{1}.log",
		        platform_file_name.c_str(), getpid());

		process_log.open(StringFormat("logs/%s_%i.log",
		                              platform_file_name.c_str(), getpid()),
		                 std::ios_base::app | std::ios_base::out);
	}
}

/**
 * Silence console logging
 */
void EQEmuLogSys::SilenceConsoleLogging() {
	for (int log_index = Logs::AA; log_index != Logs::MaxCategoryID;
	     log_index++) {
		log_settings[log_index].log_to_console = 0;
		log_settings[log_index].is_category_enabled = 0;
	}
}

/**
 * Enables console logging
 */
void EQEmuLogSys::EnableConsoleLogging() {
	for (int log_index = Logs::AA; log_index != Logs::MaxCategoryID;
	     log_index++) {
		log_settings[log_index].log_to_console = Logs::General;
		log_settings[log_index].is_category_enabled = 1;
	}
}

EQEmuLogSys* EQEmuLogSys::LoadLogDatabaseSettings() {
	std::vector<int>
	    db_categories{};

	auto results = DB::Query("SELECT log_category_id, log_to_console, log_to_file, log_to_gmsay FROM logsys_categories ORDER BY log_category_id");
	if (!results.Success()) {
		LogError("Failed to load logsys_categories: {}", results.ErrorMessage());
		return nullptr;
	}
	db_categories.reserve(results.RowCount());

	for (auto row = results.begin(); row != results.end(); ++row) {
		auto log_category_id = atoi(row[0]);
		auto log_to_console = atoi(row[1]);
		auto log_to_file = atoi(row[2]);
		auto log_to_gmsay = atoi(row[3]);

		if (log_category_id <= Logs::None ||
		    log_category_id >= Logs::MaxCategoryID) {
			continue;
		}

		bool is_category_enabled = false;

		log_settings[log_category_id].log_to_console =
		    static_cast<uint8>(log_to_console);
		if (log_to_console > 0) {
			is_category_enabled = true;
		}
		log_settings[log_category_id].log_to_file =
		    static_cast<uint8>(log_to_file);
		if (log_to_file > 0) {
			is_category_enabled = true;
		}
		log_settings[log_category_id].log_to_gmsay =
		    static_cast<uint8>(log_to_gmsay);
		if (log_to_gmsay > 0) {
			is_category_enabled = true;
		}

		if (is_category_enabled) {
			log_settings[log_category_id].is_category_enabled = 1;
		}

		// This determines whether or not the process needs to actually file log
		// anything. If we go through this whole loop and nothing is set to any
		// debug level, there is no point to create a file or keep anything open
		if (log_settings[log_category_id].log_to_file > 0) {
			LogSys.file_logs_enabled = true;
		}

		db_categories.emplace_back(log_category_id);
	}

	// info and error should always be to console
	log_settings[Logs::Info].is_category_enabled = 1;
	log_settings[Logs::Info].log_to_console = Logs::General;
	log_settings[Logs::Error].is_category_enabled = 1;
	log_settings[Logs::Error].log_to_console = Logs::General;
	return this;
}
