/* -*- c++ -*- */

#define AUTOJAM_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "autojam_swig_doc.i"

%{
#include "autojam/autojam.h"
#include "autojam/autotune.h"
%}


%include "autojam/autojam.h"
GR_SWIG_BLOCK_MAGIC2(autojam, autojam);
%include "autojam/autotune.h"
GR_SWIG_BLOCK_MAGIC2(autojam, autotune);
