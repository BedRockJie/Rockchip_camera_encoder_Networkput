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
CMAKE_SOURCE_DIR = /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build

# Include any dependencies generated for this target.
include encoder/CMakeFiles/bedrock_encoder.dir/depend.make

# Include the progress variables for this target.
include encoder/CMakeFiles/bedrock_encoder.dir/progress.make

# Include the compile flags for this target's objects.
include encoder/CMakeFiles/bedrock_encoder.dir/flags.make

encoder/CMakeFiles/bedrock_encoder.dir/bedrock_mpi_enc.cpp.o: encoder/CMakeFiles/bedrock_encoder.dir/flags.make
encoder/CMakeFiles/bedrock_encoder.dir/bedrock_mpi_enc.cpp.o: ../encoder/bedrock_mpi_enc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object encoder/CMakeFiles/bedrock_encoder.dir/bedrock_mpi_enc.cpp.o"
	cd /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/encoder && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bedrock_encoder.dir/bedrock_mpi_enc.cpp.o -c /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/encoder/bedrock_mpi_enc.cpp

encoder/CMakeFiles/bedrock_encoder.dir/bedrock_mpi_enc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bedrock_encoder.dir/bedrock_mpi_enc.cpp.i"
	cd /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/encoder && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/encoder/bedrock_mpi_enc.cpp > CMakeFiles/bedrock_encoder.dir/bedrock_mpi_enc.cpp.i

encoder/CMakeFiles/bedrock_encoder.dir/bedrock_mpi_enc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bedrock_encoder.dir/bedrock_mpi_enc.cpp.s"
	cd /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/encoder && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/encoder/bedrock_mpi_enc.cpp -o CMakeFiles/bedrock_encoder.dir/bedrock_mpi_enc.cpp.s

encoder/CMakeFiles/bedrock_encoder.dir/src/argparse.cpp.o: encoder/CMakeFiles/bedrock_encoder.dir/flags.make
encoder/CMakeFiles/bedrock_encoder.dir/src/argparse.cpp.o: ../encoder/src/argparse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object encoder/CMakeFiles/bedrock_encoder.dir/src/argparse.cpp.o"
	cd /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/encoder && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bedrock_encoder.dir/src/argparse.cpp.o -c /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/encoder/src/argparse.cpp

encoder/CMakeFiles/bedrock_encoder.dir/src/argparse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bedrock_encoder.dir/src/argparse.cpp.i"
	cd /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/encoder && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/encoder/src/argparse.cpp > CMakeFiles/bedrock_encoder.dir/src/argparse.cpp.i

encoder/CMakeFiles/bedrock_encoder.dir/src/argparse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bedrock_encoder.dir/src/argparse.cpp.s"
	cd /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/encoder && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/encoder/src/argparse.cpp -o CMakeFiles/bedrock_encoder.dir/src/argparse.cpp.s

encoder/CMakeFiles/bedrock_encoder.dir/src/mpi_test_utils.cpp.o: encoder/CMakeFiles/bedrock_encoder.dir/flags.make
encoder/CMakeFiles/bedrock_encoder.dir/src/mpi_test_utils.cpp.o: ../encoder/src/mpi_test_utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object encoder/CMakeFiles/bedrock_encoder.dir/src/mpi_test_utils.cpp.o"
	cd /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/encoder && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bedrock_encoder.dir/src/mpi_test_utils.cpp.o -c /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/encoder/src/mpi_test_utils.cpp

encoder/CMakeFiles/bedrock_encoder.dir/src/mpi_test_utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bedrock_encoder.dir/src/mpi_test_utils.cpp.i"
	cd /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/encoder && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/encoder/src/mpi_test_utils.cpp > CMakeFiles/bedrock_encoder.dir/src/mpi_test_utils.cpp.i

encoder/CMakeFiles/bedrock_encoder.dir/src/mpi_test_utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bedrock_encoder.dir/src/mpi_test_utils.cpp.s"
	cd /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/encoder && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/encoder/src/mpi_test_utils.cpp -o CMakeFiles/bedrock_encoder.dir/src/mpi_test_utils.cpp.s

encoder/CMakeFiles/bedrock_encoder.dir/src/loadbmp.cpp.o: encoder/CMakeFiles/bedrock_encoder.dir/flags.make
encoder/CMakeFiles/bedrock_encoder.dir/src/loadbmp.cpp.o: ../encoder/src/loadbmp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object encoder/CMakeFiles/bedrock_encoder.dir/src/loadbmp.cpp.o"
	cd /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/encoder && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bedrock_encoder.dir/src/loadbmp.cpp.o -c /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/encoder/src/loadbmp.cpp

encoder/CMakeFiles/bedrock_encoder.dir/src/loadbmp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bedrock_encoder.dir/src/loadbmp.cpp.i"
	cd /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/encoder && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/encoder/src/loadbmp.cpp > CMakeFiles/bedrock_encoder.dir/src/loadbmp.cpp.i

encoder/CMakeFiles/bedrock_encoder.dir/src/loadbmp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bedrock_encoder.dir/src/loadbmp.cpp.s"
	cd /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/encoder && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/encoder/src/loadbmp.cpp -o CMakeFiles/bedrock_encoder.dir/src/loadbmp.cpp.s

encoder/CMakeFiles/bedrock_encoder.dir/src/filecfg.cpp.o: encoder/CMakeFiles/bedrock_encoder.dir/flags.make
encoder/CMakeFiles/bedrock_encoder.dir/src/filecfg.cpp.o: ../encoder/src/filecfg.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object encoder/CMakeFiles/bedrock_encoder.dir/src/filecfg.cpp.o"
	cd /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/encoder && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bedrock_encoder.dir/src/filecfg.cpp.o -c /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/encoder/src/filecfg.cpp

encoder/CMakeFiles/bedrock_encoder.dir/src/filecfg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bedrock_encoder.dir/src/filecfg.cpp.i"
	cd /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/encoder && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/encoder/src/filecfg.cpp > CMakeFiles/bedrock_encoder.dir/src/filecfg.cpp.i

encoder/CMakeFiles/bedrock_encoder.dir/src/filecfg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bedrock_encoder.dir/src/filecfg.cpp.s"
	cd /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/encoder && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/encoder/src/filecfg.cpp -o CMakeFiles/bedrock_encoder.dir/src/filecfg.cpp.s

# Object files for target bedrock_encoder
bedrock_encoder_OBJECTS = \
"CMakeFiles/bedrock_encoder.dir/bedrock_mpi_enc.cpp.o" \
"CMakeFiles/bedrock_encoder.dir/src/argparse.cpp.o" \
"CMakeFiles/bedrock_encoder.dir/src/mpi_test_utils.cpp.o" \
"CMakeFiles/bedrock_encoder.dir/src/loadbmp.cpp.o" \
"CMakeFiles/bedrock_encoder.dir/src/filecfg.cpp.o"

# External object files for target bedrock_encoder
bedrock_encoder_EXTERNAL_OBJECTS =

encoder/libbedrock_encoder.a: encoder/CMakeFiles/bedrock_encoder.dir/bedrock_mpi_enc.cpp.o
encoder/libbedrock_encoder.a: encoder/CMakeFiles/bedrock_encoder.dir/src/argparse.cpp.o
encoder/libbedrock_encoder.a: encoder/CMakeFiles/bedrock_encoder.dir/src/mpi_test_utils.cpp.o
encoder/libbedrock_encoder.a: encoder/CMakeFiles/bedrock_encoder.dir/src/loadbmp.cpp.o
encoder/libbedrock_encoder.a: encoder/CMakeFiles/bedrock_encoder.dir/src/filecfg.cpp.o
encoder/libbedrock_encoder.a: encoder/CMakeFiles/bedrock_encoder.dir/build.make
encoder/libbedrock_encoder.a: encoder/CMakeFiles/bedrock_encoder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libbedrock_encoder.a"
	cd /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/encoder && $(CMAKE_COMMAND) -P CMakeFiles/bedrock_encoder.dir/cmake_clean_target.cmake
	cd /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/encoder && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bedrock_encoder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
encoder/CMakeFiles/bedrock_encoder.dir/build: encoder/libbedrock_encoder.a

.PHONY : encoder/CMakeFiles/bedrock_encoder.dir/build

encoder/CMakeFiles/bedrock_encoder.dir/clean:
	cd /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/encoder && $(CMAKE_COMMAND) -P CMakeFiles/bedrock_encoder.dir/cmake_clean.cmake
.PHONY : encoder/CMakeFiles/bedrock_encoder.dir/clean

encoder/CMakeFiles/bedrock_encoder.dir/depend:
	cd /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/encoder /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/encoder /home/jie/workspace/rk356x_nova/rk356x_linux_release_20211019/external/bedrock_encoder/build/encoder/CMakeFiles/bedrock_encoder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : encoder/CMakeFiles/bedrock_encoder.dir/depend
