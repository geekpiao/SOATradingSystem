# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/A-Files/baruch/Courseworks/MTH 9815 Software Engineering/mth9815-master/tradingsystem"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/A-Files/baruch/Courseworks/MTH 9815 Software Engineering/mth9815-master/tradingsystem"

# Include any dependencies generated for this target.
include CMakeFiles/tradingsystem.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tradingsystem.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tradingsystem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tradingsystem.dir/flags.make

CMakeFiles/tradingsystem.dir/main.cpp.o: CMakeFiles/tradingsystem.dir/flags.make
CMakeFiles/tradingsystem.dir/main.cpp.o: main.cpp
CMakeFiles/tradingsystem.dir/main.cpp.o: CMakeFiles/tradingsystem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/A-Files/baruch/Courseworks/MTH 9815 Software Engineering/mth9815-master/tradingsystem/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tradingsystem.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tradingsystem.dir/main.cpp.o -MF CMakeFiles/tradingsystem.dir/main.cpp.o.d -o CMakeFiles/tradingsystem.dir/main.cpp.o -c "/mnt/c/A-Files/baruch/Courseworks/MTH 9815 Software Engineering/mth9815-master/tradingsystem/main.cpp"

CMakeFiles/tradingsystem.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tradingsystem.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/A-Files/baruch/Courseworks/MTH 9815 Software Engineering/mth9815-master/tradingsystem/main.cpp" > CMakeFiles/tradingsystem.dir/main.cpp.i

CMakeFiles/tradingsystem.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tradingsystem.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/A-Files/baruch/Courseworks/MTH 9815 Software Engineering/mth9815-master/tradingsystem/main.cpp" -o CMakeFiles/tradingsystem.dir/main.cpp.s

# Object files for target tradingsystem
tradingsystem_OBJECTS = \
"CMakeFiles/tradingsystem.dir/main.cpp.o"

# External object files for target tradingsystem
tradingsystem_EXTERNAL_OBJECTS =

tradingsystem: CMakeFiles/tradingsystem.dir/main.cpp.o
tradingsystem: CMakeFiles/tradingsystem.dir/build.make
tradingsystem: CMakeFiles/tradingsystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/A-Files/baruch/Courseworks/MTH 9815 Software Engineering/mth9815-master/tradingsystem/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tradingsystem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tradingsystem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tradingsystem.dir/build: tradingsystem
.PHONY : CMakeFiles/tradingsystem.dir/build

CMakeFiles/tradingsystem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tradingsystem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tradingsystem.dir/clean

CMakeFiles/tradingsystem.dir/depend:
	cd "/mnt/c/A-Files/baruch/Courseworks/MTH 9815 Software Engineering/mth9815-master/tradingsystem" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/A-Files/baruch/Courseworks/MTH 9815 Software Engineering/mth9815-master/tradingsystem" "/mnt/c/A-Files/baruch/Courseworks/MTH 9815 Software Engineering/mth9815-master/tradingsystem" "/mnt/c/A-Files/baruch/Courseworks/MTH 9815 Software Engineering/mth9815-master/tradingsystem" "/mnt/c/A-Files/baruch/Courseworks/MTH 9815 Software Engineering/mth9815-master/tradingsystem" "/mnt/c/A-Files/baruch/Courseworks/MTH 9815 Software Engineering/mth9815-master/tradingsystem/CMakeFiles/tradingsystem.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/tradingsystem.dir/depend

