/*
 * epu_n_unit_ba_mexutil.c
 *
 * Code generation for function 'epu_n_unit_ba_mexutil'
 *
 * C source code generated on: Tue Oct 30 14:49:26 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_ba.h"
#include "epu_n_unit_ba_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

void error(const mxArray *b, emlrtMCInfo *location)
{
    const mxArray *pArray;
    pArray = b;
    emlrtCallMATLAB(0, NULL, 1, &pArray, "error", TRUE, location);
}

const mxArray *message(const mxArray *b, emlrtMCInfo *location)
{
    const mxArray *pArray;
    const mxArray *m10;
    pArray = b;
    return emlrtCallMATLAB(1, &m10, 1, &pArray, "message", TRUE, location);
}
/* End of code generation (epu_n_unit_ba_mexutil.c) */
