/*
 * median.c
 *
 * Code generation for function 'median'
 *
 * C source code generated on: Fri Aug 31 09:24:08 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_compute_trajectory_onset.h"
#include "median.h"
#include "epu_compute_trajectory_onset_emxutil.h"
#include "epu_compute_trajectory_onset_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo vj_emlrtRSI = { 17, "median", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/median.m" };
static emlrtRSInfo wj_emlrtRSI = { 17, "median", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/median.m" };
static emlrtRSInfo xj_emlrtRSI = { 20, "median", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/median.m" };
static emlrtRSInfo yj_emlrtRSI = { 40, "median", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/median.m" };
static emlrtRSInfo ak_emlrtRSI = { 8, "isequal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/isequal.m" };
static emlrtRSInfo bk_emlrtRSI = { 30, "eml_isequal_core", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_isequal_core.m" };
static emlrtRSInfo ck_emlrtRSI = { 56, "eml_isequal_core", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_isequal_core.m" };
static emlrtRSInfo dk_emlrtRSI = { 76, "median", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/median.m" };
static emlrtRSInfo ek_emlrtRSI = { 139, "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };
static emlrtRSInfo fk_emlrtRSI = { 161, "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };
static emlrtMCInfo cb_emlrtMCI = { 18, 9, "median", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/median.m" };
static emlrtMCInfo db_emlrtMCI = { 17, 19, "median", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/median.m" };
static emlrtMCInfo eb_emlrtMCI = { 23, 9, "median", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/median.m" };
static emlrtMCInfo fb_emlrtMCI = { 20, 19, "median", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/median.m" };
static emlrtRTEInfo xb_emlrtRTEI = { 27, 5, "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };
static emlrtRTEInfo yb_emlrtRTEI = { 1, 14, "median", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/median.m" };
static emlrtRTEInfo ac_emlrtRTEI = { 76, 1, "median", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/median.m" };
static emlrtRTEInfo bc_emlrtRTEI = { 145, 5, "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };
static emlrtBCInfo eo_emlrtBCI = { -1, -1, 77, 10, "", "median", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/median.m", 0 };
static emlrtBCInfo fo_emlrtBCI = { -1, -1, 80, 16, "", "median", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/median.m", 0 };
static emlrtBCInfo go_emlrtBCI = { -1, -1, 80, 30, "", "median", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/median.m", 0 };
static emlrtBCInfo ho_emlrtBCI = { -1, -1, 161, 38, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo io_emlrtBCI = { -1, -1, 161, 45, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo jo_emlrtBCI = { -1, -1, 20, 35, "", "eml_sort_le", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_le.m", 0 };
static emlrtBCInfo ko_emlrtBCI = { -1, -1, 20, 44, "", "eml_sort_le", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_le.m", 0 };
static emlrtBCInfo lo_emlrtBCI = { -1, -1, 20, 35, "", "eml_sort_le", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_le.m", 0 };
static emlrtBCInfo mo_emlrtBCI = { -1, -1, 20, 44, "", "eml_sort_le", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_le.m", 0 };
static emlrtBCInfo no_emlrtBCI = { -1, -1, 77, 12, "", "median", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/median.m", 0 };
static emlrtBCInfo oo_emlrtBCI = { -1, -1, 82, 9, "", "median", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/median.m", 0 };
static emlrtBCInfo po_emlrtBCI = { -1, -1, 82, 11, "", "median", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/median.m", 0 };
static emlrtBCInfo qo_emlrtBCI = { -1, -1, 80, 18, "", "median", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/median.m", 0 };
static emlrtBCInfo ro_emlrtBCI = { -1, -1, 80, 32, "", "median", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/median.m", 0 };
static emlrtBCInfo so_emlrtBCI = { -1, -1, 78, 9, "", "median", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/median.m", 0 };
static emlrtBCInfo to_emlrtBCI = { -1, -1, 78, 11, "", "median", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/median.m", 0 };
static emlrtBCInfo uo_emlrtBCI = { -1, -1, 186, 17, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo vo_emlrtBCI = { -1, -1, 186, 44, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo wo_emlrtBCI = { -1, -1, 172, 21, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo xo_emlrtBCI = { -1, -1, 172, 31, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo yo_emlrtBCI = { -1, -1, 177, 29, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo ap_emlrtBCI = { -1, -1, 177, 39, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo bp_emlrtBCI = { -1, -1, 162, 21, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo cp_emlrtBCI = { -1, -1, 162, 31, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo dp_emlrtBCI = { -1, -1, 167, 29, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo ep_emlrtBCI = { -1, -1, 167, 39, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo fp_emlrtBCI = { -1, -1, 141, 13, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo gp_emlrtBCI = { -1, -1, 142, 13, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo hp_emlrtBCI = { -1, -1, 135, 9, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
real_T median(const emxArray_real_T *x)
{
    real_T y;
    boolean_T p;
    boolean_T b_p;
    int32_T k;
    int32_T exitg1;
    int32_T i2;
    const mxArray *b_y;
    static const int32_T iv27[2] = { 1, 33 };
    const mxArray *m10;
    static const char_T cv15[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'm', 'e', 'd', 'i', 'a', 'n', '_', 's', 'p', 'e', 'c', 'i', 'a', 'l', 'E', 'm', 'p', 't', 'y' };
    const mxArray *c_y;
    static const int32_T iv28[2] = { 1, 36 };
    static const char_T cv16[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };
    int32_T midm1;
    int32_T mid;
    int32_T n;
    uint32_T uv2[2];
    emxArray_int32_T *idx;
    int32_T np1;
    emxArray_int32_T *idx0;
    int32_T i;
    int32_T j;
    int32_T pEnd;
    int32_T c_p;
    int32_T q;
    int32_T qEnd;
    int32_T kEnd;
    emlrtHeapReferenceStackEnterFcn();
    EMLRTPUSHRTSTACK(&vj_emlrtRSI);
    EMLRTPUSHRTSTACK(&ak_emlrtRSI);
    p = FALSE;
    EMLRTPUSHRTSTACK(&bk_emlrtRSI);
    EMLRTPUSHRTSTACK(&ck_emlrtRSI);
    b_p = FALSE;
    k = 0;
    do {
        exitg1 = 0U;
        if (k < 2) {
            i2 = x->size[k];
            if (i2 != 0) {
                exitg1 = 1U;
            } else {
                k++;
            }
        } else {
            b_p = TRUE;
            exitg1 = 1U;
        }
    } while (exitg1 == 0U);
    EMLRTPOPRTSTACK(&ck_emlrtRSI);
    if (b_p) {
        b_p = TRUE;
    } else {
        b_p = FALSE;
    }
    EMLRTPOPRTSTACK(&bk_emlrtRSI);
    if (!b_p) {
    } else {
        p = TRUE;
    }
    EMLRTPOPRTSTACK(&ak_emlrtRSI);
    EMLRTPOPRTSTACK(&vj_emlrtRSI);
    if (!p) {
        b_p = TRUE;
    } else {
        b_p = FALSE;
    }
    if (b_p) {
    } else {
        EMLRTPUSHRTSTACK(&wj_emlrtRSI);
        b_y = NULL;
        m10 = mxCreateCharArray(2, iv27);
        emlrtInitCharArray(33, m10, cv15);
        emlrtAssign(&b_y, m10);
        c_error(message(b_y, &cb_emlrtMCI), &db_emlrtMCI);
        EMLRTPOPRTSTACK(&wj_emlrtRSI);
    }
    if ((x->size[1] == 1) || (x->size[1] != 1)) {
        b_p = TRUE;
    } else {
        b_p = FALSE;
    }
    if (b_p) {
    } else {
        EMLRTPUSHRTSTACK(&xj_emlrtRSI);
        c_y = NULL;
        m10 = mxCreateCharArray(2, iv28);
        emlrtInitCharArray(36, m10, cv16);
        emlrtAssign(&c_y, m10);
        c_error(message(c_y, &eb_emlrtMCI), &fb_emlrtMCI);
        EMLRTPOPRTSTACK(&xj_emlrtRSI);
    }
    if (x->size[1] == 0) {
        y = rtNaN;
    } else {
        EMLRTPUSHRTSTACK(&yj_emlrtRSI);
        i2 = x->size[1];
        i2 += (i2 < 0);
        midm1 = (i2 >= 0 ? (int32_T)((uint32_T)i2 >> 1) : ~(int32_T)((uint32_T)~i2 >> 1)) - 1;
        mid = midm1 + 1;
        EMLRTPUSHRTSTACK(&dk_emlrtRSI);
        n = x->size[1];
        for (i2 = 0; i2 < 2; i2++) {
            uv2[i2] = (uint32_T)x->size[i2];
        }
        emxInit_int32_T(&idx, 2, &ac_emlrtRTEI, TRUE);
        i2 = idx->size[0] * idx->size[1];
        idx->size[0] = 1;
        idx->size[1] = (int32_T)uv2[1];
        emxEnsureCapacity((emxArray__common *)idx, i2, (int32_T)sizeof(int32_T), &xb_emlrtRTEI);
        np1 = n + 1;
        for (k = 1; k <= n; k++) {
            idx->data[emlrtDynamicBoundsCheck(k, 1, idx->size[1], &hp_emlrtBCI) - 1] = k;
        }
        for (k = 1; k <= n - 1; k += 2) {
            EMLRTPUSHRTSTACK(&ek_emlrtRSI);
            emlrtDynamicBoundsCheck(k, 1, x->size[1], &lo_emlrtBCI);
            emlrtDynamicBoundsCheck(k + 1, 1, x->size[1], &mo_emlrtBCI);
            if ((x->data[k - 1] <= x->data[k]) || muDoubleScalarIsNaN(x->data[k])) {
                b_p = TRUE;
            } else {
                b_p = FALSE;
            }
            EMLRTPOPRTSTACK(&ek_emlrtRSI);
            if (b_p) {
            } else {
                idx->data[emlrtDynamicBoundsCheck(k, 1, idx->size[1], &fp_emlrtBCI) - 1] = k + 1;
                idx->data[emlrtDynamicBoundsCheck(k + 1, 1, idx->size[1], &gp_emlrtBCI) - 1] = k;
            }
        }
        b_emxInit_int32_T(&idx0, 1, &bc_emlrtRTEI, TRUE);
        i2 = idx0->size[0];
        idx0->size[0] = n;
        emxEnsureCapacity((emxArray__common *)idx0, i2, (int32_T)sizeof(int32_T), &yb_emlrtRTEI);
        i = n - 1;
        for (i2 = 0; i2 <= i; i2++) {
            idx0->data[i2] = 1;
        }
        i = 2;
        while (i < n) {
            i2 = i << 1;
            j = 1;
            for (pEnd = 1 + i; pEnd < np1; pEnd = qEnd + i) {
                c_p = j;
                q = pEnd;
                qEnd = j + i2;
                if (qEnd > np1) {
                    qEnd = np1;
                }
                k = 1;
                kEnd = qEnd - j;
                while (k <= kEnd) {
                    EMLRTPUSHRTSTACK(&fk_emlrtRSI);
                    emlrtDynamicBoundsCheck(c_p, 1, idx->size[1], &ho_emlrtBCI);
                    emlrtDynamicBoundsCheck(q, 1, idx->size[1], &io_emlrtBCI);
                    emlrtDynamicBoundsCheck(idx->data[c_p - 1], 1, x->size[1], &jo_emlrtBCI);
                    emlrtDynamicBoundsCheck(idx->data[q - 1], 1, x->size[1], &ko_emlrtBCI);
                    if ((x->data[idx->data[c_p - 1] - 1] <= x->data[idx->data[q - 1] - 1]) || muDoubleScalarIsNaN(x->data[idx->data[q - 1] - 1])) {
                        b_p = TRUE;
                    } else {
                        b_p = FALSE;
                    }
                    EMLRTPOPRTSTACK(&fk_emlrtRSI);
                    if (b_p) {
                        idx0->data[emlrtDynamicBoundsCheck(k, 1, idx0->size[0], &bp_emlrtBCI) - 1] = idx->data[emlrtDynamicBoundsCheck(c_p, 1, idx->size[1], &cp_emlrtBCI) - 1];
                        c_p++;
                        if (c_p == pEnd) {
                            while (q < qEnd) {
                                k++;
                                idx0->data[emlrtDynamicBoundsCheck(k, 1, idx0->size[0], &dp_emlrtBCI) - 1] = idx->data[emlrtDynamicBoundsCheck(q, 1, idx->size[1], &ep_emlrtBCI) - 1];
                                q++;
                            }
                        }
                    } else {
                        idx0->data[emlrtDynamicBoundsCheck(k, 1, idx0->size[0], &wo_emlrtBCI) - 1] = idx->data[emlrtDynamicBoundsCheck(q, 1, idx->size[1], &xo_emlrtBCI) - 1];
                        q++;
                        if (q == qEnd) {
                            while (c_p < pEnd) {
                                k++;
                                idx0->data[emlrtDynamicBoundsCheck(k, 1, idx0->size[0], &yo_emlrtBCI) - 1] = idx->data[emlrtDynamicBoundsCheck(c_p, 1, idx->size[1], &ap_emlrtBCI) - 1];
                                c_p++;
                            }
                        }
                    }
                    k++;
                }
                for (k = 1; k <= kEnd; k++) {
                    idx->data[emlrtDynamicBoundsCheck((j + k) - 1, 1, idx->size[1], &uo_emlrtBCI) - 1] = idx0->data[emlrtDynamicBoundsCheck(k, 1, idx0->size[0], &vo_emlrtBCI) - 1];
                }
                j = qEnd;
            }
            i = i2;
        }
        emxFree_int32_T(&idx0);
        EMLRTPOPRTSTACK(&dk_emlrtRSI);
        emlrtDynamicBoundsCheck(idx->data[emlrtDynamicBoundsCheck(idx->size[1], 1, idx->size[1], &no_emlrtBCI) - 1], 1, x->size[1], &eo_emlrtBCI);
        if (muDoubleScalarIsNaN(x->data[idx->data[idx->size[1] - 1] - 1])) {
            y = x->data[emlrtDynamicBoundsCheck(idx->data[emlrtDynamicBoundsCheck(idx->size[1], 1, idx->size[1], &to_emlrtBCI) - 1], 1, x->size[1], &so_emlrtBCI) - 1];
        } else if (x->size[1] == (midm1 + 1) << 1) {
            emlrtDynamicBoundsCheck(idx->data[emlrtDynamicBoundsCheck(midm1 + 1, 1, idx->size[1], &qo_emlrtBCI) - 1], 1, x->size[1], &fo_emlrtBCI);
            emlrtDynamicBoundsCheck(idx->data[emlrtDynamicBoundsCheck(mid + 1, 1, idx->size[1], &ro_emlrtBCI) - 1], 1, x->size[1], &go_emlrtBCI);
            if (((x->data[idx->data[midm1] - 1] < 0.0) != (x->data[idx->data[mid] - 1] < 0.0)) || muDoubleScalarIsInf(x->data[idx->data[midm1] - 1]) || muDoubleScalarIsInf(x->data[idx->data[mid] - 1])) {
                y = (x->data[idx->data[midm1] - 1] + x->data[idx->data[mid] - 1]) / 2.0;
            } else {
                y = x->data[idx->data[midm1] - 1] + (x->data[idx->data[mid] - 1] - x->data[idx->data[midm1] - 1]) / 2.0;
            }
        } else {
            y = x->data[emlrtDynamicBoundsCheck(idx->data[emlrtDynamicBoundsCheck(mid + 1, 1, idx->size[1], &po_emlrtBCI) - 1], 1, x->size[1], &oo_emlrtBCI) - 1];
        }
        emxFree_int32_T(&idx);
        EMLRTPOPRTSTACK(&yj_emlrtRSI);
    }
    emlrtHeapReferenceStackLeaveFcn();
    return y;
}
/* End of code generation (median.c) */
