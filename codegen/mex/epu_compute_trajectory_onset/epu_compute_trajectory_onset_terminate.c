/*
 * epu_compute_trajectory_onset_terminate.c
 *
 * Code generation for function 'epu_compute_trajectory_onset_terminate'
 *
 * C source code generated on: Fri Aug 31 09:24:09 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_compute_trajectory_onset.h"
#include "epu_compute_trajectory_onset_terminate.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

void epu_compute_trajectory_onset_atexit(void)
{
    emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void epu_compute_trajectory_onset_terminate(void)
{
    emlrtLeaveRtStack(&emlrtContextGlobal);
}
/* End of code generation (epu_compute_trajectory_onset_terminate.c) */
