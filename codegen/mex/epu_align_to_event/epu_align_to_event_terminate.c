/*
 * epu_align_to_event_terminate.c
 *
 * Code generation for function 'epu_align_to_event_terminate'
 *
 * C source code generated on: Fri Aug 31 09:30:57 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_align_to_event.h"
#include "epu_align_to_event_terminate.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

void epu_align_to_event_atexit(void)
{
    emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void epu_align_to_event_terminate(void)
{
    emlrtLeaveRtStack(&emlrtContextGlobal);
}
/* End of code generation (epu_align_to_event_terminate.c) */
