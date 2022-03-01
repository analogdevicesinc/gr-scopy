/* -*- c++ -*- */
/* 
 * Copyright 2018 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_SCOPY_TRAPEZOIDAL_IMPL_H
#define INCLUDED_SCOPY_TRAPEZOIDAL_IMPL_H

#include <gnuradio/scopy/trapezoidal.h>
#include <gnuradio/fxpt_nco.h>
namespace gr {
  namespace scopy {

    class trapezoidal_impl : public trapezoidal
    {
     private:
      // Nothing to declare in this block.

     public:
      trapezoidal_impl(double sampling_freq, double wave_freq, double ampl, double rise, double holdhigh, double fall, double holdlow, float offset, double phase);
      ~trapezoidal_impl();

	double	d_sampling_freq;
	double	d_frequency;
	double d_ampl;
	double d_offset;
	gr::fxpt_nco d_nco;
	double d_phase;
	double d_rise;
	double d_fall;
	double d_holdhigh;
	double d_holdlow;


      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace scopy
} // namespace gr

#endif /* INCLUDED_SCOPY_TRAPEZOIDAL_IMPL_H */

