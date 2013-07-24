/*
 * epu_compute_trajectory_onset_mex.c
 *
 * Code generation for function 'epu_compute_trajectory_onset'
 *
 * C source code generated on: Fri Aug 31 09:24:09 2012
 *
 */

/* Include files */
#include "mex.h"
#include "epu_compute_trajectory_onset_api.h"
#include "epu_compute_trajectory_onset_initialize.h"
#include "epu_compute_trajectory_onset_terminate.h"

/* Type Definitions */

/* Function Declarations */
static void epu_compute_trajectory_onset_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]);

/* Variable Definitions */
emlrtContext emlrtContextGlobal = { true, false, EMLRT_VERSION_INFO, NULL, "epu_compute_trajectory_onset", NULL, false, NULL, false, 1, false };

/* Function Definitions */
static void epu_compute_trajectory_onset_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Temporary copy for mex outputs. */
  mxArray *outputs[1];
  int n = 0;
  int nOutputs = (nlhs < 1 ? 1 : nlhs);
  /* Check for proper number of arguments. */
  if(nrhs != 3) {
    mexErrMsgIdAndTxt("emlcoder:emlmex:WrongNumberOfInputs","3 inputs required for entry-point 'epu_compute_trajectory_onset'.");
  } else if(nlhs > 1) {
    mexErrMsgIdAndTxt("emlcoder:emlmex:TooManyOutputArguments","Too many output arguments for entry-point 'epu_compute_trajectory_onset'.");
  }
  /* Module initialization. */
  epu_compute_trajectory_onset_initialize(&emlrtContextGlobal);
  /* Call the function. */
  epu_compute_trajectory_onset_api(prhs,(const mxArray**)outputs);
  /* Copy over outputs to the caller. */
  for (n = 0; n < nOutputs; ++n) {
    plhs[n] = emlrtReturnArrayR2009a(outputs[n]);
  }
  /* Module finalization. */
  epu_compute_trajectory_onset_terminate();
}
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(epu_compute_trajectory_onset_atexit);
  emlrtClearAllocCount(&emlrtContextGlobal, 0, 0, NULL);
  /* Dispatch the entry-point. */
  epu_compute_trajectory_onset_mexFunction(nlhs, plhs, nrhs, prhs);
}
/* End of code generation (epu_compute_trajectory_onset_mex.c) */
