/*
 * File: _coder_codeconv_mex.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 11-Jul-2021 13:30:34
 */

#ifndef _CODER_CODECONV_MEX_H
#define _CODER_CODECONV_MEX_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS(void);

void unsafe_codeconv_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_codeconv_mex.h
 *
 * [EOF]
 */
