# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_SOURCE_DIR = /home/mike/source/research/keeloq/gr-signalfinder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mike/source/research/keeloq/gr-signalfinder

# Include any dependencies generated for this target.
include swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/depend.make

# Include the progress variables for this target.
include swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/progress.make

# Include the compile flags for this target's objects.
include swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/flags.make

swig/signalfinder_swig_swig_2d0df.cpp: swig/signalfinder_swig.i
swig/signalfinder_swig_swig_2d0df.cpp: swig/signalfinder_swig_doc.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/gr_swig_block_magic.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/gr_logger.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/block_gateway.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/tags.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/top_block.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/sync_block.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/msg_queue.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/io_signature.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/gnuradio.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/buffer.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/sync_decimator.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/gr_types.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/message.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/hier_block2.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/block.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/basic_block.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/runtime_swig_doc.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/sync_interpolator.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/gr_ctrlport.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/feval.i
swig/signalfinder_swig_swig_2d0df.cpp: swig/signalfinder_swig.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/gr_shared_ptr.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/prefs.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/msg_handler.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/constants.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/gr_extras.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/runtime_swig.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/tagged_stream_block.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/realtime.i
swig/signalfinder_swig_swig_2d0df.cpp: /usr/include/gnuradio/swig/block_detail.i
swig/signalfinder_swig_swig_2d0df.cpp: swig/signalfinder_swig.tag
	cd /home/mike/source/research/keeloq/gr-signalfinder/swig && /usr/bin/cmake -E copy /home/mike/source/research/keeloq/gr-signalfinder/swig/signalfinder_swig_swig_2d0df.cpp.in /home/mike/source/research/keeloq/gr-signalfinder/swig/signalfinder_swig_swig_2d0df.cpp

swig/signalfinder_swig.tag: swig/_signalfinder_swig_swig_tag
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mike/source/research/keeloq/gr-signalfinder/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating signalfinder_swig.tag"
	cd /home/mike/source/research/keeloq/gr-signalfinder/swig && ./_signalfinder_swig_swig_tag
	cd /home/mike/source/research/keeloq/gr-signalfinder/swig && /usr/bin/cmake -E touch /home/mike/source/research/keeloq/gr-signalfinder/swig/signalfinder_swig.tag

swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/signalfinder_swig_swig_2d0df.cpp.o: swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/flags.make
swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/signalfinder_swig_swig_2d0df.cpp.o: swig/signalfinder_swig_swig_2d0df.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mike/source/research/keeloq/gr-signalfinder/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/signalfinder_swig_swig_2d0df.cpp.o"
	cd /home/mike/source/research/keeloq/gr-signalfinder/swig && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/signalfinder_swig_swig_2d0df.dir/signalfinder_swig_swig_2d0df.cpp.o -c /home/mike/source/research/keeloq/gr-signalfinder/swig/signalfinder_swig_swig_2d0df.cpp

swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/signalfinder_swig_swig_2d0df.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/signalfinder_swig_swig_2d0df.dir/signalfinder_swig_swig_2d0df.cpp.i"
	cd /home/mike/source/research/keeloq/gr-signalfinder/swig && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mike/source/research/keeloq/gr-signalfinder/swig/signalfinder_swig_swig_2d0df.cpp > CMakeFiles/signalfinder_swig_swig_2d0df.dir/signalfinder_swig_swig_2d0df.cpp.i

swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/signalfinder_swig_swig_2d0df.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/signalfinder_swig_swig_2d0df.dir/signalfinder_swig_swig_2d0df.cpp.s"
	cd /home/mike/source/research/keeloq/gr-signalfinder/swig && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mike/source/research/keeloq/gr-signalfinder/swig/signalfinder_swig_swig_2d0df.cpp -o CMakeFiles/signalfinder_swig_swig_2d0df.dir/signalfinder_swig_swig_2d0df.cpp.s

swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/signalfinder_swig_swig_2d0df.cpp.o.requires:
.PHONY : swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/signalfinder_swig_swig_2d0df.cpp.o.requires

swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/signalfinder_swig_swig_2d0df.cpp.o.provides: swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/signalfinder_swig_swig_2d0df.cpp.o.requires
	$(MAKE) -f swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/build.make swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/signalfinder_swig_swig_2d0df.cpp.o.provides.build
.PHONY : swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/signalfinder_swig_swig_2d0df.cpp.o.provides

swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/signalfinder_swig_swig_2d0df.cpp.o.provides.build: swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/signalfinder_swig_swig_2d0df.cpp.o

# Object files for target signalfinder_swig_swig_2d0df
signalfinder_swig_swig_2d0df_OBJECTS = \
"CMakeFiles/signalfinder_swig_swig_2d0df.dir/signalfinder_swig_swig_2d0df.cpp.o"

# External object files for target signalfinder_swig_swig_2d0df
signalfinder_swig_swig_2d0df_EXTERNAL_OBJECTS =

swig/signalfinder_swig_swig_2d0df: swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/signalfinder_swig_swig_2d0df.cpp.o
swig/signalfinder_swig_swig_2d0df: swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/build.make
swig/signalfinder_swig_swig_2d0df: swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable signalfinder_swig_swig_2d0df"
	cd /home/mike/source/research/keeloq/gr-signalfinder/swig && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/signalfinder_swig_swig_2d0df.dir/link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Swig source"
	cd /home/mike/source/research/keeloq/gr-signalfinder/swig && /usr/bin/cmake -E make_directory /home/mike/source/research/keeloq/gr-signalfinder/swig
	cd /home/mike/source/research/keeloq/gr-signalfinder/swig && /usr/bin/swig2.0 -python -fvirtual -modern -keyword -w511 -module signalfinder_swig -DSIZE_T_UL -I/home/mike/source/research/keeloq/gr-signalfinder/swig -I/home/mike/source/research/keeloq/gr-signalfinder/swig -I/usr/include/gnuradio/swig -I/usr/include/python2.7 -I/usr/include/python2.7 -outdir /home/mike/source/research/keeloq/gr-signalfinder/swig -c++ -I/home/mike/source/research/keeloq/gr-signalfinder/lib -I/home/mike/source/research/keeloq/gr-signalfinder/include -I/home/mike/source/research/keeloq/gr-signalfinder/lib -I/home/mike/source/research/keeloq/gr-signalfinder/include -I/usr/include -I/usr/include -I/usr/include -I/home/mike/source/research/keeloq/gr-signalfinder/swig -I/home/mike/source/research/keeloq/gr-signalfinder/swig -I/usr/include/gnuradio/swig -I/usr/include/python2.7 -I/usr/include/python2.7 -o /home/mike/source/research/keeloq/gr-signalfinder/swig/signalfinder_swigPYTHON_wrap.cxx /home/mike/source/research/keeloq/gr-signalfinder/swig/signalfinder_swig.i

# Rule to build all files generated by this target.
swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/build: swig/signalfinder_swig_swig_2d0df
.PHONY : swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/build

swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/requires: swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/signalfinder_swig_swig_2d0df.cpp.o.requires
.PHONY : swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/requires

swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/clean:
	cd /home/mike/source/research/keeloq/gr-signalfinder/swig && $(CMAKE_COMMAND) -P CMakeFiles/signalfinder_swig_swig_2d0df.dir/cmake_clean.cmake
.PHONY : swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/clean

swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/depend: swig/signalfinder_swig_swig_2d0df.cpp
swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/depend: swig/signalfinder_swig.tag
	cd /home/mike/source/research/keeloq/gr-signalfinder && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mike/source/research/keeloq/gr-signalfinder /home/mike/source/research/keeloq/gr-signalfinder/swig /home/mike/source/research/keeloq/gr-signalfinder /home/mike/source/research/keeloq/gr-signalfinder/swig /home/mike/source/research/keeloq/gr-signalfinder/swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : swig/CMakeFiles/signalfinder_swig_swig_2d0df.dir/depend

