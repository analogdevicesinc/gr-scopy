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


#ifndef INCLUDED_SCOPY_MATH_H
#define INCLUDED_SCOPY_MATH_H

#include <scopy/api.h>
#include <gnuradio/hier_block2.h>

namespace gr {
	namespace scopy {
		class SCOPY_API iio_math : virtual public gr::hier_block2
		{
		public:
			typedef boost::shared_ptr<iio_math> sptr;

			static sptr make(const std::string &function,
					int ninputs = 1);
		};

		class SCOPY_API iio_math_gen : virtual public gr::hier_block2
		{
		public:
			typedef boost::shared_ptr<iio_math_gen> sptr;

			static sptr make(double sampling_freq,
					const std::string &function,
					uint64_t period_in_samples = 0);
		};
	}
}

#endif /* INCLUDED_SCOPY_MATH_H */
