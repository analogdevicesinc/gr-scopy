#ifndef INCLUDED_SCOPY_IMPL_GOERTZEL_H
#define INCLUDED_SCOPY_IMPL_GOERTZEL_H

#include <scopy/api.h>
#include <gnuradio/types.h>

namespace gr {
  namespace scopy {

    /*!
     * \brief Implements Goertzel single-bin DFT calculation
     * \ingroup misc
     */
    class SCOPY_API goertzel_scopy
    {
    public:
      goertzel_scopy(int rate, int len, float freq);

      void set_params(int rate, int len, float freq);

      // Process a input array
      gr_complex batch(float *in);

      // Process sample by sample
      void input(const float &in);
      gr_complex output();
      bool ready() const { return d_processed == d_len; }

    private:
      float d_d1;
      float d_d2;
      float d_wr;
      float d_wi;
      int   d_len;
      int   d_processed;
    };

  } /* namespace scopy */
} /* namespace gr */

#endif /* INCLUDED_SCOPY_IMPL_GOERTZEL_H */
