# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/server/build

# Include any dependencies generated for this target.
include shared_memory/CMakeFiles/shared_memory.dir/depend.make

# Include the progress variables for this target.
include shared_memory/CMakeFiles/shared_memory.dir/progress.make

# Include the compile flags for this target's objects.
include shared_memory/CMakeFiles/shared_memory.dir/flags.make

shared_memory/CMakeFiles/shared_memory.dir/base_data.cpp.o: shared_memory/CMakeFiles/shared_memory.dir/flags.make
shared_memory/CMakeFiles/shared_memory.dir/base_data.cpp.o: ../shared_memory/base_data.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object shared_memory/CMakeFiles/shared_memory.dir/base_data.cpp.o"
	cd /workspaces/server/build/shared_memory && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shared_memory.dir/base_data.cpp.o -c /workspaces/server/shared_memory/base_data.cpp

shared_memory/CMakeFiles/shared_memory.dir/base_data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shared_memory.dir/base_data.cpp.i"
	cd /workspaces/server/build/shared_memory && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/server/shared_memory/base_data.cpp > CMakeFiles/shared_memory.dir/base_data.cpp.i

shared_memory/CMakeFiles/shared_memory.dir/base_data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shared_memory.dir/base_data.cpp.s"
	cd /workspaces/server/build/shared_memory && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/server/shared_memory/base_data.cpp -o CMakeFiles/shared_memory.dir/base_data.cpp.s

shared_memory/CMakeFiles/shared_memory.dir/items.cpp.o: shared_memory/CMakeFiles/shared_memory.dir/flags.make
shared_memory/CMakeFiles/shared_memory.dir/items.cpp.o: ../shared_memory/items.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object shared_memory/CMakeFiles/shared_memory.dir/items.cpp.o"
	cd /workspaces/server/build/shared_memory && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shared_memory.dir/items.cpp.o -c /workspaces/server/shared_memory/items.cpp

shared_memory/CMakeFiles/shared_memory.dir/items.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shared_memory.dir/items.cpp.i"
	cd /workspaces/server/build/shared_memory && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/server/shared_memory/items.cpp > CMakeFiles/shared_memory.dir/items.cpp.i

shared_memory/CMakeFiles/shared_memory.dir/items.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shared_memory.dir/items.cpp.s"
	cd /workspaces/server/build/shared_memory && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/server/shared_memory/items.cpp -o CMakeFiles/shared_memory.dir/items.cpp.s

shared_memory/CMakeFiles/shared_memory.dir/loot.cpp.o: shared_memory/CMakeFiles/shared_memory.dir/flags.make
shared_memory/CMakeFiles/shared_memory.dir/loot.cpp.o: ../shared_memory/loot.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object shared_memory/CMakeFiles/shared_memory.dir/loot.cpp.o"
	cd /workspaces/server/build/shared_memory && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shared_memory.dir/loot.cpp.o -c /workspaces/server/shared_memory/loot.cpp

shared_memory/CMakeFiles/shared_memory.dir/loot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shared_memory.dir/loot.cpp.i"
	cd /workspaces/server/build/shared_memory && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/server/shared_memory/loot.cpp > CMakeFiles/shared_memory.dir/loot.cpp.i

shared_memory/CMakeFiles/shared_memory.dir/loot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shared_memory.dir/loot.cpp.s"
	cd /workspaces/server/build/shared_memory && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/server/shared_memory/loot.cpp -o CMakeFiles/shared_memory.dir/loot.cpp.s

shared_memory/CMakeFiles/shared_memory.dir/main.cpp.o: shared_memory/CMakeFiles/shared_memory.dir/flags.make
shared_memory/CMakeFiles/shared_memory.dir/main.cpp.o: ../shared_memory/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object shared_memory/CMakeFiles/shared_memory.dir/main.cpp.o"
	cd /workspaces/server/build/shared_memory && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shared_memory.dir/main.cpp.o -c /workspaces/server/shared_memory/main.cpp

shared_memory/CMakeFiles/shared_memory.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shared_memory.dir/main.cpp.i"
	cd /workspaces/server/build/shared_memory && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/server/shared_memory/main.cpp > CMakeFiles/shared_memory.dir/main.cpp.i

shared_memory/CMakeFiles/shared_memory.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shared_memory.dir/main.cpp.s"
	cd /workspaces/server/build/shared_memory && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/server/shared_memory/main.cpp -o CMakeFiles/shared_memory.dir/main.cpp.s

shared_memory/CMakeFiles/shared_memory.dir/npc_faction.cpp.o: shared_memory/CMakeFiles/shared_memory.dir/flags.make
shared_memory/CMakeFiles/shared_memory.dir/npc_faction.cpp.o: ../shared_memory/npc_faction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object shared_memory/CMakeFiles/shared_memory.dir/npc_faction.cpp.o"
	cd /workspaces/server/build/shared_memory && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shared_memory.dir/npc_faction.cpp.o -c /workspaces/server/shared_memory/npc_faction.cpp

shared_memory/CMakeFiles/shared_memory.dir/npc_faction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shared_memory.dir/npc_faction.cpp.i"
	cd /workspaces/server/build/shared_memory && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/server/shared_memory/npc_faction.cpp > CMakeFiles/shared_memory.dir/npc_faction.cpp.i

shared_memory/CMakeFiles/shared_memory.dir/npc_faction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shared_memory.dir/npc_faction.cpp.s"
	cd /workspaces/server/build/shared_memory && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/server/shared_memory/npc_faction.cpp -o CMakeFiles/shared_memory.dir/npc_faction.cpp.s

shared_memory/CMakeFiles/shared_memory.dir/spells.cpp.o: shared_memory/CMakeFiles/shared_memory.dir/flags.make
shared_memory/CMakeFiles/shared_memory.dir/spells.cpp.o: ../shared_memory/spells.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object shared_memory/CMakeFiles/shared_memory.dir/spells.cpp.o"
	cd /workspaces/server/build/shared_memory && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shared_memory.dir/spells.cpp.o -c /workspaces/server/shared_memory/spells.cpp

shared_memory/CMakeFiles/shared_memory.dir/spells.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shared_memory.dir/spells.cpp.i"
	cd /workspaces/server/build/shared_memory && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/server/shared_memory/spells.cpp > CMakeFiles/shared_memory.dir/spells.cpp.i

shared_memory/CMakeFiles/shared_memory.dir/spells.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shared_memory.dir/spells.cpp.s"
	cd /workspaces/server/build/shared_memory && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/server/shared_memory/spells.cpp -o CMakeFiles/shared_memory.dir/spells.cpp.s

shared_memory/CMakeFiles/shared_memory.dir/skill_caps.cpp.o: shared_memory/CMakeFiles/shared_memory.dir/flags.make
shared_memory/CMakeFiles/shared_memory.dir/skill_caps.cpp.o: ../shared_memory/skill_caps.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object shared_memory/CMakeFiles/shared_memory.dir/skill_caps.cpp.o"
	cd /workspaces/server/build/shared_memory && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shared_memory.dir/skill_caps.cpp.o -c /workspaces/server/shared_memory/skill_caps.cpp

shared_memory/CMakeFiles/shared_memory.dir/skill_caps.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shared_memory.dir/skill_caps.cpp.i"
	cd /workspaces/server/build/shared_memory && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/server/shared_memory/skill_caps.cpp > CMakeFiles/shared_memory.dir/skill_caps.cpp.i

shared_memory/CMakeFiles/shared_memory.dir/skill_caps.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shared_memory.dir/skill_caps.cpp.s"
	cd /workspaces/server/build/shared_memory && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/server/shared_memory/skill_caps.cpp -o CMakeFiles/shared_memory.dir/skill_caps.cpp.s

# Object files for target shared_memory
shared_memory_OBJECTS = \
"CMakeFiles/shared_memory.dir/base_data.cpp.o" \
"CMakeFiles/shared_memory.dir/items.cpp.o" \
"CMakeFiles/shared_memory.dir/loot.cpp.o" \
"CMakeFiles/shared_memory.dir/main.cpp.o" \
"CMakeFiles/shared_memory.dir/npc_faction.cpp.o" \
"CMakeFiles/shared_memory.dir/spells.cpp.o" \
"CMakeFiles/shared_memory.dir/skill_caps.cpp.o"

# External object files for target shared_memory
shared_memory_EXTERNAL_OBJECTS =

bin/shared_memory: shared_memory/CMakeFiles/shared_memory.dir/base_data.cpp.o
bin/shared_memory: shared_memory/CMakeFiles/shared_memory.dir/items.cpp.o
bin/shared_memory: shared_memory/CMakeFiles/shared_memory.dir/loot.cpp.o
bin/shared_memory: shared_memory/CMakeFiles/shared_memory.dir/main.cpp.o
bin/shared_memory: shared_memory/CMakeFiles/shared_memory.dir/npc_faction.cpp.o
bin/shared_memory: shared_memory/CMakeFiles/shared_memory.dir/spells.cpp.o
bin/shared_memory: shared_memory/CMakeFiles/shared_memory.dir/skill_caps.cpp.o
bin/shared_memory: shared_memory/CMakeFiles/shared_memory.dir/build.make
bin/shared_memory: bin/libcommon.a
bin/shared_memory: /usr/lib/x86_64-linux-gnu/libmysqlclient.so
bin/shared_memory: /usr/lib/x86_64-linux-gnu/libmysqlclient.so
bin/shared_memory: libs/zlibng/libz-ng.a
bin/shared_memory: submodules/libuv/libuv_a.a
bin/shared_memory: submodules/fmt/libfmtd.a
bin/shared_memory: submodules/recastnavigation/Detour/libDetour.a
bin/shared_memory: /usr/lib/x86_64-linux-gnu/libcurl.so
bin/shared_memory: /usr/lib/x86_64-linux-gnu/libssl.so
bin/shared_memory: /usr/lib/x86_64-linux-gnu/libcrypto.so
bin/shared_memory: /usr/lib/x86_64-linux-gnu/liblua5.1.so
bin/shared_memory: bin/libluabind.a
bin/shared_memory: shared_memory/CMakeFiles/shared_memory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable ../bin/shared_memory"
	cd /workspaces/server/build/shared_memory && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shared_memory.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
shared_memory/CMakeFiles/shared_memory.dir/build: bin/shared_memory

.PHONY : shared_memory/CMakeFiles/shared_memory.dir/build

shared_memory/CMakeFiles/shared_memory.dir/clean:
	cd /workspaces/server/build/shared_memory && $(CMAKE_COMMAND) -P CMakeFiles/shared_memory.dir/cmake_clean.cmake
.PHONY : shared_memory/CMakeFiles/shared_memory.dir/clean

shared_memory/CMakeFiles/shared_memory.dir/depend:
	cd /workspaces/server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/server /workspaces/server/shared_memory /workspaces/server/build /workspaces/server/build/shared_memory /workspaces/server/build/shared_memory/CMakeFiles/shared_memory.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : shared_memory/CMakeFiles/shared_memory.dir/depend

