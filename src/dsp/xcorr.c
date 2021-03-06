/*
 * \file xcorr.c
 * \brief
 *    A target independent cross-correlation functionality
 *
 * This file is part of toolbox
 *
 * Copyright (C) 2014 Houtouridis Christos (http://www.houtouridis.net)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include <dsp/xcorr.h>


#define  _corr_body_r() {                             \
   int n, k, sy, kmin, kmax;                          \
                                                      \
   sy = sx + st - 1;                                  \
   --sx; --st; /* Convert to last point */            \
   for (n=0; n<sy; ++n) {                             \
      /* Find correlation range - zero padding */     \
      kmax = (n - st < 0)       ? n : st;             \
      kmin = ((k = n - sx) > 0) ? k : 0;              \
      for (y[n]=0, k=kmin; k<=kmax; ++k)              \
         /* Do the sum */                             \
         y[n] += t[k] * x[sx-(n-k)];                  \
  }                                                   \
}

#define  _corr_body_c() {                             \
   int n, k, sy, kmin, kmax;                          \
                                                      \
   sy = sx + st - 1;                                  \
   --sx; --st; /* Convert to last point */            \
   for (n=0; n<sy; ++n) {                             \
      /* Find correlation range - zero padding */     \
      kmax = (n - st < 0)       ? n : st;             \
      kmin = ((k = n - sx) > 0) ? k : 0;              \
      for (y[n]=0, k=kmin; k<=kmax; ++k)              \
         /* Do the sum */                             \
         y[n] += t[k] * conj(x[sx-(n-k)]);            \
  }                                                   \
}

/*!
 * \brief
 *    Calculates the cross-correlation of int t and x
 *
 *   y[n] = t[n] (x) x[n]
 *
 *            N-1
 * (t*x)[n] = Sum {t[m]*x[n+m]}
 *            m=0
 * n: [0 .. sizoef(t)+sizeof(x)-2]
 *
 * \param   y  Pointer to output vector
 * \param   t  Pointer to target vector, or signal 1
 * \param  st  Size of vector t
 * \param   x  Pointer to input signal, or signal 2
 * \param  sx  Size of input signal
 *
 * \return none
 */
void xcorr_i (int *y, int *t, int32_t st, int *x, int32_t sx) {
   _corr_body_r();
}

/*!
 * \brief
 *    Calculates the cross-correlation of float t and x
 *
 *   y[n] = t[n] (x) x[n]
 *
 *            N-1
 * (t*x)[n] = Sum {t[m]*x[n+m]}
 *            m=0
 * n: [0 .. sizoef(t)+sizeof(x)-2]
 *
 * \param   y  Pointer to output vector
 * \param   t  Pointer to target vector, or signal 1
 * \param  st  Size of vector t
 * \param   x  Pointer to input signal, or signal 2
 * \param  sx  Size of input signal
 *
 * \return none
 */
void xcorr_f (float *y, float *t, int32_t st, float *x, int32_t sx) {
   _corr_body_r();
}

/*!
 * \brief
 *    Calculates the cross-correlation of double t and x
 *
 *   y[n] = t[n] (x) x[n]
 *
 *            N-1
 * (t*x)[n] = Sum {t[m]*x[n+m]}
 *            m=0
 * n: [0 .. sizoef(t)+sizeof(x)-2]
 *
 * \param   y  Pointer to output vector
 * \param   t  Pointer to target vector, or signal 1
 * \param  st  Size of vector t
 * \param   x  Pointer to input signal, or signal 2
 * \param  sx  Size of input signal
 *
 * \return none
 */
void xcorr_d (double *y, double *t, int32_t st, double *x, int32_t sx) {
   _corr_body_r();
}

/*!
 * \brief
 *    Calculates the cross-correlation of complex int t and x
 *
 *   y[n] = t[n] (x) x[n]
 *
 *            N-1
 * (t*x)[n] = Sum {t'[m]*x[n+m]}
 *            m=0
 * n: [0 .. sizoef(t)+sizeof(x)-2]
 *
 * \param   y  Pointer to output vector
 * \param   t  Pointer to target vector, or signal 1
 * \param  st  Size of vector t
 * \param   x  Pointer to input signal, or signal 2
 * \param  sx  Size of input signal
 *
 * \return none
 */
void xcorr_ci (complex_i_t *y, complex_i_t *t, int32_t st, complex_i_t *x, int32_t sx) {
   _corr_body_c();
}

/*!
 * \brief
 *    Calculates the cross-correlation of complex float t and x
 *
 *   y[n] = t[n] (x) x[n]
 *
 *            N-1
 * (t*x)[n] = Sum {t'[m]*x[n+m]}
 *            m=0
 * n: [0 .. sizoef(t)+sizeof(x)-2]
 *
 * \param   y  Pointer to output vector
 * \param   t  Pointer to target vector, or signal 1
 * \param  st  Size of vector t
 * \param   x  Pointer to input signal, or signal 2
 * \param  sx  Size of input signal
 *
 * \return none
 */
void xcorr_cf (complex_f_t *y, complex_f_t *t, int32_t st, complex_f_t *x, int32_t sx) {
   _corr_body_c();
}

/*!
 * \brief
 *    Calculates the cross-correlation of complex double t and x
 *
 *   y[n] = t[n] (x) x[n]
 *
 *            N-1
 * (t*x)[n] = Sum {t'[m]*x[n+m]}
 *            m=0
 * n: [0 .. sizoef(t)+sizeof(x)-2]
 *
 * \param   y  Pointer to output vector
 * \param   t  Pointer to target vector, or signal 1
 * \param  st  Size of vector t
 * \param   x  Pointer to input signal, or signal 2
 * \param  sx  Size of input signal
 *
 * \return none
 */
void xcorr_cd (complex_d_t *y, complex_d_t *t, int32_t st, complex_d_t *x, int32_t sx) {
   _corr_body_c();
}
#undef _corr_body_r
#undef _corr_body_c

