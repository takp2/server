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
include submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/depend.make

# Include the progress variables for this target.
include submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/progress.make

# Include the compile flags for this target's objects.
include submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/flags.make

submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/Source/DebugDraw.cpp.o: submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/flags.make
submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/Source/DebugDraw.cpp.o: ../submodules/recastnavigation/DebugUtils/Source/DebugDraw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/Source/DebugDraw.cpp.o"
	cd /workspaces/server/build/submodules/recastnavigation/DebugUtils && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DebugUtils.dir/Source/DebugDraw.cpp.o -c /workspaces/server/submodules/recastnavigation/DebugUtils/Source/DebugDraw.cpp

submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/Source/DebugDraw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DebugUtils.dir/Source/DebugDraw.cpp.i"
	cd /workspaces/server/build/submodules/recastnavigation/DebugUtils && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/server/submodules/recastnavigation/DebugUtils/Source/DebugDraw.cpp > CMakeFiles/DebugUtils.dir/Source/DebugDraw.cpp.i

submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/Source/DebugDraw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DebugUtils.dir/Source/DebugDraw.cpp.s"
	cd /workspaces/server/build/submodules/recastnavigation/DebugUtils && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/server/submodules/recastnavigation/DebugUtils/Source/DebugDraw.cpp -o CMakeFiles/DebugUtils.dir/Source/DebugDraw.cpp.s

submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/Source/DetourDebugDraw.cpp.o: submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/flags.make
submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/Source/DetourDebugDraw.cpp.o: ../submodules/recastnavigation/DebugUtils/Source/DetourDebugDraw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/Source/DetourDebugDraw.cpp.o"
	cd /workspaces/server/build/submodules/recastnavigation/DebugUtils && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DebugUtils.dir/Source/DetourDebugDraw.cpp.o -c /workspaces/server/submodules/recastnavigation/DebugUtils/Source/DetourDebugDraw.cpp

submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/Source/DetourDebugDraw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DebugUtils.dir/Source/DetourDebugDraw.cpp.i"
	cd /workspaces/server/build/submodules/recastnavigation/DebugUtils && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/server/submodules/recastnavigation/DebugUtils/Source/DetourDebugDraw.cpp > CMakeFiles/DebugUtils.dir/Source/DetourDebugDraw.cpp.i

submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/Source/DetourDebugDraw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DebugUtils.dir/Source/DetourDebugDraw.cpp.s"
	cd /workspaces/server/build/submodules/recastnavigation/DebugUtils && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/server/submodules/recastnavigation/DebugUtils/Source/DetourDebugDraw.cpp -o CMakeFiles/DebugUtils.dir/Source/DetourDebugDraw.cpp.s

submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/Source/RecastDebugDraw.cpp.o: submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/flags.make
submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/Source/RecastDebugDraw.cpp.o: ../submodules/recastnavigation/DebugUtils/Source/RecastDebugDraw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/Source/RecastDebugDraw.cpp.o"
	cd /workspaces/server/build/submodules/recastnavigation/DebugUtils && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DebugUtils.dir/Source/RecastDebugDraw.cpp.o -c /workspaces/server/submodules/recastnavigation/DebugUtils/Source/RecastDebugDraw.cpp

submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/Source/RecastDebugDraw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DebugUtils.dir/Source/RecastDebugDraw.cpp.i"
	cd /workspaces/server/build/submodules/recastnavigation/DebugUtils && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/server/submodules/recastnavigation/DebugUtils/Source/RecastDebugDraw.cpp > CMakeFiles/DebugUtils.dir/Source/RecastDebugDraw.cpp.i

submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/Source/RecastDebugDraw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DebugUtils.dir/Source/RecastDebugDraw.cpp.s"
	cd /workspaces/server/build/submodules/recastnavigation/DebugUtils && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/server/submodules/recastnavigation/DebugUtils/Source/RecastDebugDraw.cpp -o CMakeFiles/DebugUtils.dir/Source/RecastDebugDraw.cpp.s

submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/Source/RecastDump.cpp.o: submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/flags.make
submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/Source/RecastDump.cpp.o: ../submodules/recastnavigation/DebugUtils/Source/RecastDump.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/Source/RecastDump.cpp.o"
	cd /workspaces/server/build/submodules/recastnavigation/DebugUtils && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DebugUtils.dir/Source/RecastDump.cpp.o -c /workspaces/server/submodules/recastnavigation/DebugUtils/Source/RecastDump.cpp

submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/Source/RecastDump.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DebugUtils.dir/Source/RecastDump.cpp.i"
	cd /workspaces/server/build/submodules/recastnavigation/DebugUtils && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/server/submodules/recastnavigation/DebugUtils/Source/RecastDump.cpp > CMakeFiles/DebugUtils.dir/Source/RecastDump.cpp.i

submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/Source/RecastDump.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DebugUtils.dir/Source/RecastDump.cpp.s"
	cd /workspaces/server/build/submodules/recastnavigation/DebugUtils && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/server/submodules/recastnavigation/DebugUtils/Source/RecastDump.cpp -o CMakeFiles/DebugUtils.dir/Source/RecastDump.cpp.s

# Object files for target DebugUtils
DebugUtils_OBJECTS = \
"CMakeFiles/DebugUtils.dir/Source/DebugDraw.cpp.o" \
"CMakeFiles/DebugUtils.dir/Source/DetourDebugDraw.cpp.o" \
"CMakeFiles/DebugUtils.dir/Source/RecastDebugDraw.cpp.o" \
"CMakeFiles/DebugUtils.dir/Source/RecastDump.cpp.o"

# External object files for target DebugUtils
DebugUtils_EXTERNAL_OBJECTS =

submodules/recastnavigation/DebugUtils/libDebugUtils.a: submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/Source/DebugDraw.cpp.o
submodules/recastnavigation/DebugUtils/libDebugUtils.a: submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/Source/DetourDebugDraw.cpp.o
submodules/recastnavigation/DebugUtils/libDebugUtils.a: submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/Source/RecastDebugDraw.cpp.o
submodules/recastnavigation/DebugUtils/libDebugUtils.a: submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/Source/RecastDump.cpp.o
submodules/recastnavigation/DebugUtils/libDebugUtils.a: submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/build.make
submodules/recastnavigation/DebugUtils/libDebugUtils.a: submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libDebugUtils.a"
	cd /workspaces/server/build/submodules/recastnavigation/DebugUtils && $(CMAKE_COMMAND) -P CMakeFiles/DebugUtils.dir/cmake_clean_target.cmake
	cd /workspaces/server/build/submodules/recastnavigation/DebugUtils && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DebugUtils.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/build: submodules/recastnavigation/DebugUtils/libDebugUtils.a

.PHONY : submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/build

submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/clean:
	cd /workspaces/server/build/submodules/recastnavigation/DebugUtils && $(CMAKE_COMMAND) -P CMakeFiles/DebugUtils.dir/cmake_clean.cmake
.PHONY : submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/clean

submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/depend:
	cd /workspaces/server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/server /workspaces/server/submodules/recastnavigation/DebugUtils /workspaces/server/build /workspaces/server/build/submodules/recastnavigation/DebugUtils /workspaces/server/build/submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : submodules/recastnavigation/DebugUtils/CMakeFiles/DebugUtils.dir/depend

