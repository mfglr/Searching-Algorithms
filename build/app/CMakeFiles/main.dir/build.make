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
CMAKE_SOURCE_DIR = /home/mfglr/searchingAlgorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mfglr/searchingAlgorithms/build

# Include any dependencies generated for this target.
include app/CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include app/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include app/CMakeFiles/main.dir/flags.make

app/CMakeFiles/main.dir/main.cpp.o: app/CMakeFiles/main.dir/flags.make
app/CMakeFiles/main.dir/main.cpp.o: ../app/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mfglr/searchingAlgorithms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object app/CMakeFiles/main.dir/main.cpp.o"
	cd /home/mfglr/searchingAlgorithms/build/app && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/main.cpp.o -c /home/mfglr/searchingAlgorithms/app/main.cpp

app/CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	cd /home/mfglr/searchingAlgorithms/build/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mfglr/searchingAlgorithms/app/main.cpp > CMakeFiles/main.dir/main.cpp.i

app/CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	cd /home/mfglr/searchingAlgorithms/build/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mfglr/searchingAlgorithms/app/main.cpp -o CMakeFiles/main.dir/main.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

app/main: app/CMakeFiles/main.dir/main.cpp.o
app/main: app/CMakeFiles/main.dir/build.make
app/main: src/libsource.a
app/main: app/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mfglr/searchingAlgorithms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable main"
	cd /home/mfglr/searchingAlgorithms/build/app && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
app/CMakeFiles/main.dir/build: app/main

.PHONY : app/CMakeFiles/main.dir/build

app/CMakeFiles/main.dir/clean:
	cd /home/mfglr/searchingAlgorithms/build/app && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : app/CMakeFiles/main.dir/clean

app/CMakeFiles/main.dir/depend:
	cd /home/mfglr/searchingAlgorithms/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mfglr/searchingAlgorithms /home/mfglr/searchingAlgorithms/app /home/mfglr/searchingAlgorithms/build /home/mfglr/searchingAlgorithms/build/app /home/mfglr/searchingAlgorithms/build/app/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : app/CMakeFiles/main.dir/depend

