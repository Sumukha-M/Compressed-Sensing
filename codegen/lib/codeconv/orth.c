/*
 * File: orth.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 11-Jul-2021 13:30:34
 */

/* Include Files */
#include "orth.h"
#include "codeconv_emxutil.h"
#include "codeconv_types.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const double A[1600000]
 *                emxArray_real_T *Q
 * Return Type  : void
 */
void orth(const double A[1600000], emxArray_real_T *Q)
{
  static double U[1600000];
  double s[800];
  double absx;
  int exponent;
  int i;
  int i1;
  int r;
  svd(A, U, s);
  r = -1;
  absx = fabs(s[0]);
  if ((!rtIsInf(absx)) && (!rtIsNaN(absx))) {
    if (absx <= 2.2250738585072014E-308) {
      absx = 4.94065645841247E-324;
    } else {
      frexp(absx, &exponent);
      absx = ldexp(1.0, exponent - 53);
    }
  } else {
    absx = rtNaN;
  }
  absx *= 2000.0;
  for (exponent = 0; exponent < 800; exponent++) {
    r += (s[exponent] > absx);
  }
  if (1 > r + 1) {
    exponent = -1;
  } else {
    exponent = r;
  }
  i = Q->size[0] * Q->size[1];
  Q->size[0] = 2000;
  Q->size[1] = exponent + 1;
  emxEnsureCapacity_real_T(Q, i);
  for (i = 0; i <= exponent; i++) {
    for (i1 = 0; i1 < 2000; i1++) {
      r = i1 + 2000 * i;
      Q->data[r] = U[r];
    }
  }
}

/*
 * File trailer for orth.c
 *
 * [EOF]
 */
