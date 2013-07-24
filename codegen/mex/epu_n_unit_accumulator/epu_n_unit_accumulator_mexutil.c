/*
 * epu_n_unit_accumulator_mexutil.c
 *
 * Code generation for function 'epu_n_unit_accumulator_mexutil'
 *
 * C source code generated on: Fri Aug 31 09:23:48 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_accumulator.h"
#include "epu_n_unit_accumulator_mexutil.h"

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
    const mxArray *m11;
    pArray = b;
    return emlrtCallMATLAB(1, &m11, 1, &pArray, "message", TRUE, location);
}
/* End of code generation (epu_n_unit_accumulator_mexutil.c) */
