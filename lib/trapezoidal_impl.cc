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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "trapezoidal_impl.h"

namespace gr {
  namespace scopy {

    trapezoidal::sptr
    trapezoidal::make(double sampling_freq, double wave_freq, double ampl, double rise, double holdhigh, double fall, double holdlow, float offset, double phase)
    {
      return gnuradio::get_initial_sptr
        (new trapezoidal_impl(sampling_freq, wave_freq, ampl, rise, holdhigh, fall, holdlow, offset, phase));
    }

    /*
     * The private constructor
     */
    trapezoidal_impl::trapezoidal_impl(double sampling_freq, double wave_freq, double ampl, double rise, double holdhigh, double fall, double holdlow, float offset, double phase)
      : gr::sync_block("trapezoidal",
              gr::io_signature::make(0, 0, 0),
              gr::io_signature::make(1,1, sizeof(float))), d_sampling_freq(sampling_freq),
      		d_frequency(wave_freq), d_ampl(ampl), d_offset(offset), d_phase(phase), d_rise(rise), d_fall(fall), d_holdhigh(holdhigh), d_holdlow(holdlow)
        {
	 d_nco.set_freq (2 * M_PI * d_frequency / d_sampling_freq);
	 d_nco.set_phase(d_phase);
	}	


    /*
     * Our virtual destructor.
     */
    trapezoidal_impl::~trapezoidal_impl()
    {
    }

    int
    trapezoidal_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      float *out = (float *) output_items[0];

      // Do <+signal processing+>
	double rise_as_phase;
	double holdhigh_as_phase;
	double fall_as_phase;
	double sum;
	float t;

	sum = d_rise + d_fall + d_holdhigh + d_holdlow;
	rise_as_phase = ((d_rise  / sum)* 2*M_PI);
	holdhigh_as_phase = (((d_rise+d_holdhigh)/sum * 2*M_PI));
	fall_as_phase = (((d_rise+d_holdhigh+d_fall)/sum)* 2*M_PI);
	for(int i=0;i<noutput_items;i++) {
		double osc_phase = (d_nco.get_phase()+M_PI);
	  if (osc_phase < rise_as_phase)
	    t = (1*(osc_phase/rise_as_phase)*2*d_ampl - d_ampl);
	  else if(osc_phase < holdhigh_as_phase)
	     t = 1*d_ampl;
	  else if(osc_phase < fall_as_phase) {
	     double phase = fall_as_phase - holdhigh_as_phase;
	     double rel_phase = osc_phase - holdhigh_as_phase;
	     t = (-1*(rel_phase/phase)*2*d_ampl + d_ampl); }
	  else
	     t = -1*d_ampl;

	out[i] = t + d_offset;
	d_nco.step();
	}
      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace scopy */
} /* namespace gr */

