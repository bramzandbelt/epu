/*
 * epu_n_unit_ba_mex.c
 *
 * Code generation for function 'epu_n_unit_ba'
 *
 * C source code generated on: Tue Oct 30 14:49:26 2012
 *
 */

/* Include files */
#include "mex.h"
#include "epu_n_unit_ba_api.h"
#include "epu_n_unit_ba_initialize.h"
#include "epu_n_unit_ba_terminate.h"

/* Type Definitions */

/* Function Declarations */
static void epu_n_unit_ba_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]);

/* Variable Definitions */
emlrtContext emlrtContextGlobal = { true, false, EMLRT_VERSION_INFO, NULL, "epu_n_unit_ba", NULL, false, NULL, false, 1, false };

/* Function Definitions */
static void epu_n_unit_ba_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Temporary copy for mex outputs. */
  mxArray *outputs[2];
  int n = 0;
  int nOutputs = (nlhs < 1 ? 1 : nlhs);
  /* Check for proper number of arguments. */
  if(nrhs != 8) {
    mexErrMsgIdAndTxt("emlcoder:emlmex:WrongNumberOfInputs","8 inputs required for entry-point 'epu_n_unit_ba'.");
  } else if(nlhs > 2) {
    mexErrMsgIdAndTxt("emlcoder:emlmex:TooManyOutputArguments","Too many output arguments for entry-point 'epu_n_unit_ba'.");
  }
  /* Module initialization. */
  epu_n_unit_ba_initialize(&emlrtContextGlobal);
  /* Call the function. */
  epu_n_unit_ba_api(prhs,(const mxArray**)outputs);
  /* Copy over outputs to the caller. */
  for (n = 0; n < nOutputs; ++n) {
    plhs[n] = emlrtReturnArrayR2009a(outputs[n]);
  }
  /* Module finalization. */
  epu_n_unit_ba_terminate();
}
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(epu_n_unit_ba_atexit);
  emlrtClearAllocCount(&emlrtContextGlobal, 0, 0, NULL);
  /* Dispatch the entry-point. */
  epu_n_unit_ba_mexFunction(nlhs, plhs, nrhs, prhs);
}
/* End of code generation (epu_n_unit_ba_mex.c) */
