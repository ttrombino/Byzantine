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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Z\CLionProjects\Byzantine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Z\CLionProjects\Byzantine\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SHA.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SHA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SHA.dir/flags.make

CMakeFiles/SHA.dir/main.cpp.obj: CMakeFiles/SHA.dir/flags.make
CMakeFiles/SHA.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Z\CLionProjects\Byzantine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SHA.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SHA.dir\main.cpp.obj -c C:\Users\Z\CLionProjects\Byzantine\main.cpp

CMakeFiles/SHA.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SHA.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Z\CLionProjects\Byzantine\main.cpp > CMakeFiles\SHA.dir\main.cpp.i

CMakeFiles/SHA.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SHA.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Z\CLionProjects\Byzantine\main.cpp -o CMakeFiles\SHA.dir\main.cpp.s

CMakeFiles/SHA.dir/sha256.cpp.obj: CMakeFiles/SHA.dir/flags.make
CMakeFiles/SHA.dir/sha256.cpp.obj: ../sha256.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Z\CLionProjects\Byzantine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SHA.dir/sha256.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SHA.dir\sha256.cpp.obj -c C:\Users\Z\CLionProjects\Byzantine\sha256.cpp

CMakeFiles/SHA.dir/sha256.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SHA.dir/sha256.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Z\CLionProjects\Byzantine\sha256.cpp > CMakeFiles\SHA.dir\sha256.cpp.i

CMakeFiles/SHA.dir/sha256.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SHA.dir/sha256.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Z\CLionProjects\Byzantine\sha256.cpp -o CMakeFiles\SHA.dir\sha256.cpp.s

CMakeFiles/SHA.dir/Merkle.cpp.obj: CMakeFiles/SHA.dir/flags.make
CMakeFiles/SHA.dir/Merkle.cpp.obj: ../Merkle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Z\CLionProjects\Byzantine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SHA.dir/Merkle.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SHA.dir\Merkle.cpp.obj -c C:\Users\Z\CLionProjects\Byzantine\Merkle.cpp

CMakeFiles/SHA.dir/Merkle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SHA.dir/Merkle.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Z\CLionProjects\Byzantine\Merkle.cpp > CMakeFiles\SHA.dir\Merkle.cpp.i

CMakeFiles/SHA.dir/Merkle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SHA.dir/Merkle.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Z\CLionProjects\Byzantine\Merkle.cpp -o CMakeFiles\SHA.dir\Merkle.cpp.s

CMakeFiles/SHA.dir/Block.cpp.obj: CMakeFiles/SHA.dir/flags.make
CMakeFiles/SHA.dir/Block.cpp.obj: ../Block.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Z\CLionProjects\Byzantine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SHA.dir/Block.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SHA.dir\Block.cpp.obj -c C:\Users\Z\CLionProjects\Byzantine\Block.cpp

CMakeFiles/SHA.dir/Block.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SHA.dir/Block.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Z\CLionProjects\Byzantine\Block.cpp > CMakeFiles\SHA.dir\Block.cpp.i

CMakeFiles/SHA.dir/Block.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SHA.dir/Block.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Z\CLionProjects\Byzantine\Block.cpp -o CMakeFiles\SHA.dir\Block.cpp.s

CMakeFiles/SHA.dir/Transaction.cpp.obj: CMakeFiles/SHA.dir/flags.make
CMakeFiles/SHA.dir/Transaction.cpp.obj: ../Transaction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Z\CLionProjects\Byzantine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SHA.dir/Transaction.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SHA.dir\Transaction.cpp.obj -c C:\Users\Z\CLionProjects\Byzantine\Transaction.cpp

CMakeFiles/SHA.dir/Transaction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SHA.dir/Transaction.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Z\CLionProjects\Byzantine\Transaction.cpp > CMakeFiles\SHA.dir\Transaction.cpp.i

CMakeFiles/SHA.dir/Transaction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SHA.dir/Transaction.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Z\CLionProjects\Byzantine\Transaction.cpp -o CMakeFiles\SHA.dir\Transaction.cpp.s

# Object files for target SHA
SHA_OBJECTS = \
"CMakeFiles/SHA.dir/main.cpp.obj" \
"CMakeFiles/SHA.dir/sha256.cpp.obj" \
"CMakeFiles/SHA.dir/Merkle.cpp.obj" \
"CMakeFiles/SHA.dir/Block.cpp.obj" \
"CMakeFiles/SHA.dir/Transaction.cpp.obj"

# External object files for target SHA
SHA_EXTERNAL_OBJECTS =

SHA.exe: CMakeFiles/SHA.dir/main.cpp.obj
SHA.exe: CMakeFiles/SHA.dir/sha256.cpp.obj
SHA.exe: CMakeFiles/SHA.dir/Merkle.cpp.obj
SHA.exe: CMakeFiles/SHA.dir/Block.cpp.obj
SHA.exe: CMakeFiles/SHA.dir/Transaction.cpp.obj
SHA.exe: CMakeFiles/SHA.dir/build.make
SHA.exe: CMakeFiles/SHA.dir/linklibs.rsp
SHA.exe: CMakeFiles/SHA.dir/objects1.rsp
SHA.exe: CMakeFiles/SHA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Z\CLionProjects\Byzantine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable SHA.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SHA.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SHA.dir/build: SHA.exe

.PHONY : CMakeFiles/SHA.dir/build

CMakeFiles/SHA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SHA.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SHA.dir/clean

CMakeFiles/SHA.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Z\CLionProjects\Byzantine C:\Users\Z\CLionProjects\Byzantine C:\Users\Z\CLionProjects\Byzantine\cmake-build-debug C:\Users\Z\CLionProjects\Byzantine\cmake-build-debug C:\Users\Z\CLionProjects\Byzantine\cmake-build-debug\CMakeFiles\SHA.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SHA.dir/depend

