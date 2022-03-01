/* -*- c++ -*- */
/*
 * Copyright 2022 Analog Devices Inc..
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <gnuradio/io_signature.h>
#include "modulo_const_ff_impl.h"

namespace gr {
  namespace scopy {

    #pragma message("set the following appropriately and remove this warning")
    using input_type = float;
    #pragma message("set the following appropriately and remove this warning")
    using output_type = float;
    modulo_const_ff::sptr
    modulo_const_ff::make(float modulo, size_t vlen)
    {
      return gnuradio::make_block_sptr<modulo_const_ff_impl>(
        modulo, vlen);
    }


    /*
     * The private constructor
     */
    modulo_const_ff_impl::modulo_const_ff_impl(float modulo, size_t vlen)
      : gr::sync_block("modulo_const_ff",
              gr::io_signature::make(1 /* min inputs */, 1 /* max inputs */, sizeof(input_type)),
              gr::io_signature::make(1 /* min outputs */, 1 /*max outputs */, sizeof(output_type)))
    {}

    /*
     * Our virtual destructor.
     */
    modulo_const_ff_impl::~modulo_const_ff_impl()
    {
    }

    int
    modulo_const_ff_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      auto in = static_cast<const input_type*>(input_items[0]);
      auto out = static_cast<output_type*>(output_items[0]);

      #pragma message("Implement the signal processing in your block and remove this warning")
      // Do <+signal processing+>

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace scopy */
} /* namespace gr */
