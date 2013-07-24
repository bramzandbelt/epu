/*
 * exp.c
 *
 * Code generation for function 'exp'
 *
 * C source code generated on: Tue Oct 30 14:49:26 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_ba.h"
#include "exp.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtBCInfo xd_emlrtBCI = { 0, MAX_int32_T, 11, 11, "", "exp", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elfun/exp.m", 0 };
static emlrtBCInfo yd_emlrtBCI = { -1, -1, 12, 27, "", "exp", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elfun/exp.m", 0 };
static emlrtBCInfo ae_emlrtBCI = { -1, -1, 12, 5, "", "exp", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elfun/exp.m", 0 };

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
void b_exp(emxArray_real_T *x)
{
    int32_T i7;
    int32_T k;
    i7 = emlrtBoundsCheck(x->size[0] * x->size[1], &xd_emlrtBCI);
    for (k = 0; k <= i7 - 1; k++) {
        emlrtDynamicBoundsCheck((int32_T)(1.0 + (real_T)k), 1, x->size[0] * x->size[1], &yd_emlrtBCI);
        x->data[emlrtDynamicBoundsCheck(1 + k, 1, x->size[0] * x->size[1], &ae_emlrtBCI) - 1] = muDoubleScalarExp(x->data[k]);
    }
}
/* End of code generation (exp.c) */
