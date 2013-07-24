/*
 * ceil.c
 *
 * Code generation for function 'ceil'
 *
 * C source code generated on: Tue Oct 30 14:49:26 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_ba.h"
#include "ceil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtBCInfo ud_emlrtBCI = { 0, MAX_int32_T, 11, 11, "", "ceil", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elfun/ceil.m", 0 };
static emlrtBCInfo vd_emlrtBCI = { -1, -1, 12, 28, "", "ceil", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elfun/ceil.m", 0 };
static emlrtBCInfo wd_emlrtBCI = { -1, -1, 12, 5, "", "ceil", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elfun/ceil.m", 0 };

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
void b_ceil(emxArray_real_T *x)
{
    int32_T i6;
    int32_T k;
    emlrtBoundsCheck(x->size[1], &ud_emlrtBCI);
    i6 = x->size[1];
    for (k = 0; k <= i6 - 1; k++) {
        emlrtDynamicBoundsCheck((int32_T)(1.0 + (real_T)k), 1, x->size[1], &vd_emlrtBCI);
        x->data[emlrtDynamicBoundsCheck((int32_T)(1.0 + (real_T)k), 1, x->size[1], &wd_emlrtBCI) - 1] = muDoubleScalarCeil(x->data[(int32_T)(1.0 + (real_T)k) - 1]);
    }
}
/* End of code generation (ceil.c) */
