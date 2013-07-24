/*
 * isequal.c
 *
 * Code generation for function 'isequal'
 *
 * C source code generated on: Fri Aug 31 09:23:48 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_accumulator.h"
#include "isequal.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo w_emlrtRSI = { 8, "isequal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/isequal.m" };
static emlrtRSInfo x_emlrtRSI = { 30, "eml_isequal_core", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_isequal_core.m" };
static emlrtRSInfo y_emlrtRSI = { 56, "eml_isequal_core", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_isequal_core.m" };

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
boolean_T isequal(const emxArray_boolean_T *varargin_1)
{
    boolean_T p;
    boolean_T b_p;
    int32_T k;
    int32_T exitg1;
    int32_T i1;
    EMLRTPUSHRTSTACK(&w_emlrtRSI);
    p = FALSE;
    EMLRTPUSHRTSTACK(&x_emlrtRSI);
    EMLRTPUSHRTSTACK(&y_emlrtRSI);
    b_p = FALSE;
    k = 0;
    do {
        exitg1 = 0U;
        if (k < 2) {
            i1 = varargin_1->size[k];
            if (i1 != 0) {
                exitg1 = 1U;
            } else {
                k++;
            }
        } else {
            b_p = TRUE;
            exitg1 = 1U;
        }
    } while (exitg1 == 0U);
    EMLRTPOPRTSTACK(&y_emlrtRSI);
    if (b_p) {
        b_p = TRUE;
    } else {
        b_p = FALSE;
    }
    EMLRTPOPRTSTACK(&x_emlrtRSI);
    if (!b_p) {
    } else {
        p = TRUE;
    }
    EMLRTPOPRTSTACK(&w_emlrtRSI);
    return p;
}
/* End of code generation (isequal.c) */
