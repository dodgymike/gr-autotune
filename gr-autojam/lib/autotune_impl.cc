/* -*- c++ -*- */
/* 
 * Copyright 2016 <+YOU OR YOUR COMPANY+>.
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
#include "autotune_impl.h"

namespace gr {
  namespace signalfinder {

    autotune::sptr autotune::make(int sample_rate, int fft_size, int output_size)
    {
      return gnuradio::get_initial_sptr
        (new autotune_impl(sample_rate, fft_size, output_size));
    }

    /*
     * The private constructor
     */
    autotune_impl::autotune_impl(int sample_rate, int fft_size, int output_size)
      : gr::sync_block("autotune",
              gr::io_signature::make(1, 1, sizeof(gr_complex) * fft_size),
              gr::io_signature::make(1, 1, sizeof(gr_complex) * output_size)),
	m_fft_size(fft_size), m_sample_rate(sample_rate), m_output_size(output_size)
    {
    }

    /*
     * Our virtual destructor.
     */
    autotune_impl::~autotune_impl()
    {
    }

    int
    autotune_impl::work(int noutput_items,
			  gr_vector_const_void_star &input_items,
			  gr_vector_void_star &output_items)
    {
//        const gr_complex *in = (const gr_complex *) input_items[0];
//        gr_complex *out = (gr_complex *) output_items[0];

	int signal_index = 0;
	int signal_averaging_window_size = m_output_size / 10;
	int half_window_size = signal_averaging_window_size / 2;

	int half_output_row_size = m_output_size / 2;

        float max_average = 0.0f;
        for(int row_index = 0; row_index < (m_fft_size - signal_averaging_window_size); row_index++) {
          long sum = 0;
          for(int averaging_window_index = 0; averaging_window_index < signal_averaging_window_size; averaging_window_index++) {
            gr_complex* input_item = (gr_complex*)input_items[row_index + averaging_window_index];
            sum += abs(input_item->real());
          }
          float average = sum / signal_averaging_window_size;
          if(average > max_average) {
            signal_index = row_index + half_window_size;
            max_average = average;
          }
        }

        int output_start_index = find_output_start_index(signal_index, m_output_size, m_fft_size, half_output_row_size);

        int output_index = 0;
        for(int write_index = output_start_index; write_index < (output_start_index + m_output_size); write_index++) {
          *(gr_complex*)output_items[output_index] = *(gr_complex*)input_items[write_index];
        }
        for(; output_index < m_output_size; output_index++) {
          *(gr_complex*)output_items[output_index] = gr_complex(0,0);
        }

        // Tell runtime system how many output items we produced.
        return noutput_items;
    }

    int autotune_impl::find_output_start_index(int signal_index, int output_row_size, int row_size, int half_output_row_size) {
      int output_start_index = signal_index;

      // check for the top-end boundary
      if(output_start_index + output_row_size >= row_size) {
        output_start_index = row_size - output_row_size - 1;
      }

      // make sure the signal is in the middle
      output_start_index -= half_output_row_size;
      if(output_start_index < 0) {
        output_start_index = 0;
      }

      return output_start_index;
    }

  } /* namespace signalfinder */
} /* namespace gr */

