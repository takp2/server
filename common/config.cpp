#define RYML_SINGLE_HDR_DEFINE_NOW
#define RYML_USE_ASSERT
#include <yaml-cpp/yaml.h>

#include "../common/global_define.h"
#include "../common/eqemu_logsys.h"
#include "config.h"
#include "misc_functions.h"

#include <iostream>
#include <sstream>

std::string Config::ConfigFile = "config.yaml";
Config *Config::_config = nullptr;

bool Config::parse_config() {
	if (_root["world"].IsNull()) {
		LogError("Missing world section in config.yaml");
		return false;
	}
	std::string value;

	if (_root["world"]["short_name"].IsNull()) {
		LogError("Missing world.short_name in config.yaml");
		return false;
	}
	if (_root["world"]["short_name"].Type() != YAML::NodeType::Scalar) {
		LogError("World.short_name must be a string");
		return false;
	}
	ShortName = _root["world"]["short_name"].as<std::string>();

	if (_root["world"]["long_name"].IsNull()) {
		LogError("Missing world.long_name in config.yaml");
		return false;
	}
	if (_root["world"]["long_name"].Type() != YAML::NodeType::Scalar) {
		LogError("World.long_name must be a string");
		return false;
	}
	LongName = _root["world"]["long_name"].as<std::string>();

	if (!_root["world"]["wan_address"].IsNull()) {
		// LogError("Missing world.wan_address in config.yaml");
		if (_root["world"]["wan_address"].Type() != YAML::NodeType::Scalar) {
			// LogError("World.wan_address must be a string");
			// return false;
			WorldAddress = "";
		} else {
			WorldAddress = _root["world"]["wan_address"].as<std::string>();
		}
	}

	if (_root["world"]["lan_address"].IsNull()) {
		LogError("Missing world.lan_address in config.yaml");
		return false;
	}
	if (_root["world"]["lan_address"].Type() != YAML::NodeType::Scalar) {
		LogError("World.lan_address must be a string");
		return false;
	}
	LocalAddress = _root["world"]["lan_address"].as<std::string>();

	if (!_root["world"]["max_clients"].IsNull()) {
		if (_root["world"]["max_clients"].Type() != YAML::NodeType::Scalar) {
			LogError("World.max_clients must be an integer");
			return false;
		}
		MaxClients = _root["world"]["max_clients"].as<int32_t>();
	}

	if (_root["world"]["shared_key"].IsNull()) {
		LogError("Missing world.shared_key in config.yaml");
		return false;
	}
	if (_root["world"]["shared_key"].Type() != YAML::NodeType::Scalar) {
		LogError("World.shared_key must be a string");
		return false;
	}
	SharedKey = _root["world"]["shared_key"].as<std::string>();

	if (!_root["world"]["is_locked"].IsNull()) {
		if (_root["world"]["is_locked"].Type() != YAML::NodeType::Scalar) {
			LogError("World.is_locked must be a boolean");
			return false;
		}
		Locked = _root["world"]["is_locked"].as<bool>();
	} else {
		Locked = false;
	}

	if (!_root["world"]["intranet_ip"].IsNull()) {
		if (_root["world"]["intranet_ip"].Type() != YAML::NodeType::Scalar) {
			LogError("World.intranet_ip must be a string");
			return false;
		}
		WorldIP = _root["world"]["intranet_ip"].as<std::string>();
	} else {
		WorldIP = "0.0.0.0";
	}

	if (!_root["world"]["intranet_port"].IsNull()) {
		if (_root["world"]["intranet_port"].Type() != YAML::NodeType::Scalar) {
			LogError("World.intranet_port must be a number");
			return false;
		}
		WorldTCPPort = _root["world"]["intranet_port"].as<uint16_t>();
	} else {
		WorldTCPPort = 0;
	}

	loginlist.Clear();
	for (std::size_t i = 0; i < _root["login_server"].size(); i++) {
		auto loginconfig = new LoginConfig;
		if (_root["login_server"][i]["host"].IsNull()) {
			LogError("Missing login_server.host in config.yaml");
			return false;
		}
		if (_root["login_server"][i]["host"].Type() != YAML::NodeType::Scalar) {
			LogError("Login_server.host must be a string");
			return false;
		}
		loginconfig->LoginHost = _root["login_server"][i]["host"].as<std::string>();
		if (_root["login_server"][i]["port"].IsNull()) {
			LogError("Missing login_server.port in config.yaml");
			return false;
		}
		if (_root["login_server"][i]["port"].Type() != YAML::NodeType::Scalar) {
			LogError("Login_server.port must be a number");
			return false;
		}
		loginconfig->LoginPort = _root["login_server"][i]["port"].as<uint16>();
		if (!_root["login_server"][i]["account"].IsNull()) {
			if (_root["login_server"][i]["account"].Type() != YAML::NodeType::Scalar) {
				LogError("Login_server.account must be a string");
				return false;
			}
			loginconfig->LoginAccount = _root["login_server"][i]["account"].as<std::string>();
		}
		if (!_root["login_server"][i]["password"].IsNull()) {
			if (_root["login_server"][i]["password"].Type() != YAML::NodeType::Scalar) {
				LogError("Login_server.password must be a string");
				return false;
			}
			loginconfig->LoginPassword = _root["login_server"][i]["password"].as<std::string>();
		}
		if (!_root["login_server"][i]["type"].IsNull()) {
			if (_root["login_server"][i]["type"].Type() != YAML::NodeType::Scalar) {
				LogError("Login_server.type must be a number");
				return false;
			}
			loginconfig->LoginType = _root["login_server"][i]["type"].as<uint8>();
		}
		loginlist.Insert(loginconfig);
	}

	if (!_root["world"]["telnet_is_enabled"].IsNull()) {
		if (_root["world"]["telnet_is_enabled"].Type() != YAML::NodeType::Scalar) {
			LogError("Telnet.is_enabled must be a boolean");
			return false;
		}
		TelnetEnabled = _root["world"]["telnet_is_enabled"].as<bool>();
	} else {
		TelnetEnabled = false;
	}

	if (!_root["ucs"]["host"].IsNull()) {
		if (_root["ucs"]["host"].Type() != YAML::NodeType::Scalar) {
			LogError("Ucs.host must be a string");
			return false;
		}

		UCSHost = _root["ucs"]["host"].as<std::string>();
	}

	if (!_root["ucs"]["port"].IsNull()) {
		if (_root["ucs"]["port"].Type() != YAML::NodeType::Scalar) {
			LogError("Ucs.port must be a number");
			return false;
		}
		UCSPort = _root["ucs"]["port"].as<uint16_t>();
	}

	if (!_root["database"]["host"].IsNull()) {
		if (_root["database"]["host"].Type() != YAML::NodeType::Scalar) {
			LogError("Database.host must be a string");
			return false;
		}
		DatabaseHost = _root["database"]["host"].as<std::string>();
	} else {
		LogError("Missing database.host in config.yaml");
		return false;
	}

	if (!_root["database"]["username"].IsNull()) {
		if (_root["database"]["username"].Type() != YAML::NodeType::Scalar) {
			LogError("Database.username must be a string");
			return false;
		}
		DatabaseUsername = _root["database"]["username"].as<std::string>();
	} else {
		LogError("Missing database.username in config.yaml");
		return false;
	}

	if (!_root["database"]["password"].IsNull()) {
		if (_root["database"]["password"].Type() != YAML::NodeType::Scalar) {
			LogError("Database.password must be a string");
			return false;
		}
		DatabasePassword = _root["database"]["password"].as<std::string>();
	} else {
		LogError("Missing database.password in config.yaml");
		return false;
	}

	if (!_root["database"]["db"].IsNull()) {
		if (_root["database"]["db"].Type() != YAML::NodeType::Scalar) {
			LogError("Database.db must be a string");
			return false;
		}
		DatabaseDB = _root["database"]["db"].as<std::string>();
	} else {
		LogError("Missing database.db in config.yaml");
		return false;
	}

	if (!_root["database"]["port"].IsNull()) {
		if (_root["database"]["port"].Type() != YAML::NodeType::Scalar) {
			LogError("Database.port must be a number");
			return false;
		}
		DatabasePort = _root["database"]["port"].as<uint16_t>();
	} else {
		LogError("Missing database.port in config.yaml");
		return false;
	}

	if (!_root["query_serv"]["host"].IsNull()) {
		if (_root["query_serv"]["host"].Type() != YAML::NodeType::Scalar) {
			LogError("Query_serv.host must be a string");
			return false;
		}
		QSDatabaseHost = _root["query_serv"]["host"].as<std::string>();
	} else {
		LogError("Missing query_serv.host in config.yaml");
		return false;
	}

	if (!_root["query_serv"]["username"].IsNull()) {
		if (_root["query_serv"]["username"].Type() != YAML::NodeType::Scalar) {
			LogError("Query_serv.username must be a string");
			return false;
		}
		QSDatabaseUsername = _root["query_serv"]["username"].as<std::string>();
	} else {
		LogError("Missing query_serv.username in config.yaml");
		return false;
	}

	if (!_root["query_serv"]["password"].IsNull()) {
		if (_root["query_serv"]["password"].Type() != YAML::NodeType::Scalar) {
			LogError("Query_serv.password must be a string");
			return false;
		}
		QSDatabasePassword = _root["query_serv"]["password"].as<std::string>();
	} else {
		LogError("Missing query_serv.password in config.yaml");
		return false;
	}

	if (!_root["query_serv"]["db"].IsNull()) {
		if (_root["query_serv"]["db"].Type() != YAML::NodeType::Scalar) {
			LogError("Query_serv.db must be a string");
			return false;
		}
		QSDatabaseDB = _root["query_serv"]["db"].as<std::string>();
	} else {
		LogError("Missing query_serv.db in config.yaml");
		return false;
	}

	if (!_root["query_serv"]["port"].IsNull()) {
		if (_root["query_serv"]["port"].Type() != YAML::NodeType::Scalar) {
			LogError("Query_serv.port must be a number");
			return false;
		}
		QSDatabasePort = _root["query_serv"]["port"].as<uint16_t>();
	} else {
		LogError("Missing query_serv.port in config.yaml");
		return false;
	}

	if (!_root["zone"]["default_status"].IsNull()) {
		if (_root["zone"]["default_status"].Type() != YAML::NodeType::Scalar) {
			LogError("Zone.default_status must be a number");
			return false;
		}
		DefaultStatus = _root["zone"]["default_status"].as<uint8_t>();
	} else {
		DefaultStatus = 0;
	}

	if (!_root["zone"]["port_min"].IsNull()) {
		if (_root["zone"]["port_min"].Type() != YAML::NodeType::Scalar) {
			LogError("Zone.port_min must be a number");
			return false;
		}
		ZonePortLow = _root["zone"]["port_min"].as<uint16_t>();
	} else {
		ZonePortLow = 7000;
	}

	if (!_root["zone"]["port_max"].IsNull()) {
		if (_root["zone"]["port_max"].Type() != YAML::NodeType::Scalar) {
			LogError("Zone.port_max must be a number");
			return false;
		}
		ZonePortHigh = _root["zone"]["port_max"].as<uint16_t>();
	} else {
		ZonePortHigh = 7400;
	}

	if (!_root["dir"]["maps"].IsNull()) {
		if (_root["dir"]["maps"].Type() != YAML::NodeType::Scalar) {
			LogError("Dir.maps must be a string");
			return false;
		}
		MapDir = _root["dir"]["maps"].as<std::string>();
	} else {
		MapDir = "maps/";
	}

	if (!_root["dir"]["logs"].IsNull()) {
		if (_root["dir"]["logs"].Type() != YAML::NodeType::Scalar) {
			LogError("Dir.logs must be a string");
			return false;
		}
		LogDir = _root["dir"]["logs"].as<std::string>();
	} else {
		LogDir = "logs/";
	}

	if (!_root["dir"]["lua_modules"].IsNull()) {
		if (_root["dir"]["lua_modules"].Type() != YAML::NodeType::Scalar) {
			LogError("Dir.lua_modules must be a string");
			return false;
		}
		LuaModuleDir = _root["dir"]["lua_modules"].as<std::string>();
	} else {
		LuaModuleDir = "quests/lua_modules/";
	}

	if (!_root["dir"]["quests"].IsNull()) {
		if (_root["dir"]["quests"].Type() != YAML::NodeType::Scalar) {
			LogError("Dir.quests must be a string");
			return false;
		}
		QuestDir = _root["dir"]["quests"].as<std::string>();
	} else {
		QuestDir = "quests/";
	}

	if (!_root["dir"]["patches"].IsNull()) {
		if (_root["dir"]["patches"].Type() != YAML::NodeType::Scalar) {
			LogError("Dir.patches must be a string");
			return false;
		}
		PatchDir = _root["dir"]["patches"].as<std::string>();
	} else {
		PatchDir = "assets/patches/";
	}

	if (!_root["dir"]["shared_memory"].IsNull()) {
		if (_root["dir"]["shared_memory"].Type() != YAML::NodeType::Scalar) {
			LogError("Dir.shared_memory must be a string");
			return false;
		}
		SharedMemDir = _root["dir"]["shared_memory"].as<std::string>();
	} else {
		SharedMemDir = "shared/";
	}
	return true;
}

std::string Config::GetByName(const std::string &var_name) const {
	if (var_name == "ShortName") {
		return (ShortName);
	}
	if (var_name == "LongName") {
		return (LongName);
	}
	if (var_name == "WorldAddress") {
		return (WorldAddress);
	}
	if (var_name == "LoginHost") {
		return (LoginHost);
	}
	if (var_name == "LoginAccount") {
		return (LoginAccount);
	}
	if (var_name == "LoginPassword") {
		return (LoginPassword);
	}
	if (var_name == "LoginPort") {
		return (itoa(LoginPort));
	}
	if (var_name == "Locked") {
		return (Locked ? "true" : "false");
	}
	if (var_name == "WorldTCPPort") {
		return (itoa(WorldTCPPort));
	}
	if (var_name == "WorldIP") {
		return (WorldIP);
	}
	if (var_name == "TelnetEnabled") {
		return (TelnetEnabled ? "true" : "false");
	}
	if (var_name == "UCSHost") {
		return (UCSHost);
	}
	if (var_name == "UCSPort") {
		return (itoa(UCSPort));
	}
	if (var_name == "DatabaseHost") {
		return (DatabaseHost);
	}
	if (var_name == "DatabaseUsername") {
		return (DatabaseUsername);
	}
	if (var_name == "DatabasePassword") {
		return (DatabasePassword);
	}
	if (var_name == "DatabaseDB") {
		return (DatabaseDB);
	}
	if (var_name == "DatabasePort") {
		return (itoa(DatabasePort));
	}
	if (var_name == "QSDatabaseHost") {
		return (QSDatabaseHost);
	}
	if (var_name == "QSDatabaseUsername") {
		return (QSDatabaseUsername);
	}
	if (var_name == "QSDatabasePassword") {
		return (QSDatabasePassword);
	}
	if (var_name == "QSDatabaseDB") {
		return (QSDatabaseDB);
	}
	if (var_name == "QSDatabasePort") {
		return (itoa(QSDatabasePort));
	}
	if (var_name == "MapDir") {
		return (MapDir);
	}
	if (var_name == "QuestDir") {
		return (QuestDir);
	}
	if (var_name == "LuaModuleDir") {
		return (LuaModuleDir);
	}
	if (var_name == "PatchDir") {
		return (PatchDir);
	}
	if (var_name == "SharedMemDir") {
		return (SharedMemDir);
	}
	if (var_name == "LogDir") {
		return (LogDir);
	}
	if (var_name == "ZonePortLow") {
		return (itoa(ZonePortLow));
	}
	if (var_name == "ZonePortHigh") {
		return (itoa(ZonePortHigh));
	}
	if (var_name == "DefaultStatus") {
		return (itoa(DefaultStatus));
	}
	//	if(var_name == "DynamicCount")
	//		return(itoa(DynamicCount));
	return ("");
}

void Config::Dump() const {
	std::cout << "ShortName = " << ShortName << std::endl;
	std::cout << "LongName = " << LongName << std::endl;
	std::cout << "WorldAddress = " << WorldAddress << std::endl;
	std::cout << "LoginHost = " << LoginHost << std::endl;
	std::cout << "LoginAccount = " << LoginAccount << std::endl;
	std::cout << "LoginPassword = " << LoginPassword << std::endl;
	std::cout << "LoginPort = " << LoginPort << std::endl;
	std::cout << "LoginType = " << LoginType << std::endl;
	std::cout << "Locked = " << Locked << std::endl;
	std::cout << "WorldTCPPort = " << WorldTCPPort << std::endl;
	std::cout << "WorldIP = " << WorldIP << std::endl;
	std::cout << "TelnetEnabled = " << TelnetEnabled << std::endl;
	std::cout << "UCSHost = " << UCSHost << std::endl;
	std::cout << "UCSPort = " << UCSPort << std::endl;
	std::cout << "DatabaseHost = " << DatabaseHost << std::endl;
	std::cout << "DatabaseUsername = " << DatabaseUsername << std::endl;
	std::cout << "DatabasePassword = " << DatabasePassword << std::endl;
	std::cout << "DatabaseDB = " << DatabaseDB << std::endl;
	std::cout << "DatabasePort = " << DatabasePort << std::endl;
	std::cout << "QSDatabaseHost = " << QSDatabaseHost << std::endl;
	std::cout << "QSDatabaseUsername = " << QSDatabaseUsername << std::endl;
	std::cout << "QSDatabasePassword = " << QSDatabasePassword << std::endl;
	std::cout << "QSDatabaseDB = " << QSDatabaseDB << std::endl;
	std::cout << "QSDatabasePort = " << QSDatabasePort << std::endl;
	std::cout << "MapDir = " << MapDir << std::endl;
	std::cout << "QuestDir = " << QuestDir << std::endl;
	std::cout << "LuaModuleDir = " << LuaModuleDir << std::endl;
	std::cout << "PatchDir = " << PatchDir << std::endl;
	std::cout << "SharedMemDir = " << SharedMemDir << std::endl;
	std::cout << "LogDir = " << LogDir << std::endl;
	std::cout << "ZonePortLow = " << ZonePortLow << std::endl;
	std::cout << "ZonePortHigh = " << ZonePortHigh << std::endl;
	std::cout << "DefaultStatus = " << (int)DefaultStatus << std::endl;
}
