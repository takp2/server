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
include queryserv/CMakeFiles/queryserv.dir/depend.make

# Include the progress variables for this target.
include queryserv/CMakeFiles/queryserv.dir/progress.make

# Include the compile flags for this target's objects.
include queryserv/CMakeFiles/queryserv.dir/flags.make

queryserv/CMakeFiles/queryserv.dir/database.cpp.o: queryserv/CMakeFiles/queryserv.dir/flags.make
queryserv/CMakeFiles/queryserv.dir/database.cpp.o: ../queryserv/database.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object queryserv/CMakeFiles/queryserv.dir/database.cpp.o"
	cd /workspaces/server/build/queryserv && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/queryserv.dir/database.cpp.o -c /workspaces/server/queryserv/database.cpp

queryserv/CMakeFiles/queryserv.dir/database.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/queryserv.dir/database.cpp.i"
	cd /workspaces/server/build/queryserv && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/server/queryserv/database.cpp > CMakeFiles/queryserv.dir/database.cpp.i

queryserv/CMakeFiles/queryserv.dir/database.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/queryserv.dir/database.cpp.s"
	cd /workspaces/server/build/queryserv && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/server/queryserv/database.cpp -o CMakeFiles/queryserv.dir/database.cpp.s

queryserv/CMakeFiles/queryserv.dir/dbupdate.cpp.o: queryserv/CMakeFiles/queryserv.dir/flags.make
queryserv/CMakeFiles/queryserv.dir/dbupdate.cpp.o: ../queryserv/dbupdate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object queryserv/CMakeFiles/queryserv.dir/dbupdate.cpp.o"
	cd /workspaces/server/build/queryserv && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/queryserv.dir/dbupdate.cpp.o -c /workspaces/server/queryserv/dbupdate.cpp

queryserv/CMakeFiles/queryserv.dir/dbupdate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/queryserv.dir/dbupdate.cpp.i"
	cd /workspaces/server/build/queryserv && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/server/queryserv/dbupdate.cpp > CMakeFiles/queryserv.dir/dbupdate.cpp.i

queryserv/CMakeFiles/queryserv.dir/dbupdate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/queryserv.dir/dbupdate.cpp.s"
	cd /workspaces/server/build/queryserv && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/server/queryserv/dbupdate.cpp -o CMakeFiles/queryserv.dir/dbupdate.cpp.s

queryserv/CMakeFiles/queryserv.dir/queryserv.cpp.o: queryserv/CMakeFiles/queryserv.dir/flags.make
queryserv/CMakeFiles/queryserv.dir/queryserv.cpp.o: ../queryserv/queryserv.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object queryserv/CMakeFiles/queryserv.dir/queryserv.cpp.o"
	cd /workspaces/server/build/queryserv && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/queryserv.dir/queryserv.cpp.o -c /workspaces/server/queryserv/queryserv.cpp

queryserv/CMakeFiles/queryserv.dir/queryserv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/queryserv.dir/queryserv.cpp.i"
	cd /workspaces/server/build/queryserv && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/server/queryserv/queryserv.cpp > CMakeFiles/queryserv.dir/queryserv.cpp.i

queryserv/CMakeFiles/queryserv.dir/queryserv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/queryserv.dir/queryserv.cpp.s"
	cd /workspaces/server/build/queryserv && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/server/queryserv/queryserv.cpp -o CMakeFiles/queryserv.dir/queryserv.cpp.s

queryserv/CMakeFiles/queryserv.dir/queryservconfig.cpp.o: queryserv/CMakeFiles/queryserv.dir/flags.make
queryserv/CMakeFiles/queryserv.dir/queryservconfig.cpp.o: ../queryserv/queryservconfig.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object queryserv/CMakeFiles/queryserv.dir/queryservconfig.cpp.o"
	cd /workspaces/server/build/queryserv && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/queryserv.dir/queryservconfig.cpp.o -c /workspaces/server/queryserv/queryservconfig.cpp

queryserv/CMakeFiles/queryserv.dir/queryservconfig.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/queryserv.dir/queryservconfig.cpp.i"
	cd /workspaces/server/build/queryserv && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/server/queryserv/queryservconfig.cpp > CMakeFiles/queryserv.dir/queryservconfig.cpp.i

queryserv/CMakeFiles/queryserv.dir/queryservconfig.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/queryserv.dir/queryservconfig.cpp.s"
	cd /workspaces/server/build/queryserv && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/server/queryserv/queryservconfig.cpp -o CMakeFiles/queryserv.dir/queryservconfig.cpp.s

queryserv/CMakeFiles/queryserv.dir/worldserver.cpp.o: queryserv/CMakeFiles/queryserv.dir/flags.make
queryserv/CMakeFiles/queryserv.dir/worldserver.cpp.o: ../queryserv/worldserver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object queryserv/CMakeFiles/queryserv.dir/worldserver.cpp.o"
	cd /workspaces/server/build/queryserv && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/queryserv.dir/worldserver.cpp.o -c /workspaces/server/queryserv/worldserver.cpp

queryserv/CMakeFiles/queryserv.dir/worldserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/queryserv.dir/worldserver.cpp.i"
	cd /workspaces/server/build/queryserv && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/server/queryserv/worldserver.cpp > CMakeFiles/queryserv.dir/worldserver.cpp.i

queryserv/CMakeFiles/queryserv.dir/worldserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/queryserv.dir/worldserver.cpp.s"
	cd /workspaces/server/build/queryserv && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/server/queryserv/worldserver.cpp -o CMakeFiles/queryserv.dir/worldserver.cpp.s

# Object files for target queryserv
queryserv_OBJECTS = \
"CMakeFiles/queryserv.dir/database.cpp.o" \
"CMakeFiles/queryserv.dir/dbupdate.cpp.o" \
"CMakeFiles/queryserv.dir/queryserv.cpp.o" \
"CMakeFiles/queryserv.dir/queryservconfig.cpp.o" \
"CMakeFiles/queryserv.dir/worldserver.cpp.o"

# External object files for target queryserv
queryserv_EXTERNAL_OBJECTS =

bin/queryserv: queryserv/CMakeFiles/queryserv.dir/database.cpp.o
bin/queryserv: queryserv/CMakeFiles/queryserv.dir/dbupdate.cpp.o
bin/queryserv: queryserv/CMakeFiles/queryserv.dir/queryserv.cpp.o
bin/queryserv: queryserv/CMakeFiles/queryserv.dir/queryservconfig.cpp.o
bin/queryserv: queryserv/CMakeFiles/queryserv.dir/worldserver.cpp.o
bin/queryserv: queryserv/CMakeFiles/queryserv.dir/build.make
bin/queryserv: bin/libcommon.a
bin/queryserv: /usr/lib/x86_64-linux-gnu/libmysqlclient.so
bin/queryserv: /usr/lib/x86_64-linux-gnu/libmysqlclient.so
bin/queryserv: libs/zlibng/libz-ng.a
bin/queryserv: submodules/libuv/libuv_a.a
bin/queryserv: submodules/fmt/libfmtd.a
bin/queryserv: submodules/recastnavigation/Detour/libDetour.a
bin/queryserv: /usr/lib/x86_64-linux-gnu/libcurl.so
bin/queryserv: /usr/lib/x86_64-linux-gnu/libssl.so
bin/queryserv: /usr/lib/x86_64-linux-gnu/libcrypto.so
bin/queryserv: /usr/lib/x86_64-linux-gnu/liblua5.1.so
bin/queryserv: bin/libluabind.a
bin/queryserv: queryserv/CMakeFiles/queryserv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ../bin/queryserv"
	cd /workspaces/server/build/queryserv && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/queryserv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
queryserv/CMakeFiles/queryserv.dir/build: bin/queryserv

.PHONY : queryserv/CMakeFiles/queryserv.dir/build

queryserv/CMakeFiles/queryserv.dir/clean:
	cd /workspaces/server/build/queryserv && $(CMAKE_COMMAND) -P CMakeFiles/queryserv.dir/cmake_clean.cmake
.PHONY : queryserv/CMakeFiles/queryserv.dir/clean

queryserv/CMakeFiles/queryserv.dir/depend:
	cd /workspaces/server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/server /workspaces/server/queryserv /workspaces/server/build /workspaces/server/build/queryserv /workspaces/server/build/queryserv/CMakeFiles/queryserv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : queryserv/CMakeFiles/queryserv.dir/depend

