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
CMAKE_SOURCE_DIR = /root/argos-sir-sim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/argos-sir-sim/build

# Include any dependencies generated for this target.
include loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/depend.make

# Include the progress variables for this target.
include loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/progress.make

# Include the compile flags for this target's objects.
include loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/flags.make

loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/foraging_loop_functions_autogen/mocs_compilation.cpp.o: loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/flags.make
loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/foraging_loop_functions_autogen/mocs_compilation.cpp.o: loop_functions/foraging_loop_functions/foraging_loop_functions_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/argos-sir-sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/foraging_loop_functions_autogen/mocs_compilation.cpp.o"
	cd /root/argos-sir-sim/build/loop_functions/foraging_loop_functions && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/foraging_loop_functions.dir/foraging_loop_functions_autogen/mocs_compilation.cpp.o -c /root/argos-sir-sim/build/loop_functions/foraging_loop_functions/foraging_loop_functions_autogen/mocs_compilation.cpp

loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/foraging_loop_functions_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/foraging_loop_functions.dir/foraging_loop_functions_autogen/mocs_compilation.cpp.i"
	cd /root/argos-sir-sim/build/loop_functions/foraging_loop_functions && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/argos-sir-sim/build/loop_functions/foraging_loop_functions/foraging_loop_functions_autogen/mocs_compilation.cpp > CMakeFiles/foraging_loop_functions.dir/foraging_loop_functions_autogen/mocs_compilation.cpp.i

loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/foraging_loop_functions_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/foraging_loop_functions.dir/foraging_loop_functions_autogen/mocs_compilation.cpp.s"
	cd /root/argos-sir-sim/build/loop_functions/foraging_loop_functions && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/argos-sir-sim/build/loop_functions/foraging_loop_functions/foraging_loop_functions_autogen/mocs_compilation.cpp -o CMakeFiles/foraging_loop_functions.dir/foraging_loop_functions_autogen/mocs_compilation.cpp.s

loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/foraging_loop_functions.cpp.o: loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/flags.make
loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/foraging_loop_functions.cpp.o: ../loop_functions/foraging_loop_functions/foraging_loop_functions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/argos-sir-sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/foraging_loop_functions.cpp.o"
	cd /root/argos-sir-sim/build/loop_functions/foraging_loop_functions && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/foraging_loop_functions.dir/foraging_loop_functions.cpp.o -c /root/argos-sir-sim/loop_functions/foraging_loop_functions/foraging_loop_functions.cpp

loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/foraging_loop_functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/foraging_loop_functions.dir/foraging_loop_functions.cpp.i"
	cd /root/argos-sir-sim/build/loop_functions/foraging_loop_functions && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/argos-sir-sim/loop_functions/foraging_loop_functions/foraging_loop_functions.cpp > CMakeFiles/foraging_loop_functions.dir/foraging_loop_functions.cpp.i

loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/foraging_loop_functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/foraging_loop_functions.dir/foraging_loop_functions.cpp.s"
	cd /root/argos-sir-sim/build/loop_functions/foraging_loop_functions && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/argos-sir-sim/loop_functions/foraging_loop_functions/foraging_loop_functions.cpp -o CMakeFiles/foraging_loop_functions.dir/foraging_loop_functions.cpp.s

loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/foraging_qt_user_functions.cpp.o: loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/flags.make
loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/foraging_qt_user_functions.cpp.o: ../loop_functions/foraging_loop_functions/foraging_qt_user_functions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/argos-sir-sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/foraging_qt_user_functions.cpp.o"
	cd /root/argos-sir-sim/build/loop_functions/foraging_loop_functions && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/foraging_loop_functions.dir/foraging_qt_user_functions.cpp.o -c /root/argos-sir-sim/loop_functions/foraging_loop_functions/foraging_qt_user_functions.cpp

loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/foraging_qt_user_functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/foraging_loop_functions.dir/foraging_qt_user_functions.cpp.i"
	cd /root/argos-sir-sim/build/loop_functions/foraging_loop_functions && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/argos-sir-sim/loop_functions/foraging_loop_functions/foraging_qt_user_functions.cpp > CMakeFiles/foraging_loop_functions.dir/foraging_qt_user_functions.cpp.i

loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/foraging_qt_user_functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/foraging_loop_functions.dir/foraging_qt_user_functions.cpp.s"
	cd /root/argos-sir-sim/build/loop_functions/foraging_loop_functions && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/argos-sir-sim/loop_functions/foraging_loop_functions/foraging_qt_user_functions.cpp -o CMakeFiles/foraging_loop_functions.dir/foraging_qt_user_functions.cpp.s

# Object files for target foraging_loop_functions
foraging_loop_functions_OBJECTS = \
"CMakeFiles/foraging_loop_functions.dir/foraging_loop_functions_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/foraging_loop_functions.dir/foraging_loop_functions.cpp.o" \
"CMakeFiles/foraging_loop_functions.dir/foraging_qt_user_functions.cpp.o"

# External object files for target foraging_loop_functions
foraging_loop_functions_EXTERNAL_OBJECTS =

loop_functions/foraging_loop_functions/libforaging_loop_functions.so: loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/foraging_loop_functions_autogen/mocs_compilation.cpp.o
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/foraging_loop_functions.cpp.o
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/foraging_qt_user_functions.cpp.o
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/build.make
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/libdl.so
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/libpthread.so
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/libfreeimage.so
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/libfreeimageplus.so
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/libGL.so
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/libGLU.so
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/libglut.so
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/libXmu.so
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/libXi.so
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/liblua5.3.so
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/libm.so
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: controllers/footbot_foraging/libfootbot_foraging.so
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/libdl.so
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/libpthread.so
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/libfreeimage.so
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/libfreeimageplus.so
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/libGL.so
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/libGLU.so
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/libglut.so
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/libXmu.so
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/libXi.so
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/liblua5.3.so
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: /usr/lib/x86_64-linux-gnu/libm.so
loop_functions/foraging_loop_functions/libforaging_loop_functions.so: loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/argos-sir-sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared module libforaging_loop_functions.so"
	cd /root/argos-sir-sim/build/loop_functions/foraging_loop_functions && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/foraging_loop_functions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/build: loop_functions/foraging_loop_functions/libforaging_loop_functions.so

.PHONY : loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/build

loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/clean:
	cd /root/argos-sir-sim/build/loop_functions/foraging_loop_functions && $(CMAKE_COMMAND) -P CMakeFiles/foraging_loop_functions.dir/cmake_clean.cmake
.PHONY : loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/clean

loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/depend:
	cd /root/argos-sir-sim/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/argos-sir-sim /root/argos-sir-sim/loop_functions/foraging_loop_functions /root/argos-sir-sim/build /root/argos-sir-sim/build/loop_functions/foraging_loop_functions /root/argos-sir-sim/build/loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : loop_functions/foraging_loop_functions/CMakeFiles/foraging_loop_functions.dir/depend

