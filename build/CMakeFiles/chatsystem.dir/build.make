# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_SOURCE_DIR = /home/pawn/projects/ChatSystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pawn/projects/ChatSystem/build

# Include any dependencies generated for this target.
include CMakeFiles/chatsystem.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/chatsystem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chatsystem.dir/flags.make

CMakeFiles/chatsystem.dir/Chat_System/main.cpp.o: CMakeFiles/chatsystem.dir/flags.make
CMakeFiles/chatsystem.dir/Chat_System/main.cpp.o: ../Chat_System/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pawn/projects/ChatSystem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chatsystem.dir/Chat_System/main.cpp.o"
	/usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chatsystem.dir/Chat_System/main.cpp.o -c /home/pawn/projects/ChatSystem/Chat_System/main.cpp

CMakeFiles/chatsystem.dir/Chat_System/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chatsystem.dir/Chat_System/main.cpp.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pawn/projects/ChatSystem/Chat_System/main.cpp > CMakeFiles/chatsystem.dir/Chat_System/main.cpp.i

CMakeFiles/chatsystem.dir/Chat_System/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chatsystem.dir/Chat_System/main.cpp.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pawn/projects/ChatSystem/Chat_System/main.cpp -o CMakeFiles/chatsystem.dir/Chat_System/main.cpp.s

# Object files for target chatsystem
chatsystem_OBJECTS = \
"CMakeFiles/chatsystem.dir/Chat_System/main.cpp.o"

# External object files for target chatsystem
chatsystem_EXTERNAL_OBJECTS =

chatsystem: CMakeFiles/chatsystem.dir/Chat_System/main.cpp.o
chatsystem: CMakeFiles/chatsystem.dir/build.make
chatsystem: CMakeFiles/chatsystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pawn/projects/ChatSystem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable chatsystem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chatsystem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chatsystem.dir/build: chatsystem

.PHONY : CMakeFiles/chatsystem.dir/build

CMakeFiles/chatsystem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chatsystem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chatsystem.dir/clean

CMakeFiles/chatsystem.dir/depend:
	cd /home/pawn/projects/ChatSystem/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pawn/projects/ChatSystem /home/pawn/projects/ChatSystem /home/pawn/projects/ChatSystem/build /home/pawn/projects/ChatSystem/build /home/pawn/projects/ChatSystem/build/CMakeFiles/chatsystem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chatsystem.dir/depend
