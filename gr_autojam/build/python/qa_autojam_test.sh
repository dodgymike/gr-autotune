#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/mike/source/gr-autotune/gr_autojam/python
export GR_CONF_CONTROLPORT_ON=False
export PATH=/home/mike/source/gr-autotune/gr_autojam/build/python:$PATH
export LD_LIBRARY_PATH=/home/mike/source/gr-autotune/gr_autojam/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=/home/mike/source/gr-autotune/gr_autojam/build/swig:$PYTHONPATH
/usr/bin/python2 /home/mike/source/gr-autotune/gr_autojam/python/qa_autojam.py 
