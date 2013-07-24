/*
 * epu_n_unit_accumulator_terminate.c
 *
 * Code generation for function 'epu_n_unit_accumulator_terminate'
 *
 * C source code generated on: Fri Aug 31 09:23:48 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_accumulator.h"
#include "epu_n_unit_accumulator_terminate.h"
#include "epu_n_unit_accumulator_data.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

void epu_n_unit_accumulator_atexit(void)
{
    emlrtExitTimeCleanup(&emlrtContextGlobal);
    mxFree(epu_n_unit_accumulatorPersistentDataGlobal);
}

void epu_n_unit_accumulator_terminate(void)
{
    emlrtLeaveRtStack(&emlrtContextGlobal);
}
/* End of code generation (epu_n_unit_accumulator_terminate.c) */
