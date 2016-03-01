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
#include "autojam_impl.h"

namespace gr {
  namespace autojam {

    autojam::sptr
    autojam::make(int decimation)
    {
      return gnuradio::get_initial_sptr
        (new autojam_impl(decimation));
    }

    /*
     * The private constructor
     */
    autojam_impl::autojam_impl(int decimation)
      : gr::sync_block("autojam",
              gr::io_signature::make(1, 1, sizeof(int8_t)),
              gr::io_signature::make(1, 1, sizeof(int8_t)))
    {
      d_last_bit = 0;
      d_one_count = 0;
      d_zero_count = 0;
      d_max_symbol_bits = 256;
      d_symbol_index = 0;

      d_jam = 0;
    }

    /*
     * Our virtual destructor.
     */
    autojam_impl::~autojam_impl()
    {
    }

    int
    autojam_impl::work(int noutput_items,
			  gr_vector_const_void_star &input_items,
			  gr_vector_void_star &output_items)
    {
        const int8_t *in = (const int8_t *) input_items[0];
        int8_t * out = (int8_t  *) output_items[0];

      unsigned char cur_bit;
      for(int i = 0; i < noutput_items; i++) {
        cur_bit = in[i];
        if((cur_bit ^ d_last_bit) && (cur_bit)) {
          float total_count = d_one_count + d_zero_count;
          float on_off_ratio = (float)d_one_count / total_count;
          int on_off = (on_off_ratio > 0.6f);

          if(d_symbol_index >= (d_max_symbol_bits + 1)) {
            d_symbol_index = 0;
          }

          d_symbol_bits[d_symbol_index++] = on_off;

          d_one_count = 0;
          d_zero_count = 0;
        }

        if(!cur_bit) {
          if(d_one_count + d_zero_count > 2) {
            if(d_zero_count > (d_one_count * 4)) {
              if(d_symbol_index > 1) {
                printf("got a code: ");
                for(int i = 0; i < d_symbol_index; i++) {
                  printf("%d", d_symbol_bits[i]);
                }
                printf("\n");

                if(d_symbol_index == 12) {
                  printf("JAM TIME!\n");
                  d_jam = 1;
                } else {
                  printf("NO MORE JAM TIME!\n");
                  d_jam = 0;
                }

                d_symbol_index = 0;
                d_one_count = 0;
                d_zero_count = 0;
              }
            }
          }
        }

        if(cur_bit) {
          d_one_count++;
        } else {
          d_zero_count++;
        }

        d_last_bit = cur_bit;

        out[i] = d_jam;
      }

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace autojam */
} /* namespace gr */

