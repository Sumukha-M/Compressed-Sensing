/*
 * File: xaxpy.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 11-Jul-2021 13:30:34
 */

#ifndef XAXPY_H
#define XAXPY_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_xaxpy(int n, double a, const double x[1600000], int ix0, double y[2000],
             int iy0);

void c_xaxpy(int n, double a, const double x[2000], int ix0, double y[1600000],
             int iy0);

void xaxpy(int n, double a, int ix0, double y[1600000], int iy0);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for xaxpy.h
 *
 * [EOF]
 */
