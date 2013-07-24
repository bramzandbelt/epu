/*
 * interp1.c
 *
 * Code generation for function 'interp1'
 *
 * C source code generated on: Fri Aug 31 09:23:48 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_accumulator.h"
#include "interp1.h"
#include "epu_n_unit_accumulator_emxutil.h"
#include "epu_n_unit_accumulator_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo uc_emlrtRSI = { 96, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtRSInfo vc_emlrtRSI = { 105, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtRSInfo wc_emlrtRSI = { 121, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtRSInfo xc_emlrtRSI = { 134, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtRSInfo yc_emlrtRSI = { 145, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtRSInfo ad_emlrtRSI = { 150, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtRSInfo bd_emlrtRSI = { 243, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtRSInfo cd_emlrtRSI = { 20, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtRSInfo dd_emlrtRSI = { 20, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtRSInfo ed_emlrtRSI = { 31, "eml_bsearch", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_bsearch.m" };
static emlrtMCInfo cb_emlrtMCI = { 97, 9, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtMCInfo db_emlrtMCI = { 96, 19, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtMCInfo eb_emlrtMCI = { 106, 13, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtMCInfo fb_emlrtMCI = { 105, 23, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtMCInfo gb_emlrtMCI = { 122, 5, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtMCInfo hb_emlrtMCI = { 121, 15, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtMCInfo ib_emlrtMCI = { 20, 19, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo jb_emlrtMCI = { 20, 5, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo kb_emlrtMCI = { 20, 19, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo lb_emlrtMCI = { 20, 5, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtRTEInfo l_emlrtRTEI = { 50, 15, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtBCInfo rc_emlrtBCI = { -1, -1, 133, 18, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo sc_emlrtBCI = { -1, -1, 139, 8, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo tc_emlrtBCI = { -1, -1, 139, 15, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo uc_emlrtBCI = { -1, -1, 141, 13, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo vc_emlrtBCI = { -1, -1, 153, 11, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo wc_emlrtBCI = { -1, -1, 154, 11, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo xc_emlrtBCI = { -1, -1, 243, 39, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo yc_emlrtBCI = { -1, -1, 244, 26, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo ad_emlrtBCI = { -1, -1, 217, 16, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo bd_emlrtBCI = { -1, -1, 227, 20, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo cd_emlrtBCI = { -1, -1, 245, 37, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo dd_emlrtBCI = { -1, -1, 245, 46, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo ed_emlrtBCI = { -1, -1, 32, 14, "", "eml_bsearch", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_bsearch.m", 0 };
static emlrtBCInfo fd_emlrtBCI = { -1, -1, 252, 42, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo gd_emlrtBCI = { -1, -1, 252, 68, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo hd_emlrtBCI = { -1, -1, 252, 21, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo id_emlrtBCI = { -1, -1, 252, 31, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo jd_emlrtBCI = { -1, -1, 149, 12, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo kd_emlrtBCI = { -1, -1, 149, 20, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo ld_emlrtBCI = { -1, -1, 28, 23, "", "flipdim", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/flipdim.m", 0 };
static emlrtBCInfo md_emlrtBCI = { -1, -1, 29, 17, "", "flipdim", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/flipdim.m", 0 };
static emlrtBCInfo nd_emlrtBCI = { -1, -1, 29, 29, "", "flipdim", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/flipdim.m", 0 };
static emlrtBCInfo od_emlrtBCI = { -1, -1, 30, 17, "", "flipdim", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/flipdim.m", 0 };

/* Function Declarations */
static void b_eml_error(void);
static void c_eml_error(void);

/* Function Definitions */

/*
 * 
 */
static void b_eml_error(void)
{
    const mxArray *y;
    static const int32_T iv21[2] = { 1, 21 };
    const mxArray *m7;
    static const char_T cv15[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'n', 't', 'e', 'r', 'p', '1', ':', 'N', 'a', 'N', 'i', 'n', 'X' };
    EMLRTPUSHRTSTACK(&cd_emlrtRSI);
    y = NULL;
    m7 = mxCreateCharArray(2, iv21);
    emlrtInitCharArray(21, m7, cv15);
    emlrtAssign(&y, m7);
    error(message(y, &ib_emlrtMCI), &jb_emlrtMCI);
    EMLRTPOPRTSTACK(&cd_emlrtRSI);
}

/*
 * 
 */
static void c_eml_error(void)
{
    const mxArray *y;
    static const int32_T iv22[2] = { 1, 35 };
    const mxArray *m8;
    static const char_T cv16[35] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'i', 'n', 't', 'e', 'r', 'p', '1', '_', 'n', 'o', 'n', 'M', 'o', 'n', 'o', 't', 'o', 'n', 'i', 'c', 'X' };
    EMLRTPUSHRTSTACK(&dd_emlrtRSI);
    y = NULL;
    m8 = mxCreateCharArray(2, iv22);
    emlrtInitCharArray(35, m8, cv16);
    emlrtAssign(&y, m8);
    error(message(y, &kb_emlrtMCI), &lb_emlrtMCI);
    EMLRTPOPRTSTACK(&dd_emlrtRSI);
}

/*
 * 
 */
void interp1_work(emxArray_real_T *y, const emxArray_real_T *xi, emxArray_real_T *x, emxArray_real_T *yi)
{
    boolean_T b3;
    const mxArray *b_y;
    static const int32_T iv17[2] = { 1, 45 };
    const mxArray *m6;
    static const char_T cv12[45] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'i', 'n', 't', 'e', 'r', 'p', '1', '_', 'v', 's', 'i', 'z', 'e', 'M', 'a', 't', 'r', 'i', 'x', 'B', 'e', 'c', 'a', 'm', 'e', 'R', 'o', 'w', 'V', 'e', 'c' };
    int32_T nyrows;
    int32_T nycols;
    int32_T nx;
    const mxArray *c_y;
    static const int32_T iv18[2] = { 1, 36 };
    static const char_T cv13[36] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'n', 't', 'e', 'r', 'p', '1', '_', 'Y', 'I', 'n', 'v', 'a', 'l', 'i', 'd', 'N', 'u', 'm', 'R', 'o', 'w', 's' };
    uint32_T outsize_idx_0;
    uint32_T outsize_idx_1;
    const mxArray *d_y;
    static const int32_T iv19[2] = { 1, 27 };
    static const char_T cv14[27] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'n', 't', 'e', 'r', 'p', '1', ':', 'N', 'o', 't', 'E', 'n', 'o', 'u', 'g', 'h', 'P', 't', 's' };
    int32_T i;
    int32_T npages;
    int32_T i1;
    emxArray_int32_T *r11;
    emxArray_real_T *b_x;
    int32_T exitg1;
    int32_T i2;
    int32_T nxi;
    int32_T iv20[2];
    emxArray_int32_T r12;
    int32_T ixright;
    real_T r;
    uint32_T high_i;
    uint32_T mid_i;
    real_T b;
    emlrtHeapReferenceStackEnterFcn();
    if (((y->size[0] == 1) && (y->size[1] == 1)) || (!((y->size[0] == 1) || (y->size[1] == 1))) || (y->size[0] != 1)) {
        b3 = TRUE;
    } else {
        b3 = FALSE;
    }
    if (b3) {
    } else {
        EMLRTPUSHRTSTACK(&uc_emlrtRSI);
        b_y = NULL;
        m6 = mxCreateCharArray(2, iv17);
        emlrtInitCharArray(45, m6, cv12);
        emlrtAssign(&b_y, m6);
        error(message(b_y, &cb_emlrtMCI), &db_emlrtMCI);
        EMLRTPOPRTSTACK(&uc_emlrtRSI);
    }
    nyrows = y->size[0];
    nycols = y->size[1];
    nx = x->size[1];
    if (nx == nyrows) {
    } else {
        EMLRTPUSHRTSTACK(&vc_emlrtRSI);
        c_y = NULL;
        m6 = mxCreateCharArray(2, iv18);
        emlrtInitCharArray(36, m6, cv13);
        emlrtAssign(&c_y, m6);
        error(message(c_y, &eb_emlrtMCI), &fb_emlrtMCI);
        EMLRTPOPRTSTACK(&vc_emlrtRSI);
    }
    outsize_idx_0 = (uint32_T)xi->size[1];
    outsize_idx_1 = (uint32_T)y->size[1];
    if (nx > 1) {
    } else {
        EMLRTPUSHRTSTACK(&wc_emlrtRSI);
        d_y = NULL;
        m6 = mxCreateCharArray(2, iv19);
        emlrtInitCharArray(27, m6, cv14);
        emlrtAssign(&d_y, m6);
        error(message(d_y, &gb_emlrtMCI), &hb_emlrtMCI);
        EMLRTPOPRTSTACK(&wc_emlrtRSI);
    }
    i = yi->size[0] * yi->size[1];
    yi->size[0] = (int32_T)outsize_idx_0;
    emxEnsureCapacity((emxArray__common *)yi, i, (int32_T)sizeof(real_T), &l_emlrtRTEI);
    i = yi->size[0] * yi->size[1];
    yi->size[1] = (int32_T)outsize_idx_1;
    emxEnsureCapacity((emxArray__common *)yi, i, (int32_T)sizeof(real_T), &l_emlrtRTEI);
    npages = (int32_T)outsize_idx_0 * (int32_T)outsize_idx_1 - 1;
    for (i = 0; i <= npages; i++) {
        yi->data[i] = rtNaN;
    }
    if (xi->size[1] == 0) {
    } else {
        i1 = 1;
        emxInit_int32_T(&r11, 1, &l_emlrtRTEI, TRUE);
        emxInit_real_T(&b_x, 2, &l_emlrtRTEI, TRUE);
        do {
            exitg1 = 0U;
            if (i1 <= nx) {
                emlrtDynamicBoundsCheck(i1, 1, x->size[1], &rc_emlrtBCI);
                if (muDoubleScalarIsNaN(x->data[i1 - 1])) {
                    EMLRTPUSHRTSTACK(&xc_emlrtRSI);
                    b_eml_error();
                    EMLRTPOPRTSTACK(&xc_emlrtRSI);
                    exitg1 = 1U;
                } else {
                    i1++;
                }
            } else {
                emlrtDynamicBoundsCheck(2, 1, x->size[1], &sc_emlrtBCI);
                emlrtDynamicBoundsCheck(1, 1, x->size[1], &tc_emlrtBCI);
                if (x->data[1] < x->data[0]) {
                    if (1 > x->size[1]) {
                        i = 1;
                        i1 = 1;
                        i2 = 0;
                    } else {
                        i = emlrtDynamicBoundsCheck(x->size[1], 1, x->size[1], &uc_emlrtBCI);
                        i1 = -1;
                        i2 = 1;
                    }
                    nxi = r11->size[0];
                    r11->size[0] = (i2 - i) / i1 + 1;
                    emxEnsureCapacity((emxArray__common *)r11, nxi, (int32_T)sizeof(int32_T), &l_emlrtRTEI);
                    npages = (i2 - i) / i1;
                    for (i2 = 0; i2 <= npages; i2++) {
                        r11->data[i2] = i + i1 * i2;
                    }
                    iv20[0] = 1;
                    iv20[1] = r11->size[0];
                    i = b_x->size[0] * b_x->size[1];
                    b_x->size[0] = iv20[0];
                    b_x->size[1] = iv20[1];
                    emxEnsureCapacity((emxArray__common *)b_x, i, (int32_T)sizeof(real_T), &l_emlrtRTEI);
                    npages = iv20[1] - 1;
                    for (i = 0; i <= npages; i++) {
                        nxi = iv20[0] - 1;
                        for (i1 = 0; i1 <= nxi; i1++) {
                            r12 = *r11;
                            r12.size = (int32_T *)&iv20;
                            r12.numDimensions = 1;
                            b_x->data[i1 + b_x->size[0] * i] = x->data[r12.data[i1 + r12.size[0] * i] - 1];
                        }
                    }
                    i = x->size[0] * x->size[1];
                    x->size[0] = 1;
                    x->size[1] = b_x->size[1];
                    emxEnsureCapacity((emxArray__common *)x, i, (int32_T)sizeof(real_T), &l_emlrtRTEI);
                    npages = b_x->size[1] - 1;
                    for (i = 0; i <= npages; i++) {
                        x->data[x->size[0] * i] = b_x->data[b_x->size[0] * i];
                    }
                    EMLRTPUSHRTSTACK(&yc_emlrtRSI);
                    if ((!((y->size[0] == 0) || (y->size[1] == 0))) && (y->size[0] > 1)) {
                        nxi = y->size[0];
                        npages = y->size[1];
                        i2 = 0;
                        for (i = 1; i <= npages; i++) {
                            i1 = i2 + 1;
                            i2 += nxi;
                            for (ixright = i2; i1 < ixright; ixright--) {
                                r = y->data[emlrtDynamicBoundsCheck(i1, 1, y->size[0] * y->size[1], &ld_emlrtBCI) - 1];
                                y->data[emlrtDynamicBoundsCheck(i1, 1, y->size[0] * y->size[1], &md_emlrtBCI) - 1] = y->data[emlrtDynamicBoundsCheck(ixright, 1, y->size[0] * y->size[1], &nd_emlrtBCI) - 1];
                                y->data[emlrtDynamicBoundsCheck(ixright, 1, y->size[0] * y->size[1], &od_emlrtBCI) - 1] = r;
                                i1++;
                            }
                        }
                    }
                    EMLRTPOPRTSTACK(&yc_emlrtRSI);
                }
                for (i1 = 2; i1 <= nx; i1++) {
                    if (x->data[emlrtDynamicBoundsCheck(i1, 1, x->size[1], &jd_emlrtBCI) - 1] <= x->data[emlrtDynamicBoundsCheck(i1 - 1, 1, x->size[1], &kd_emlrtBCI) - 1]) {
                        EMLRTPUSHRTSTACK(&ad_emlrtRSI);
                        c_eml_error();
                        EMLRTPOPRTSTACK(&ad_emlrtRSI);
                    }
                }
                emlrtDynamicBoundsCheck(1, 1, x->size[1], &vc_emlrtBCI);
                emlrtDynamicBoundsCheck(x->size[1], 1, x->size[1], &wc_emlrtBCI);
                nxi = xi->size[1];
                for (i1 = 1; i1 <= nxi; i1++) {
                    npages = 0;
                    if ((xi->data[emlrtDynamicBoundsCheck(i1, 1, xi->size[1], &ad_emlrtBCI) - 1] > x->data[x->size[1] - 1]) || (xi->data[emlrtDynamicBoundsCheck(i1, 1, xi->size[1], &bd_emlrtBCI) - 1] < x->data[0])) {
                    } else {
                        EMLRTPUSHRTSTACK(&bd_emlrtRSI);
                        emlrtDynamicBoundsCheck(i1, 1, xi->size[1], &xc_emlrtBCI);
                        outsize_idx_0 = 1U;
                        outsize_idx_1 = 2U;
                        high_i = (uint32_T)x->size[1];
                        while (high_i > outsize_idx_1) {
                            EMLRTPUSHRTSTACK(&ed_emlrtRSI);
                            mid_i = (outsize_idx_0 >> 1U) + (high_i >> 1U);
                            if (((outsize_idx_0 & 1U) == 1U) && ((high_i & 1U) == 1U)) {
                                mid_i++;
                            }
                            EMLRTPOPRTSTACK(&ed_emlrtRSI);
                            if (xi->data[i1 - 1] >= x->data[(int32_T)(uint32_T)emlrtDynamicBoundsCheck((int32_T)mid_i, 1, x->size[1], &ed_emlrtBCI) - 1]) {
                                outsize_idx_0 = mid_i;
                                outsize_idx_1 = mid_i + 1U;
                            } else {
                                high_i = mid_i;
                            }
                        }
                        npages = (int32_T)outsize_idx_0;
                        EMLRTPOPRTSTACK(&bd_emlrtRSI);
                        emlrtDynamicBoundsCheck((int32_T)outsize_idx_0, 1, x->size[1], &yc_emlrtBCI);
                        r = (xi->data[emlrtDynamicBoundsCheck(i1, 1, xi->size[1], &cd_emlrtBCI) - 1] - x->data[(int32_T)outsize_idx_0 - 1]) / (x->data[emlrtDynamicBoundsCheck((int32_T)outsize_idx_0 + 1, 1, x->size[1], &dd_emlrtBCI) - 1] - x->data[(int32_T)outsize_idx_0 - 1]);
                    }
                    if (npages > 0) {
                        i2 = i1;
                        for (i = 1; i <= nycols; i++) {
                            b = y->data[emlrtDynamicBoundsCheck(npages + 1, 1, y->size[0] * y->size[1], &fd_emlrtBCI) - 1] - y->data[emlrtDynamicBoundsCheck(npages, 1, y->size[0] * y->size[1], &gd_emlrtBCI) - 1];
                            yi->data[emlrtDynamicBoundsCheck(i2, 1, yi->size[0] * yi->size[1], &hd_emlrtBCI) - 1] = y->data[emlrtDynamicBoundsCheck(npages, 1, y->size[0] * y->size[1], &id_emlrtBCI) - 1] + r * b;
                            i2 += nxi;
                            npages += nyrows;
                        }
                    }
                }
                exitg1 = 1U;
            }
        } while (exitg1 == 0U);
        emxFree_real_T(&b_x);
        emxFree_int32_T(&r11);
    }
    emlrtHeapReferenceStackLeaveFcn();
}
/* End of code generation (interp1.c) */
