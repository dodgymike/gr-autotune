#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/mike/source/research/keeloq/gr-signalfinder/python
export GR_CONF_CONTROLPORT_ON=False
export PATH=/home/mike/source/research/keeloq/gr-signalfinder/python:$PATH
export LD_LIBRARY_PATH=/home/mike/source/research/keeloq/gr-signalfinder/lib:$LD_LIBRARY_PATH
export PYTHONPATH=/home/mike/source/research/keeloq/gr-signalfinder/swig:$PYTHONPATH
/usr/bin/python2 /home/mike/source/research/keeloq/gr-signalfinder/python/qa_signalfinder.py 
