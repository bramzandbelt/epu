/*
 * epu_n_unit_ba_terminate.c
 *
 * Code generation for function 'epu_n_unit_ba_terminate'
 *
 * C source code generated on: Tue Oct 30 14:49:26 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_ba.h"
#include "epu_n_unit_ba_terminate.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

void epu_n_unit_ba_atexit(void)
{
    emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void epu_n_unit_ba_terminate(void)
{
    emlrtLeaveRtStack(&emlrtContextGlobal);
}
/* End of code generation (epu_n_unit_ba_terminate.c) */
