/*
 * rdivide.c
 *
 * Code generation for function 'rdivide'
 *
 * C source code generated on: Tue Oct 30 14:49:26 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_ba.h"
#include "rdivide.h"
#include "epu_n_unit_ba_emxutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo w_emlrtRSI = { 13, "rdivide", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/rdivide.m" };
static emlrtRSInfo bc_emlrtRSI = { 13, "rdivide", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/rdivide.m" };
static emlrtRTEInfo m_emlrtRTEI = { 1, 14, "rdivide", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/rdivide.m" };
static emlrtRTEInfo q_emlrtRTEI = { 1, 14, "rdivide", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/rdivide.m" };
static emlrtECInfo n_emlrtECI = { 2, 16, 9, "eml_div", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_div.m" };
static emlrtECInfo o_emlrtECI = { 2, 16, 9, "eml_div", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_div.m" };

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
void b_rdivide(const emxArray_real_T *x, const emxArray_real_T *y, emxArray_real_T *z)
{
    int32_T b_x[2];
    int32_T i1;
    int32_T b_y[2];
    int32_T loop_ub;
    EMLRTPUSHRTSTACK(&bc_emlrtRSI);
    for (i1 = 0; i1 < 2; i1++) {
        b_x[i1] = x->size[i1];
    }
    for (i1 = 0; i1 < 2; i1++) {
        b_y[i1] = y->size[i1];
    }
    emlrtSizeEqCheckND(b_x, b_y, &o_emlrtECI);
    i1 = z->size[0] * z->size[1];
    z->size[0] = x->size[0];
    z->size[1] = x->size[1];
    emxEnsureCapacity((emxArray__common *)z, i1, (int32_T)sizeof(real_T), &q_emlrtRTEI);
    loop_ub = x->size[0] * x->size[1] - 1;
    for (i1 = 0; i1 <= loop_ub; i1++) {
        z->data[i1] = x->data[i1] / y->data[i1];
    }
    EMLRTPOPRTSTACK(&bc_emlrtRSI);
}

/*
 * 
 */
void rdivide(const emxArray_real_T *x, const emxArray_real_T *y, emxArray_real_T *z)
{
    int32_T b_x[2];
    int32_T i0;
    int32_T b_y[2];
    int32_T loop_ub;
    EMLRTPUSHRTSTACK(&w_emlrtRSI);
    for (i0 = 0; i0 < 2; i0++) {
        b_x[i0] = x->size[i0];
    }
    for (i0 = 0; i0 < 2; i0++) {
        b_y[i0] = y->size[i0];
    }
    emlrtSizeEqCheckND(b_x, b_y, &n_emlrtECI);
    i0 = z->size[0] * z->size[1];
    z->size[0] = 1;
    z->size[1] = x->size[1];
    emxEnsureCapacity((emxArray__common *)z, i0, (int32_T)sizeof(real_T), &m_emlrtRTEI);
    loop_ub = x->size[0] * x->size[1] - 1;
    for (i0 = 0; i0 <= loop_ub; i0++) {
        z->data[i0] = x->data[i0] / y->data[i0];
    }
    EMLRTPOPRTSTACK(&w_emlrtRSI);
}
/* End of code generation (rdivide.c) */
