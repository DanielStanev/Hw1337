# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = C:\Programs\Jetbrains\CLion\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Programs\Jetbrains\CLion\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Files\Projects\Clion\NVV200000Asg5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Files\Projects\Clion\NVV200000Asg5\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/NVV200000Asg5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NVV200000Asg5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NVV200000Asg5.dir/flags.make

CMakeFiles/NVV200000Asg5.dir/NVV200000Asg5.cpp.obj: CMakeFiles/NVV200000Asg5.dir/flags.make
CMakeFiles/NVV200000Asg5.dir/NVV200000Asg5.cpp.obj: ../NVV200000Asg5.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Files\Projects\Clion\NVV200000Asg5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NVV200000Asg5.dir/NVV200000Asg5.cpp.obj"
	C:\MinGW64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\NVV200000Asg5.dir\NVV200000Asg5.cpp.obj -c C:\Files\Projects\Clion\NVV200000Asg5\NVV200000Asg5.cpp

CMakeFiles/NVV200000Asg5.dir/NVV200000Asg5.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NVV200000Asg5.dir/NVV200000Asg5.cpp.i"
	C:\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Files\Projects\Clion\NVV200000Asg5\NVV200000Asg5.cpp > CMakeFiles\NVV200000Asg5.dir\NVV200000Asg5.cpp.i

CMakeFiles/NVV200000Asg5.dir/NVV200000Asg5.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NVV200000Asg5.dir/NVV200000Asg5.cpp.s"
	C:\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Files\Projects\Clion\NVV200000Asg5\NVV200000Asg5.cpp -o CMakeFiles\NVV200000Asg5.dir\NVV200000Asg5.cpp.s

# Object files for target NVV200000Asg5
NVV200000Asg5_OBJECTS = \
"CMakeFiles/NVV200000Asg5.dir/NVV200000Asg5.cpp.obj"

# External object files for target NVV200000Asg5
NVV200000Asg5_EXTERNAL_OBJECTS =

NVV200000Asg5.exe: CMakeFiles/NVV200000Asg5.dir/NVV200000Asg5.cpp.obj
NVV200000Asg5.exe: CMakeFiles/NVV200000Asg5.dir/build.make
NVV200000Asg5.exe: CMakeFiles/NVV200000Asg5.dir/linklibs.rsp
NVV200000Asg5.exe: CMakeFiles/NVV200000Asg5.dir/objects1.rsp
NVV200000Asg5.exe: CMakeFiles/NVV200000Asg5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Files\Projects\Clion\NVV200000Asg5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable NVV200000Asg5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\NVV200000Asg5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NVV200000Asg5.dir/build: NVV200000Asg5.exe

.PHONY : CMakeFiles/NVV200000Asg5.dir/build

CMakeFiles/NVV200000Asg5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\NVV200000Asg5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/NVV200000Asg5.dir/clean

CMakeFiles/NVV200000Asg5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Files\Projects\Clion\NVV200000Asg5 C:\Files\Projects\Clion\NVV200000Asg5 C:\Files\Projects\Clion\NVV200000Asg5\cmake-build-debug C:\Files\Projects\Clion\NVV200000Asg5\cmake-build-debug C:\Files\Projects\Clion\NVV200000Asg5\cmake-build-debug\CMakeFiles\NVV200000Asg5.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NVV200000Asg5.dir/depend

