# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\1prog\2course\life

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\1prog\2course\life\cmake-build-debug

# Include any dependencies generated for this target.
include lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/flags.make

lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/flags.make
lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/includes_CXX.rsp
lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: ../lib/googletest-release-1.6.0/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\1prog\2course\life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/src/gtest-all.cc.obj"
	cd /d C:\1prog\2course\life\cmake-build-debug\lib\googletest-release-1.6.0 && C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gtest.dir\src\gtest-all.cc.obj -c C:\1prog\2course\life\lib\googletest-release-1.6.0\src\gtest-all.cc

lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /d C:\1prog\2course\life\cmake-build-debug\lib\googletest-release-1.6.0 && C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\1prog\2course\life\lib\googletest-release-1.6.0\src\gtest-all.cc > CMakeFiles\gtest.dir\src\gtest-all.cc.i

lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /d C:\1prog\2course\life\cmake-build-debug\lib\googletest-release-1.6.0 && C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\1prog\2course\life\lib\googletest-release-1.6.0\src\gtest-all.cc -o CMakeFiles\gtest.dir\src\gtest-all.cc.s

lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/src/gtest-all.cc.obj.requires:

.PHONY : lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/src/gtest-all.cc.obj.requires

lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/src/gtest-all.cc.obj.provides: lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/src/gtest-all.cc.obj.requires
	$(MAKE) -f lib\googletest-release-1.6.0\CMakeFiles\gtest.dir\build.make lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/src/gtest-all.cc.obj.provides.build
.PHONY : lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/src/gtest-all.cc.obj.provides

lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/src/gtest-all.cc.obj.provides.build: lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/src/gtest-all.cc.obj


# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.obj"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

lib/googletest-release-1.6.0/libgtest.a: lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/src/gtest-all.cc.obj
lib/googletest-release-1.6.0/libgtest.a: lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/build.make
lib/googletest-release-1.6.0/libgtest.a: lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\1prog\2course\life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest.a"
	cd /d C:\1prog\2course\life\cmake-build-debug\lib\googletest-release-1.6.0 && $(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean_target.cmake
	cd /d C:\1prog\2course\life\cmake-build-debug\lib\googletest-release-1.6.0 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gtest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/build: lib/googletest-release-1.6.0/libgtest.a

.PHONY : lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/build

lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/requires: lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/src/gtest-all.cc.obj.requires

.PHONY : lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/requires

lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/clean:
	cd /d C:\1prog\2course\life\cmake-build-debug\lib\googletest-release-1.6.0 && $(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean.cmake
.PHONY : lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/clean

lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\1prog\2course\life C:\1prog\2course\life\lib\googletest-release-1.6.0 C:\1prog\2course\life\cmake-build-debug C:\1prog\2course\life\cmake-build-debug\lib\googletest-release-1.6.0 C:\1prog\2course\life\cmake-build-debug\lib\googletest-release-1.6.0\CMakeFiles\gtest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : lib/googletest-release-1.6.0/CMakeFiles/gtest.dir/depend

