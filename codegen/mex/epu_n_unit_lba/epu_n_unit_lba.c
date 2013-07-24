/*
 * epu_n_unit_lba.c
 *
 * Code generation for function 'epu_n_unit_lba'
 *
 * C source code generated on: Fri Aug 31 09:31:05 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_lba.h"
#include "epu_n_unit_lba_emxutil.h"
#include "all.h"
#include "mean.h"
#include "epu_n_unit_lba_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 55, "epu_n_unit_lba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_lba.m" };
static emlrtRSInfo b_emlrtRSI = { 59, "epu_n_unit_lba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_lba.m" };
static emlrtRSInfo c_emlrtRSI = { 62, "epu_n_unit_lba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_lba.m" };
static emlrtRSInfo d_emlrtRSI = { 68, "epu_n_unit_lba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_lba.m" };
static emlrtRSInfo e_emlrtRSI = { 74, "epu_n_unit_lba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_lba.m" };
static emlrtRSInfo f_emlrtRSI = { 81, "epu_n_unit_lba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_lba.m" };
static emlrtRSInfo g_emlrtRSI = { 81, "epu_n_unit_lba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_lba.m" };
static emlrtRSInfo h_emlrtRSI = { 13, "rdivide", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/rdivide.m" };
static emlrtRSInfo j_emlrtRSI = { 25, "sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/sort.m" };
static emlrtRSInfo k_emlrtRSI = { 49, "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };
static emlrtRSInfo l_emlrtRSI = { 61, "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };
static emlrtRSInfo m_emlrtRSI = { 63, "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };
static emlrtRSInfo n_emlrtRSI = { 77, "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };
static emlrtRSInfo o_emlrtRSI = { 18, "eml_assert_valid_dim", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m" };
static emlrtRSInfo p_emlrtRSI = { 21, "eml_assert_valid_dim", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m" };
static emlrtRSInfo q_emlrtRSI = { 91, "eml_matrix_vstride", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m" };
static emlrtRSInfo r_emlrtRSI = { 16, "eml_matrix_npages", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m" };
static emlrtRSInfo s_emlrtRSI = { 139, "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };
static emlrtRSInfo t_emlrtRSI = { 161, "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };
static emlrtRSInfo kb_emlrtRSI = { 21, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRSInfo lb_emlrtRSI = { 79, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRSInfo mb_emlrtRSI = { 117, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRSInfo nb_emlrtRSI = { 233, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRSInfo ob_emlrtRSI = { 19, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };
static emlrtRSInfo pb_emlrtRSI = { 48, "eml_assert_valid_size_arg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m" };
static emlrtRSInfo qb_emlrtRSI = { 52, "eml_assert_valid_size_arg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m" };
static emlrtRSInfo rb_emlrtRSI = { 10, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };
static emlrtMCInfo emlrtMCI = { 20, 5, "eml_assert_valid_dim", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m" };
static emlrtMCInfo b_emlrtMCI = { 18, 15, "eml_assert_valid_dim", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m" };
static emlrtMCInfo c_emlrtMCI = { 22, 66, "eml_assert_valid_dim", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m" };
static emlrtMCInfo d_emlrtMCI = { 21, 15, "eml_assert_valid_dim", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m" };
static emlrtMCInfo m_emlrtMCI = { 234, 5, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtMCInfo n_emlrtMCI = { 233, 15, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtMCInfo o_emlrtMCI = { 49, 13, "eml_assert_valid_size_arg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m" };
static emlrtMCInfo p_emlrtMCI = { 48, 23, "eml_assert_valid_size_arg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m" };
static emlrtMCInfo q_emlrtMCI = { 53, 5, "eml_assert_valid_size_arg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m" };
static emlrtMCInfo r_emlrtMCI = { 52, 15, "eml_assert_valid_size_arg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m" };
static emlrtRTEInfo emlrtRTEI = { 1, 28, "epu_n_unit_lba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_lba.m" };
static emlrtRTEInfo b_emlrtRTEI = { 118, 1, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRTEInfo c_emlrtRTEI = { 45, 1, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };
static emlrtRTEInfo d_emlrtRTEI = { 45, 1, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };
static emlrtRTEInfo e_emlrtRTEI = { 55, 4, "epu_n_unit_lba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_lba.m" };
static emlrtRTEInfo f_emlrtRTEI = { 51, 1, "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };
static emlrtRTEInfo g_emlrtRTEI = { 52, 1, "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };
static emlrtRTEInfo h_emlrtRTEI = { 60, 5, "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };
static emlrtRTEInfo i_emlrtRTEI = { 27, 5, "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };
static emlrtRTEInfo j_emlrtRTEI = { 1, 20, "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };
static emlrtRTEInfo k_emlrtRTEI = { 51, 1, "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };
static emlrtRTEInfo l_emlrtRTEI = { 77, 13, "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };
static emlrtRTEInfo m_emlrtRTEI = { 1, 13, "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };
static emlrtRTEInfo n_emlrtRTEI = { 145, 5, "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };
static emlrtBCInfo emlrtBCI = { -1, -1, 69, 23, "accumulationTime", "epu_n_unit_lba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_lba.m", 0 };
static emlrtDCInfo emlrtDCI = { 81, 21, "epu_n_unit_lba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_lba.m", 4 };
static emlrtECInfo emlrtECI = { 2, 81, 41, "epu_n_unit_lba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_lba.m" };
static emlrtECInfo b_emlrtECI = { 2, 81, 14, "epu_n_unit_lba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_lba.m" };
static emlrtECInfo c_emlrtECI = { 2, 16, 9, "eml_div", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_div.m" };
static emlrtBCInfo b_emlrtBCI = { -1, -1, 12, 28, "", "ceil", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elfun/ceil.m", 0 };
static emlrtDCInfo b_emlrtDCI = { 118, 28, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 4 };
static emlrtBCInfo c_emlrtBCI = { -1, -1, 120, 5, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo d_emlrtBCI = { -1, -1, 64, 29, "", "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m", 0 };
static emlrtBCInfo e_emlrtBCI = { -1, -1, 68, 40, "dtAccumulation", "epu_n_unit_lba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_lba.m", 0 };
static emlrtDCInfo c_emlrtDCI = { 68, 40, "epu_n_unit_lba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_lba.m", 1 };
static emlrtBCInfo f_emlrtBCI = { -1, -1, 122, 9, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo g_emlrtBCI = { -1, -1, 134, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo h_emlrtBCI = { -1, -1, 135, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo i_emlrtBCI = { -1, -1, 131, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo j_emlrtBCI = { -1, -1, 64, 21, "", "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m", 0 };
static emlrtBCInfo k_emlrtBCI = { -1, -1, 64, 29, "", "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m", 0 };
static emlrtBCInfo l_emlrtBCI = { -1, -1, 81, 106, "v", "epu_n_unit_lba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_lba.m", 0 };
static emlrtDCInfo d_emlrtDCI = { 81, 106, "epu_n_unit_lba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_lba.m", 1 };
static emlrtDCInfo e_emlrtDCI = { 45, 48, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m", 4 };
static emlrtBCInfo m_emlrtBCI = { -1, -1, 64, 21, "", "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m", 0 };
static emlrtBCInfo n_emlrtBCI = { -1, -1, 127, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo o_emlrtBCI = { -1, -1, 128, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo p_emlrtBCI = { -1, -1, 12, 5, "", "ceil", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elfun/ceil.m", 0 };
static emlrtBCInfo q_emlrtBCI = { -1, -1, 20, 44, "", "eml_sort_le", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_le.m", 0 };
static emlrtBCInfo r_emlrtBCI = { -1, -1, 20, 35, "", "eml_sort_le", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_le.m", 0 };
static emlrtBCInfo s_emlrtBCI = { -1, -1, 20, 44, "", "eml_sort_le", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_le.m", 0 };
static emlrtBCInfo t_emlrtBCI = { -1, -1, 20, 35, "", "eml_sort_le", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_le.m", 0 };
static emlrtBCInfo u_emlrtBCI = { -1, -1, 161, 45, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo v_emlrtBCI = { -1, -1, 161, 38, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo w_emlrtBCI = { -1, -1, 186, 17, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo x_emlrtBCI = { -1, -1, 186, 44, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo y_emlrtBCI = { -1, -1, 172, 21, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo ab_emlrtBCI = { -1, -1, 172, 31, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo bb_emlrtBCI = { -1, -1, 177, 29, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo cb_emlrtBCI = { -1, -1, 177, 39, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo db_emlrtBCI = { -1, -1, 162, 21, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo eb_emlrtBCI = { -1, -1, 162, 31, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo fb_emlrtBCI = { -1, -1, 167, 29, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo gb_emlrtBCI = { -1, -1, 167, 39, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo hb_emlrtBCI = { -1, -1, 141, 13, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo ib_emlrtBCI = { -1, -1, 142, 13, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo jb_emlrtBCI = { -1, -1, 135, 9, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo kb_emlrtBCI = { -1, -1, 81, 17, "", "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m", 0 };
static emlrtBCInfo lb_emlrtBCI = { -1, -1, 81, 25, "", "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m", 0 };
static emlrtBCInfo mb_emlrtBCI = { -1, -1, 81, 31, "", "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m", 0 };
static emlrtBCInfo nb_emlrtBCI = { -1, -1, 82, 17, "", "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m", 0 };
static emlrtBCInfo ob_emlrtBCI = { -1, -1, 82, 27, "", "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m", 0 };
static emlrtBCInfo pb_emlrtBCI = { -1, -1, 43, 9, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo qb_emlrtBCI = { -1, -1, 74, 17, "", "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m", 0 };
static emlrtBCInfo rb_emlrtBCI = { -1, -1, 74, 28, "", "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m", 0 };

/* Function Declarations */
static const mxArray *b_message(const mxArray *b, const mxArray *c, emlrtMCInfo *location);
static void eml_assert_valid_size_arg(real_T varargin_1);
static void eml_sort(const emxArray_real_T *x, emxArray_real_T *y);

/* Function Definitions */

static const mxArray *b_message(const mxArray *b, const mxArray *c, emlrtMCInfo *location)
{
    const mxArray *pArrays[2];
    const mxArray *m8;
    pArrays[0] = b;
    pArrays[1] = c;
    return emlrtCallMATLAB(1, &m8, 2, pArrays, "message", TRUE, location);
}

/*
 * 
 */
static void eml_assert_valid_size_arg(real_T varargin_1)
{
    boolean_T p;
    const mxArray *y;
    static const int32_T iv8[2] = { 1, 28 };
    const mxArray *m4;
    static const char_T cv8[28] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'N', 'o', 'n', 'I', 'n', 't', 'e', 'g', 'e', 'r', 'I', 'n', 'p', 'u', 't' };
    real_T n;
    const mxArray *b_y;
    static const int32_T iv9[2] = { 1, 21 };
    static const char_T cv9[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };
    if ((varargin_1 != muDoubleScalarFloor(varargin_1)) || muDoubleScalarIsInf(varargin_1)) {
        p = FALSE;
    } else {
        p = TRUE;
    }
    if (p) {
    } else {
        EMLRTPUSHRTSTACK(&pb_emlrtRSI);
        y = NULL;
        m4 = mxCreateCharArray(2, iv8);
        emlrtInitCharArray(28, m4, cv8);
        emlrtAssign(&y, m4);
        error(message(y, &o_emlrtMCI), &p_emlrtMCI);
        EMLRTPOPRTSTACK(&pb_emlrtRSI);
    }
    if (varargin_1 <= 0.0) {
        n = 0.0;
    } else {
        n = varargin_1;
    }
    if (n <= 2.147483647E+9) {
    } else {
        EMLRTPUSHRTSTACK(&qb_emlrtRSI);
        b_y = NULL;
        m4 = mxCreateCharArray(2, iv9);
        emlrtInitCharArray(21, m4, cv9);
        emlrtAssign(&b_y, m4);
        error(message(b_y, &q_emlrtMCI), &r_emlrtMCI);
        EMLRTPOPRTSTACK(&qb_emlrtRSI);
    }
}

/*
 * 
 */
static void eml_sort(const emxArray_real_T *x, emxArray_real_T *y)
{
    int32_T dim;
    int32_T a;
    emxArray_real_T *vwork;
    emxArray_int32_T *idx;
    int32_T ix;
    uint32_T unnamed_idx_0;
    int32_T vstride;
    int32_T k;
    emxArray_int32_T *iidx;
    emxArray_int32_T *idx0;
    int32_T i1;
    int32_T j;
    int32_T n;
    int32_T np1;
    boolean_T b0;
    int32_T b_j;
    int32_T pEnd;
    int32_T p;
    int32_T q;
    int32_T qEnd;
    int32_T kEnd;
    emlrtHeapReferenceStackEnterFcn();
    dim = 2;
    if (x->size[0] != 1) {
        dim = 1;
    }
    EMLRTPUSHRTSTACK(&k_emlrtRSI);
    eml_assert_valid_dim((real_T)dim);
    EMLRTPOPRTSTACK(&k_emlrtRSI);
    if (dim <= 1) {
        a = x->size[0] - 1;
    } else {
        a = 0;
    }
    b_emxInit_real_T(&vwork, 1, &k_emlrtRTEI, TRUE);
    emxInit_int32_T(&idx, 1, &m_emlrtRTEI, TRUE);
    ix = vwork->size[0];
    vwork->size[0] = (int32_T)(uint32_T)(a + 1);
    emxEnsureCapacity((emxArray__common *)vwork, ix, (int32_T)sizeof(real_T), &f_emlrtRTEI);
    ix = y->size[0];
    y->size[0] = x->size[0];
    emxEnsureCapacity((emxArray__common *)y, ix, (int32_T)sizeof(real_T), &g_emlrtRTEI);
    unnamed_idx_0 = (uint32_T)x->size[0];
    ix = idx->size[0];
    idx->size[0] = (int32_T)unnamed_idx_0;
    emxEnsureCapacity((emxArray__common *)idx, ix, (int32_T)sizeof(int32_T), &h_emlrtRTEI);
    EMLRTPUSHRTSTACK(&l_emlrtRSI);
    EMLRTPUSHRTSTACK(&q_emlrtRSI);
    vstride = 1;
    k = 1;
    while (k <= dim - 1) {
        ix = x->size[0];
        vstride *= ix;
        k = 2;
    }
    EMLRTPOPRTSTACK(&q_emlrtRSI);
    EMLRTPOPRTSTACK(&l_emlrtRSI);
    EMLRTPUSHRTSTACK(&m_emlrtRSI);
    EMLRTPUSHRTSTACK(&r_emlrtRSI);
    EMLRTPOPRTSTACK(&r_emlrtRSI);
    EMLRTPOPRTSTACK(&m_emlrtRSI);
    emxInit_int32_T(&iidx, 1, &l_emlrtRTEI, TRUE);
    emxInit_int32_T(&idx0, 1, &n_emlrtRTEI, TRUE);
    i1 = 0;
    for (j = 1; j <= vstride; j++) {
        i1++;
        ix = i1;
        for (k = 0; k <= a; k++) {
            vwork->data[emlrtDynamicBoundsCheck(k + 1, 1, vwork->size[0], &qb_emlrtBCI) - 1] = x->data[emlrtDynamicBoundsCheck(ix, 1, x->size[0], &rb_emlrtBCI) - 1];
            ix += vstride;
        }
        EMLRTPUSHRTSTACK(&n_emlrtRSI);
        n = vwork->size[0];
        unnamed_idx_0 = (uint32_T)vwork->size[0];
        ix = iidx->size[0];
        iidx->size[0] = (int32_T)unnamed_idx_0;
        emxEnsureCapacity((emxArray__common *)iidx, ix, (int32_T)sizeof(int32_T), &i_emlrtRTEI);
        np1 = n + 1;
        if (vwork->size[0] == 0) {
            for (k = 1; k <= n; k++) {
                iidx->data[emlrtDynamicBoundsCheck(k, 1, iidx->size[0], &pb_emlrtBCI) - 1] = k;
            }
        } else {
            for (k = 1; k <= n; k++) {
                iidx->data[emlrtDynamicBoundsCheck(k, 1, iidx->size[0], &jb_emlrtBCI) - 1] = k;
            }
            for (k = 1; k <= n - 1; k += 2) {
                EMLRTPUSHRTSTACK(&s_emlrtRSI);
                emlrtDynamicBoundsCheck(k, 1, vwork->size[0], &r_emlrtBCI);
                emlrtDynamicBoundsCheck(k + 1, 1, vwork->size[0], &q_emlrtBCI);
                if ((vwork->data[k - 1] <= vwork->data[k]) || muDoubleScalarIsNaN(vwork->data[k])) {
                    b0 = TRUE;
                } else {
                    b0 = FALSE;
                }
                EMLRTPOPRTSTACK(&s_emlrtRSI);
                if (b0) {
                } else {
                    iidx->data[emlrtDynamicBoundsCheck(k, 1, iidx->size[0], &hb_emlrtBCI) - 1] = k + 1;
                    iidx->data[emlrtDynamicBoundsCheck(k + 1, 1, iidx->size[0], &ib_emlrtBCI) - 1] = k;
                }
            }
            ix = idx0->size[0];
            idx0->size[0] = n;
            emxEnsureCapacity((emxArray__common *)idx0, ix, (int32_T)sizeof(int32_T), &j_emlrtRTEI);
            dim = n - 1;
            for (ix = 0; ix <= dim; ix++) {
                idx0->data[ix] = 1;
            }
            dim = 2;
            while (dim < n) {
                ix = dim << 1;
                b_j = 1;
                for (pEnd = 1 + dim; pEnd < np1; pEnd = qEnd + dim) {
                    p = b_j;
                    q = pEnd;
                    qEnd = b_j + ix;
                    if (qEnd > np1) {
                        qEnd = np1;
                    }
                    k = 1;
                    kEnd = qEnd - b_j;
                    while (k <= kEnd) {
                        EMLRTPUSHRTSTACK(&t_emlrtRSI);
                        emlrtDynamicBoundsCheck(p, 1, iidx->size[0], &v_emlrtBCI);
                        emlrtDynamicBoundsCheck(q, 1, iidx->size[0], &u_emlrtBCI);
                        emlrtDynamicBoundsCheck(iidx->data[p - 1], 1, vwork->size[0], &t_emlrtBCI);
                        emlrtDynamicBoundsCheck(iidx->data[q - 1], 1, vwork->size[0], &s_emlrtBCI);
                        if ((vwork->data[iidx->data[p - 1] - 1] <= vwork->data[iidx->data[q - 1] - 1]) || muDoubleScalarIsNaN(vwork->data[iidx->data[q - 1] - 1])) {
                            b0 = TRUE;
                        } else {
                            b0 = FALSE;
                        }
                        EMLRTPOPRTSTACK(&t_emlrtRSI);
                        if (b0) {
                            idx0->data[emlrtDynamicBoundsCheck(k, 1, idx0->size[0], &db_emlrtBCI) - 1] = iidx->data[emlrtDynamicBoundsCheck(p, 1, iidx->size[0], &eb_emlrtBCI) - 1];
                            p++;
                            if (p == pEnd) {
                                while (q < qEnd) {
                                    k++;
                                    idx0->data[emlrtDynamicBoundsCheck(k, 1, idx0->size[0], &fb_emlrtBCI) - 1] = iidx->data[emlrtDynamicBoundsCheck(q, 1, iidx->size[0], &gb_emlrtBCI) - 1];
                                    q++;
                                }
                            }
                        } else {
                            idx0->data[emlrtDynamicBoundsCheck(k, 1, idx0->size[0], &y_emlrtBCI) - 1] = iidx->data[emlrtDynamicBoundsCheck(q, 1, iidx->size[0], &ab_emlrtBCI) - 1];
                            q++;
                            if (q == qEnd) {
                                while (p < pEnd) {
                                    k++;
                                    idx0->data[emlrtDynamicBoundsCheck(k, 1, idx0->size[0], &bb_emlrtBCI) - 1] = iidx->data[emlrtDynamicBoundsCheck(p, 1, iidx->size[0], &cb_emlrtBCI) - 1];
                                    p++;
                                }
                            }
                        }
                        k++;
                    }
                    for (k = 1; k <= kEnd; k++) {
                        iidx->data[emlrtDynamicBoundsCheck((b_j + k) - 1, 1, iidx->size[0], &w_emlrtBCI) - 1] = idx0->data[emlrtDynamicBoundsCheck(k, 1, idx0->size[0], &x_emlrtBCI) - 1];
                    }
                    b_j = qEnd;
                }
                dim = ix;
            }
        }
        EMLRTPOPRTSTACK(&n_emlrtRSI);
        ix = i1;
        for (k = 1; k - 1 <= a; k++) {
            y->data[emlrtDynamicBoundsCheck(ix, 1, y->size[0], &kb_emlrtBCI) - 1] = vwork->data[emlrtDynamicBoundsCheck(iidx->data[emlrtDynamicBoundsCheck(k, 1, iidx->size[0], &mb_emlrtBCI) - 1], 1, vwork->size[0], &lb_emlrtBCI) - 1];
            idx->data[emlrtDynamicBoundsCheck(ix, 1, idx->size[0], &nb_emlrtBCI) - 1] = iidx->data[emlrtDynamicBoundsCheck(k, 1, iidx->size[0], &ob_emlrtBCI) - 1];
            ix += vstride;
        }
    }
    emxFree_int32_T(&idx0);
    emxFree_int32_T(&idx);
    emxFree_int32_T(&iidx);
    emxFree_real_T(&vwork);
    emlrtHeapReferenceStackLeaveFcn();
}

/*
 * 
 */
void eml_assert_valid_dim(real_T dim)
{
    boolean_T b1;
    const mxArray *y;
    static const int32_T iv1[2] = { 1, 53 };
    const mxArray *m1;
    static const char_T cv1[53] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'g', 'e', 't', 'd', 'i', 'm', 'a', 'r', 'g', '_', 'd', 'i', 'm', 'e', 'n', 's', 'i', 'o', 'n', 'M', 'u', 's', 't', 'B', 'e', 'P', 'o', 's', 'i', 't', 'i', 'v', 'e', 'I', 'n', 't', 'e', 'g', 'e', 'r' };
    const mxArray *b_y;
    static const int32_T iv2[2] = { 1, 46 };
    static const char_T cv2[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 's', 's', 'e', 'r', 't', '_', 'v', 'a', 'l', 'i', 'd', '_', 'd', 'i', 'm', '_', 'd', 'i', 'm', 'T', 'o', 'o', 'L', 'a', 'r', 'g', 'e' };
    const mxArray *c_y;
    static const int32_T iv3[2] = { 1, 5 };
    static const char_T cv3[5] = { 'i', 'n', 't', '3', '2' };
    if ((dim >= 1.0) && (dim == muDoubleScalarFloor(dim))) {
        b1 = TRUE;
    } else {
        b1 = FALSE;
    }
    if (b1) {
    } else {
        EMLRTPUSHRTSTACK(&o_emlrtRSI);
        y = NULL;
        m1 = mxCreateCharArray(2, iv1);
        emlrtInitCharArray(53, m1, cv1);
        emlrtAssign(&y, m1);
        error(message(y, &emlrtMCI), &b_emlrtMCI);
        EMLRTPOPRTSTACK(&o_emlrtRSI);
    }
    if (dim <= 2.147483647E+9) {
    } else {
        EMLRTPUSHRTSTACK(&p_emlrtRSI);
        b_y = NULL;
        m1 = mxCreateCharArray(2, iv2);
        emlrtInitCharArray(46, m1, cv2);
        emlrtAssign(&b_y, m1);
        c_y = NULL;
        m1 = mxCreateCharArray(2, iv3);
        emlrtInitCharArray(5, m1, cv3);
        emlrtAssign(&c_y, m1);
        error(b_message(b_y, c_y, &c_emlrtMCI), &d_emlrtMCI);
        EMLRTPOPRTSTACK(&p_emlrtRSI);
    }
}

/*
 * function [rt,activation] = epu_n_unit_lba(v,theta,affTime,effTime,pN,dMeth,iAT)
 */
void epu_n_unit_lba(const emxArray_real_T *v, const emxArray_real_T *theta, real_T affTime, real_T effTime, emxArray_real_T *pN, real_T dMeth, const emxArray_real_T *iAT, real_T *rt, emxArray_real_T *activation)
{
    real_T accumulationTime;
    emxArray_real_T *y;
    emxArray_real_T *b_y;
    int32_T b_theta[2];
    int32_T i0;
    int32_T b_v[2];
    emxArray_real_T *dtAccumulation;
    int32_T loop_ub;
    emxArray_real_T *b_dtAccumulation;
    int32_T nm1d2;
    emxArray_boolean_T *b_pN;
    boolean_T n_too_large;
    emxArray_real_T *x;
    int32_T k;
    emxArray_int32_T *r0;
    int32_T b_x[1];
    emxArray_real_T c_x;
    real_T d_x;
    int32_T iacol;
    real_T anew;
    real_T apnd;
    real_T ndbl;
    real_T cdiff;
    const mxArray *c_y;
    static const int32_T iv0[2] = { 1, 21 };
    const mxArray *m0;
    static const char_T cv0[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };
    int32_T nm1;
    int32_T mv[2];
    emxArray_real_T *r1;
    int32_T ib;
    int32_T ia;
    emxArray_real_T *c_v;
    emxArray_real_T *r2;
    emxArray_real_T *d_v;
    emxArray_real_T *e_v;
    emxArray_real_T *f_v;
    int32_T exitg1;
    emlrtHeapReferenceStackEnterFcn();
    /*  */
    /*  INPUTS */
    /*  v             - vector with accumulation rates across accumulators */
    /*                  * units:          spikes s-1 ms-1 */
    /*                  * size & class:   1xnA double, where nA is number of */
    /*                                    accumulators */
    /*                  * support:        v ? ?: (0,+?) */
    /*  theta         - vector with thresholds across accumulators */
    /*                  * units:          spikes s-1 */
    /*                  * size & class:   1xnA double, where nA is number of */
    /*                                    accumulators */
    /*                  * support:        theta ? ?: (0,+?) */
    /*  affTime       - afferent (encoding) time */
    /*                  * units:          ms */
    /*                  * size & class:   1x1 double */
    /*                  * support:        affTime ? ?: [0,+?) */
    /*  effTime       - efferent (response execution) time */
    /*                  * units:          ms */
    /*                  * size & class:   1x1 double */
    /*                  * support:        effTime ? ?: [0,+?) */
    /*  pN            - proportion of accumulators necessary to produce an RT ('RT */
    /*                  rule'). */
    /*                  * units:          unitless */
    /*                  * size & class:   1x1 double */
    /*                  * support:        pN ? ?: [0,1], where 0 means that the very */
    /*                  first accumulator reaching threshold produces RT */
    /*  dMeth         - decision method, polling or pooling */
    /*                  * units:          unitless */
    /*                  * size & class:   1x1 double */
    /*                  * support:        * 1   polling */
    /*                                    * 2   pooling */
    /*  iAT           - accumulators indices for which to provide accumulation */
    /*                  trajectories */
    /*                  * units:          unitless */
    /*                  * size & class:   1xN double, where N is the number of indices */
    /*                  to get and N <= nA, where nA is number of accumulators */
    /*                  * support:        iAT ? ?: [1,nA] */
    /*  */
    /*  USAGE */
    /*  [rt,activation] = epu_n_unit_lba(v,theta,affTime,effTime,pN,dMeth,iAT); */
    /*  */
    /*  */
    /*  Bram Zandbelt, August 2012 */
    /* 'epu_n_unit_lba:46' rt = Inf; */
    /* 'epu_n_unit_lba:47' accumulationTime = Inf; */
    accumulationTime = rtInf;
    /*  Number of accumulator units */
    /* 'epu_n_unit_lba:49' nA = size(v,2); */
    /* 'epu_n_unit_lba:50' nAT = numel(iAT); */
    /* 'epu_n_unit_lba:52' if dMeth == 1 */
    b_emxInit_real_T(&y, 1, &emlrtRTEI, TRUE);
    emxInit_real_T(&b_y, 2, &emlrtRTEI, TRUE);
    if (dMeth == 1.0) {
        /*  Polling */
        /*  Compute the growth time for each accumulator */
        /* 'epu_n_unit_lba:55' dtAccumulation = theta./v; */
        EMLRTPUSHRTSTACK(&emlrtRSI);
        EMLRTPUSHRTSTACK(&h_emlrtRSI);
        for (i0 = 0; i0 < 2; i0++) {
            b_theta[i0] = theta->size[i0];
        }
        for (i0 = 0; i0 < 2; i0++) {
            b_v[i0] = v->size[i0];
        }
        emxInit_real_T(&dtAccumulation, 2, &e_emlrtRTEI, TRUE);
        emlrtSizeEqCheckND(b_theta, b_v, &c_emlrtECI);
        i0 = dtAccumulation->size[0] * dtAccumulation->size[1];
        dtAccumulation->size[0] = 1;
        dtAccumulation->size[1] = theta->size[1];
        emxEnsureCapacity((emxArray__common *)dtAccumulation, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
        loop_ub = theta->size[0] * theta->size[1] - 1;
        for (i0 = 0; i0 <= loop_ub; i0++) {
            dtAccumulation->data[i0] = theta->data[i0] / v->data[i0];
        }
        EMLRTPOPRTSTACK(&h_emlrtRSI);
        EMLRTPOPRTSTACK(&emlrtRSI);
        /* 'epu_n_unit_lba:57' if nA > 1 */
        if (v->size[1] > 1) {
            b_emxInit_real_T(&b_dtAccumulation, 1, &emlrtRTEI, TRUE);
            /*  Per simulation, sort growth times in ascending order */
            /* 'epu_n_unit_lba:59' dtAccumulation = sort(dtAccumulation')'; */
            EMLRTPUSHRTSTACK(&b_emlrtRSI);
            EMLRTPUSHRTSTACK(&j_emlrtRSI);
            i0 = b_dtAccumulation->size[0];
            b_dtAccumulation->size[0] = dtAccumulation->size[1];
            emxEnsureCapacity((emxArray__common *)b_dtAccumulation, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
            loop_ub = dtAccumulation->size[1] - 1;
            for (i0 = 0; i0 <= loop_ub; i0++) {
                b_dtAccumulation->data[i0] = dtAccumulation->data[i0];
            }
            eml_sort(b_dtAccumulation, y);
            EMLRTPOPRTSTACK(&j_emlrtRSI);
            i0 = dtAccumulation->size[0] * dtAccumulation->size[1];
            dtAccumulation->size[0] = 1;
            emxEnsureCapacity((emxArray__common *)dtAccumulation, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
            nm1d2 = y->size[0];
            i0 = dtAccumulation->size[0] * dtAccumulation->size[1];
            dtAccumulation->size[1] = nm1d2;
            emxEnsureCapacity((emxArray__common *)dtAccumulation, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
            emxFree_real_T(&b_dtAccumulation);
            loop_ub = y->size[0] - 1;
            for (i0 = 0; i0 <= loop_ub; i0++) {
                dtAccumulation->data[i0] = y->data[i0];
            }
            EMLRTPOPRTSTACK(&b_emlrtRSI);
        }
        emxInit_boolean_T(&b_pN, 2, &emlrtRTEI, TRUE);
        /* 'epu_n_unit_lba:62' if all(pN == 0) */
        EMLRTPUSHRTSTACK(&c_emlrtRSI);
        i0 = b_pN->size[0] * b_pN->size[1];
        b_pN->size[0] = 1;
        b_pN->size[1] = pN->size[1];
        emxEnsureCapacity((emxArray__common *)b_pN, i0, (int32_T)sizeof(boolean_T), &emlrtRTEI);
        loop_ub = pN->size[0] * pN->size[1] - 1;
        for (i0 = 0; i0 <= loop_ub; i0++) {
            b_pN->data[i0] = (pN->data[i0] == 0.0);
        }
        n_too_large = all(b_pN);
        EMLRTPOPRTSTACK(&c_emlrtRSI);
        emxFree_boolean_T(&b_pN);
        if (n_too_large) {
            /* 'epu_n_unit_lba:63' pN = realmin; */
            i0 = pN->size[0] * pN->size[1];
            pN->size[0] = 1;
            pN->size[1] = 1;
            emxEnsureCapacity((emxArray__common *)pN, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
            pN->data[0] = 2.2250738585072014E-308;
            /*  This ensures that very first accumulator determines RT */
        }
        /*  Compute rt as the sum of afferent time, time for pN fraction of accumulators */
        /*  to reach threshold and efferent time */
        /* 'epu_n_unit_lba:68' accumulationTime = dtAccumulation(:,ceil(pN*nA)); */
        EMLRTPUSHRTSTACK(&d_emlrtRSI);
        i0 = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 1;
        b_y->size[1] = pN->size[1];
        emxEnsureCapacity((emxArray__common *)b_y, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
        nm1d2 = v->size[1];
        loop_ub = pN->size[0] * pN->size[1] - 1;
        for (i0 = 0; i0 <= loop_ub; i0++) {
            b_y->data[i0] = pN->data[i0] * (real_T)nm1d2;
        }
        emxInit_real_T(&x, 2, &emlrtRTEI, TRUE);
        i0 = x->size[0] * x->size[1];
        x->size[0] = 1;
        x->size[1] = b_y->size[1];
        emxEnsureCapacity((emxArray__common *)x, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
        loop_ub = b_y->size[0] * b_y->size[1] - 1;
        for (i0 = 0; i0 <= loop_ub; i0++) {
            x->data[i0] = b_y->data[i0];
        }
        for (k = 0; k <= b_y->size[1] - 1; k++) {
            emlrtDynamicBoundsCheck((int32_T)(1.0 + (real_T)k), 1, x->size[1], &b_emlrtBCI);
            x->data[emlrtDynamicBoundsCheck(1 + k, 1, x->size[1], &p_emlrtBCI) - 1] = muDoubleScalarCeil(x->data[k]);
        }
        loop_ub = x->size[0] * x->size[1] - 1;
        for (i0 = 0; i0 <= loop_ub; i0++) {
            emlrtDynamicBoundsCheck((int32_T)emlrtIntegerCheckR2009b(x->data[i0], &c_emlrtDCI), 1, dtAccumulation->size[1], &e_emlrtBCI);
        }
        emxInit_int32_T(&r0, 1, &emlrtRTEI, TRUE);
        EMLRTPOPRTSTACK(&d_emlrtRSI);
        /* 'epu_n_unit_lba:69' accumulationTime = accumulationTime(1); */
        i0 = r0->size[0];
        r0->size[0] = x->size[1];
        emxEnsureCapacity((emxArray__common *)r0, i0, (int32_T)sizeof(int32_T), &emlrtRTEI);
        loop_ub = x->size[1] - 1;
        for (i0 = 0; i0 <= loop_ub; i0++) {
            r0->data[i0] = (int32_T)x->data[i0];
        }
        b_x[0] = x->size[1];
        c_x = *x;
        c_x.size = (int32_T *)&b_x;
        c_x.numDimensions = 1;
        emlrtDynamicBoundsCheck(1, 1, c_x.size[0], &emlrtBCI);
        accumulationTime = dtAccumulation->data[dtAccumulation->size[0] * (r0->data[0] - 1)];
        emxFree_int32_T(&r0);
        emxFree_real_T(&x);
        emxFree_real_T(&dtAccumulation);
    } else {
        if (dMeth == 2.0) {
            /* 'epu_n_unit_lba:71' elseif dMeth == 2 */
            /*  Compute the growth time for each accumulator */
            /* 'epu_n_unit_lba:74' accumulationTime(1) = mean(theta)./mean(v); */
            EMLRTPUSHRTSTACK(&e_emlrtRSI);
            d_x = mean(theta);
            accumulationTime = mean(v);
            accumulationTime = d_x / accumulationTime;
            EMLRTPOPRTSTACK(&e_emlrtRSI);
        }
    }
    /* 'epu_n_unit_lba:78' rt(1) = affTime + accumulationTime + effTime; */
    *rt = (affTime + accumulationTime) + effTime;
    /*  Compute activation trajectories */
    /* 'epu_n_unit_lba:81' activation = [zeros(floor(affTime),nAT);repmat(colon(1,ceil(accumulationTime + effTime))',1,nAT).*repmat(v(iAT),ceil(accumulationTime + effTime),1)]; */
    EMLRTPUSHRTSTACK(&f_emlrtRSI);
    d_x = muDoubleScalarCeil(accumulationTime + effTime);
    EMLRTPUSHRTSTACK(&kb_emlrtRSI);
    EMLRTPUSHRTSTACK(&lb_emlrtRSI);
    if (muDoubleScalarIsNaN(d_x)) {
        iacol = 1;
        anew = rtNaN;
        apnd = d_x;
        n_too_large = FALSE;
    } else if (d_x < 1.0) {
        iacol = 0;
        anew = 1.0;
        apnd = d_x;
        n_too_large = FALSE;
    } else if (muDoubleScalarIsInf(d_x)) {
        iacol = 1;
        anew = rtNaN;
        apnd = d_x;
        if (1.0 == d_x) {
            n_too_large = TRUE;
        } else {
            n_too_large = FALSE;
        }
        n_too_large = !n_too_large;
    } else {
        anew = 1.0;
        ndbl = muDoubleScalarFloor((d_x - 1.0) + 0.5);
        apnd = 1.0 + ndbl;
        cdiff = (1.0 + ndbl) - d_x;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * d_x) {
            ndbl++;
            apnd = d_x;
        } else if (cdiff > 0.0) {
            apnd = 1.0 + (ndbl - 1.0);
        } else {
            ndbl++;
        }
        n_too_large = (ndbl > 2.147483647E+9);
        if (ndbl >= 0.0) {
            iacol = (int32_T)ndbl;
        } else {
            iacol = 0;
        }
    }
    EMLRTPUSHRTSTACK(&mb_emlrtRSI);
    if (!n_too_large) {
    } else {
        EMLRTPUSHRTSTACK(&nb_emlrtRSI);
        c_y = NULL;
        m0 = mxCreateCharArray(2, iv0);
        emlrtInitCharArray(21, m0, cv0);
        emlrtAssign(&c_y, m0);
        error(message(c_y, &m_emlrtMCI), &n_emlrtMCI);
        EMLRTPOPRTSTACK(&nb_emlrtRSI);
    }
    EMLRTPOPRTSTACK(&mb_emlrtRSI);
    emlrtNonNegativeCheckR2009b((real_T)iacol, &b_emlrtDCI);
    i0 = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = iacol;
    emxEnsureCapacity((emxArray__common *)b_y, i0, (int32_T)sizeof(real_T), &b_emlrtRTEI);
    if (iacol > 0) {
        emlrtDynamicBoundsCheck(1, 1, b_y->size[1], &c_emlrtBCI);
        b_y->data[0] = anew;
        if (iacol > 1) {
            b_y->data[emlrtDynamicBoundsCheck(iacol, 1, b_y->size[1], &f_emlrtBCI) - 1] = apnd;
            nm1 = iacol - 1;
            i0 = nm1;
            nm1d2 = (int32_T)((uint32_T)i0 >> 1);
            for (k = 1; k <= nm1d2 - 1; k++) {
                b_y->data[emlrtDynamicBoundsCheck(k + 1, 1, b_y->size[1], &n_emlrtBCI) - 1] = anew + (real_T)k;
                b_y->data[emlrtDynamicBoundsCheck(iacol - k, 1, b_y->size[1], &o_emlrtBCI) - 1] = apnd - (real_T)k;
            }
            if (nm1d2 << 1 == nm1) {
                b_y->data[emlrtDynamicBoundsCheck(nm1d2 + 1, 1, b_y->size[1], &i_emlrtBCI) - 1] = (anew + apnd) / 2.0;
            } else {
                b_y->data[emlrtDynamicBoundsCheck(nm1d2 + 1, 1, b_y->size[1], &g_emlrtBCI) - 1] = anew + (real_T)nm1d2;
                b_y->data[emlrtDynamicBoundsCheck(nm1d2 + 2, 1, b_y->size[1], &h_emlrtBCI) - 1] = apnd - (real_T)nm1d2;
            }
        }
    }
    EMLRTPOPRTSTACK(&lb_emlrtRSI);
    EMLRTPOPRTSTACK(&kb_emlrtRSI);
    i0 = y->size[0];
    y->size[0] = b_y->size[1];
    emxEnsureCapacity((emxArray__common *)y, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
    loop_ub = b_y->size[1] - 1;
    for (i0 = 0; i0 <= loop_ub; i0++) {
        y->data[i0] = b_y->data[i0];
    }
    emxFree_real_T(&b_y);
    EMLRTPUSHRTSTACK(&ob_emlrtRSI);
    eml_assert_valid_size_arg((real_T)iAT->size[1]);
    EMLRTPOPRTSTACK(&ob_emlrtRSI);
    mv[0] = 1;
    mv[1] = iAT->size[1];
    b_theta[0] = y->size[0];
    b_theta[1] = 1;
    for (i0 = 0; i0 < 2; i0++) {
        b_v[i0] = b_theta[i0] * mv[i0];
    }
    emxInit_real_T(&r1, 2, &emlrtRTEI, TRUE);
    i0 = r1->size[0] * r1->size[1];
    r1->size[0] = b_v[0];
    r1->size[1] = b_v[1];
    emxEnsureCapacity((emxArray__common *)r1, i0, (int32_T)sizeof(real_T), &c_emlrtRTEI);
    if ((r1->size[0] == 0) || (r1->size[1] == 0)) {
    } else {
        ib = 1;
        for (nm1d2 = 1; nm1d2 <= mv[1]; nm1d2++) {
            ia = 1;
            for (k = 1; k <= y->size[0]; k++) {
                r1->data[emlrtDynamicBoundsCheck(ib, 1, r1->size[0] * r1->size[1], &j_emlrtBCI) - 1] = y->data[emlrtDynamicBoundsCheck(ia, 1, y->size[0], &k_emlrtBCI) - 1];
                ia++;
                ib++;
            }
        }
    }
    emxFree_real_T(&y);
    EMLRTPOPRTSTACK(&f_emlrtRSI);
    EMLRTPUSHRTSTACK(&g_emlrtRSI);
    d_x = muDoubleScalarCeil(accumulationTime + effTime);
    loop_ub = iAT->size[0] * iAT->size[1] - 1;
    for (i0 = 0; i0 <= loop_ub; i0++) {
        emlrtDynamicBoundsCheck((int32_T)emlrtIntegerCheckR2009b(iAT->data[i0], &d_emlrtDCI), 1, v->size[1], &l_emlrtBCI);
    }
    emxInit_real_T(&c_v, 2, &emlrtRTEI, TRUE);
    EMLRTPUSHRTSTACK(&rb_emlrtRSI);
    eml_assert_valid_size_arg(d_x);
    EMLRTPOPRTSTACK(&rb_emlrtRSI);
    d_x = d_x < 0.0 ? muDoubleScalarCeil(d_x - 0.5) : muDoubleScalarFloor(d_x + 0.5);
    if (d_x < 2.147483648E+9) {
        if (d_x >= -2.147483648E+9) {
            i0 = (int32_T)d_x;
        } else {
            i0 = MIN_int32_T;
        }
    } else if (d_x >= 2.147483648E+9) {
        i0 = MAX_int32_T;
    } else {
        i0 = 0;
    }
    mv[0] = i0;
    mv[1] = 1;
    i0 = c_v->size[0] * c_v->size[1];
    c_v->size[0] = 1;
    c_v->size[1] = iAT->size[1];
    emxEnsureCapacity((emxArray__common *)c_v, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
    loop_ub = iAT->size[1] - 1;
    for (i0 = 0; i0 <= loop_ub; i0++) {
        c_v->data[c_v->size[0] * i0] = v->data[(int32_T)iAT->data[iAT->size[0] * i0] - 1];
    }
    for (i0 = 0; i0 < 2; i0++) {
        b_v[i0] = (int32_T)emlrtNonNegativeCheckR2009b((real_T)(c_v->size[i0] * mv[i0]), &e_emlrtDCI);
    }
    emxFree_real_T(&c_v);
    emxInit_real_T(&r2, 2, &emlrtRTEI, TRUE);
    i0 = r2->size[0] * r2->size[1];
    r2->size[0] = b_v[0];
    r2->size[1] = b_v[1];
    emxEnsureCapacity((emxArray__common *)r2, i0, (int32_T)sizeof(real_T), &d_emlrtRTEI);
    if ((r2->size[0] == 0) || (r2->size[1] == 0)) {
    } else {
        ia = 1;
        ib = 1;
        emxInit_real_T(&d_v, 2, &emlrtRTEI, TRUE);
        emxInit_real_T(&e_v, 2, &emlrtRTEI, TRUE);
        emxInit_real_T(&f_v, 2, &emlrtRTEI, TRUE);
        iacol = 1;
        nm1 = 1;
        do {
            exitg1 = 0U;
            i0 = d_v->size[0] * d_v->size[1];
            d_v->size[0] = 1;
            d_v->size[1] = iAT->size[1];
            emxEnsureCapacity((emxArray__common *)d_v, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
            loop_ub = iAT->size[1] - 1;
            for (i0 = 0; i0 <= loop_ub; i0++) {
                d_v->data[d_v->size[0] * i0] = v->data[(int32_T)iAT->data[iAT->size[0] * i0] - 1];
            }
            if (nm1 <= d_v->size[1]) {
                for (k = 1; k <= mv[0]; k++) {
                    i0 = e_v->size[0] * e_v->size[1];
                    e_v->size[0] = 1;
                    e_v->size[1] = iAT->size[1];
                    emxEnsureCapacity((emxArray__common *)e_v, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                    loop_ub = iAT->size[1] - 1;
                    for (i0 = 0; i0 <= loop_ub; i0++) {
                        e_v->data[e_v->size[0] * i0] = v->data[(int32_T)iAT->data[iAT->size[0] * i0] - 1];
                    }
                    i0 = f_v->size[0] * f_v->size[1];
                    f_v->size[0] = 1;
                    f_v->size[1] = iAT->size[1];
                    emxEnsureCapacity((emxArray__common *)f_v, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                    loop_ub = iAT->size[1] - 1;
                    for (i0 = 0; i0 <= loop_ub; i0++) {
                        f_v->data[f_v->size[0] * i0] = v->data[(int32_T)iAT->data[iAT->size[0] * i0] - 1];
                    }
                    nm1d2 = emlrtDynamicBoundsCheck(iacol, 1, f_v->size[1], &d_emlrtBCI);
                    r2->data[emlrtDynamicBoundsCheck(ib, 1, r2->size[0] * r2->size[1], &m_emlrtBCI) - 1] = v->data[(int32_T)iAT->data[nm1d2 - 1] - 1];
                    ia = iacol + 1;
                    ib++;
                }
                iacol = ia;
                nm1++;
            } else {
                exitg1 = 1U;
            }
        } while (exitg1 == 0U);
        emxFree_real_T(&f_v);
        emxFree_real_T(&e_v);
        emxFree_real_T(&d_v);
    }
    EMLRTPOPRTSTACK(&g_emlrtRSI);
    for (i0 = 0; i0 < 2; i0++) {
        b_v[i0] = r1->size[i0];
    }
    for (i0 = 0; i0 < 2; i0++) {
        b_theta[i0] = r2->size[i0];
    }
    emlrtSizeEqCheckND(b_v, b_theta, &emlrtECI);
    d_x = muDoubleScalarFloor(affTime);
    emlrtNonNegativeCheckR2009b(d_x, &emlrtDCI);
    i0 = r1->size[0] * r1->size[1];
    emxEnsureCapacity((emxArray__common *)r1, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
    i0 = r1->size[0];
    nm1d2 = r1->size[1];
    loop_ub = i0 * nm1d2 - 1;
    for (i0 = 0; i0 <= loop_ub; i0++) {
        r1->data[i0] *= r2->data[i0];
    }
    emxFree_real_T(&r2);
    nm1d2 = iAT->size[1];
    emlrtDimSizeEqCheck(nm1d2, r1->size[1], &b_emlrtECI);
    nm1d2 = iAT->size[1];
    i0 = activation->size[0] * activation->size[1];
    activation->size[0] = (int32_T)d_x + r1->size[0];
    activation->size[1] = nm1d2;
    emxEnsureCapacity((emxArray__common *)activation, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
    loop_ub = nm1d2 - 1;
    for (i0 = 0; i0 <= loop_ub; i0++) {
        iacol = (int32_T)d_x - 1;
        for (nm1d2 = 0; nm1d2 <= iacol; nm1d2++) {
            activation->data[nm1d2 + activation->size[0] * i0] = 0.0;
        }
    }
    loop_ub = r1->size[1] - 1;
    for (i0 = 0; i0 <= loop_ub; i0++) {
        iacol = r1->size[0] - 1;
        for (nm1d2 = 0; nm1d2 <= iacol; nm1d2++) {
            activation->data[(nm1d2 + (int32_T)d_x) + activation->size[0] * i0] = r1->data[nm1d2 + r1->size[0] * i0];
        }
    }
    emxFree_real_T(&r1);
    /*  Activation */
    /*  activation(floor(affTime)+1:end,:) = repmat(colon(1,ceil(accumulationTime + effTime))',1,nAT).*repmat(v(iAT),ceil(accumulationTime + effTime),1); */
    emlrtHeapReferenceStackLeaveFcn();
}
/* End of code generation (epu_n_unit_lba.c) */
