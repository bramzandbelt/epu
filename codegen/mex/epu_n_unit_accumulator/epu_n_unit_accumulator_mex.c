/*
 * epu_n_unit_accumulator_mex.c
 *
 * Code generation for function 'epu_n_unit_accumulator'
 *
 * C source code generated on: Fri Aug 31 09:23:48 2012
 *
 */

/* Include files */
#include "mex.h"
#include "epu_n_unit_accumulator_api.h"
#include "epu_n_unit_accumulator_data.h"
#include "epu_n_unit_accumulator_initialize.h"
#include "epu_n_unit_accumulator_terminate.h"

/* Type Definitions */

/* Function Declarations */
static void epu_n_unit_accumulator_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]);

/* Variable Definitions */
emlrtContext emlrtContextGlobal = { true, false, EMLRT_VERSION_INFO, NULL, "epu_n_unit_accumulator", NULL, false, NULL, false, 1, false };

/* Function Definitions */
static void epu_n_unit_accumulator_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Temporary copy for mex outputs. */
  mxArray *outputs[2];
  int n = 0;
  int nOutputs = (nlhs < 1 ? 1 : nlhs);
  epu_n_unit_accumulatorStackData* b_epu_n_unit_accumulatorStackDa = (epu_n_unit_accumulatorStackData*)mxCalloc(1,sizeof(epu_n_unit_accumulatorStackData));
  b_epu_n_unit_accumulatorStackDa->pd = epu_n_unit_accumulatorPersistentDataGlobal;
  /* Check for proper number of arguments. */
  if(nrhs != 12) {
    mexErrMsgIdAndTxt("emlcoder:emlmex:WrongNumberOfInputs","12 inputs required for entry-point 'epu_n_unit_accumulator'.");
  } else if(nlhs > 2) {
    mexErrMsgIdAndTxt("emlcoder:emlmex:TooManyOutputArguments","Too many output arguments for entry-point 'epu_n_unit_accumulator'.");
  }
  /* Module initialization. */
  epu_n_unit_accumulator_initialize(b_epu_n_unit_accumulatorStackDa, &emlrtContextGlobal);
  /* Call the function. */
  epu_n_unit_accumulator_api(b_epu_n_unit_accumulatorStackDa, prhs,(const mxArray**)outputs);
  /* Copy over outputs to the caller. */
  for (n = 0; n < nOutputs; ++n) {
    plhs[n] = emlrtReturnArrayR2009a(outputs[n]);
  }
  /* Module finalization. */
  epu_n_unit_accumulator_terminate();
  mxFree(b_epu_n_unit_accumulatorStackDa);
}
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Initialize the memory manager. */
  if (epu_n_unit_accumulatorPersistentDataGlobal == NULL) {
      epu_n_unit_accumulatorPersistentDataGlobal = (c_epu_n_unit_accumulatorPersist*)mxCalloc(1,sizeof(c_epu_n_unit_accumulatorPersist));
      mexMakeMemoryPersistent(epu_n_unit_accumulatorPersistentDataGlobal);
  }
  mexAtExit(epu_n_unit_accumulator_atexit);
  emlrtClearAllocCount(&emlrtContextGlobal, 0, 0, NULL);
  /* Dispatch the entry-point. */
  epu_n_unit_accumulator_mexFunction(nlhs, plhs, nrhs, prhs);
}
/* End of code generation (epu_n_unit_accumulator_mex.c) */
