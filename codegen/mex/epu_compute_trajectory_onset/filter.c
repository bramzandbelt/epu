/*
 * filter.c
 *
 * Code generation for function 'filter'
 *
 * C source code generated on: Fri Aug 31 09:24:08 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_compute_trajectory_onset.h"
#include "filter.h"
#include "epu_compute_trajectory_onset_emxutil.h"
#include "median.h"
#include "epu_compute_trajectory_onset_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo ti_emlrtRSI = { 17, "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m" };
static emlrtRSInfo ui_emlrtRSI = { 44, "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m" };
static emlrtRSInfo vi_emlrtRSI = { 144, "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m" };
static emlrtRSInfo wi_emlrtRSI = { 182, "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m" };
static emlrtRSInfo xi_emlrtRSI = { 42, "eml_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m" };
static emlrtRSInfo aj_emlrtRSI = { 25, "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m" };
static emlrtRSInfo bj_emlrtRSI = { 66, "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m" };
static emlrtRSInfo cj_emlrtRSI = { 42, "eml_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m" };
static emlrtRSInfo ej_emlrtRSI = { 25, "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m" };
static emlrtRSInfo fj_emlrtRSI = { 66, "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m" };
static emlrtMCInfo t_emlrtMCI = { 18, 5, "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m" };
static emlrtMCInfo u_emlrtMCI = { 17, 15, "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m" };
static emlrtMCInfo v_emlrtMCI = { 47, 9, "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m" };
static emlrtMCInfo w_emlrtMCI = { 44, 19, "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m" };
static emlrtRTEInfo rb_emlrtRTEI = { 115, 1, "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m" };
static emlrtRTEInfo sb_emlrtRTEI = { 124, 1, "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m" };
static emlrtRTEInfo tb_emlrtRTEI = { 1, 19, "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m" };
static emlrtRTEInfo ub_emlrtRTEI = { 153, 9, "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m" };
static emlrtRTEInfo vb_emlrtRTEI = { 153, 9, "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m" };
static emlrtRTEInfo wb_emlrtRTEI = { 1, 13, "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m" };
static emlrtBCInfo hn_emlrtBCI = { -1, -1, 66, 49, "", "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m", 0 };
static emlrtBCInfo in_emlrtBCI = { -1, -1, 66, 49, "", "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m", 0 };
static emlrtBCInfo jn_emlrtBCI = { -1, -1, 179, 53, "", "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m", 0 };
static emlrtBCInfo kn_emlrtBCI = { -1, -1, 179, 47, "", "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m", 0 };
static emlrtBCInfo ln_emlrtBCI = { -1, -1, 141, 40, "", "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m", 0 };
static emlrtBCInfo mn_emlrtBCI = { -1, -1, 141, 35, "", "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m", 0 };
static emlrtBCInfo nn_emlrtBCI = { -1, -1, 196, 16, "", "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m", 0 };
static emlrtBCInfo on_emlrtBCI = { -1, -1, 196, 23, "", "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m", 0 };
static emlrtBCInfo pn_emlrtBCI = { -1, -1, 172, 13, "", "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m", 0 };
static emlrtBCInfo qn_emlrtBCI = { -1, -1, 176, 58, "", "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m", 0 };
static emlrtBCInfo rn_emlrtBCI = { -1, -1, 182, 40, "", "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m", 0 };
static emlrtBCInfo sn_emlrtBCI = { -1, -1, 193, 13, "", "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m", 0 };
static emlrtBCInfo tn_emlrtBCI = { -1, -1, 179, 21, "", "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m", 0 };
static emlrtBCInfo un_emlrtBCI = { -1, -1, 179, 34, "", "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m", 0 };
static emlrtBCInfo vn_emlrtBCI = { -1, -1, 170, 17, "", "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m", 0 };
static emlrtBCInfo wn_emlrtBCI = { -1, -1, 170, 30, "", "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m", 0 };
static emlrtBCInfo xn_emlrtBCI = { -1, -1, 164, 17, "", "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m", 0 };
static emlrtBCInfo yn_emlrtBCI = { -1, -1, 135, 58, "", "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m", 0 };
static emlrtBCInfo ao_emlrtBCI = { -1, -1, 144, 33, "", "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m", 0 };
static emlrtBCInfo bo_emlrtBCI = { -1, -1, 67, 26, "", "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m", 0 };
static emlrtBCInfo co_emlrtBCI = { -1, -1, 141, 21, "", "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m", 0 };
static emlrtBCInfo do_emlrtBCI = { -1, -1, 141, 28, "", "filter", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/filter.m", 0 };

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
void filter(const emxArray_real_T *b, const emxArray_real_T *x, emxArray_real_T *y)
{
    const mxArray *b_y;
    static const int32_T iv25[2] = { 1, 36 };
    const mxArray *m9;
    static const char_T cv13[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'f', 'i', 'l', 't', 'e', 'r', '_', 'n', 'o', 't', 'V', 'e', 'c', 't', 'o', 'r', 'I', 'n', 'p', 'u', 't', 'B' };
    int32_T nb;
    int32_T ndbuffer;
    int32_T ndbufferm1;
    boolean_T b2;
    const mxArray *c_y;
    static const int32_T iv26[2] = { 1, 36 };
    static const char_T cv14[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };
    uint32_T uv1[2];
    int32_T j;
    emxArray_real_T *zf;
    int32_T nx;
    int32_T k;
    real_T a;
    int32_T incx;
    int32_T incy;
    emxArray_real_T *dbuffer;
    int32_T b_zf[2];
    emxArray_real_T c_zf;
    emlrtHeapReferenceStackEnterFcn();
    if (!(b->size[1] == 0)) {
    } else {
        EMLRTPUSHRTSTACK(&ti_emlrtRSI);
        b_y = NULL;
        m9 = mxCreateCharArray(2, iv25);
        emlrtInitCharArray(36, m9, cv13);
        emlrtAssign(&b_y, m9);
        c_error(message(b_y, &t_emlrtMCI), &u_emlrtMCI);
        EMLRTPOPRTSTACK(&ti_emlrtRSI);
    }
    nb = b->size[1];
    ndbuffer = muIntScalarMax_sint32(1, nb);
    ndbufferm1 = ndbuffer - 1;
    if ((x->size[1] == 1) || (x->size[1] != 1)) {
        b2 = TRUE;
    } else {
        b2 = FALSE;
    }
    if (b2) {
    } else {
        EMLRTPUSHRTSTACK(&ui_emlrtRSI);
        c_y = NULL;
        m9 = mxCreateCharArray(2, iv26);
        emlrtInitCharArray(36, m9, cv14);
        emlrtAssign(&c_y, m9);
        c_error(message(c_y, &v_emlrtMCI), &w_emlrtMCI);
        EMLRTPOPRTSTACK(&ui_emlrtRSI);
    }
    for (j = 0; j < 2; j++) {
        uv1[j] = (uint32_T)x->size[j];
    }
    b_emxInit_real_T(&zf, 1, &wb_emlrtRTEI, TRUE);
    j = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int32_T)uv1[1];
    emxEnsureCapacity((emxArray__common *)y, j, (int32_T)sizeof(real_T), &rb_emlrtRTEI);
    nx = x->size[1];
    j = zf->size[0];
    zf->size[0] = ndbufferm1;
    emxEnsureCapacity((emxArray__common *)zf, j, (int32_T)sizeof(real_T), &sb_emlrtRTEI);
    if (nx >= (nb << 1)) {
        j = y->size[0] * y->size[1];
        y->size[0] = 1;
        emxEnsureCapacity((emxArray__common *)y, j, (int32_T)sizeof(real_T), &tb_emlrtRTEI);
        ndbuffer = y->size[1] - 1;
        for (j = 0; j <= ndbuffer; j++) {
            y->data[y->size[0] * j] = 0.0;
        }
        for (k = 1; k <= nb; k++) {
            ndbuffer = (nx - k) + 1;
            if ((b->data[emlrtDynamicBoundsCheck(k, 1, b->size[1], &yn_emlrtBCI) - 1] == 0.0) || (ndbuffer < 23)) {
                ndbuffer = (k + nx) - k;
                for (j = k; j <= ndbuffer; j++) {
                    emlrtDynamicBoundsCheck(k, 1, b->size[1], &mn_emlrtBCI);
                    emlrtDynamicBoundsCheck((j - k) + 1, 1, x->size[1], &ln_emlrtBCI);
                    y->data[emlrtDynamicBoundsCheck(j, 1, y->size[1], &co_emlrtBCI) - 1] = y->data[emlrtDynamicBoundsCheck(j, 1, y->size[1], &do_emlrtBCI) - 1] + b->data[k - 1] * x->data[j - k];
                }
            } else {
                EMLRTPUSHRTSTACK(&vi_emlrtRSI);
                a = b->data[emlrtDynamicBoundsCheck(k, 1, b->size[1], &ao_emlrtBCI) - 1];
                EMLRTPUSHRTSTACK(&xi_emlrtRSI);
                EMLRTPUSHRTSTACK(&aj_emlrtRSI);
                incx = 1;
                incy = 1;
                EMLRTPUSHRTSTACK(&bj_emlrtRSI);
                emlrtDynamicBoundsCheck(1, 1, x->size[1], &hn_emlrtBCI);
                daxpy32(&ndbuffer, &a, &x->data[0], &incx, &y->data[emlrtDynamicBoundsCheck(k, 1, y->size[1], &bo_emlrtBCI) - 1], &incy);
                EMLRTPOPRTSTACK(&bj_emlrtRSI);
                EMLRTPOPRTSTACK(&aj_emlrtRSI);
                EMLRTPOPRTSTACK(&xi_emlrtRSI);
                EMLRTPOPRTSTACK(&vi_emlrtRSI);
            }
        }
    } else {
        b_emxInit_real_T(&dbuffer, 1, &vb_emlrtRTEI, TRUE);
        j = dbuffer->size[0];
        dbuffer->size[0] = ndbuffer;
        emxEnsureCapacity((emxArray__common *)dbuffer, j, (int32_T)sizeof(real_T), &ub_emlrtRTEI);
        for (k = 1; k <= ndbufferm1; k++) {
            dbuffer->data[emlrtDynamicBoundsCheck(k + 1, 1, dbuffer->size[0], &xn_emlrtBCI) - 1] = 0.0;
        }
        for (j = 1; j <= nx; j++) {
            for (k = 1; k <= ndbufferm1; k++) {
                dbuffer->data[emlrtDynamicBoundsCheck(k, 1, dbuffer->size[0], &vn_emlrtBCI) - 1] = dbuffer->data[emlrtDynamicBoundsCheck(k + 1, 1, dbuffer->size[0], &wn_emlrtBCI) - 1];
            }
            dbuffer->data[emlrtDynamicBoundsCheck(ndbuffer, 1, dbuffer->size[0], &pn_emlrtBCI) - 1] = 0.0;
            if ((x->data[emlrtDynamicBoundsCheck(j, 1, x->size[1], &qn_emlrtBCI) - 1] == 0.0) || (nb < 23)) {
                for (k = 1; k <= nb; k++) {
                    emlrtDynamicBoundsCheck(j, 1, x->size[1], &kn_emlrtBCI);
                    emlrtDynamicBoundsCheck(k, 1, b->size[1], &jn_emlrtBCI);
                    dbuffer->data[emlrtDynamicBoundsCheck(k, 1, dbuffer->size[0], &tn_emlrtBCI) - 1] = dbuffer->data[emlrtDynamicBoundsCheck(k, 1, dbuffer->size[0], &un_emlrtBCI) - 1] + x->data[j - 1] * b->data[k - 1];
                }
            } else {
                EMLRTPUSHRTSTACK(&wi_emlrtRSI);
                a = x->data[emlrtDynamicBoundsCheck(j, 1, x->size[1], &rn_emlrtBCI) - 1];
                EMLRTPUSHRTSTACK(&cj_emlrtRSI);
                EMLRTPUSHRTSTACK(&ej_emlrtRSI);
                incx = 1;
                incy = 1;
                EMLRTPUSHRTSTACK(&fj_emlrtRSI);
                emlrtDynamicBoundsCheck(1, 1, b->size[1], &in_emlrtBCI);
                daxpy32(&nb, &a, &b->data[0], &incx, &dbuffer->data[0], &incy);
                EMLRTPOPRTSTACK(&fj_emlrtRSI);
                EMLRTPOPRTSTACK(&ej_emlrtRSI);
                EMLRTPOPRTSTACK(&cj_emlrtRSI);
                EMLRTPOPRTSTACK(&wi_emlrtRSI);
            }
            y->data[emlrtDynamicBoundsCheck(j, 1, y->size[1], &sn_emlrtBCI) - 1] = dbuffer->data[0];
        }
        for (k = 1; k <= ndbufferm1; k++) {
            b_zf[0] = zf->size[0];
            b_zf[1] = 1;
            c_zf = *zf;
            c_zf.size = (int32_T *)&b_zf;
            c_zf.numDimensions = 1;
            c_zf.data[emlrtDynamicBoundsCheck(k, 1, zf->size[0], &nn_emlrtBCI) - 1] = dbuffer->data[emlrtDynamicBoundsCheck(k + 1, 1, dbuffer->size[0], &on_emlrtBCI) - 1];
        }
        emxFree_real_T(&dbuffer);
    }
    emxFree_real_T(&zf);
    emlrtHeapReferenceStackLeaveFcn();
}
/* End of code generation (filter.c) */
