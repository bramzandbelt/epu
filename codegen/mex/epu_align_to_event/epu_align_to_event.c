/*
 * epu_align_to_event.c
 *
 * Code generation for function 'epu_align_to_event'
 *
 * C source code generated on: Fri Aug 31 09:30:57 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_align_to_event.h"
#include "epu_align_to_event_emxutil.h"
#include "repmat.h"
#include "diff.h"
#include "round.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 21, "epu_align_to_event", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_align_to_event.m" };
static emlrtRSInfo b_emlrtRSI = { 26, "epu_align_to_event", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_align_to_event.m" };
static emlrtRSInfo c_emlrtRSI = { 27, "epu_align_to_event", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_align_to_event.m" };
static emlrtRSInfo d_emlrtRSI = { 29, "epu_align_to_event", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_align_to_event.m" };
static emlrtRSInfo e_emlrtRSI = { 29, "epu_align_to_event", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_align_to_event.m" };
static emlrtRSInfo f_emlrtRSI = { 32, "epu_align_to_event", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_align_to_event.m" };
static emlrtRSInfo g_emlrtRSI = { 33, "epu_align_to_event", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_align_to_event.m" };
static emlrtRSInfo h_emlrtRSI = { 36, "epu_align_to_event", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_align_to_event.m" };
static emlrtRSInfo i_emlrtRSI = { 37, "epu_align_to_event", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_align_to_event.m" };
static emlrtRSInfo j_emlrtRSI = { 43, "epu_align_to_event", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_align_to_event.m" };
static emlrtRSInfo k_emlrtRSI = { 16, "min", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/min.m" };
static emlrtRSInfo l_emlrtRSI = { 18, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtRSInfo m_emlrtRSI = { 88, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtRSInfo n_emlrtRSI = { 16, "max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/max.m" };
static emlrtRSInfo o_emlrtRSI = { 18, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtRSInfo p_emlrtRSI = { 88, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtRSInfo q_emlrtRSI = { 79, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRSInfo r_emlrtRSI = { 117, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRSInfo s_emlrtRSI = { 233, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRSInfo u_emlrtRSI = { 48, "eml_assert_valid_size_arg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m" };
static emlrtRSInfo v_emlrtRSI = { 52, "eml_assert_valid_size_arg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m" };
static emlrtRSInfo w_emlrtRSI = { 16, "min", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/min.m" };
static emlrtRSInfo x_emlrtRSI = { 18, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtRSInfo y_emlrtRSI = { 88, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtRSInfo ab_emlrtRSI = { 16, "max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/max.m" };
static emlrtRSInfo bb_emlrtRSI = { 18, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtRSInfo cb_emlrtRSI = { 88, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtRSInfo db_emlrtRSI = { 11, "eml_li_find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m" };
static emlrtRSInfo eb_emlrtRSI = { 14, "eml_li_find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m" };
static emlrtRSInfo fb_emlrtRSI = { 20, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtRSInfo gb_emlrtRSI = { 41, "reshape", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/reshape.m" };
static emlrtRSInfo hb_emlrtRSI = { 45, "reshape", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/reshape.m" };
static emlrtRSInfo ib_emlrtRSI = { 58, "reshape", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/reshape.m" };
static emlrtRSInfo jb_emlrtRSI = { 61, "reshape", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/reshape.m" };
static emlrtRSInfo kb_emlrtRSI = { 61, "reshape", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/reshape.m" };
static emlrtRSInfo lb_emlrtRSI = { 66, "reshape", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/reshape.m" };
static emlrtMCInfo emlrtMCI = { 234, 5, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtMCInfo b_emlrtMCI = { 233, 15, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtMCInfo c_emlrtMCI = { 49, 13, "eml_assert_valid_size_arg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m" };
static emlrtMCInfo d_emlrtMCI = { 48, 23, "eml_assert_valid_size_arg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m" };
static emlrtMCInfo e_emlrtMCI = { 53, 5, "eml_assert_valid_size_arg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m" };
static emlrtMCInfo f_emlrtMCI = { 52, 15, "eml_assert_valid_size_arg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m" };
static emlrtMCInfo g_emlrtMCI = { 14, 5, "eml_li_find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m" };
static emlrtMCInfo h_emlrtMCI = { 20, 19, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo i_emlrtMCI = { 20, 5, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo j_emlrtMCI = { 67, 5, "reshape", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/reshape.m" };
static emlrtMCInfo k_emlrtMCI = { 66, 15, "reshape", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/reshape.m" };
static emlrtRTEInfo emlrtRTEI = { 118, 1, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRTEInfo b_emlrtRTEI = { 1, 25, "epu_align_to_event", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_align_to_event.m" };
static emlrtRTEInfo c_emlrtRTEI = { 20, 9, "eml_li_find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m" };
static emlrtRTEInfo d_emlrtRTEI = { 65, 1, "reshape", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/reshape.m" };
static emlrtRTEInfo e_emlrtRTEI = { 31, 1, "epu_align_to_event", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_align_to_event.m" };
static emlrtRTEInfo f_emlrtRTEI = { 29, 1, "epu_align_to_event", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_align_to_event.m" };
static emlrtECInfo emlrtECI = { 2, 29, 3, "epu_align_to_event", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_align_to_event.m" };
static emlrtECInfo b_emlrtECI = { 1, 43, 38, "epu_align_to_event", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_align_to_event.m" };
static emlrtDCInfo emlrtDCI = { 118, 28, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 4 };
static emlrtBCInfo emlrtBCI = { -1, -1, 120, 5, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtDCInfo b_emlrtDCI = { 20, 34, "eml_li_find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m", 4 };
static emlrtBCInfo b_emlrtBCI = { -1, -1, 69, 12, "", "reshape", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/reshape.m", 0 };
static emlrtBCInfo c_emlrtBCI = { -1, -1, 122, 9, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo d_emlrtBCI = { -1, -1, 134, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo e_emlrtBCI = { -1, -1, 135, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo f_emlrtBCI = { -1, -1, 131, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtDCInfo c_emlrtDCI = { 33, 26, "epu_align_to_event", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_align_to_event.m", 1 };
static emlrtDCInfo d_emlrtDCI = { 33, 26, "epu_align_to_event", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_align_to_event.m", 4 };
static emlrtDCInfo e_emlrtDCI = { 37, 39, "epu_align_to_event", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_align_to_event.m", 1 };
static emlrtDCInfo f_emlrtDCI = { 37, 39, "epu_align_to_event", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_align_to_event.m", 4 };
static emlrtBCInfo g_emlrtBCI = { -1, -1, 43, 24, "currentArray", "epu_align_to_event", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_align_to_event.m", 0 };
static emlrtDCInfo g_emlrtDCI = { 65, 48, "reshape", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/reshape.m", 4 };
static emlrtBCInfo h_emlrtBCI = { -1, -1, 69, 5, "", "reshape", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/reshape.m", 0 };
static emlrtBCInfo i_emlrtBCI = { -1, -1, 27, 12, "", "eml_li_find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m", 0 };
static emlrtBCInfo j_emlrtBCI = { -1, -1, 28, 13, "", "eml_li_find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m", 0 };
static emlrtBCInfo k_emlrtBCI = { -1, -1, 40, 12, "", "eml_li_find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m", 0 };
static emlrtBCInfo l_emlrtBCI = { -1, -1, 127, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo m_emlrtBCI = { -1, -1, 128, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };

/* Function Declarations */
static void eml_error(void);
static void error(const mxArray *b, emlrtMCInfo *location);
static const mxArray *message(const mxArray *b, emlrtMCInfo *location);

/* Function Definitions */

/*
 * 
 */
static void eml_error(void)
{
    const mxArray *y;
    static const int32_T iv8[2] = { 1, 39 };
    const mxArray *m2;
    static const char_T cv4[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'r', 'e', 's', 'h', 'a', 'p', 'e', '_', 'e', 'm', 'p', 't', 'y', 'R', 'e', 's', 'h', 'a', 'p', 'e', 'L', 'i', 'm', 'i', 't' };
    EMLRTPUSHRTSTACK(&fb_emlrtRSI);
    y = NULL;
    m2 = mxCreateCharArray(2, iv8);
    emlrtInitCharArray(39, m2, cv4);
    emlrtAssign(&y, m2);
    error(message(y, &h_emlrtMCI), &i_emlrtMCI);
    EMLRTPOPRTSTACK(&fb_emlrtRSI);
}

static void error(const mxArray *b, emlrtMCInfo *location)
{
    const mxArray *pArray;
    pArray = b;
    emlrtCallMATLAB(0, NULL, 1, &pArray, "error", TRUE, location);
}

static const mxArray *message(const mxArray *b, emlrtMCInfo *location)
{
    const mxArray *pArray;
    const mxArray *m4;
    pArray = b;
    return emlrtCallMATLAB(1, &m4, 1, &pArray, "message", TRUE, location);
}

/*
 * 
 */
void eml_assert_valid_size_arg(real_T varargin_1)
{
    boolean_T p;
    const mxArray *y;
    static const int32_T iv6[2] = { 1, 28 };
    const mxArray *m1;
    static const char_T cv2[28] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'N', 'o', 'n', 'I', 'n', 't', 'e', 'g', 'e', 'r', 'I', 'n', 'p', 'u', 't' };
    real_T n;
    const mxArray *b_y;
    static const int32_T iv7[2] = { 1, 21 };
    static const char_T cv3[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };
    if ((varargin_1 != muDoubleScalarFloor(varargin_1)) || muDoubleScalarIsInf(varargin_1)) {
        p = FALSE;
    } else {
        p = TRUE;
    }
    if (p) {
    } else {
        EMLRTPUSHRTSTACK(&u_emlrtRSI);
        y = NULL;
        m1 = mxCreateCharArray(2, iv6);
        emlrtInitCharArray(28, m1, cv2);
        emlrtAssign(&y, m1);
        error(message(y, &c_emlrtMCI), &d_emlrtMCI);
        EMLRTPOPRTSTACK(&u_emlrtRSI);
    }
    if (varargin_1 <= 0.0) {
        n = 0.0;
    } else {
        n = varargin_1;
    }
    if (n <= 2.147483647E+9) {
    } else {
        EMLRTPUSHRTSTACK(&v_emlrtRSI);
        b_y = NULL;
        m1 = mxCreateCharArray(2, iv7);
        emlrtInitCharArray(21, m1, cv3);
        emlrtAssign(&b_y, m1);
        error(message(b_y, &e_emlrtMCI), &f_emlrtMCI);
        EMLRTPOPRTSTACK(&v_emlrtRSI);
    }
}

/*
 * function alignedArray = epu_align_to_event(rt,outputTimeFrame,minTrialTime,trajectories)
 */
void epu_align_to_event(real_T rt, real_T outputTimeFrame[2], real_T minTrialTime, const emxArray_real_T *trajectories, emxArray_real_T *alignedArray)
{
    real_T inputTimeFrame[2];
    real_T timeFrameInterest[2];
    int32_T i0;
    real_T varargin_1[4];
    int32_T ixstart;
    real_T tmp1;
    int32_T nm1;
    boolean_T exitg10;
    real_T ndbl;
    boolean_T exitg9;
    int32_T nx;
    real_T apnd;
    boolean_T n_too_large;
    real_T cdiff;
    real_T absa;
    real_T absb;
    const mxArray *y;
    static const int32_T iv0[2] = { 1, 21 };
    const mxArray *m0;
    static const char_T cv0[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };
    emxArray_real_T *b_y;
    int32_T k;
    emxArray_real_T *c_y;
    emxArray_real_T *r0;
    int32_T sz[2];
    int32_T iv1[2];
    emxArray_real_T *currentArray;
    boolean_T exitg8;
    boolean_T exitg7;
    boolean_T exitg6;
    boolean_T exitg5;
    boolean_T exitg4;
    boolean_T exitg3;
    boolean_T exitg2;
    boolean_T exitg1;
    emxArray_real_T *b_currentArray;
    emxArray_real_T *c_currentArray;
    emxArray_real_T *t;
    emxArray_boolean_T *x;
    emxArray_boolean_T *r1;
    int32_T b_x[1];
    int32_T iv2[1];
    const mxArray *d_y;
    emxArray_int32_T *e_y;
    emxArray_real_T *d_currentArray;
    emxArray_real_T *e_currentArray;
    const mxArray *f_y;
    static const int32_T iv3[2] = { 1, 40 };
    static const char_T cv1[40] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'g', 'e', 't', 'R', 'e', 's', 'h', 'a', 'p', 'e', 'D', 'i', 'm', 's', '_', 'n', 'o', 't', 'S', 'a', 'm', 'e', 'N', 'u', 'm', 'e', 'l' };
    emxArray_real_T *f_currentArray;
    emlrtHeapReferenceStackEnterFcn();
    /*  */
    /*  Usage alignedArray = align_to_rt(rt,outputTimeFrame,minTrialTime,trajectories) */
    /*  rt                 - scalar, response time */
    /*  outputTimeFrame    - 1x2 vector containing the time frame for which to plot */
    /*                     data */
    /*  minTrialTime       - scalar, the time (in ms) for the first data point in input array */
    /*  trajectories       - 1xN vector containing activation trajectory for this trial */
    /*  */
    /*  Based on Mathew Nelson's ADAlignTrials */
    /*  */
    /*  Bram Zandbelt, November 2011 */
    /*  Handling input arguments */
    /* 'epu_align_to_event:15' if nargin<4 */
    /*  Round data */
    /* 'epu_align_to_event:20' rt=round(rt); */
    b_round(&rt);
    /* 'epu_align_to_event:21' outputTimeFrame=round(outputTimeFrame); */
    EMLRTPUSHRTSTACK(&emlrtRSI);
    c_round(outputTimeFrame);
    EMLRTPOPRTSTACK(&emlrtRSI);
    /* 'epu_align_to_event:22' minTrialTime=round(minTrialTime); */
    b_round(&minTrialTime);
    /* 'epu_align_to_event:24' inputTimeFrame = [minTrialTime,minTrialTime+size(trajectories,2)-1]; */
    inputTimeFrame[0] = minTrialTime;
    inputTimeFrame[1] = (minTrialTime + (real_T)trajectories->size[1]) - 1.0;
    /* 'epu_align_to_event:25' timeFrameInterest = rt+outputTimeFrame; */
    for (i0 = 0; i0 < 2; i0++) {
        timeFrameInterest[i0] = rt + outputTimeFrame[i0];
    }
    /* 'epu_align_to_event:26' absTimeFrame = [min([inputTimeFrame,timeFrameInterest]),max([inputTimeFrame,timeFrameInterest])]; */
    EMLRTPUSHRTSTACK(&b_emlrtRSI);
    for (i0 = 0; i0 < 2; i0++) {
        varargin_1[i0] = inputTimeFrame[i0];
    }
    for (i0 = 0; i0 < 2; i0++) {
        varargin_1[i0 + 2] = timeFrameInterest[i0];
    }
    EMLRTPUSHRTSTACK(&k_emlrtRSI);
    EMLRTPUSHRTSTACK(&l_emlrtRSI);
    EMLRTPUSHRTSTACK(&m_emlrtRSI);
    ixstart = 1;
    tmp1 = varargin_1[0];
    if (muDoubleScalarIsNaN(varargin_1[0])) {
        nm1 = 2;
        exitg10 = 0U;
        while ((exitg10 == 0U) && (nm1 < 5)) {
            ixstart = nm1;
            if (!muDoubleScalarIsNaN(varargin_1[nm1 - 1])) {
                tmp1 = varargin_1[nm1 - 1];
                exitg10 = 1U;
            } else {
                nm1++;
            }
        }
    }
    if (ixstart < 4) {
        while (ixstart + 1 < 5) {
            if (varargin_1[ixstart] < tmp1) {
                tmp1 = varargin_1[ixstart];
            }
            ixstart++;
        }
    }
    EMLRTPOPRTSTACK(&m_emlrtRSI);
    EMLRTPOPRTSTACK(&l_emlrtRSI);
    EMLRTPOPRTSTACK(&k_emlrtRSI);
    for (i0 = 0; i0 < 2; i0++) {
        varargin_1[i0] = inputTimeFrame[i0];
    }
    for (i0 = 0; i0 < 2; i0++) {
        varargin_1[i0 + 2] = timeFrameInterest[i0];
    }
    EMLRTPUSHRTSTACK(&n_emlrtRSI);
    EMLRTPUSHRTSTACK(&o_emlrtRSI);
    EMLRTPUSHRTSTACK(&p_emlrtRSI);
    ixstart = 1;
    ndbl = varargin_1[0];
    if (muDoubleScalarIsNaN(varargin_1[0])) {
        nm1 = 2;
        exitg9 = 0U;
        while ((exitg9 == 0U) && (nm1 < 5)) {
            ixstart = nm1;
            if (!muDoubleScalarIsNaN(varargin_1[nm1 - 1])) {
                ndbl = varargin_1[nm1 - 1];
                exitg9 = 1U;
            } else {
                nm1++;
            }
        }
    }
    if (ixstart < 4) {
        while (ixstart + 1 < 5) {
            if (varargin_1[ixstart] > ndbl) {
                ndbl = varargin_1[ixstart];
            }
            ixstart++;
        }
    }
    EMLRTPOPRTSTACK(&p_emlrtRSI);
    EMLRTPOPRTSTACK(&o_emlrtRSI);
    EMLRTPOPRTSTACK(&n_emlrtRSI);
    timeFrameInterest[0] = tmp1;
    timeFrameInterest[1] = ndbl;
    EMLRTPOPRTSTACK(&b_emlrtRSI);
    /* 'epu_align_to_event:27' absNSamples = diff(absTimeFrame)+1; */
    EMLRTPUSHRTSTACK(&c_emlrtRSI);
    EMLRTPOPRTSTACK(&c_emlrtRSI);
    /* 'epu_align_to_event:29' t=repmat(absTimeFrame(1):1:absTimeFrame(2),1,1)-repmat(rt,1,absNSamples); */
    EMLRTPUSHRTSTACK(&d_emlrtRSI);
    EMLRTPUSHRTSTACK(&q_emlrtRSI);
    if (muDoubleScalarIsNaN(timeFrameInterest[0]) || muDoubleScalarIsNaN(timeFrameInterest[1])) {
        nx = 1;
        tmp1 = rtNaN;
        apnd = timeFrameInterest[1];
        n_too_large = FALSE;
    } else if (timeFrameInterest[1] < timeFrameInterest[0]) {
        nx = 0;
        tmp1 = timeFrameInterest[0];
        apnd = timeFrameInterest[1];
        n_too_large = FALSE;
    } else if (muDoubleScalarIsInf(timeFrameInterest[0]) || muDoubleScalarIsInf(timeFrameInterest[1])) {
        nx = 1;
        tmp1 = rtNaN;
        apnd = timeFrameInterest[1];
        if (timeFrameInterest[0] == timeFrameInterest[1]) {
            n_too_large = TRUE;
        } else {
            n_too_large = FALSE;
        }
        n_too_large = !n_too_large;
    } else {
        tmp1 = timeFrameInterest[0];
        ndbl = muDoubleScalarFloor((timeFrameInterest[1] - timeFrameInterest[0]) + 0.5);
        apnd = timeFrameInterest[0] + ndbl;
        cdiff = apnd - timeFrameInterest[1];
        absa = muDoubleScalarAbs(timeFrameInterest[0]);
        absb = muDoubleScalarAbs(timeFrameInterest[1]);
        if (absa > absb) {
            absb = absa;
        }
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * absb) {
            ndbl++;
            apnd = timeFrameInterest[1];
        } else if (cdiff > 0.0) {
            apnd = timeFrameInterest[0] + (ndbl - 1.0);
        } else {
            ndbl++;
        }
        n_too_large = (ndbl > 2.147483647E+9);
        if (ndbl >= 0.0) {
            nx = (int32_T)ndbl;
        } else {
            nx = 0;
        }
    }
    EMLRTPUSHRTSTACK(&r_emlrtRSI);
    if (!n_too_large) {
    } else {
        EMLRTPUSHRTSTACK(&s_emlrtRSI);
        y = NULL;
        m0 = mxCreateCharArray(2, iv0);
        emlrtInitCharArray(21, m0, cv0);
        emlrtAssign(&y, m0);
        error(message(y, &emlrtMCI), &b_emlrtMCI);
        EMLRTPOPRTSTACK(&s_emlrtRSI);
    }
    emxInit_real_T(&b_y, 2, &b_emlrtRTEI, TRUE);
    EMLRTPOPRTSTACK(&r_emlrtRSI);
    emlrtNonNegativeCheckR2009b((real_T)nx, &emlrtDCI);
    i0 = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = nx;
    emxEnsureCapacity((emxArray__common *)b_y, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
    if (nx > 0) {
        emlrtDynamicBoundsCheck(1, 1, b_y->size[1], &emlrtBCI);
        b_y->data[0] = tmp1;
        if (nx > 1) {
            b_y->data[emlrtDynamicBoundsCheck(nx, 1, b_y->size[1], &c_emlrtBCI) - 1] = apnd;
            nm1 = nx - 1;
            i0 = nm1;
            ixstart = (int32_T)((uint32_T)i0 >> 1);
            for (k = 1; k <= ixstart - 1; k++) {
                b_y->data[emlrtDynamicBoundsCheck(k + 1, 1, b_y->size[1], &l_emlrtBCI) - 1] = tmp1 + (real_T)k;
                b_y->data[emlrtDynamicBoundsCheck(nx - k, 1, b_y->size[1], &m_emlrtBCI) - 1] = apnd - (real_T)k;
            }
            if (ixstart << 1 == nm1) {
                b_y->data[emlrtDynamicBoundsCheck(ixstart + 1, 1, b_y->size[1], &f_emlrtBCI) - 1] = (tmp1 + apnd) / 2.0;
            } else {
                b_y->data[emlrtDynamicBoundsCheck(ixstart + 1, 1, b_y->size[1], &d_emlrtBCI) - 1] = tmp1 + (real_T)ixstart;
                b_y->data[emlrtDynamicBoundsCheck(ixstart + 2, 1, b_y->size[1], &e_emlrtBCI) - 1] = apnd - (real_T)ixstart;
            }
        }
    }
    emxInit_real_T(&c_y, 2, &b_emlrtRTEI, TRUE);
    EMLRTPOPRTSTACK(&q_emlrtRSI);
    i0 = c_y->size[0] * c_y->size[1];
    c_y->size[0] = 1;
    c_y->size[1] = b_y->size[1];
    emxEnsureCapacity((emxArray__common *)c_y, i0, (int32_T)sizeof(real_T), &b_emlrtRTEI);
    nm1 = b_y->size[0] * b_y->size[1] - 1;
    for (i0 = 0; i0 <= nm1; i0++) {
        c_y->data[i0] = b_y->data[i0];
    }
    emxInit_real_T(&r0, 2, &b_emlrtRTEI, TRUE);
    repmat(c_y, b_y);
    EMLRTPOPRTSTACK(&d_emlrtRSI);
    EMLRTPUSHRTSTACK(&e_emlrtRSI);
    b_repmat(rt, diff(timeFrameInterest) + 1.0, r0);
    EMLRTPOPRTSTACK(&e_emlrtRSI);
    emxFree_real_T(&c_y);
    for (i0 = 0; i0 < 2; i0++) {
        sz[i0] = b_y->size[i0];
    }
    for (i0 = 0; i0 < 2; i0++) {
        iv1[i0] = r0->size[i0];
    }
    emxInit_real_T(&currentArray, 2, &e_emlrtRTEI, TRUE);
    emlrtSizeEqCheckND(sz, iv1, &emlrtECI);
    /* 'epu_align_to_event:31' currentArray = trajectories; */
    i0 = currentArray->size[0] * currentArray->size[1];
    currentArray->size[0] = 1;
    currentArray->size[1] = trajectories->size[1];
    emxEnsureCapacity((emxArray__common *)currentArray, i0, (int32_T)sizeof(real_T), &b_emlrtRTEI);
    nm1 = trajectories->size[0] * trajectories->size[1] - 1;
    for (i0 = 0; i0 <= nm1; i0++) {
        currentArray->data[i0] = trajectories->data[i0];
    }
    /* 'epu_align_to_event:32' if min(absTimeFrame) < min(inputTimeFrame) */
    EMLRTPUSHRTSTACK(&f_emlrtRSI);
    EMLRTPUSHRTSTACK(&w_emlrtRSI);
    EMLRTPUSHRTSTACK(&x_emlrtRSI);
    EMLRTPUSHRTSTACK(&y_emlrtRSI);
    ixstart = 1;
    tmp1 = timeFrameInterest[0];
    if (muDoubleScalarIsNaN(timeFrameInterest[0])) {
        nm1 = 2;
        exitg8 = 0U;
        while ((exitg8 == 0U) && (nm1 < 3)) {
            ixstart = 2;
            if (!muDoubleScalarIsNaN(timeFrameInterest[1])) {
                tmp1 = timeFrameInterest[1];
                exitg8 = 1U;
            } else {
                nm1 = 3;
            }
        }
    }
    if ((ixstart < 2) && (timeFrameInterest[1] < tmp1)) {
        tmp1 = timeFrameInterest[1];
    }
    EMLRTPOPRTSTACK(&y_emlrtRSI);
    EMLRTPOPRTSTACK(&x_emlrtRSI);
    EMLRTPOPRTSTACK(&w_emlrtRSI);
    EMLRTPUSHRTSTACK(&w_emlrtRSI);
    EMLRTPUSHRTSTACK(&x_emlrtRSI);
    EMLRTPUSHRTSTACK(&y_emlrtRSI);
    ixstart = 1;
    ndbl = inputTimeFrame[0];
    if (muDoubleScalarIsNaN(inputTimeFrame[0])) {
        nm1 = 2;
        exitg7 = 0U;
        while ((exitg7 == 0U) && (nm1 < 3)) {
            ixstart = 2;
            if (!muDoubleScalarIsNaN(inputTimeFrame[1])) {
                ndbl = inputTimeFrame[1];
                exitg7 = 1U;
            } else {
                nm1 = 3;
            }
        }
    }
    if ((ixstart < 2) && (inputTimeFrame[1] < ndbl)) {
        ndbl = inputTimeFrame[1];
    }
    EMLRTPOPRTSTACK(&y_emlrtRSI);
    EMLRTPOPRTSTACK(&x_emlrtRSI);
    EMLRTPOPRTSTACK(&w_emlrtRSI);
    EMLRTPOPRTSTACK(&f_emlrtRSI);
    if (tmp1 < ndbl) {
        /* 'epu_align_to_event:33' currentArray = [nan(1,min(inputTimeFrame)-min(absTimeFrame)),currentArray]; */
        EMLRTPUSHRTSTACK(&g_emlrtRSI);
        EMLRTPUSHRTSTACK(&w_emlrtRSI);
        EMLRTPUSHRTSTACK(&x_emlrtRSI);
        EMLRTPUSHRTSTACK(&y_emlrtRSI);
        ixstart = 1;
        tmp1 = inputTimeFrame[0];
        if (muDoubleScalarIsNaN(inputTimeFrame[0])) {
            nm1 = 2;
            exitg6 = 0U;
            while ((exitg6 == 0U) && (nm1 < 3)) {
                ixstart = 2;
                if (!muDoubleScalarIsNaN(inputTimeFrame[1])) {
                    tmp1 = inputTimeFrame[1];
                    exitg6 = 1U;
                } else {
                    nm1 = 3;
                }
            }
        }
        if ((ixstart < 2) && (inputTimeFrame[1] < tmp1)) {
            tmp1 = inputTimeFrame[1];
        }
        EMLRTPOPRTSTACK(&y_emlrtRSI);
        EMLRTPOPRTSTACK(&x_emlrtRSI);
        EMLRTPOPRTSTACK(&w_emlrtRSI);
        EMLRTPUSHRTSTACK(&w_emlrtRSI);
        EMLRTPUSHRTSTACK(&x_emlrtRSI);
        EMLRTPUSHRTSTACK(&y_emlrtRSI);
        ixstart = 1;
        ndbl = timeFrameInterest[0];
        if (muDoubleScalarIsNaN(timeFrameInterest[0])) {
            nm1 = 2;
            exitg5 = 0U;
            while ((exitg5 == 0U) && (nm1 < 3)) {
                ixstart = 2;
                if (!muDoubleScalarIsNaN(timeFrameInterest[1])) {
                    ndbl = timeFrameInterest[1];
                    exitg5 = 1U;
                } else {
                    nm1 = 3;
                }
            }
        }
        if ((ixstart < 2) && (timeFrameInterest[1] < ndbl)) {
            ndbl = timeFrameInterest[1];
        }
        EMLRTPOPRTSTACK(&y_emlrtRSI);
        EMLRTPOPRTSTACK(&x_emlrtRSI);
        EMLRTPOPRTSTACK(&w_emlrtRSI);
        ixstart = (int32_T)emlrtIntegerCheckR2009b(emlrtNonNegativeCheckR2009b(tmp1 - ndbl, &d_emlrtDCI), &c_emlrtDCI);
        i0 = currentArray->size[0] * currentArray->size[1];
        currentArray->size[0] = 1;
        currentArray->size[1] = ixstart + trajectories->size[1];
        emxEnsureCapacity((emxArray__common *)currentArray, i0, (int32_T)sizeof(real_T), &b_emlrtRTEI);
        nm1 = ixstart - 1;
        for (i0 = 0; i0 <= nm1; i0++) {
            currentArray->data[currentArray->size[0] * i0] = rtNaN;
        }
        nm1 = trajectories->size[1] - 1;
        for (i0 = 0; i0 <= nm1; i0++) {
            currentArray->data[currentArray->size[0] * (i0 + ixstart)] = trajectories->data[trajectories->size[0] * i0];
        }
        EMLRTPOPRTSTACK(&g_emlrtRSI);
    }
    /* 'epu_align_to_event:36' if max(absTimeFrame) > max(inputTimeFrame) */
    EMLRTPUSHRTSTACK(&h_emlrtRSI);
    EMLRTPUSHRTSTACK(&ab_emlrtRSI);
    EMLRTPUSHRTSTACK(&bb_emlrtRSI);
    EMLRTPUSHRTSTACK(&cb_emlrtRSI);
    ixstart = 1;
    tmp1 = timeFrameInterest[0];
    if (muDoubleScalarIsNaN(timeFrameInterest[0])) {
        nm1 = 2;
        exitg4 = 0U;
        while ((exitg4 == 0U) && (nm1 < 3)) {
            ixstart = 2;
            if (!muDoubleScalarIsNaN(timeFrameInterest[1])) {
                tmp1 = timeFrameInterest[1];
                exitg4 = 1U;
            } else {
                nm1 = 3;
            }
        }
    }
    if ((ixstart < 2) && (timeFrameInterest[1] > tmp1)) {
        tmp1 = timeFrameInterest[1];
    }
    EMLRTPOPRTSTACK(&cb_emlrtRSI);
    EMLRTPOPRTSTACK(&bb_emlrtRSI);
    EMLRTPOPRTSTACK(&ab_emlrtRSI);
    EMLRTPUSHRTSTACK(&ab_emlrtRSI);
    EMLRTPUSHRTSTACK(&bb_emlrtRSI);
    EMLRTPUSHRTSTACK(&cb_emlrtRSI);
    ixstart = 1;
    ndbl = inputTimeFrame[0];
    if (muDoubleScalarIsNaN(inputTimeFrame[0])) {
        nm1 = 2;
        exitg3 = 0U;
        while ((exitg3 == 0U) && (nm1 < 3)) {
            ixstart = 2;
            if (!muDoubleScalarIsNaN(inputTimeFrame[1])) {
                ndbl = inputTimeFrame[1];
                exitg3 = 1U;
            } else {
                nm1 = 3;
            }
        }
    }
    if ((ixstart < 2) && (inputTimeFrame[1] > ndbl)) {
        ndbl = inputTimeFrame[1];
    }
    EMLRTPOPRTSTACK(&cb_emlrtRSI);
    EMLRTPOPRTSTACK(&bb_emlrtRSI);
    EMLRTPOPRTSTACK(&ab_emlrtRSI);
    EMLRTPOPRTSTACK(&h_emlrtRSI);
    if (tmp1 > ndbl) {
        /* 'epu_align_to_event:37' currentArray = [currentArray,nan(1,max(absTimeFrame)-max(inputTimeFrame))]; */
        EMLRTPUSHRTSTACK(&i_emlrtRSI);
        EMLRTPUSHRTSTACK(&ab_emlrtRSI);
        EMLRTPUSHRTSTACK(&bb_emlrtRSI);
        EMLRTPUSHRTSTACK(&cb_emlrtRSI);
        ixstart = 1;
        tmp1 = timeFrameInterest[0];
        if (muDoubleScalarIsNaN(timeFrameInterest[0])) {
            nm1 = 2;
            exitg2 = 0U;
            while ((exitg2 == 0U) && (nm1 < 3)) {
                ixstart = 2;
                if (!muDoubleScalarIsNaN(timeFrameInterest[1])) {
                    tmp1 = timeFrameInterest[1];
                    exitg2 = 1U;
                } else {
                    nm1 = 3;
                }
            }
        }
        if ((ixstart < 2) && (timeFrameInterest[1] > tmp1)) {
            tmp1 = timeFrameInterest[1];
        }
        EMLRTPOPRTSTACK(&cb_emlrtRSI);
        EMLRTPOPRTSTACK(&bb_emlrtRSI);
        EMLRTPOPRTSTACK(&ab_emlrtRSI);
        EMLRTPUSHRTSTACK(&ab_emlrtRSI);
        EMLRTPUSHRTSTACK(&bb_emlrtRSI);
        EMLRTPUSHRTSTACK(&cb_emlrtRSI);
        ixstart = 1;
        ndbl = inputTimeFrame[0];
        if (muDoubleScalarIsNaN(inputTimeFrame[0])) {
            nm1 = 2;
            exitg1 = 0U;
            while ((exitg1 == 0U) && (nm1 < 3)) {
                ixstart = 2;
                if (!muDoubleScalarIsNaN(inputTimeFrame[1])) {
                    ndbl = inputTimeFrame[1];
                    exitg1 = 1U;
                } else {
                    nm1 = 3;
                }
            }
        }
        if ((ixstart < 2) && (inputTimeFrame[1] > ndbl)) {
            ndbl = inputTimeFrame[1];
        }
        emxInit_real_T(&b_currentArray, 2, &b_emlrtRTEI, TRUE);
        EMLRTPOPRTSTACK(&cb_emlrtRSI);
        EMLRTPOPRTSTACK(&bb_emlrtRSI);
        EMLRTPOPRTSTACK(&ab_emlrtRSI);
        ixstart = (int32_T)emlrtIntegerCheckR2009b(emlrtNonNegativeCheckR2009b(tmp1 - ndbl, &f_emlrtDCI), &e_emlrtDCI);
        i0 = b_currentArray->size[0] * b_currentArray->size[1];
        b_currentArray->size[0] = 1;
        b_currentArray->size[1] = currentArray->size[1] + ixstart;
        emxEnsureCapacity((emxArray__common *)b_currentArray, i0, (int32_T)sizeof(real_T), &b_emlrtRTEI);
        nm1 = currentArray->size[1] - 1;
        for (i0 = 0; i0 <= nm1; i0++) {
            b_currentArray->data[b_currentArray->size[0] * i0] = currentArray->data[currentArray->size[0] * i0];
        }
        nm1 = ixstart - 1;
        for (i0 = 0; i0 <= nm1; i0++) {
            b_currentArray->data[b_currentArray->size[0] * (i0 + currentArray->size[1])] = rtNaN;
        }
        i0 = currentArray->size[0] * currentArray->size[1];
        currentArray->size[0] = 1;
        currentArray->size[1] = b_currentArray->size[1];
        emxEnsureCapacity((emxArray__common *)currentArray, i0, (int32_T)sizeof(real_T), &b_emlrtRTEI);
        nm1 = b_currentArray->size[1] - 1;
        for (i0 = 0; i0 <= nm1; i0++) {
            currentArray->data[currentArray->size[0] * i0] = b_currentArray->data[b_currentArray->size[0] * i0];
        }
        emxFree_real_T(&b_currentArray);
        EMLRTPOPRTSTACK(&i_emlrtRSI);
    }
    b_emxInit_real_T(&c_currentArray, 1, &e_emlrtRTEI, TRUE);
    /* 'epu_align_to_event:40' currentArray = currentArray'; */
    i0 = c_currentArray->size[0];
    c_currentArray->size[0] = currentArray->size[1];
    emxEnsureCapacity((emxArray__common *)c_currentArray, i0, (int32_T)sizeof(real_T), &b_emlrtRTEI);
    nm1 = currentArray->size[1] - 1;
    for (i0 = 0; i0 <= nm1; i0++) {
        c_currentArray->data[i0] = currentArray->data[i0];
    }
    emxFree_real_T(&currentArray);
    b_emxInit_real_T(&t, 1, &f_emlrtRTEI, TRUE);
    /* 'epu_align_to_event:41' t = t'; */
    i0 = t->size[0];
    t->size[0] = b_y->size[1];
    emxEnsureCapacity((emxArray__common *)t, i0, (int32_T)sizeof(real_T), &b_emlrtRTEI);
    nm1 = b_y->size[1] - 1;
    for (i0 = 0; i0 <= nm1; i0++) {
        t->data[i0] = b_y->data[i0] - r0->data[i0];
    }
    emxFree_real_T(&b_y);
    emxFree_real_T(&r0);
    emxInit_boolean_T(&x, 1, &b_emlrtRTEI, TRUE);
    /* 'epu_align_to_event:43' alignedArray = reshape(currentArray( t>=outputTimeFrame(1) & t<=outputTimeFrame(2) ),diff(outputTimeFrame)+1,1)'; */
    i0 = x->size[0];
    x->size[0] = t->size[0];
    emxEnsureCapacity((emxArray__common *)x, i0, (int32_T)sizeof(boolean_T), &b_emlrtRTEI);
    nm1 = t->size[0] - 1;
    for (i0 = 0; i0 <= nm1; i0++) {
        x->data[i0] = (t->data[i0] >= outputTimeFrame[0]);
    }
    emxInit_boolean_T(&r1, 1, &b_emlrtRTEI, TRUE);
    i0 = r1->size[0];
    r1->size[0] = t->size[0];
    emxEnsureCapacity((emxArray__common *)r1, i0, (int32_T)sizeof(boolean_T), &b_emlrtRTEI);
    nm1 = t->size[0] - 1;
    for (i0 = 0; i0 <= nm1; i0++) {
        r1->data[i0] = (t->data[i0] <= outputTimeFrame[1]);
    }
    b_x[0] = x->size[0];
    iv2[0] = r1->size[0];
    emlrtSizeEqCheckND(b_x, iv2, &b_emlrtECI);
    EMLRTPUSHRTSTACK(&j_emlrtRSI);
    i0 = x->size[0];
    emxEnsureCapacity((emxArray__common *)x, i0, (int32_T)sizeof(boolean_T), &b_emlrtRTEI);
    nm1 = x->size[0] - 1;
    for (i0 = 0; i0 <= nm1; i0++) {
        x->data[i0] = (x->data[i0] && r1->data[i0]);
    }
    emxFree_boolean_T(&r1);
    nx = x->size[0];
    EMLRTPUSHRTSTACK(&db_emlrtRSI);
    k = 0;
    for (nm1 = 1; nm1 <= nx; nm1++) {
        if (x->data[emlrtDynamicBoundsCheck(nm1, 1, x->size[0], &k_emlrtBCI) - 1]) {
            k++;
        }
    }
    EMLRTPOPRTSTACK(&db_emlrtRSI);
    if (k <= nx) {
    } else {
        EMLRTPUSHRTSTACK(&eb_emlrtRSI);
        d_y = NULL;
        m0 = mxCreateString("Assertion failed.");
        emlrtAssign(&d_y, m0);
        error(d_y, &g_emlrtMCI);
        EMLRTPOPRTSTACK(&eb_emlrtRSI);
    }
    emxInit_int32_T(&e_y, 1, &b_emlrtRTEI, TRUE);
    emlrtNonNegativeCheckR2009b((real_T)k, &b_emlrtDCI);
    i0 = e_y->size[0];
    e_y->size[0] = k;
    emxEnsureCapacity((emxArray__common *)e_y, i0, (int32_T)sizeof(int32_T), &c_emlrtRTEI);
    ixstart = 1;
    for (nm1 = 1; nm1 <= nx; nm1++) {
        if (x->data[emlrtDynamicBoundsCheck(nm1, 1, x->size[0], &i_emlrtBCI) - 1]) {
            e_y->data[emlrtDynamicBoundsCheck(ixstart, 1, e_y->size[0], &j_emlrtBCI) - 1] = nm1;
            ixstart++;
        }
    }
    emxFree_boolean_T(&x);
    tmp1 = outputTimeFrame[1] - outputTimeFrame[0];
    nm1 = e_y->size[0] - 1;
    for (i0 = 0; i0 <= nm1; i0++) {
        emlrtDynamicBoundsCheck(e_y->data[i0], 1, c_currentArray->size[0], &g_emlrtBCI);
    }
    b_emxInit_real_T(&d_currentArray, 1, &b_emlrtRTEI, TRUE);
    i0 = d_currentArray->size[0];
    d_currentArray->size[0] = e_y->size[0];
    emxEnsureCapacity((emxArray__common *)d_currentArray, i0, (int32_T)sizeof(real_T), &b_emlrtRTEI);
    nm1 = e_y->size[0] - 1;
    for (i0 = 0; i0 <= nm1; i0++) {
        d_currentArray->data[i0] = c_currentArray->data[e_y->data[i0] - 1];
    }
    nx = d_currentArray->size[0];
    emxFree_real_T(&d_currentArray);
    for (i0 = 0; i0 < 2; i0++) {
        sz[i0] = 0;
    }
    b_emxInit_real_T(&e_currentArray, 1, &b_emlrtRTEI, TRUE);
    EMLRTPUSHRTSTACK(&gb_emlrtRSI);
    eml_assert_valid_size_arg(tmp1 + 1.0);
    EMLRTPOPRTSTACK(&gb_emlrtRSI);
    tmp1++;
    tmp1 = tmp1 < 0.0 ? muDoubleScalarCeil(tmp1 - 0.5) : muDoubleScalarFloor(tmp1 + 0.5);
    if (tmp1 < 2.147483648E+9) {
        if (tmp1 >= -2.147483648E+9) {
            i0 = (int32_T)tmp1;
        } else {
            i0 = MIN_int32_T;
        }
    } else if (tmp1 >= 2.147483648E+9) {
        i0 = MAX_int32_T;
    } else {
        i0 = 0;
    }
    sz[0] = i0;
    sz[1] = 1;
    EMLRTPUSHRTSTACK(&hb_emlrtRSI);
    EMLRTPOPRTSTACK(&hb_emlrtRSI);
    EMLRTPUSHRTSTACK(&ib_emlrtRSI);
    i0 = e_currentArray->size[0];
    e_currentArray->size[0] = e_y->size[0];
    emxEnsureCapacity((emxArray__common *)e_currentArray, i0, (int32_T)sizeof(real_T), &b_emlrtRTEI);
    nm1 = e_y->size[0] - 1;
    for (i0 = 0; i0 <= nm1; i0++) {
        e_currentArray->data[i0] = c_currentArray->data[e_y->data[i0] - 1];
    }
    timeFrameInterest[0] = (real_T)e_currentArray->size[0];
    timeFrameInterest[1] = 1.0;
    EMLRTPUSHRTSTACK(&ab_emlrtRSI);
    EMLRTPUSHRTSTACK(&bb_emlrtRSI);
    EMLRTPUSHRTSTACK(&cb_emlrtRSI);
    ixstart = (int32_T)timeFrameInterest[0];
    emxFree_real_T(&e_currentArray);
    if (1.0 > timeFrameInterest[0]) {
        ixstart = 1;
    }
    EMLRTPOPRTSTACK(&cb_emlrtRSI);
    EMLRTPOPRTSTACK(&bb_emlrtRSI);
    EMLRTPOPRTSTACK(&ab_emlrtRSI);
    if (nx < ixstart) {
    } else {
        ixstart = nx;
    }
    EMLRTPOPRTSTACK(&ib_emlrtRSI);
    if (sz[0] > ixstart) {
        EMLRTPUSHRTSTACK(&jb_emlrtRSI);
        eml_error();
        EMLRTPOPRTSTACK(&jb_emlrtRSI);
    }
    if (1 > ixstart) {
        EMLRTPUSHRTSTACK(&kb_emlrtRSI);
        eml_error();
        EMLRTPOPRTSTACK(&kb_emlrtRSI);
    }
    for (i0 = 0; i0 < 2; i0++) {
        emlrtNonNegativeCheckR2009b((real_T)sz[i0], &g_emlrtDCI);
    }
    i0 = t->size[0];
    t->size[0] = sz[0];
    emxEnsureCapacity((emxArray__common *)t, i0, (int32_T)sizeof(real_T), &d_emlrtRTEI);
    if (t->size[0] == nx) {
    } else {
        EMLRTPUSHRTSTACK(&lb_emlrtRSI);
        f_y = NULL;
        m0 = mxCreateCharArray(2, iv3);
        emlrtInitCharArray(40, m0, cv1);
        emlrtAssign(&f_y, m0);
        error(message(f_y, &j_emlrtMCI), &k_emlrtMCI);
        EMLRTPOPRTSTACK(&lb_emlrtRSI);
    }
    k = 1;
    b_emxInit_real_T(&f_currentArray, 1, &b_emlrtRTEI, TRUE);
    while (k <= nx) {
        i0 = f_currentArray->size[0];
        f_currentArray->size[0] = e_y->size[0];
        emxEnsureCapacity((emxArray__common *)f_currentArray, i0, (int32_T)sizeof(real_T), &b_emlrtRTEI);
        nm1 = e_y->size[0] - 1;
        for (i0 = 0; i0 <= nm1; i0++) {
            f_currentArray->data[i0] = c_currentArray->data[e_y->data[i0] - 1];
        }
        ixstart = emlrtDynamicBoundsCheck(k, 1, f_currentArray->size[0], &b_emlrtBCI);
        t->data[emlrtDynamicBoundsCheck(k, 1, t->size[0], &h_emlrtBCI) - 1] = c_currentArray->data[e_y->data[ixstart - 1] - 1];
        k++;
    }
    emxFree_real_T(&f_currentArray);
    emxFree_int32_T(&e_y);
    emxFree_real_T(&c_currentArray);
    i0 = alignedArray->size[0] * alignedArray->size[1];
    alignedArray->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)alignedArray, i0, (int32_T)sizeof(real_T), &b_emlrtRTEI);
    ixstart = t->size[0];
    i0 = alignedArray->size[0] * alignedArray->size[1];
    alignedArray->size[1] = ixstart;
    emxEnsureCapacity((emxArray__common *)alignedArray, i0, (int32_T)sizeof(real_T), &b_emlrtRTEI);
    nm1 = t->size[0] - 1;
    for (i0 = 0; i0 <= nm1; i0++) {
        alignedArray->data[i0] = t->data[i0];
    }
    emxFree_real_T(&t);
    EMLRTPOPRTSTACK(&j_emlrtRSI);
    emlrtHeapReferenceStackLeaveFcn();
}
/* End of code generation (epu_align_to_event.c) */
