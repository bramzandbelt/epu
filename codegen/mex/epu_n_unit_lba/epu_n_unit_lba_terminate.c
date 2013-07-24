/*
 * epu_n_unit_lba_terminate.c
 *
 * Code generation for function 'epu_n_unit_lba_terminate'
 *
 * C source code generated on: Fri Aug 31 09:31:05 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_lba.h"
#include "epu_n_unit_lba_terminate.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

void epu_n_unit_lba_atexit(void)
{
    emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void epu_n_unit_lba_terminate(void)
{
    emlrtLeaveRtStack(&emlrtContextGlobal);
}
/* End of code generation (epu_n_unit_lba_terminate.c) */
