# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Ida\Desktop\algoritmi\Algoritmi & Strutture Dati\Strutture dati\mergeList"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Ida\Desktop\algoritmi\Algoritmi & Strutture Dati\Strutture dati\mergeList\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/mergeList.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mergeList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mergeList.dir/flags.make

CMakeFiles/mergeList.dir/main.c.obj: CMakeFiles/mergeList.dir/flags.make
CMakeFiles/mergeList.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Ida\Desktop\algoritmi\Algoritmi & Strutture Dati\Strutture dati\mergeList\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/mergeList.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\mergeList.dir\main.c.obj   -c "C:\Users\Ida\Desktop\algoritmi\Algoritmi & Strutture Dati\Strutture dati\mergeList\main.c"

CMakeFiles/mergeList.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mergeList.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Ida\Desktop\algoritmi\Algoritmi & Strutture Dati\Strutture dati\mergeList\main.c" > CMakeFiles\mergeList.dir\main.c.i

CMakeFiles/mergeList.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mergeList.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Ida\Desktop\algoritmi\Algoritmi & Strutture Dati\Strutture dati\mergeList\main.c" -o CMakeFiles\mergeList.dir\main.c.s

# Object files for target mergeList
mergeList_OBJECTS = \
"CMakeFiles/mergeList.dir/main.c.obj"

# External object files for target mergeList
mergeList_EXTERNAL_OBJECTS =

mergeList.exe: CMakeFiles/mergeList.dir/main.c.obj
mergeList.exe: CMakeFiles/mergeList.dir/build.make
mergeList.exe: CMakeFiles/mergeList.dir/linklibs.rsp
mergeList.exe: CMakeFiles/mergeList.dir/objects1.rsp
mergeList.exe: CMakeFiles/mergeList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Ida\Desktop\algoritmi\Algoritmi & Strutture Dati\Strutture dati\mergeList\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable mergeList.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\mergeList.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mergeList.dir/build: mergeList.exe

.PHONY : CMakeFiles/mergeList.dir/build

CMakeFiles/mergeList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\mergeList.dir\cmake_clean.cmake
.PHONY : CMakeFiles/mergeList.dir/clean

CMakeFiles/mergeList.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Ida\Desktop\algoritmi\Algoritmi & Strutture Dati\Strutture dati\mergeList" "C:\Users\Ida\Desktop\algoritmi\Algoritmi & Strutture Dati\Strutture dati\mergeList" "C:\Users\Ida\Desktop\algoritmi\Algoritmi & Strutture Dati\Strutture dati\mergeList\cmake-build-debug" "C:\Users\Ida\Desktop\algoritmi\Algoritmi & Strutture Dati\Strutture dati\mergeList\cmake-build-debug" "C:\Users\Ida\Desktop\algoritmi\Algoritmi & Strutture Dati\Strutture dati\mergeList\cmake-build-debug\CMakeFiles\mergeList.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/mergeList.dir/depend

