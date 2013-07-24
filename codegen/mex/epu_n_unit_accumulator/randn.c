/*
 * randn.c
 *
 * Code generation for function 'randn'
 *
 * C source code generated on: Fri Aug 31 09:23:48 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_accumulator.h"
#include "randn.h"
#include "epu_n_unit_accumulator_emxutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo ab_emlrtRSI = { 98, "randn", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/randn.m" };
static emlrtRSInfo bb_emlrtRSI = { 42, "eml_rand_shr3cong", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_rand_shr3cong.m" };
static emlrtRSInfo cb_emlrtRSI = { 147, "eml_rand_shr3cong", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_rand_shr3cong.m" };
static emlrtRSInfo db_emlrtRSI = { 158, "eml_rand_shr3cong", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_rand_shr3cong.m" };
static emlrtRSInfo eb_emlrtRSI = { 182, "eml_rand_shr3cong", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_rand_shr3cong.m" };
static emlrtRSInfo fb_emlrtRSI = { 185, "eml_rand_shr3cong", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_rand_shr3cong.m" };
static emlrtRTEInfo j_emlrtRTEI = { 87, 5, "randn", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/randn.m" };
static emlrtDCInfo m_emlrtDCI = { 87, 37, "randn", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/randn.m", 1 };
static emlrtDCInfo n_emlrtDCI = { 87, 37, "randn", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/randn.m", 4 };
static emlrtBCInfo kc_emlrtBCI = { -1, -1, 105, 19, "", "randn", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/randn.m", 0 };
static emlrtBCInfo lc_emlrtBCI = { -1, -1, 98, 19, "", "randn", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/randn.m", 0 };

/* Function Declarations */
static void genrandu(uint32_T s, uint32_T *state, real_T *r);

/* Function Definitions */

/*
 * 
 */
static void genrandu(uint32_T s, uint32_T *state, real_T *r)
{
    int32_T hi;
    uint32_T test1;
    uint32_T test2;
    hi = (int32_T)(s / 127773U);
    test1 = 16807U * (s - (uint32_T)hi * 127773U);
    test2 = 2836U * (uint32_T)hi;
    if (test1 < test2) {
        *state = (test1 - test2) + 2147483647U;
    } else {
        *state = test1 - test2;
    }
    *r = (real_T)*state * 4.6566128752457969E-10;
}

/*
 * 
 */
void randn(epu_n_unit_accumulatorStackData *SD, real_T varargin_2, emxArray_real_T *r)
{
    int32_T i2;
    int32_T k;
    uint32_T icng;
    uint32_T jsr;
    uint32_T state;
    int32_T j;
    int32_T jp1;
    static const real_T dv0[65] = { 0.340945, 0.4573146, 0.5397793, 0.6062427, 0.6631691, 0.7136975, 0.7596125, 0.8020356, 0.8417227, 0.8792102, 0.9148948, 0.9490791, 0.9820005, 1.0138492, 1.044781, 1.0749254, 1.1043917, 1.1332738, 1.161653, 1.189601, 1.2171815, 1.2444516, 1.2714635, 1.298265, 1.3249008, 1.3514125, 1.3778399, 1.4042211, 1.4305929, 1.4569915, 1.4834527, 1.5100122, 1.5367061, 1.5635712, 1.5906454, 1.617968, 1.6455802, 1.6735255, 1.7018503, 1.7306045, 1.7598422, 1.7896223, 1.8200099, 1.851077, 1.8829044, 1.9155831, 1.9492166, 1.9839239, 2.0198431, 2.0571356, 2.095993, 2.136645, 2.1793713, 2.2245175, 2.2725186, 2.3239338, 2.3795008, 2.4402218, 2.5075117, 2.5834658, 2.6713916, 2.7769942, 2.7769942, 2.7769942, 2.7769942 };
    real_T b_r;
    real_T x;
    real_T y;
    real_T s;
    real_T c_r;
    emlrtIntegerCheckR2009b(emlrtNonNegativeCheckR2009b(varargin_2, &n_emlrtDCI), &m_emlrtDCI);
    i2 = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = (int32_T)varargin_2;
    emxEnsureCapacity((emxArray__common *)r, i2, (int32_T)sizeof(real_T), &j_emlrtRTEI);
    if (SD->pd->method == 0) {
        i2 = r->size[1];
        for (k = 0; k <= i2 - 1; k++) {
            EMLRTPUSHRTSTACK(&ab_emlrtRSI);
            EMLRTPUSHRTSTACK(&bb_emlrtRSI);
            EMLRTPUSHRTSTACK(&cb_emlrtRSI);
            icng = 69069U * SD->pd->v5_state[0] + 1234567U;
            jsr = SD->pd->v5_state[1] ^ SD->pd->v5_state[1] << 13U;
            jsr ^= jsr >> 17U;
            jsr ^= jsr << 5U;
            state = icng + jsr;
            EMLRTPOPRTSTACK(&cb_emlrtRSI);
            j = (int32_T)(state & 63U);
            jp1 = j + 1;
            b_r = (real_T)(int32_T)state * 4.6566128730773926E-10 * dv0[jp1];
            if (muDoubleScalarAbs(b_r) <= dv0[j]) {
            } else {
                x = (muDoubleScalarAbs(b_r) - dv0[j]) / (dv0[jp1] - dv0[j]);
                EMLRTPUSHRTSTACK(&db_emlrtRSI);
                icng = 69069U * icng + 1234567U;
                jsr ^= jsr << 13U;
                jsr ^= jsr >> 17U;
                jsr ^= jsr << 5U;
                EMLRTPOPRTSTACK(&db_emlrtRSI);
                y = (real_T)(int32_T)(icng + jsr) * 2.328306436538696E-10;
                s = x + (0.5 + y);
                if (s > 1.301198) {
                    if (b_r < 0.0) {
                        b_r = 0.4878992 * x - 0.4878992;
                    } else {
                        b_r = 0.4878992 - 0.4878992 * x;
                    }
                } else if (s <= 0.9689279) {
                } else {
                    c_r = 0.4878992 * x;
                    x = 0.4878992 - 0.4878992 * x;
                    if (0.5 + y > 12.67706 - 12.37586 * muDoubleScalarExp(-0.5 * (0.4878992 - c_r) * x)) {
                        if (b_r < 0.0) {
                            b_r = -(0.4878992 - c_r);
                        } else {
                            b_r = 0.4878992 - c_r;
                        }
                    } else if (muDoubleScalarExp(-0.5 * dv0[jp1] * dv0[jp1]) + (0.5 + y) * 0.01958303 / dv0[jp1] <= muDoubleScalarExp(-0.5 * b_r * b_r)) {
                    } else {
                        do {
                            EMLRTPUSHRTSTACK(&eb_emlrtRSI);
                            icng = 69069U * icng + 1234567U;
                            jsr ^= jsr << 13U;
                            jsr ^= jsr >> 17U;
                            jsr ^= jsr << 5U;
                            EMLRTPOPRTSTACK(&eb_emlrtRSI);
                            x = muDoubleScalarLog(0.5 + (real_T)(int32_T)(icng + jsr) * 2.328306436538696E-10) / 2.776994;
                            EMLRTPUSHRTSTACK(&fb_emlrtRSI);
                            icng = 69069U * icng + 1234567U;
                            jsr ^= jsr << 13U;
                            jsr ^= jsr >> 17U;
                            jsr ^= jsr << 5U;
                            EMLRTPOPRTSTACK(&fb_emlrtRSI);
                        } while (!(-2.0 * muDoubleScalarLog(0.5 + (real_T)(int32_T)(icng + jsr) * 2.328306436538696E-10) > x * x));
                        if (b_r < 0.0) {
                            b_r = x - 2.776994;
                        } else {
                            b_r = 2.776994 - x;
                        }
                    }
                }
            }
            SD->pd->v5_state[0] = icng;
            SD->pd->v5_state[1] = jsr;
            EMLRTPOPRTSTACK(&bb_emlrtRSI);
            EMLRTPOPRTSTACK(&ab_emlrtRSI);
            r->data[emlrtDynamicBoundsCheck(k + 1, 1, r->size[1], &lc_emlrtBCI) - 1] = b_r;
        }
    } else {
        i2 = r->size[1];
        for (k = 0; k <= i2 - 1; k++) {
            do {
                genrandu(SD->pd->v4_state, &state, &b_r);
                genrandu(state, &SD->pd->v4_state, &s);
                c_r = 2.0 * b_r - 1.0;
                s = 2.0 * s - 1.0;
                s = s * s + c_r * c_r;
            } while (!(s <= 1.0));
            r->data[emlrtDynamicBoundsCheck(k + 1, 1, r->size[1], &kc_emlrtBCI) - 1] = (2.0 * b_r - 1.0) * muDoubleScalarSqrt(-2.0 * muDoubleScalarLog(s) / s);
        }
    }
}
/* End of code generation (randn.c) */
