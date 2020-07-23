/* -*- c++ -*- */

#define SCOPY_API

%include "gnuradio/swig/gnuradio.i"			// the common stuff
%{
#include "scopy/math.h"
#include "scopy/power_ff.h"
#include "scopy/modulo_ff.h"
#include "scopy/modulo_const_ff.h"
#include "scopy/goertzel_scopy_fc.h"
#include "scopy/t_source.h"
%}

//load generated python docstrings
%include "scopy_swig_doc.i"
%include "scopy/math.h"
%include "scopy/power_ff.h"
%include "scopy/modulo_ff.h"
%include "scopy/modulo_const_ff.h"

GR_SWIG_BLOCK_MAGIC2(scopy, iio_math);
GR_SWIG_BLOCK_MAGIC2(scopy, iio_math_gen);
GR_SWIG_BLOCK_MAGIC2(scopy, power_ff);
GR_SWIG_BLOCK_MAGIC2(scopy, modulo_ff);
GR_SWIG_BLOCK_MAGIC2(scopy, modulo_const_ff);


%include "scopy/goertzel_scopy_fc.h"
GR_SWIG_BLOCK_MAGIC2(scopy, goertzel_scopy_fc);
%include "scopy/t_source.h"
GR_SWIG_BLOCK_MAGIC2(scopy, t_source);
