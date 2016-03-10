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


#ifndef INCLUDED_SIGNALFINDER_AUTOTUNE_H
#define INCLUDED_SIGNALFINDER_AUTOTUNE_H

#include <signalfinder/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace signalfinder {

    /*!
     * \brief <+description of block+>
     * \ingroup signalfinder
     *
     */
    class SIGNALFINDER_API autotune : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<autotune> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of signalfinder::autotune.
       *
       * To avoid accidental use of raw pointers, signalfinder::autotune's
       * constructor is in a private implementation
       * class. signalfinder::autotune::make is the public interface for
       * creating new instances.
       */
      static sptr make(int sample_rate, int fft_size, int output_size);
    };

  } // namespace signalfinder
} // namespace gr

#endif /* INCLUDED_SIGNALFINDER_AUTOTUNE_H */

