/*
 * epu_compute_trajectory_onset_mexutil.c
 *
 * Code generation for function 'epu_compute_trajectory_onset_mexutil'
 *
 * C source code generated on: Fri Aug 31 09:24:08 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_compute_trajectory_onset.h"
#include "epu_compute_trajectory_onset_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

void c_error(const mxArray *b, emlrtMCInfo *location)
{
    const mxArray *pArray;
    pArray = b;
    emlrtCallMATLAB(0, NULL, 1, &pArray, "error", TRUE, location);
}

const mxArray *message(const mxArray *b, emlrtMCInfo *location)
{
    const mxArray *pArray;
    const mxArray *m12;
    pArray = b;
    return emlrtCallMATLAB(1, &m12, 1, &pArray, "message", TRUE, location);
}
/* End of code generation (epu_compute_trajectory_onset_mexutil.c) */
