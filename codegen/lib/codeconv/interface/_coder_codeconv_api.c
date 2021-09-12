/*
 * File: _coder_codeconv_api.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 11-Jul-2021 13:30:34
 */

/* Include Files */
#include "_coder_codeconv_api.h"
#include "_coder_codeconv_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131610U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "codeconv",                                           /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static const mxArray *emlrt_marshallOut(const real_T u_data[],
                                        const int32_T *u_size);

/* Function Definitions */
/*
 * Arguments    : const real_T u_data[]
 *                const int32_T *u_size
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const real_T u_data[],
                                        const int32_T *u_size)
{
  static const int32_T i = 0;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, u_size, 1);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const mxArray **plhs
 * Return Type  : void
 */
void codeconv_api(const mxArray **plhs)
{
  real_T(*b_data)[800];
  int32_T b_size;
  b_data = (real_T(*)[800])mxMalloc(sizeof(real_T[800]));
  /* Invoke the target function */
  codeconv(*b_data, *(int32_T(*)[1]) & b_size);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(*b_data, &b_size);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void codeconv_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  codeconv_xil_terminate();
  codeconv_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void codeconv_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void codeconv_terminate(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_codeconv_api.c
 *
 * [EOF]
 */
