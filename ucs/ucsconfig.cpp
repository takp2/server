#include "ucsconfig.h"

#include "../common/global_define.h"

ucsconfig *ucsconfig::_chat_config = nullptr;

std::string ucsconfig::GetByName(const std::string &var_name) const {
	return (Config::GetByName(var_name));
}
