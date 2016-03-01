#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/mike/source/gr-autotune/gr_autojam/lib
export GR_CONF_CONTROLPORT_ON=False
export PATH=/home/mike/source/gr-autotune/gr_autojam/build/lib:$PATH
export LD_LIBRARY_PATH=/home/mike/source/gr-autotune/gr_autojam/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$PYTHONPATH
test-autojam 
