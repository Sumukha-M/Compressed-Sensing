/*
 * File: xrot.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 11-Jul-2021 13:30:34
 */

/* Include Files */
#include "xrot.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : double x[1600000]
 *                int ix0
 *                int iy0
 *                double c
 *                double s
 * Return Type  : void
 */
void xrot(double x[1600000], int ix0, int iy0, double c, double s)
{
  double b_temp_tmp;
  double d_temp_tmp;
  int c_temp_tmp;
  int k;
  int temp_tmp;
  for (k = 0; k < 2000; k++) {
    temp_tmp = (iy0 + k) - 1;
    b_temp_tmp = x[temp_tmp];
    c_temp_tmp = (ix0 + k) - 1;
    d_temp_tmp = x[c_temp_tmp];
    x[temp_tmp] = c * b_temp_tmp - s * d_temp_tmp;
    x[c_temp_tmp] = c * d_temp_tmp + s * b_temp_tmp;
  }
}

/*
 * File trailer for xrot.c
 *
 * [EOF]
 */
