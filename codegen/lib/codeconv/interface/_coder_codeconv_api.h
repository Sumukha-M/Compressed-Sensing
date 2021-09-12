/*
 * File: _coder_codeconv_api.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 11-Jul-2021 13:30:34
 */

#ifndef _CODER_CODECONV_API_H
#define _CODER_CODECONV_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void codeconv(real_T b_data[], int32_T b_size[1]);

void codeconv_api(const mxArray **plhs);

void codeconv_atexit(void);

void codeconv_initialize(void);

void codeconv_terminate(void);

void codeconv_xil_shutdown(void);

void codeconv_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_codeconv_api.h
 *
 * [EOF]
 */
