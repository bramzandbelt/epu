/*
 * sum.c
 *
 * Code generation for function 'sum'
 *
 * C source code generated on: Fri Aug 31 09:23:48 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_accumulator.h"
#include "sum.h"
#include "interp1.h"
#include "isequal.h"
#include "epu_n_unit_accumulator_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo sb_emlrtRSI = { 17, "sum", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/sum.m" };
static emlrtRSInfo tb_emlrtRSI = { 17, "sum", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/sum.m" };
static emlrtRSInfo ub_emlrtRSI = { 20, "sum", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/sum.m" };
static emlrtMCInfo l_emlrtMCI = { 18, 9, "sum", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/sum.m" };
static emlrtMCInfo m_emlrtMCI = { 17, 19, "sum", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/sum.m" };
static emlrtMCInfo n_emlrtMCI = { 23, 9, "sum", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/sum.m" };
static emlrtMCInfo o_emlrtMCI = { 20, 19, "sum", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/sum.m" };
static emlrtBCInfo pc_emlrtBCI = { -1, -1, 56, 22, "", "sum", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/sum.m", 0 };

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
real_T sum(const emxArray_boolean_T *x)
{
    real_T y;
    boolean_T b1;
    const mxArray *b_y;
    static const int32_T iv13[2] = { 1, 30 };
    const mxArray *m4;
    static const char_T cv8[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 's', 'u', 'm', '_', 's', 'p', 'e', 'c', 'i', 'a', 'l', 'E', 'm', 'p', 't', 'y' };
    const mxArray *c_y;
    static const int32_T iv14[2] = { 1, 36 };
    static const char_T cv9[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };
    int32_T vlen;
    int32_T k;
    EMLRTPUSHRTSTACK(&sb_emlrtRSI);
    b1 = !isequal(x);
    EMLRTPOPRTSTACK(&sb_emlrtRSI);
    if (b1) {
        b1 = TRUE;
    } else {
        b1 = FALSE;
    }
    if (b1) {
    } else {
        EMLRTPUSHRTSTACK(&tb_emlrtRSI);
        b_y = NULL;
        m4 = mxCreateCharArray(2, iv13);
        emlrtInitCharArray(30, m4, cv8);
        emlrtAssign(&b_y, m4);
        error(message(b_y, &l_emlrtMCI), &m_emlrtMCI);
        EMLRTPOPRTSTACK(&tb_emlrtRSI);
    }
    if ((x->size[1] == 1) || (x->size[1] != 1)) {
        b1 = TRUE;
    } else {
        b1 = FALSE;
    }
    if (b1) {
    } else {
        EMLRTPUSHRTSTACK(&ub_emlrtRSI);
        c_y = NULL;
        m4 = mxCreateCharArray(2, iv14);
        emlrtInitCharArray(36, m4, cv9);
        emlrtAssign(&c_y, m4);
        error(message(c_y, &n_emlrtMCI), &o_emlrtMCI);
        EMLRTPOPRTSTACK(&ub_emlrtRSI);
    }
    if (x->size[1] == 0) {
        y = 0.0;
    } else {
        vlen = x->size[1];
        y = (real_T)x->data[0];
        for (k = 2; k <= vlen; k++) {
            y += (real_T)x->data[emlrtDynamicBoundsCheck(k, 1, x->size[1], &pc_emlrtBCI) - 1];
        }
    }
    return y;
}
/* End of code generation (sum.c) */
