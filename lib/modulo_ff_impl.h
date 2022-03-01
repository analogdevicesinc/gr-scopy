/* -*- c++ -*- */
/*
 * Copyright 2022 Analog Devices Inc..
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_SCOPY_MODULO_FF_IMPL_H
#define INCLUDED_SCOPY_MODULO_FF_IMPL_H

#include <gnuradio/scopy/modulo_ff.h>

namespace gr {
  namespace scopy {

    class modulo_ff_impl : public modulo_ff
    {
     private:
      // Nothing to declare in this block.

     public:
      modulo_ff_impl(size_t vlen);
      ~modulo_ff_impl();

      // Where all the action really happens
      int work(
              int noutput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items
      );
    };

  } // namespace scopy
} // namespace gr

#endif /* INCLUDED_SCOPY_MODULO_FF_IMPL_H */