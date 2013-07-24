/*
 * all.c
 *
 * Code generation for function 'all'
 *
 * C source code generated on: Fri Aug 31 09:23:48 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_accumulator.h"
#include "all.h"
#include "interp1.h"
#include "isequal.h"
#include "epu_n_unit_accumulator_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo s_emlrtRSI = { 12, "all", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/all.m" };
static emlrtRSInfo t_emlrtRSI = { 24, "eml_all_or_any", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_all_or_any.m" };
static emlrtRSInfo u_emlrtRSI = { 24, "eml_all_or_any", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_all_or_any.m" };
static emlrtRSInfo v_emlrtRSI = { 27, "eml_all_or_any", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_all_or_any.m" };
static emlrtMCInfo emlrtMCI = { 25, 9, "eml_all_or_any", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_all_or_any.m" };
static emlrtMCInfo b_emlrtMCI = { 24, 19, "eml_all_or_any", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_all_or_any.m" };
static emlrtMCInfo c_emlrtMCI = { 30, 9, "eml_all_or_any", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_all_or_any.m" };
static emlrtMCInfo d_emlrtMCI = { 27, 19, "eml_all_or_any", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_all_or_any.m" };
static emlrtBCInfo jc_emlrtBCI = { -1, -1, 111, 24, "", "eml_all_or_any", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_all_or_any.m", 0 };

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
boolean_T all(const emxArray_boolean_T *x)
{
    boolean_T y;
    boolean_T b0;
    const mxArray *b_y;
    static const int32_T iv10[2] = { 1, 41 };
    const mxArray *m1;
    static const char_T cv5[41] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r', '_', 'a', 'n', 'y', '_', 's', 'p', 'e', 'c', 'i', 'a', 'l', 'E', 'm', 'p', 't', 'y' };
    const mxArray *c_y;
    static const int32_T iv11[2] = { 1, 51 };
    static const char_T cv6[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r', '_', 'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };
    int32_T i2;
    int32_T ix;
    boolean_T exitg1;
    EMLRTPUSHRTSTACK(&s_emlrtRSI);
    EMLRTPUSHRTSTACK(&t_emlrtRSI);
    b0 = !isequal(x);
    EMLRTPOPRTSTACK(&t_emlrtRSI);
    if (b0) {
        b0 = TRUE;
    } else {
        b0 = FALSE;
    }
    if (b0) {
    } else {
        EMLRTPUSHRTSTACK(&u_emlrtRSI);
        b_y = NULL;
        m1 = mxCreateCharArray(2, iv10);
        emlrtInitCharArray(41, m1, cv5);
        emlrtAssign(&b_y, m1);
        error(message(b_y, &emlrtMCI), &b_emlrtMCI);
        EMLRTPOPRTSTACK(&u_emlrtRSI);
    }
    if ((x->size[1] == 1) || (x->size[1] != 1)) {
        b0 = TRUE;
    } else {
        b0 = FALSE;
    }
    if (b0) {
    } else {
        EMLRTPUSHRTSTACK(&v_emlrtRSI);
        c_y = NULL;
        m1 = mxCreateCharArray(2, iv11);
        emlrtInitCharArray(51, m1, cv6);
        emlrtAssign(&c_y, m1);
        error(message(c_y, &c_emlrtMCI), &d_emlrtMCI);
        EMLRTPOPRTSTACK(&v_emlrtRSI);
    }
    y = TRUE;
    i2 = x->size[1];
    ix = 1;
    exitg1 = 0U;
    while ((exitg1 == 0U) && (ix <= i2)) {
        if (x->data[emlrtDynamicBoundsCheck(ix, 1, x->size[1], &jc_emlrtBCI) - 1] == 0) {
            y = FALSE;
            exitg1 = 1U;
        } else {
            ix++;
        }
    }
    EMLRTPOPRTSTACK(&s_emlrtRSI);
    return y;
}
/* End of code generation (all.c) */
