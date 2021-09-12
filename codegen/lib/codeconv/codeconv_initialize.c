/*
 * File: codeconv_initialize.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 11-Jul-2021 13:30:34
 */

/* Include Files */
#include "codeconv_initialize.h"
#include "codeconv_data.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void codeconv_initialize(void)
{
  rt_InitInfAndNaN();
  c_eml_rand_mt19937ar_stateful_i();
  isInitialized_codeconv = true;
}

/*
 * File trailer for codeconv_initialize.c
 *
 * [EOF]
 */
