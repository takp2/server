#include "process.h"

#include <memory>
#include <string>

std::string Process::execute(const std::string &cmd) {
	std::shared_ptr<FILE> pipe(popen(cmd.c_str(), "r"), pclose);
	if (!pipe) {
		return "ERROR";
	}
	char buffer[128];
	std::string result;
	while (!feof(pipe.get())) {
		if (fgets(buffer, 128, pipe.get()) != nullptr) {
			result += buffer;
		}
	}

	return result;
}
