#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/mike/source/research/keeloq/gr-signalfinder/lib
export GR_CONF_CONTROLPORT_ON=False
export PATH=/home/mike/source/research/keeloq/gr-signalfinder/lib:$PATH
export LD_LIBRARY_PATH=/home/mike/source/research/keeloq/gr-signalfinder/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$PYTHONPATH
test-signalfinder 
