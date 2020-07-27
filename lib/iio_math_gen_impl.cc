/* -*- c++ -*- */
/* 
 * Copyright 2016 Analog Devices Inc.
 * Author: Paul Cercueil <paul.cercueil@analog.com>
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

#define _USE_MATH_DEFINES
#include <cmath>

#include "iio_math_impl.h"
#include "t_source_impl.h"

#include <gnuradio/analog/sig_source.h>
#include <gnuradio/analog/sig_source_waveform.h>
#include <gnuradio/io_signature.h>

using namespace gr;
using namespace gr::scopy;


iio_math_gen::sptr iio_math_gen::make(double sampling_freq,
		const std::string &function, uint64_t period_in_samples)
{
	return gnuradio::get_initial_sptr(new iio_math_gen_impl(
				sampling_freq, function, period_in_samples));
}

iio_math_gen_impl::iio_math_gen_impl(double sampling_freq, const std::string &function, uint64_t period_in_samples) : hier_block2("math_gen",
		io_signature::make(0, 0, 0),
		io_signature::make(1, 1, sizeof(float)))
{
	src_block = t_source::make(sampling_freq, period_in_samples);

	int ret = parse_function(function);
	if (ret)
		throw std::runtime_error("Invalid function");

	cleanup();
	src_block.reset();
}

gr::basic_block_sptr iio_math_gen_impl::get_src_block()
{
	return src_block;
}

void iio_math_gen_impl::connect_to_output(gr::basic_block_sptr block, unsigned int port)
{
	basic_block_sptr hier = shared_from_this();

	connect(block, 0, hier, 0);
}
