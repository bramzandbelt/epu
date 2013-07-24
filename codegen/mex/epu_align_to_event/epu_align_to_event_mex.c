/*
 * epu_align_to_event_mex.c
 *
 * Code generation for function 'epu_align_to_event'
 *
 * C source code generated on: Fri Aug 31 09:30:57 2012
 *
 */

/* Include files */
#include "mex.h"
#include "epu_align_to_event_api.h"
#include "epu_align_to_event_initialize.h"
#include "epu_align_to_event_terminate.h"

/* Type Definitions */

/* Function Declarations */
static void epu_align_to_event_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]);

/* Variable Definitions */
emlrtContext emlrtContextGlobal = { true, false, EMLRT_VERSION_INFO, NULL, "epu_align_to_event", NULL, false, NULL, false, 1, false };

/* Function Definitions */
static void epu_align_to_event_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Temporary copy for mex outputs. */
  mxArray *outputs[1];
  int n = 0;
  int nOutputs = (nlhs < 1 ? 1 : nlhs);
  /* Check for proper number of arguments. */
  if(nrhs != 4) {
    mexErrMsgIdAndTxt("emlcoder:emlmex:WrongNumberOfInputs","4 inputs required for entry-point 'epu_align_to_event'.");
  } else if(nlhs > 1) {
    mexErrMsgIdAndTxt("emlcoder:emlmex:TooManyOutputArguments","Too many output arguments for entry-point 'epu_align_to_event'.");
  }
  /* Module initialization. */
  epu_align_to_event_initialize(&emlrtContextGlobal);
  /* Call the function. */
  epu_align_to_event_api(prhs,(const mxArray**)outputs);
  /* Copy over outputs to the caller. */
  for (n = 0; n < nOutputs; ++n) {
    plhs[n] = emlrtReturnArrayR2009a(outputs[n]);
  }
  /* Module finalization. */
  epu_align_to_event_terminate();
}
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(epu_align_to_event_atexit);
  emlrtClearAllocCount(&emlrtContextGlobal, 0, 0, NULL);
  /* Dispatch the entry-point. */
  epu_align_to_event_mexFunction(nlhs, plhs, nrhs, prhs);
}
/* End of code generation (epu_align_to_event_mex.c) */
