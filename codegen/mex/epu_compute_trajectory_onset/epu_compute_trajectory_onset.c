/*
 * epu_compute_trajectory_onset.c
 *
 * Code generation for function 'epu_compute_trajectory_onset'
 *
 * C source code generated on: Fri Aug 31 09:24:08 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_compute_trajectory_onset.h"
#include "epu_compute_trajectory_onset_emxutil.h"
#include "median.h"
#include "colon.h"
#include "movingslope.h"
#include "epu_compute_trajectory_onset_mexutil.h"
#include "epu_compute_trajectory_onset_data.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 20, "epu_compute_trajectory_onset", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_compute_trajectory_onset.m" };
static emlrtRSInfo b_emlrtRSI = { 21, "epu_compute_trajectory_onset", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_compute_trajectory_onset.m" };
static emlrtRSInfo c_emlrtRSI = { 22, "epu_compute_trajectory_onset", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_compute_trajectory_onset.m" };
static emlrtRSInfo gk_emlrtRSI = { 41, "find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/find.m" };
static emlrtRSInfo hk_emlrtRSI = { 65, "find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/find.m" };
static emlrtRSInfo ik_emlrtRSI = { 239, "find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/find.m" };
static emlrtMCInfo gb_emlrtMCI = { 65, 1, "find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/find.m" };
static emlrtMCInfo hb_emlrtMCI = { 239, 9, "find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/find.m" };
static emlrtRTEInfo b_emlrtRTEI = { 1, 14, "epu_compute_trajectory_onset", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_compute_trajectory_onset.m" };
static emlrtRTEInfo c_emlrtRTEI = { 111, 5, "find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/find.m" };
static emlrtRTEInfo d_emlrtRTEI = { 20, 1, "epu_compute_trajectory_onset", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_compute_trajectory_onset.m" };
static emlrtRTEInfo e_emlrtRTEI = { 33, 6, "find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/find.m" };
static emlrtBCInfo emlrtBCI = { -1, -1, 249, 17, "", "find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/find.m", 0 };
static emlrtBCInfo b_emlrtBCI = { -1, -1, 249, 17, "", "find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/find.m", 0 };
static emlrtBCInfo c_emlrtBCI = { -1, -1, 233, 17, "", "find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/find.m", 0 };
static emlrtBCInfo d_emlrtBCI = { 0, MAX_int32_T, 50, 11, "", "find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/find.m", 0 };
static emlrtBCInfo e_emlrtBCI = { -1, -1, 120, 5, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtDCInfo emlrtDCI = { 118, 28, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 4 };
static emlrtBCInfo f_emlrtBCI = { -1, -1, 122, 9, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo g_emlrtBCI = { -1, -1, 134, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo h_emlrtBCI = { -1, -1, 135, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo i_emlrtBCI = { -1, -1, 131, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo j_emlrtBCI = { -1, -1, 231, 33, "", "find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/find.m", 0 };
static emlrtBCInfo k_emlrtBCI = { -1, -1, 22, 5, "X", "epu_compute_trajectory_onset", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_compute_trajectory_onset.m", 0 };
static emlrtDCInfo b_emlrtDCI = { 22, 5, "epu_compute_trajectory_onset", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_compute_trajectory_onset.m", 1 };
static emlrtBCInfo l_emlrtBCI = { -1, -1, 127, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo m_emlrtBCI = { -1, -1, 128, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };

/* Function Declarations */

/* Function Definitions */

/*
 * function t = epu_compute_trajectory_onset(X,Y,Z)
 */
void epu_compute_trajectory_onset(const emxArray_real_T *X, const emxArray_real_T *Y, real_T Z, emxArray_real_T *t)
{
    emxArray_real_T *dVec;
    boolean_T n_too_large;
    real_T bnew;
    real_T halfWindow;
    int32_T nx;
    const mxArray *y;
    static const int32_T iv0[2] = { 1, 21 };
    const mxArray *m0;
    static const char_T cv0[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };
    emxArray_real_T *b_y;
    int32_T i0;
    int32_T nm1;
    int32_T nm1d2;
    int32_T k;
    emxArray_boolean_T *x;
    const mxArray *c_y;
    emxArray_int32_T *ii;
    boolean_T exitg1;
    const mxArray *d_y;
    emxArray_int32_T *r0;
    emxArray_int32_T *b_ii;
    int32_T iv1[2];
    emxArray_int32_T r1;
    emlrtHeapReferenceStackEnterFcn();
    emxInit_real_T(&dVec, 2, &d_emlrtRTEI, TRUE);
    /*  */
    /*  INPUTS */
    /*  X      - vector of time points with 1-ms increments (e.g. [-200:1:10]) */
    /*  Y      - vector of activation trajectory */
    /*  Z      - scalar if full width of moving time window */
    /*  */
    /*  OUTPUT */
    /*  t      - trajectory onset (in ms) */
    /*  */
    /*  Bram Zandbelt, July 2012 */
    /*  */
    /*  OUTPUT */
    /*  time from response when trajectory starts */
    /*  coder.extrinsic('movingslope'); */
    /*  Estimate local slope, using sliding window */
    /* 'epu_compute_trajectory_onset:20' dVec = movingslope(Y,Z,1,1); */
    EMLRTPUSHRTSTACK(&emlrtRSI);
    movingslope(Y, Z, dVec);
    EMLRTPOPRTSTACK(&emlrtRSI);
    /* 'epu_compute_trajectory_onset:21' halfWindow = round(median(1:Z)); */
    EMLRTPUSHRTSTACK(&b_emlrtRSI);
    EMLRTPUSHRTSTACK(&gj_emlrtRSI);
    EMLRTPUSHRTSTACK(&hj_emlrtRSI);
    float_colon_length(1.0, Z, &nx, &halfWindow, &bnew, &n_too_large);
    EMLRTPUSHRTSTACK(&ij_emlrtRSI);
    if (!n_too_large) {
    } else {
        EMLRTPUSHRTSTACK(&x_emlrtRSI);
        y = NULL;
        m0 = mxCreateCharArray(2, iv0);
        emlrtInitCharArray(21, m0, cv0);
        emlrtAssign(&y, m0);
        c_error(message(y, &d_emlrtMCI), &e_emlrtMCI);
        EMLRTPOPRTSTACK(&x_emlrtRSI);
    }
    emxInit_real_T(&b_y, 2, &b_emlrtRTEI, TRUE);
    EMLRTPOPRTSTACK(&ij_emlrtRSI);
    emlrtNonNegativeCheckR2009b((real_T)nx, &emlrtDCI);
    i0 = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = nx;
    emxEnsureCapacity((emxArray__common *)b_y, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
    if (nx > 0) {
        emlrtDynamicBoundsCheck(1, 1, b_y->size[1], &e_emlrtBCI);
        b_y->data[0] = halfWindow;
        if (nx > 1) {
            b_y->data[emlrtDynamicBoundsCheck(nx, 1, b_y->size[1], &f_emlrtBCI) - 1] = bnew;
            nm1 = nx - 1;
            i0 = nm1;
            nm1d2 = (int32_T)((uint32_T)i0 >> 1);
            for (k = 1; k <= nm1d2 - 1; k++) {
                b_y->data[emlrtDynamicBoundsCheck(k + 1, 1, b_y->size[1], &l_emlrtBCI) - 1] = halfWindow + (real_T)k;
                b_y->data[emlrtDynamicBoundsCheck(nx - k, 1, b_y->size[1], &m_emlrtBCI) - 1] = bnew - (real_T)k;
            }
            if (nm1d2 << 1 == nm1) {
                b_y->data[emlrtDynamicBoundsCheck(nm1d2 + 1, 1, b_y->size[1], &i_emlrtBCI) - 1] = (halfWindow + bnew) / 2.0;
            } else {
                b_y->data[emlrtDynamicBoundsCheck(nm1d2 + 1, 1, b_y->size[1], &g_emlrtBCI) - 1] = halfWindow + (real_T)nm1d2;
                b_y->data[emlrtDynamicBoundsCheck(nm1d2 + 2, 1, b_y->size[1], &h_emlrtBCI) - 1] = bnew - (real_T)nm1d2;
            }
        }
    }
    EMLRTPOPRTSTACK(&hj_emlrtRSI);
    EMLRTPOPRTSTACK(&gj_emlrtRSI);
    halfWindow = median(b_y);
    emxFree_real_T(&b_y);
    if (muDoubleScalarAbs(halfWindow) > 4.503599627370496E+15) {
    } else if (halfWindow >= 0.5) {
        halfWindow = muDoubleScalarFloor(halfWindow + 0.5);
    } else if (halfWindow > -0.5) {
        halfWindow = -0.0;
    } else {
        halfWindow = muDoubleScalarCeil(halfWindow - 0.5);
    }
    emxInit_boolean_T(&x, 2, &b_emlrtRTEI, TRUE);
    EMLRTPOPRTSTACK(&b_emlrtRSI);
    /* 'epu_compute_trajectory_onset:22' t = X(find(dVec>0,1) + halfWindow); */
    EMLRTPUSHRTSTACK(&c_emlrtRSI);
    i0 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = dVec->size[1];
    emxEnsureCapacity((emxArray__common *)x, i0, (int32_T)sizeof(boolean_T), &b_emlrtRTEI);
    nm1d2 = dVec->size[0] * dVec->size[1] - 1;
    for (i0 = 0; i0 <= nm1d2; i0++) {
        x->data[i0] = (dVec->data[i0] > 0.0);
    }
    emxFree_real_T(&dVec);
    EMLRTPUSHRTSTACK(&gk_emlrtRSI);
    nx = emlrtBoundsCheck(x->size[1], &d_emlrtBCI);
    k = muIntScalarMin_sint32(1, nx);
    if (k <= nx) {
    } else {
        EMLRTPUSHRTSTACK(&hk_emlrtRSI);
        c_y = NULL;
        m0 = mxCreateString("Assertion failed.");
        emlrtAssign(&c_y, m0);
        c_error(c_y, &gb_emlrtMCI);
        EMLRTPOPRTSTACK(&hk_emlrtRSI);
    }
    emxInit_int32_T(&ii, 2, &e_emlrtRTEI, TRUE);
    nm1 = 0;
    i0 = ii->size[0] * ii->size[1];
    ii->size[0] = 1;
    ii->size[1] = k;
    emxEnsureCapacity((emxArray__common *)ii, i0, (int32_T)sizeof(int32_T), &c_emlrtRTEI);
    nm1d2 = 1;
    exitg1 = 0U;
    while ((exitg1 == 0U) && (nm1d2 <= nx)) {
        if (x->data[emlrtDynamicBoundsCheck(nm1d2, 1, x->size[1], &j_emlrtBCI) - 1]) {
            nm1 = 1;
            emlrtDynamicBoundsCheck(1, 1, ii->size[1], &c_emlrtBCI);
            ii->data[0] = nm1d2;
            exitg1 = 1U;
        } else {
            nm1d2++;
        }
    }
    emxFree_boolean_T(&x);
    if (nm1 <= k) {
    } else {
        EMLRTPUSHRTSTACK(&ik_emlrtRSI);
        d_y = NULL;
        m0 = mxCreateString("Assertion failed.");
        emlrtAssign(&d_y, m0);
        c_error(d_y, &hb_emlrtMCI);
        EMLRTPOPRTSTACK(&ik_emlrtRSI);
    }
    if (k == 1) {
        if (nm1 == 0) {
            i0 = ii->size[0] * ii->size[1];
            ii->size[0] = 1;
            ii->size[1] = 0;
            emxEnsureCapacity((emxArray__common *)ii, i0, (int32_T)sizeof(int32_T), &b_emlrtRTEI);
        }
    } else {
        if (1 > nm1) {
            i0 = -1;
        } else {
            emlrtDynamicBoundsCheck(1, 1, ii->size[1], &b_emlrtBCI);
            emlrtDynamicBoundsCheck(1, 1, ii->size[1], &emlrtBCI);
            i0 = 0;
        }
        b_emxInit_int32_T(&r0, 1, &b_emlrtRTEI, TRUE);
        nx = r0->size[0];
        r0->size[0] = i0 + 1;
        emxEnsureCapacity((emxArray__common *)r0, nx, (int32_T)sizeof(int32_T), &b_emlrtRTEI);
        nx = 0;
        while (nx <= i0) {
            r0->data[0] = 1;
            nx = 1;
        }
        emxInit_int32_T(&b_ii, 2, &b_emlrtRTEI, TRUE);
        iv1[0] = 1;
        iv1[1] = r0->size[0];
        i0 = b_ii->size[0] * b_ii->size[1];
        b_ii->size[0] = iv1[0];
        b_ii->size[1] = iv1[1];
        emxEnsureCapacity((emxArray__common *)b_ii, i0, (int32_T)sizeof(int32_T), &b_emlrtRTEI);
        nm1d2 = iv1[1] - 1;
        for (i0 = 0; i0 <= nm1d2; i0++) {
            nm1 = iv1[0] - 1;
            for (nx = 0; nx <= nm1; nx++) {
                r1 = *r0;
                r1.size = (int32_T *)&iv1;
                r1.numDimensions = 1;
                b_ii->data[nx + b_ii->size[0] * i0] = ii->data[r1.data[nx + r1.size[0] * i0] - 1];
            }
        }
        emxFree_int32_T(&r0);
        i0 = ii->size[0] * ii->size[1];
        ii->size[0] = 1;
        ii->size[1] = b_ii->size[1];
        emxEnsureCapacity((emxArray__common *)ii, i0, (int32_T)sizeof(int32_T), &b_emlrtRTEI);
        nm1d2 = b_ii->size[1] - 1;
        for (i0 = 0; i0 <= nm1d2; i0++) {
            ii->data[ii->size[0] * i0] = b_ii->data[b_ii->size[0] * i0];
        }
        emxFree_int32_T(&b_ii);
    }
    EMLRTPOPRTSTACK(&gk_emlrtRSI);
    i0 = t->size[0] * t->size[1];
    t->size[0] = 1;
    t->size[1] = ii->size[1];
    emxEnsureCapacity((emxArray__common *)t, i0, (int32_T)sizeof(real_T), &b_emlrtRTEI);
    nm1d2 = ii->size[0] * ii->size[1] - 1;
    for (i0 = 0; i0 <= nm1d2; i0++) {
        t->data[i0] = X->data[emlrtDynamicBoundsCheck((int32_T)emlrtIntegerCheckR2009b((real_T)ii->data[i0] + halfWindow, &b_emlrtDCI), 1, X->size[1], &k_emlrtBCI) - 1];
    }
    emxFree_int32_T(&ii);
    EMLRTPOPRTSTACK(&c_emlrtRSI);
    emlrtHeapReferenceStackLeaveFcn();
}
/* End of code generation (epu_compute_trajectory_onset.c) */
