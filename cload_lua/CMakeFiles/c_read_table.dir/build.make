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
CMAKE_SOURCE_DIR = /root/git/Lua/cload_lua

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/git/Lua/cload_lua

# Include any dependencies generated for this target.
include CMakeFiles/c_read_table.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/c_read_table.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/c_read_table.dir/flags.make

CMakeFiles/c_read_table.dir/main.cpp.o: CMakeFiles/c_read_table.dir/flags.make
CMakeFiles/c_read_table.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/git/Lua/cload_lua/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/c_read_table.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/c_read_table.dir/main.cpp.o -c /root/git/Lua/cload_lua/main.cpp

CMakeFiles/c_read_table.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c_read_table.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/git/Lua/cload_lua/main.cpp > CMakeFiles/c_read_table.dir/main.cpp.i

CMakeFiles/c_read_table.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c_read_table.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/git/Lua/cload_lua/main.cpp -o CMakeFiles/c_read_table.dir/main.cpp.s

# Object files for target c_read_table
c_read_table_OBJECTS = \
"CMakeFiles/c_read_table.dir/main.cpp.o"

# External object files for target c_read_table
c_read_table_EXTERNAL_OBJECTS =

c_read_table: CMakeFiles/c_read_table.dir/main.cpp.o
c_read_table: CMakeFiles/c_read_table.dir/build.make
c_read_table: CMakeFiles/c_read_table.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/git/Lua/cload_lua/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable c_read_table"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/c_read_table.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/c_read_table.dir/build: c_read_table

.PHONY : CMakeFiles/c_read_table.dir/build

CMakeFiles/c_read_table.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/c_read_table.dir/cmake_clean.cmake
.PHONY : CMakeFiles/c_read_table.dir/clean

CMakeFiles/c_read_table.dir/depend:
	cd /root/git/Lua/cload_lua && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/git/Lua/cload_lua /root/git/Lua/cload_lua /root/git/Lua/cload_lua /root/git/Lua/cload_lua /root/git/Lua/cload_lua/CMakeFiles/c_read_table.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/c_read_table.dir/depend

