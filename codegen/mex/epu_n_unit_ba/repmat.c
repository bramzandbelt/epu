/*
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 * C source code generated on: Tue Oct 30 14:49:26 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_ba.h"
#include "repmat.h"
#include "epu_n_unit_ba_emxutil.h"
#include "epu_n_unit_ba_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo wb_emlrtRSI = { 10, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };
static emlrtRSInfo xb_emlrtRSI = { 19, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };
static emlrtRSInfo yb_emlrtRSI = { 48, "eml_assert_valid_size_arg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m" };
static emlrtRSInfo ac_emlrtRSI = { 52, "eml_assert_valid_size_arg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m" };
static emlrtRSInfo dc_emlrtRSI = { 10, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };
static emlrtRSInfo ec_emlrtRSI = { 19, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };
static emlrtRSInfo fc_emlrtRSI = { 10, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };
static emlrtRSInfo gc_emlrtRSI = { 19, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };
static emlrtMCInfo m_emlrtMCI = { 49, 13, "eml_assert_valid_size_arg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m" };
static emlrtMCInfo n_emlrtMCI = { 48, 23, "eml_assert_valid_size_arg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m" };
static emlrtMCInfo o_emlrtMCI = { 53, 5, "eml_assert_valid_size_arg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m" };
static emlrtMCInfo p_emlrtMCI = { 52, 15, "eml_assert_valid_size_arg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m" };
static emlrtRTEInfo p_emlrtRTEI = { 45, 1, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };
static emlrtRTEInfo r_emlrtRTEI = { 1, 14, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };
static emlrtRTEInfo s_emlrtRTEI = { 45, 1, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };
static emlrtDCInfo j_emlrtDCI = { 45, 48, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m", 4 };
static emlrtBCInfo id_emlrtBCI = { -1, -1, 64, 21, "", "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m", 0 };
static emlrtBCInfo jd_emlrtBCI = { -1, -1, 64, 29, "", "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m", 0 };
static emlrtDCInfo k_emlrtDCI = { 42, 22, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m", 4 };
static emlrtDCInfo l_emlrtDCI = { 45, 48, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m", 4 };
static emlrtBCInfo kd_emlrtBCI = { -1, -1, 64, 21, "", "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m", 0 };
static emlrtBCInfo ld_emlrtBCI = { -1, -1, 64, 29, "", "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m", 0 };

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
void b_repmat(real_T m, real_T n, emxArray_real_T *b)
{
    boolean_T p;
    const mxArray *y;
    static const int32_T iv15[2] = { 1, 28 };
    const mxArray *m4;
    static const char_T cv11[28] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'N', 'o', 'n', 'I', 'n', 't', 'e', 'g', 'e', 'r', 'I', 'n', 'p', 'u', 't' };
    real_T b_n;
    const mxArray *b_y;
    static const int32_T iv16[2] = { 1, 21 };
    static const char_T cv12[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };
    const mxArray *c_y;
    static const int32_T iv17[2] = { 1, 28 };
    const mxArray *d_y;
    static const int32_T iv18[2] = { 1, 21 };
    int32_T b_m[2];
    int32_T i2;
    int32_T outsize[2];
    int32_T loop_ub;
    EMLRTPUSHRTSTACK(&dc_emlrtRSI);
    if ((m != muDoubleScalarFloor(m)) || muDoubleScalarIsInf(m)) {
        p = FALSE;
    } else {
        p = TRUE;
    }
    if (p) {
    } else {
        EMLRTPUSHRTSTACK(&yb_emlrtRSI);
        y = NULL;
        m4 = mxCreateCharArray(2, iv15);
        emlrtInitCharArray(28, m4, cv11);
        emlrtAssign(&y, m4);
        error(message(y, &m_emlrtMCI), &n_emlrtMCI);
        EMLRTPOPRTSTACK(&yb_emlrtRSI);
    }
    if (m <= 0.0) {
        b_n = 0.0;
    } else {
        b_n = m;
    }
    if (b_n <= 2.147483647E+9) {
    } else {
        EMLRTPUSHRTSTACK(&ac_emlrtRSI);
        b_y = NULL;
        m4 = mxCreateCharArray(2, iv16);
        emlrtInitCharArray(21, m4, cv12);
        emlrtAssign(&b_y, m4);
        error(message(b_y, &o_emlrtMCI), &p_emlrtMCI);
        EMLRTPOPRTSTACK(&ac_emlrtRSI);
    }
    EMLRTPOPRTSTACK(&dc_emlrtRSI);
    EMLRTPUSHRTSTACK(&ec_emlrtRSI);
    if ((n != muDoubleScalarFloor(n)) || muDoubleScalarIsInf(n)) {
        p = FALSE;
    } else {
        p = TRUE;
    }
    if (p) {
    } else {
        EMLRTPUSHRTSTACK(&yb_emlrtRSI);
        c_y = NULL;
        m4 = mxCreateCharArray(2, iv17);
        emlrtInitCharArray(28, m4, cv11);
        emlrtAssign(&c_y, m4);
        error(message(c_y, &m_emlrtMCI), &n_emlrtMCI);
        EMLRTPOPRTSTACK(&yb_emlrtRSI);
    }
    if (n <= 0.0) {
        b_n = 0.0;
    } else {
        b_n = n;
    }
    if (b_n <= 2.147483647E+9) {
    } else {
        EMLRTPUSHRTSTACK(&ac_emlrtRSI);
        d_y = NULL;
        m4 = mxCreateCharArray(2, iv18);
        emlrtInitCharArray(21, m4, cv12);
        emlrtAssign(&d_y, m4);
        error(message(d_y, &o_emlrtMCI), &p_emlrtMCI);
        EMLRTPOPRTSTACK(&ac_emlrtRSI);
    }
    EMLRTPOPRTSTACK(&ec_emlrtRSI);
    b_n = m;
    b_n = b_n < 0.0 ? muDoubleScalarCeil(b_n - 0.5) : muDoubleScalarFloor(b_n + 0.5);
    if (b_n < 2.147483648E+9) {
        if (b_n >= -2.147483648E+9) {
            i2 = (int32_T)b_n;
        } else {
            i2 = MIN_int32_T;
        }
    } else if (b_n >= 2.147483648E+9) {
        i2 = MAX_int32_T;
    } else {
        i2 = 0;
    }
    b_m[0] = i2;
    b_n = n;
    b_n = b_n < 0.0 ? muDoubleScalarCeil(b_n - 0.5) : muDoubleScalarFloor(b_n + 0.5);
    if (b_n < 2.147483648E+9) {
        if (b_n >= -2.147483648E+9) {
            i2 = (int32_T)b_n;
        } else {
            i2 = MIN_int32_T;
        }
    } else if (b_n >= 2.147483648E+9) {
        i2 = MAX_int32_T;
    } else {
        i2 = 0;
    }
    b_m[1] = i2;
    for (i2 = 0; i2 < 2; i2++) {
        outsize[i2] = b_m[i2];
    }
    b_n = m;
    b_n = b_n < 0.0 ? muDoubleScalarCeil(b_n - 0.5) : muDoubleScalarFloor(b_n + 0.5);
    if (b_n < 2.147483648E+9) {
        if (b_n >= -2.147483648E+9) {
            i2 = (int32_T)b_n;
        } else {
            i2 = MIN_int32_T;
        }
    } else if (b_n >= 2.147483648E+9) {
        i2 = MAX_int32_T;
    } else {
        i2 = 0;
    }
    b_m[0] = i2;
    b_n = n;
    b_n = b_n < 0.0 ? muDoubleScalarCeil(b_n - 0.5) : muDoubleScalarFloor(b_n + 0.5);
    if (b_n < 2.147483648E+9) {
        if (b_n >= -2.147483648E+9) {
            i2 = (int32_T)b_n;
        } else {
            i2 = MIN_int32_T;
        }
    } else if (b_n >= 2.147483648E+9) {
        i2 = MAX_int32_T;
    } else {
        i2 = 0;
    }
    b_m[1] = i2;
    for (i2 = 0; i2 < 2; i2++) {
        emlrtNonNegativeCheckR2009b((real_T)b_m[i2], &k_emlrtDCI);
    }
    i2 = b->size[0] * b->size[1];
    b->size[0] = outsize[0];
    emxEnsureCapacity((emxArray__common *)b, i2, (int32_T)sizeof(real_T), &r_emlrtRTEI);
    i2 = b->size[0] * b->size[1];
    b->size[1] = outsize[1];
    emxEnsureCapacity((emxArray__common *)b, i2, (int32_T)sizeof(real_T), &r_emlrtRTEI);
    loop_ub = outsize[0] * outsize[1] - 1;
    for (i2 = 0; i2 <= loop_ub; i2++) {
        b->data[i2] = 0.0;
    }
}

/*
 * 
 */
void c_repmat(const emxArray_real_T *a, real_T n, emxArray_real_T *b)
{
    boolean_T p;
    const mxArray *y;
    static const int32_T iv19[2] = { 1, 28 };
    const mxArray *m5;
    static const char_T cv13[28] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'N', 'o', 'n', 'I', 'n', 't', 'e', 'g', 'e', 'r', 'I', 'n', 'p', 'u', 't' };
    real_T b_n;
    const mxArray *b_y;
    static const int32_T iv20[2] = { 1, 21 };
    static const char_T cv14[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };
    int32_T mv[2];
    int32_T ib;
    int32_T b_a[2];
    int32_T iv21[2];
    int32_T jtilecol;
    int32_T ia;
    int32_T k;
    EMLRTPUSHRTSTACK(&fc_emlrtRSI);
    EMLRTPOPRTSTACK(&fc_emlrtRSI);
    EMLRTPUSHRTSTACK(&gc_emlrtRSI);
    if ((n != muDoubleScalarFloor(n)) || muDoubleScalarIsInf(n)) {
        p = FALSE;
    } else {
        p = TRUE;
    }
    if (p) {
    } else {
        EMLRTPUSHRTSTACK(&yb_emlrtRSI);
        y = NULL;
        m5 = mxCreateCharArray(2, iv19);
        emlrtInitCharArray(28, m5, cv13);
        emlrtAssign(&y, m5);
        error(message(y, &m_emlrtMCI), &n_emlrtMCI);
        EMLRTPOPRTSTACK(&yb_emlrtRSI);
    }
    if (n <= 0.0) {
        b_n = 0.0;
    } else {
        b_n = n;
    }
    if (b_n <= 2.147483647E+9) {
    } else {
        EMLRTPUSHRTSTACK(&ac_emlrtRSI);
        b_y = NULL;
        m5 = mxCreateCharArray(2, iv20);
        emlrtInitCharArray(21, m5, cv14);
        emlrtAssign(&b_y, m5);
        error(message(b_y, &o_emlrtMCI), &p_emlrtMCI);
        EMLRTPOPRTSTACK(&ac_emlrtRSI);
    }
    EMLRTPOPRTSTACK(&gc_emlrtRSI);
    mv[0] = 1;
    b_n = n;
    b_n = b_n < 0.0 ? muDoubleScalarCeil(b_n - 0.5) : muDoubleScalarFloor(b_n + 0.5);
    if (b_n < 2.147483648E+9) {
        if (b_n >= -2.147483648E+9) {
            ib = (int32_T)b_n;
        } else {
            ib = MIN_int32_T;
        }
    } else if (b_n >= 2.147483648E+9) {
        ib = MAX_int32_T;
    } else {
        ib = 0;
    }
    mv[1] = ib;
    b_a[0] = a->size[0];
    b_a[1] = 1;
    for (ib = 0; ib < 2; ib++) {
        iv21[ib] = (int32_T)emlrtNonNegativeCheckR2009b((real_T)(b_a[ib] * mv[ib]), &l_emlrtDCI);
    }
    ib = b->size[0] * b->size[1];
    b->size[0] = iv21[0];
    b->size[1] = iv21[1];
    emxEnsureCapacity((emxArray__common *)b, ib, (int32_T)sizeof(real_T), &s_emlrtRTEI);
    if ((b->size[0] == 0) || (b->size[1] == 0)) {
    } else {
        ib = 1;
        for (jtilecol = 1; jtilecol <= mv[1]; jtilecol++) {
            ia = 1;
            for (k = 1; k <= a->size[0]; k++) {
                b->data[emlrtDynamicBoundsCheck(ib, 1, b->size[0] * b->size[1], &kd_emlrtBCI) - 1] = a->data[emlrtDynamicBoundsCheck(ia, 1, a->size[0], &ld_emlrtBCI) - 1];
                ia++;
                ib++;
            }
        }
    }
}

/*
 * 
 */
void repmat(const emxArray_real_T *a, real_T m, emxArray_real_T *b)
{
    boolean_T p;
    const mxArray *y;
    static const int32_T iv12[2] = { 1, 28 };
    const mxArray *m3;
    static const char_T cv9[28] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'N', 'o', 'n', 'I', 'n', 't', 'e', 'g', 'e', 'r', 'I', 'n', 'p', 'u', 't' };
    real_T n;
    const mxArray *b_y;
    static const int32_T iv13[2] = { 1, 21 };
    static const char_T cv10[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };
    int32_T ia;
    int32_T mv[2];
    int32_T iv14[2];
    int32_T ib;
    int32_T iacol;
    int32_T jcol;
    int32_T itilerow;
    EMLRTPUSHRTSTACK(&wb_emlrtRSI);
    if ((m != muDoubleScalarFloor(m)) || muDoubleScalarIsInf(m)) {
        p = FALSE;
    } else {
        p = TRUE;
    }
    if (p) {
    } else {
        EMLRTPUSHRTSTACK(&yb_emlrtRSI);
        y = NULL;
        m3 = mxCreateCharArray(2, iv12);
        emlrtInitCharArray(28, m3, cv9);
        emlrtAssign(&y, m3);
        error(message(y, &m_emlrtMCI), &n_emlrtMCI);
        EMLRTPOPRTSTACK(&yb_emlrtRSI);
    }
    if (m <= 0.0) {
        n = 0.0;
    } else {
        n = m;
    }
    if (n <= 2.147483647E+9) {
    } else {
        EMLRTPUSHRTSTACK(&ac_emlrtRSI);
        b_y = NULL;
        m3 = mxCreateCharArray(2, iv13);
        emlrtInitCharArray(21, m3, cv10);
        emlrtAssign(&b_y, m3);
        error(message(b_y, &o_emlrtMCI), &p_emlrtMCI);
        EMLRTPOPRTSTACK(&ac_emlrtRSI);
    }
    EMLRTPOPRTSTACK(&wb_emlrtRSI);
    EMLRTPUSHRTSTACK(&xb_emlrtRSI);
    EMLRTPOPRTSTACK(&xb_emlrtRSI);
    n = m;
    n = n < 0.0 ? muDoubleScalarCeil(n - 0.5) : muDoubleScalarFloor(n + 0.5);
    if (n < 2.147483648E+9) {
        if (n >= -2.147483648E+9) {
            ia = (int32_T)n;
        } else {
            ia = MIN_int32_T;
        }
    } else if (n >= 2.147483648E+9) {
        ia = MAX_int32_T;
    } else {
        ia = 0;
    }
    mv[0] = ia;
    mv[1] = 1;
    for (ia = 0; ia < 2; ia++) {
        iv14[ia] = (int32_T)emlrtNonNegativeCheckR2009b((real_T)(a->size[ia] * mv[ia]), &j_emlrtDCI);
    }
    ia = b->size[0] * b->size[1];
    b->size[0] = iv14[0];
    b->size[1] = iv14[1];
    emxEnsureCapacity((emxArray__common *)b, ia, (int32_T)sizeof(real_T), &p_emlrtRTEI);
    if ((b->size[0] == 0) || (b->size[1] == 0)) {
    } else {
        ia = 1;
        ib = 1;
        iacol = 1;
        for (jcol = 1; jcol <= a->size[1]; jcol++) {
            for (itilerow = 1; itilerow <= mv[0]; itilerow++) {
                b->data[emlrtDynamicBoundsCheck(ib, 1, b->size[0] * b->size[1], &id_emlrtBCI) - 1] = a->data[emlrtDynamicBoundsCheck(iacol, 1, a->size[1], &jd_emlrtBCI) - 1];
                ia = iacol + 1;
                ib++;
            }
            iacol = ia;
        }
    }
}
/* End of code generation (repmat.c) */
