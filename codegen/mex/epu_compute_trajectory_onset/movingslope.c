/*
 * movingslope.c
 *
 * Code generation for function 'movingslope'
 *
 * C source code generated on: Fri Aug 31 09:24:08 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_compute_trajectory_onset.h"
#include "movingslope.h"
#include "epu_compute_trajectory_onset_emxutil.h"
#include "median.h"
#include "colon.h"
#include "pinv.h"
#include "filter.h"
#include "mrdivide.h"
#include "mod.h"
#include "error.h"
#include "epu_compute_trajectory_onset_mexutil.h"
#include "epu_compute_trajectory_onset_data.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo g_emlrtRSI = { 148, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtRSInfo h_emlrtRSI = { 163, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtRSInfo i_emlrtRSI = { 166, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtRSInfo j_emlrtRSI = { 179, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtRSInfo k_emlrtRSI = { 180, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtRSInfo l_emlrtRSI = { 183, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtRSInfo m_emlrtRSI = { 191, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtRSInfo n_emlrtRSI = { 192, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtRSInfo o_emlrtRSI = { 194, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtRSInfo p_emlrtRSI = { 198, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtRSInfo q_emlrtRSI = { 199, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtRSInfo r_emlrtRSI = { 200, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtRSInfo s_emlrtRSI = { 200, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtRSInfo t_emlrtRSI = { 185, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtRSInfo u_emlrtRSI = { 21, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRSInfo v_emlrtRSI = { 79, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRSInfo w_emlrtRSI = { 117, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRSInfo y_emlrtRSI = { 215, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtRSInfo ab_emlrtRSI = { 216, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtRSInfo cb_emlrtRSI = { 10, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };
static emlrtRSInfo db_emlrtRSI = { 48, "eml_assert_valid_size_arg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m" };
static emlrtRSInfo eb_emlrtRSI = { 52, "eml_assert_valid_size_arg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m" };
static emlrtRSInfo fb_emlrtRSI = { 40, "power", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/power.m" };
static emlrtRSInfo gb_emlrtRSI = { 46, "power", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/power.m" };
static emlrtRSInfo hb_emlrtRSI = { 17, "eml_scalexp_alloc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m" };
static emlrtRSInfo ib_emlrtRSI = { 16, "eml_scalexp_alloc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m" };
static emlrtRSInfo jb_emlrtRSI = { 8, "isequal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/isequal.m" };
static emlrtRSInfo kb_emlrtRSI = { 30, "eml_isequal_core", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_isequal_core.m" };
static emlrtRSInfo lb_emlrtRSI = { 20, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtRSInfo mb_emlrtRSI = { 18, "pinv", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/pinv.m" };
static emlrtRSInfo nb_emlrtRSI = { 20, "pinv", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/pinv.m" };
static emlrtRSInfo jj_emlrtRSI = { 49, "mtimes", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };
static emlrtRSInfo kj_emlrtRSI = { 21, "mtimes", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };
static emlrtRSInfo lj_emlrtRSI = { 84, "mtimes", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };
static emlrtRSInfo mj_emlrtRSI = { 89, "mtimes", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };
static emlrtRSInfo nj_emlrtRSI = { 31, "eml_xdotu", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m" };
static emlrtRSInfo oj_emlrtRSI = { 28, "eml_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m" };
static emlrtRSInfo qj_emlrtRSI = { 28, "eml_blas_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m" };
static emlrtRSInfo sj_emlrtRSI = { 21, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRSInfo tj_emlrtRSI = { 79, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRSInfo uj_emlrtRSI = { 117, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtMCInfo f_emlrtMCI = { 49, 13, "eml_assert_valid_size_arg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m" };
static emlrtMCInfo g_emlrtMCI = { 48, 23, "eml_assert_valid_size_arg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m" };
static emlrtMCInfo h_emlrtMCI = { 53, 5, "eml_assert_valid_size_arg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m" };
static emlrtMCInfo i_emlrtMCI = { 52, 15, "eml_assert_valid_size_arg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m" };
static emlrtMCInfo j_emlrtMCI = { 20, 17, "eml_scalexp_alloc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m" };
static emlrtMCInfo k_emlrtMCI = { 17, 17, "eml_scalexp_alloc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m" };
static emlrtMCInfo l_emlrtMCI = { 20, 19, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo m_emlrtMCI = { 20, 5, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo x_emlrtMCI = { 85, 13, "mtimes", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };
static emlrtMCInfo y_emlrtMCI = { 84, 23, "mtimes", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };
static emlrtMCInfo ab_emlrtMCI = { 90, 13, "mtimes", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };
static emlrtMCInfo bb_emlrtMCI = { 89, 23, "mtimes", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };
static emlrtRTEInfo f_emlrtRTEI = { 118, 1, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRTEInfo g_emlrtRTEI = { 1, 17, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtRTEInfo h_emlrtRTEI = { 118, 1, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRTEInfo i_emlrtRTEI = { 180, 1, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtRTEInfo j_emlrtRTEI = { 183, 1, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtRTEInfo k_emlrtRTEI = { 45, 1, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };
static emlrtRTEInfo l_emlrtRTEI = { 45, 1, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };
static emlrtRTEInfo m_emlrtRTEI = { 14, 9, "eml_scalexp_alloc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m" };
static emlrtRTEInfo n_emlrtRTEI = { 212, 17, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtRTEInfo o_emlrtRTEI = { 215, 1, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtRTEInfo p_emlrtRTEI = { 216, 1, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtBCInfo n_emlrtBCI = { -1, -1, 59, 5, "", "eml_blas_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m", 0 };
static emlrtBCInfo o_emlrtBCI = { -1, -1, 58, 35, "", "eml_blas_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m", 0 };
static emlrtBCInfo p_emlrtBCI = { -1, -1, 120, 5, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtDCInfo c_emlrtDCI = { 118, 28, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 4 };
static emlrtBCInfo q_emlrtBCI = { -1, -1, 120, 5, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtDCInfo d_emlrtDCI = { 118, 28, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 4 };
static emlrtBCInfo r_emlrtBCI = { -1, -1, 58, 35, "", "eml_blas_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m", 0 };
static emlrtBCInfo s_emlrtBCI = { -1, -1, 120, 5, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtDCInfo e_emlrtDCI = { 118, 28, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 4 };
static emlrtBCInfo t_emlrtBCI = { -1, -1, 120, 5, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtDCInfo f_emlrtDCI = { 118, 28, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 4 };
static emlrtBCInfo u_emlrtBCI = { -1, -1, 120, 5, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtDCInfo g_emlrtDCI = { 118, 28, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 4 };
static emlrtECInfo emlrtECI = { -1, 185, 1, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtECInfo b_emlrtECI = { -1, 200, 28, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtECInfo c_emlrtECI = { -1, 194, 18, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtBCInfo v_emlrtBCI = { -1, -1, 194, 18, "vec", "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m", 0 };
static emlrtDCInfo h_emlrtDCI = { 194, 18, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m", 1 };
static emlrtBCInfo w_emlrtBCI = { -1, -1, 194, 18, "vec", "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m", 0 };
static emlrtRTEInfo dc_emlrtRTEI = { 189, 1, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m" };
static emlrtBCInfo x_emlrtBCI = { -1, -1, 185, 35, "f", "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m", 0 };
static emlrtBCInfo y_emlrtBCI = { -1, -1, 185, 35, "f", "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m", 0 };
static emlrtDCInfo i_emlrtDCI = { 185, 35, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m", 1 };
static emlrtBCInfo ab_emlrtBCI = { 0, MAX_int32_T, 185, 51, "f(supportlength:end)", "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m", 0 };
static emlrtBCInfo bb_emlrtBCI = { -1, -1, 122, 9, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo cb_emlrtBCI = { -1, -1, 134, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo db_emlrtBCI = { -1, -1, 135, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo eb_emlrtBCI = { -1, -1, 131, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo fb_emlrtBCI = { -1, -1, 122, 9, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo gb_emlrtBCI = { -1, -1, 134, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo hb_emlrtBCI = { -1, -1, 135, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo ib_emlrtBCI = { -1, -1, 131, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo jb_emlrtBCI = { -1, -1, 185, 1, "Dvec", "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m", 0 };
static emlrtDCInfo j_emlrtDCI = { 185, 1, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m", 1 };
static emlrtBCInfo kb_emlrtBCI = { -1, -1, 122, 9, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo lb_emlrtBCI = { -1, -1, 134, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo mb_emlrtBCI = { -1, -1, 135, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo nb_emlrtBCI = { -1, -1, 131, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo ob_emlrtBCI = { -1, -1, 194, 3, "Dvec", "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m", 0 };
static emlrtBCInfo pb_emlrtBCI = { -1, -1, 122, 9, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo qb_emlrtBCI = { -1, -1, 134, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo rb_emlrtBCI = { -1, -1, 135, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo sb_emlrtBCI = { -1, -1, 131, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo tb_emlrtBCI = { -1, -1, 122, 9, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo ub_emlrtBCI = { -1, -1, 134, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo vb_emlrtBCI = { -1, -1, 135, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo wb_emlrtBCI = { -1, -1, 131, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo xb_emlrtBCI = { -1, -1, 200, 28, "vec", "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m", 0 };
static emlrtDCInfo k_emlrtDCI = { 200, 28, "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m", 1 };
static emlrtBCInfo yb_emlrtBCI = { -1, -1, 200, 5, "Dvec", "movingslope", "/Users/bram/Dropbox/Matlab/derrico_john/movingslope/movingslope.m", 0 };
static emlrtBCInfo ac_emlrtBCI = { -1, -1, 127, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo bc_emlrtBCI = { -1, -1, 128, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo cc_emlrtBCI = { -1, -1, 127, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo dc_emlrtBCI = { -1, -1, 128, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo ec_emlrtBCI = { -1, -1, 127, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo fc_emlrtBCI = { -1, -1, 128, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo gc_emlrtBCI = { -1, -1, 127, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo hc_emlrtBCI = { -1, -1, 128, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo ic_emlrtBCI = { -1, -1, 127, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo jc_emlrtBCI = { -1, -1, 128, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo kc_emlrtBCI = { -1, -1, 43, 14, "", "power", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/power.m", 0 };
static emlrtBCInfo lc_emlrtBCI = { -1, -1, 42, 14, "", "power", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/power.m", 0 };
static emlrtBCInfo mc_emlrtBCI = { 0, MAX_int32_T, 41, 15, "", "power", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/power.m", 0 };
static emlrtBCInfo nc_emlrtBCI = { -1, -1, 64, 21, "", "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m", 0 };
static emlrtBCInfo oc_emlrtBCI = { -1, -1, 64, 29, "", "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m", 0 };
static emlrtDCInfo l_emlrtDCI = { 45, 48, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m", 4 };
static emlrtBCInfo pc_emlrtBCI = { -1, -1, 64, 21, "", "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m", 0 };
static emlrtBCInfo qc_emlrtBCI = { 1, 2, 64, 29, "", "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m", 0 };
static emlrtBCInfo rc_emlrtBCI = { -1, -1, 51, 13, "", "power", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/power.m", 0 };

/* Function Declarations */
static void eml_error(void);
static void getcoef(const emxArray_real_T *t, real_T supportlength, emxArray_real_T *coef);

/* Function Definitions */

/*
 * 
 */
static void eml_error(void)
{
    const mxArray *y;
    static const int32_T iv18[2] = { 1, 31 };
    const mxArray *m5;
    static const char_T cv9[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };
    EMLRTPUSHRTSTACK(&lb_emlrtRSI);
    y = NULL;
    m5 = mxCreateCharArray(2, iv18);
    emlrtInitCharArray(31, m5, cv9);
    emlrtAssign(&y, m5);
    c_error(message(y, &l_emlrtMCI), &m_emlrtMCI);
    EMLRTPOPRTSTACK(&lb_emlrtRSI);
}

/*
 * function coef = getcoef(t,supportlength,modelorder)
 */
static void getcoef(const emxArray_real_T *t, real_T supportlength, emxArray_real_T *coef)
{
    int32_T b_t[2];
    int32_T iv14[2];
    int32_T iacol;
    int64_T i2;
    emxArray_real_T *b;
    int32_T ib;
    int32_T jtilecol;
    int32_T ia;
    int32_T k;
    boolean_T p;
    const mxArray *y;
    static const int32_T iv15[2] = { 1, 28 };
    const mxArray *m4;
    static const char_T cv6[28] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'N', 'o', 'n', 'I', 'n', 't', 'e', 'g', 'e', 'r', 'I', 'n', 'p', 'u', 't' };
    real_T n;
    const mxArray *b_y;
    static const int32_T iv16[2] = { 1, 21 };
    static const char_T cv7[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };
    int32_T mv[2];
    emxArray_real_T *b_b;
    uint32_T varargin_1[2];
    emxArray_real_T *A;
    uint32_T varargin_2[2];
    boolean_T b1;
    boolean_T exitg1;
    const mxArray *c_y;
    static const int32_T iv17[2] = { 1, 21 };
    static const char_T cv8[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'm', 'a', 'g', 'r', 'e', 'e' };
    emxArray_real_T *pinvA;
    emxArray_real_T *b_A;
    emlrtHeapReferenceStackEnterFcn();
    /*  mainline end */
    /*  ========================================================= */
    /*  subfunction, used to compute the filter coefficients */
    /*  Note: bsxfun would have worked here as well, but some people */
    /*  might not yet have that release of matlab. */
    /* 'movingslope:215' A = repmat(t,1,modelorder+1).^repmat(0:modelorder,supportlength,1); */
    EMLRTPUSHRTSTACK(&y_emlrtRSI);
    b_t[0] = t->size[0];
    b_t[1] = 1;
    for (iacol = 0; iacol < 2; iacol++) {
        i2 = (int64_T)b_t[iacol] * (int64_T)(1 + iacol);
        if (i2 > 2147483647L) {
            i2 = 2147483647L;
        } else {
            if (i2 < -2147483648L) {
                i2 = -2147483648L;
            }
        }
        iv14[iacol] = (int32_T)i2;
    }
    emxInit_real_T(&b, 2, &n_emlrtRTEI, TRUE);
    iacol = b->size[0] * b->size[1];
    b->size[0] = iv14[0];
    b->size[1] = 2;
    emxEnsureCapacity((emxArray__common *)b, iacol, (int32_T)sizeof(real_T), &k_emlrtRTEI);
    if (b->size[0] == 0) {
    } else {
        ib = 1;
        for (jtilecol = 0; jtilecol < 2; jtilecol++) {
            ia = 1;
            for (k = 1; k <= t->size[0]; k++) {
                b->data[emlrtDynamicBoundsCheck(ib, 1, b->size[0] << 1, &nc_emlrtBCI) - 1] = t->data[emlrtDynamicBoundsCheck(ia, 1, t->size[0], &oc_emlrtBCI) - 1];
                ia++;
                ib++;
            }
        }
    }
    EMLRTPUSHRTSTACK(&cb_emlrtRSI);
    if ((supportlength != muDoubleScalarFloor(supportlength)) || muDoubleScalarIsInf(supportlength)) {
        p = FALSE;
    } else {
        p = TRUE;
    }
    if (p) {
    } else {
        EMLRTPUSHRTSTACK(&db_emlrtRSI);
        y = NULL;
        m4 = mxCreateCharArray(2, iv15);
        emlrtInitCharArray(28, m4, cv6);
        emlrtAssign(&y, m4);
        c_error(message(y, &f_emlrtMCI), &g_emlrtMCI);
        EMLRTPOPRTSTACK(&db_emlrtRSI);
    }
    if (supportlength <= 0.0) {
        n = 0.0;
    } else {
        n = supportlength;
    }
    if (n <= 2.147483647E+9) {
    } else {
        EMLRTPUSHRTSTACK(&eb_emlrtRSI);
        b_y = NULL;
        m4 = mxCreateCharArray(2, iv16);
        emlrtInitCharArray(21, m4, cv7);
        emlrtAssign(&b_y, m4);
        c_error(message(b_y, &h_emlrtMCI), &i_emlrtMCI);
        EMLRTPOPRTSTACK(&eb_emlrtRSI);
    }
    EMLRTPOPRTSTACK(&cb_emlrtRSI);
    n = supportlength;
    n = n < 0.0 ? muDoubleScalarCeil(n - 0.5) : muDoubleScalarFloor(n + 0.5);
    if (n < 2.147483648E+9) {
        if (n >= -2.147483648E+9) {
            iacol = (int32_T)n;
        } else {
            iacol = MIN_int32_T;
        }
    } else if (n >= 2.147483648E+9) {
        iacol = MAX_int32_T;
    } else {
        iacol = 0;
    }
    mv[0] = iacol;
    mv[1] = 1;
    for (iacol = 0; iacol < 2; iacol++) {
        i2 = (int64_T)(1 + iacol) * (int64_T)mv[iacol];
        if (i2 > 2147483647L) {
            i2 = 2147483647L;
        } else {
            if (i2 < -2147483648L) {
                i2 = -2147483648L;
            }
        }
        iv14[iacol] = (int32_T)emlrtNonNegativeCheckR2009b((real_T)(int32_T)i2, &l_emlrtDCI);
    }
    emxInit_real_T(&b_b, 2, &n_emlrtRTEI, TRUE);
    iacol = b_b->size[0] * b_b->size[1];
    b_b->size[0] = iv14[0];
    b_b->size[1] = 2;
    emxEnsureCapacity((emxArray__common *)b_b, iacol, (int32_T)sizeof(real_T), &l_emlrtRTEI);
    if (b_b->size[0] == 0) {
    } else {
        ia = 1;
        ib = 1;
        iacol = 1;
        for (jtilecol = 0; jtilecol < 2; jtilecol++) {
            for (k = 1; k <= mv[0]; k++) {
                b_b->data[emlrtDynamicBoundsCheck(ib, 1, b_b->size[0] << 1, &pc_emlrtBCI) - 1] = (real_T)(int8_T)(emlrtBoundsCheck(iacol, &qc_emlrtBCI) - 1);
                ia = iacol + 1;
                ib++;
            }
            iacol = ia;
        }
    }
    EMLRTPUSHRTSTACK(&fb_emlrtRSI);
    for (iacol = 0; iacol < 2; iacol++) {
        varargin_1[iacol] = (uint32_T)b->size[iacol];
    }
    emxInit_real_T(&A, 2, &o_emlrtRTEI, TRUE);
    iacol = A->size[0] * A->size[1];
    A->size[0] = (int32_T)varargin_1[0];
    A->size[1] = 2;
    emxEnsureCapacity((emxArray__common *)A, iacol, (int32_T)sizeof(real_T), &m_emlrtRTEI);
    EMLRTPUSHRTSTACK(&hb_emlrtRSI);
    for (iacol = 0; iacol < 2; iacol++) {
        varargin_1[iacol] = (uint32_T)b_b->size[iacol];
    }
    for (iacol = 0; iacol < 2; iacol++) {
        varargin_2[iacol] = (uint32_T)A->size[iacol];
    }
    EMLRTPUSHRTSTACK(&jb_emlrtRSI);
    b1 = FALSE;
    EMLRTPUSHRTSTACK(&kb_emlrtRSI);
    p = TRUE;
    k = 0;
    exitg1 = 0U;
    while ((exitg1 == 0U) && (k < 2)) {
        if (!(varargin_1[k] == varargin_2[k])) {
            p = FALSE;
            exitg1 = 1U;
        } else {
            k++;
        }
    }
    EMLRTPOPRTSTACK(&kb_emlrtRSI);
    if (!p) {
    } else {
        b1 = TRUE;
    }
    EMLRTPOPRTSTACK(&jb_emlrtRSI);
    EMLRTPOPRTSTACK(&hb_emlrtRSI);
    if (b1) {
        b1 = TRUE;
    } else {
        b1 = FALSE;
    }
    if (b1) {
    } else {
        EMLRTPUSHRTSTACK(&ib_emlrtRSI);
        c_y = NULL;
        m4 = mxCreateCharArray(2, iv17);
        emlrtInitCharArray(21, m4, cv8);
        emlrtAssign(&c_y, m4);
        c_error(message(c_y, &j_emlrtMCI), &k_emlrtMCI);
        EMLRTPOPRTSTACK(&ib_emlrtRSI);
    }
    EMLRTPOPRTSTACK(&fb_emlrtRSI);
    iacol = emlrtBoundsCheck(A->size[0] << 1, &mc_emlrtBCI);
    for (k = 0; k <= iacol - 1; k++) {
        emlrtDynamicBoundsCheck((int32_T)(1.0 + (real_T)k), 1, b->size[0] << 1, &lc_emlrtBCI);
        emlrtDynamicBoundsCheck((int32_T)(1.0 + (real_T)k), 1, b_b->size[0] << 1, &kc_emlrtBCI);
        if ((b->data[k] < 0.0) && (b_b->data[k] != b_b->data[k])) {
            EMLRTPUSHRTSTACK(&gb_emlrtRSI);
            eml_error();
            EMLRTPOPRTSTACK(&gb_emlrtRSI);
        }
        A->data[emlrtDynamicBoundsCheck(1 + k, 1, A->size[0] << 1, &rc_emlrtBCI) - 1] = muDoubleScalarPower(b->data[k], b_b->data[k]);
    }
    emxFree_real_T(&b_b);
    EMLRTPOPRTSTACK(&y_emlrtRSI);
    /* 'movingslope:216' pinvA = pinv(A); */
    EMLRTPUSHRTSTACK(&ab_emlrtRSI);
    emxInit_real_T(&pinvA, 2, &p_emlrtRTEI, TRUE);
    if (A->size[0] < 2) {
        emxInit_real_T(&b_A, 2, &n_emlrtRTEI, TRUE);
        EMLRTPUSHRTSTACK(&mb_emlrtRSI);
        iacol = b_A->size[0] * b_A->size[1];
        b_A->size[0] = 2;
        b_A->size[1] = A->size[0];
        emxEnsureCapacity((emxArray__common *)b_A, iacol, (int32_T)sizeof(real_T), &n_emlrtRTEI);
        jtilecol = A->size[0] - 1;
        for (iacol = 0; iacol <= jtilecol; iacol++) {
            for (k = 0; k < 2; k++) {
                b_A->data[k + b_A->size[0] * iacol] = A->data[iacol + A->size[0] * k];
            }
        }
        eml_pinv(b_A, b);
        iacol = pinvA->size[0] * pinvA->size[1];
        pinvA->size[0] = 2;
        pinvA->size[1] = b->size[0];
        emxEnsureCapacity((emxArray__common *)pinvA, iacol, (int32_T)sizeof(real_T), &n_emlrtRTEI);
        emxFree_real_T(&b_A);
        jtilecol = b->size[0] - 1;
        for (iacol = 0; iacol <= jtilecol; iacol++) {
            for (k = 0; k < 2; k++) {
                pinvA->data[k + pinvA->size[0] * iacol] = b->data[iacol + b->size[0] * k];
            }
        }
        EMLRTPOPRTSTACK(&mb_emlrtRSI);
    } else {
        EMLRTPUSHRTSTACK(&nb_emlrtRSI);
        b_eml_pinv(A, pinvA);
        EMLRTPOPRTSTACK(&nb_emlrtRSI);
    }
    emxFree_real_T(&b);
    emxFree_real_T(&A);
    EMLRTPOPRTSTACK(&ab_emlrtRSI);
    /*  we only need the linear term */
    /* 'movingslope:218' coef = pinvA(2,:); */
    iacol = pinvA->size[1];
    k = coef->size[0] * coef->size[1];
    coef->size[0] = 1;
    coef->size[1] = iacol;
    emxEnsureCapacity((emxArray__common *)coef, k, (int32_T)sizeof(real_T), &n_emlrtRTEI);
    jtilecol = iacol - 1;
    for (iacol = 0; iacol <= jtilecol; iacol++) {
        coef->data[coef->size[0] * iacol] = pinvA->data[1 + pinvA->size[0] * iacol];
    }
    emxFree_real_T(&pinvA);
    /*  nested function end */
    emlrtHeapReferenceStackLeaveFcn();
}

/*
 * function Dvec = movingslope(vec,supportlength,modelorder,dt)
 */
void movingslope(const emxArray_real_T *vec, real_T supportlength, emxArray_real_T *Dvec)
{
    int32_T parity;
    real_T s;
    boolean_T innerDimOk;
    real_T bnew;
    real_T anew;
    int32_T n;
    const mxArray *y;
    static const int32_T iv4[2] = { 1, 21 };
    const mxArray *m3;
    static const char_T cv3[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };
    emxArray_real_T *coef;
    int32_T i1;
    int32_T nm1;
    int32_T nm1d2;
    int32_T k;
    emxArray_real_T *b_coef;
    int32_T loop_ub;
    emxArray_real_T *c_coef;
    emxArray_real_T *f;
    uint32_T uv0[2];
    int32_T i;
    const mxArray *b_y;
    static const int32_T iv5[2] = { 1, 21 };
    int32_T b_vec;
    emxArray_int32_T *r2;
    emxArray_int32_T *r3;
    emxArray_real_T *b_f;
    int32_T iv6[2];
    emxArray_int32_T r4;
    emxArray_int32_T *r5;
    emxArray_real_T *b;
    emxArray_real_T *d_coef;
    emxArray_real_T *e_coef;
    emxArray_int32_T *r6;
    emxArray_int32_T *r7;
    emxArray_int32_T *r8;
    emxArray_int32_T *r9;
    emxArray_int32_T *r10;
    emxArray_int32_T *r11;
    emxArray_int32_T *r12;
    emxArray_real_T *c_vec;
    emxArray_real_T *d_vec;
    emxArray_real_T *e_vec;
    emxArray_real_T *f_vec;
    emxArray_real_T *g_vec;
    emxArray_real_T *h_vec;
    emxArray_real_T *i_vec;
    const mxArray *c_y;
    static const int32_T iv7[2] = { 1, 21 };
    boolean_T guard4 = FALSE;
    const mxArray *d_y;
    static const int32_T iv8[2] = { 1, 21 };
    static const char_T cv4[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'n', 'n', 'e', 'r', 'd', 'i', 'm' };
    const mxArray *e_y;
    static const int32_T iv9[2] = { 1, 45 };
    static const char_T cv5[45] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'm', 't', 'i', 'm', 'e', 's', '_', 'n', 'o', 'D', 'y', 'n', 'a', 'm', 'i', 'c', 'S', 'c', 'a', 'l', 'a', 'r', 'E', 'x', 'p', 'a', 'n', 's', 'i', 'o', 'n' };
    boolean_T guard3 = FALSE;
    const mxArray *f_y;
    static const int32_T iv10[2] = { 1, 21 };
    const mxArray *g_y;
    static const int32_T iv11[2] = { 1, 21 };
    boolean_T guard2 = FALSE;
    const mxArray *h_y;
    static const int32_T iv12[2] = { 1, 21 };
    const mxArray *i_y;
    static const int32_T iv13[2] = { 1, 45 };
    boolean_T guard1 = FALSE;
    emlrtHeapReferenceStackEnterFcn();
    /*  movingslope: estimate local slope for a sequence of points, using a sliding window */
    /*  usage: Dvec = movingslope(vec) */
    /*  usage: Dvec = movingslope(vec,supportlength) */
    /*  usage: Dvec = movingslope(vec,supportlength,modelorder) */
    /*  usage: Dvec = movingslope(vec,supportlength,modelorder,dt) */
    /*  */
    /*  */
    /*  movingslope uses filter to determine the slope of a curve stored */
    /*  as an equally (unit) spaced sequence of points. A patch is applied */
    /*  at each end where filter will have problems. A non-unit spacing */
    /*  can be supplied. */
    /*  */
    /*  Note that with a 3 point window and equally spaced data sequence, */
    /*  this code should be similar to gradient. However, with wider */
    /*  windows this tool will be more robust to noisy data sequences. */
    /*  */
    /*  */
    /*  arguments: (input) */
    /*   vec - row of column vector, to be differentiated. vec must be of */
    /*         length at least 2. */
    /*  */
    /*   supportlength - (OPTIONAL) scalar integer - defines the number of */
    /*         points used for the moving window. supportlength may be no */
    /*         more than the length of vec. */
    /*  */
    /*         supportlength must be at least 2, but no more than length(vec) */
    /*  */
    /*         If supportlength is an odd number, then the sliding window */
    /*         will be central. If it is an even number, then the window */
    /*         will be slid backwards by one element. Thus a 2 point window */
    /*         will result in a backwards differences used, except at the */
    /*         very first point, where a forward difference will be used. */
    /*  */
    /*         DEFAULT: supportlength = 3 */
    /*  */
    /*   modelorder - (OPTIONAL) - scalar - Defines the order of the windowed */
    /*         model used to estimate the slope. When model order is 1, the */
    /*         model is a linear one. If modelorder is less than supportlength-1. */
    /*         then the sliding window will be a regression one. If modelorder */
    /*         is equal to supportlength-1, then the window will result in a */
    /*         sliding Lagrange interpolant. */
    /*  */
    /*         modelorder must be at least 1, but not exceeding */
    /*         min(10,supportlength-1) */
    /*  */
    /*         DEFAULT: modelorder = 1 */
    /*  */
    /*   dt - (OPTIONAL) - scalar - spacing for sequences which do not have */
    /*         a unit spacing. */
    /*  */
    /*         DEFAULT: dt = 1 */
    /*  */
    /*  arguments: (output) */
    /*   Dvec = vector of derivative estimates, Dvec will be of the same size */
    /*         and shape as is vec. */
    /*   */
    /*  */
    /*  Example: */
    /*   Estimate the first derivative using a 7 point window with first through */
    /*   fourth order models in the sliding window. Note that the higher order */
    /*   approximations provide better accuracy on this curve with no noise. */
    /*    */
    /*   t = 0:.1:1; */
    /*   vec = exp(t); */
    /*  */
    /*   Dvec = movingslope(vec,7,1,.1) */
    /*   Dvec = */
    /*   Columns 1 through 7 */
    /*     1.3657  1.3657  1.3657  1.3657  1.5093  1.668  1.8435 */
    /*   Columns 8 through 11 */
    /*     2.0373  2.0373  2.0373  2.0373 */
    /*  */
    /*   Dvec = movingslope(vec,7,2,.1) */
    /*   Dvec = */
    /*   Columns 1 through 7 */
    /*     0.95747 1.0935  1.2296  1.3657  1.5093  1.668  1.8435 */
    /*   Columns 8 through 11 */
    /*     2.0373  2.2403  2.4433  2.6463 */
    /*  */
    /*   Dvec = movingslope(vec,7,3,.1) */
    /*   Dvec = */
    /*   Columns 1 through 7 */
    /*     1.0027  1.1049  1.2206  1.3498  1.4918  1.6487  1.8221 */
    /*   Columns 8 through 11 */
    /*     2.0137  2.2268  2.4602  2.7138 */
    /*  */
    /*   Dvec = movingslope(vec,7,4,.1) */
    /*   Dvec = */
    /*     Columns 1 through 7 */
    /*     0.99988 1.1052  1.2214  1.3498  1.4918  1.6487  1.8221 */
    /*   Columns 8 through 11 */
    /*     2.0137  2.2255  2.4597  2.7181 */
    /*  */
    /*  */
    /*  Example: */
    /*   Estimate the slope of a noisy curve, using a locally quadratic */
    /*   approximation. In this case, use a straight line so that we know */
    /*   the true slope should be 1. Use a wide window, since we have */
    /*   noisy data. */
    /*    */
    /*   t = 0:100; */
    /*   vec = t + randn(size(t)); */
    /*   Dvec = movingslope(vec,10,2,1) */
    /*   mean(Dvec) */
    /*   ans =  */
    /*      1.0013 */
    /*   std(Dvec) */
    /*   ans = */
    /*      0.10598 */
    /*  */
    /*   By way of comparison, gradient gives a much noisier estimate */
    /*   of the slope of this curve. */
    /*  */
    /*   std(gradient(vec)) */
    /*   ans = */
    /*      0.69847 */
    /*  */
    /*  */
    /*  Example: */
    /*   As a time test, generate random data vector of length 500000. */
    /*   Compute the slopes using a window of width 10. */
    /*  */
    /*   vec = rand(1,500000); */
    /*   tic */
    /*   Dvec = movingslope(vec,10,2); */
    /*   toc */
    /*  */
    /*   Elapsed time is 0.626021 seconds. */
    /*  */
    /*  */
    /*  See also: gradient */
    /*  */
    /*  */
    /*  Author: John D'Errico */
    /*  e-mail: woodchips@rochester.rr.com */
    /*  Release: 1.0 */
    /*  Release date: 10/19/07 */
    /*  how long is vec? is it a vector? */
    /* 'movingslope:141' if (nargin==0) */
    /* 'movingslope:145' if ~isvector(vec) */
    /* 'movingslope:148' n = length(vec); */
    EMLRTPUSHRTSTACK(&g_emlrtRSI);
    EMLRTPOPRTSTACK(&g_emlrtRSI);
    /*  supply defaults */
    /* 'movingslope:151' if (nargin<4) || isempty(dt) */
    /* 'movingslope:154' if (nargin<3) || isempty(modelorder) */
    /* 'movingslope:157' if (nargin<2) || isempty(supportlength) */
    /*  check the parameters for problems */
    /* 'movingslope:162' if (length(supportlength)~=1) || (supportlength<=1) || (supportlength>n) || (supportlength~=floor(supportlength)) */
    if ((supportlength <= 1.0) || (supportlength > (real_T)vec->size[1]) || (supportlength != muDoubleScalarFloor(supportlength))) {
        EMLRTPUSHRTSTACK(&h_emlrtRSI);
        error();
        EMLRTPOPRTSTACK(&h_emlrtRSI);
        /* 'movingslope:163' error('supportlength must be a scalar integer, >= 2, and no more than length(vec)') */
    }
    /* 'movingslope:165' if (length(modelorder)~=1) || (modelorder<1) || (modelorder>min(10,supportlength-1)) || (modelorder~=floor(modelorder)) */
    if (1.0 > muDoubleScalarMin(10.0, supportlength - 1.0)) {
        EMLRTPUSHRTSTACK(&i_emlrtRSI);
        b_error();
        EMLRTPOPRTSTACK(&i_emlrtRSI);
        /* 'movingslope:166' error('modelorder must be a scalar integer, >= 1, and no more than min(10,supportlength-1)') */
    }
    /* 'movingslope:168' if (length(dt)~=1) || (dt<0) */
    /*  now build the filter coefficients to estimate the slope */
    /* 'movingslope:173' if mod(supportlength,2) == 1 */
    if (b_mod(supportlength, 2.0) == 1.0) {
        /* 'movingslope:174' parity = 1; */
        parity = 1;
        /*  odd parity */
    } else {
        /* 'movingslope:175' else */
        /* 'movingslope:176' parity = 0; */
        parity = 0;
    }
    /* 'movingslope:178' s = (supportlength-parity)/2; */
    s = mrdivide(supportlength - (real_T)parity, 2.0);
    /* 'movingslope:179' t = ((-s+1-parity):s)'; */
    EMLRTPUSHRTSTACK(&j_emlrtRSI);
    EMLRTPUSHRTSTACK(&u_emlrtRSI);
    EMLRTPUSHRTSTACK(&v_emlrtRSI);
    float_colon_length((-s + 1.0) - (real_T)parity, s, &n, &anew, &bnew, &innerDimOk);
    EMLRTPUSHRTSTACK(&w_emlrtRSI);
    if (!innerDimOk) {
    } else {
        EMLRTPUSHRTSTACK(&x_emlrtRSI);
        y = NULL;
        m3 = mxCreateCharArray(2, iv4);
        emlrtInitCharArray(21, m3, cv3);
        emlrtAssign(&y, m3);
        c_error(message(y, &d_emlrtMCI), &e_emlrtMCI);
        EMLRTPOPRTSTACK(&x_emlrtRSI);
    }
    emxInit_real_T(&coef, 2, &i_emlrtRTEI, TRUE);
    EMLRTPOPRTSTACK(&w_emlrtRSI);
    emlrtNonNegativeCheckR2009b((real_T)n, &g_emlrtDCI);
    i1 = coef->size[0] * coef->size[1];
    coef->size[0] = 1;
    coef->size[1] = n;
    emxEnsureCapacity((emxArray__common *)coef, i1, (int32_T)sizeof(real_T), &f_emlrtRTEI);
    if (n > 0) {
        emlrtDynamicBoundsCheck(1, 1, coef->size[1], &u_emlrtBCI);
        coef->data[0] = anew;
        if (n > 1) {
            coef->data[emlrtDynamicBoundsCheck(n, 1, coef->size[1], &bb_emlrtBCI) - 1] = bnew;
            nm1 = n - 1;
            i1 = nm1;
            nm1d2 = (int32_T)((uint32_T)i1 >> 1);
            for (k = 1; k <= nm1d2 - 1; k++) {
                coef->data[emlrtDynamicBoundsCheck(k + 1, 1, coef->size[1], &ic_emlrtBCI) - 1] = anew + (real_T)k;
                coef->data[emlrtDynamicBoundsCheck(n - k, 1, coef->size[1], &jc_emlrtBCI) - 1] = bnew - (real_T)k;
            }
            if (nm1d2 << 1 == nm1) {
                coef->data[emlrtDynamicBoundsCheck(nm1d2 + 1, 1, coef->size[1], &eb_emlrtBCI) - 1] = (anew + bnew) / 2.0;
            } else {
                coef->data[emlrtDynamicBoundsCheck(nm1d2 + 1, 1, coef->size[1], &cb_emlrtBCI) - 1] = anew + (real_T)nm1d2;
                coef->data[emlrtDynamicBoundsCheck(nm1d2 + 2, 1, coef->size[1], &db_emlrtBCI) - 1] = bnew - (real_T)nm1d2;
            }
        }
    }
    b_emxInit_real_T(&b_coef, 1, &g_emlrtRTEI, TRUE);
    EMLRTPOPRTSTACK(&v_emlrtRSI);
    EMLRTPOPRTSTACK(&u_emlrtRSI);
    EMLRTPOPRTSTACK(&j_emlrtRSI);
    /* 'movingslope:180' coef = getcoef(t,supportlength,modelorder); */
    EMLRTPUSHRTSTACK(&k_emlrtRSI);
    i1 = b_coef->size[0];
    b_coef->size[0] = coef->size[1];
    emxEnsureCapacity((emxArray__common *)b_coef, i1, (int32_T)sizeof(real_T), &g_emlrtRTEI);
    loop_ub = coef->size[1] - 1;
    for (i1 = 0; i1 <= loop_ub; i1++) {
        b_coef->data[i1] = coef->data[i1];
    }
    emxInit_real_T(&c_coef, 2, &g_emlrtRTEI, TRUE);
    getcoef(b_coef, supportlength, coef);
    EMLRTPOPRTSTACK(&k_emlrtRSI);
    /*  Apply the filter to the entire vector */
    /* 'movingslope:183' f = filter(-coef,1,vec); */
    EMLRTPUSHRTSTACK(&l_emlrtRSI);
    i1 = c_coef->size[0] * c_coef->size[1];
    c_coef->size[0] = 1;
    c_coef->size[1] = coef->size[1];
    emxEnsureCapacity((emxArray__common *)c_coef, i1, (int32_T)sizeof(real_T), &g_emlrtRTEI);
    emxFree_real_T(&b_coef);
    loop_ub = coef->size[0] * coef->size[1] - 1;
    for (i1 = 0; i1 <= loop_ub; i1++) {
        c_coef->data[i1] = -coef->data[i1];
    }
    emxInit_real_T(&f, 2, &j_emlrtRTEI, TRUE);
    filter(c_coef, vec, f);
    EMLRTPOPRTSTACK(&l_emlrtRSI);
    /* 'movingslope:184' Dvec = zeros(size(vec)); */
    emxFree_real_T(&c_coef);
    for (i1 = 0; i1 < 2; i1++) {
        uv0[i1] = (uint32_T)vec->size[i1];
    }
    i1 = Dvec->size[0] * Dvec->size[1];
    Dvec->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)Dvec, i1, (int32_T)sizeof(real_T), &g_emlrtRTEI);
    i1 = Dvec->size[0] * Dvec->size[1];
    Dvec->size[1] = (int32_T)uv0[1];
    emxEnsureCapacity((emxArray__common *)Dvec, i1, (int32_T)sizeof(real_T), &g_emlrtRTEI);
    loop_ub = (int32_T)uv0[1] - 1;
    for (i1 = 0; i1 <= loop_ub; i1++) {
        Dvec->data[i1] = 0.0;
    }
    /* 'movingslope:185' Dvec(s+(1:(n-supportlength+1))) = f(supportlength:end); */
    emlrtBoundsCheck(f->size[1], &ab_emlrtBCI);
    if (supportlength > (real_T)f->size[1]) {
        i1 = 1;
        i = 0;
    } else {
        i1 = emlrtDynamicBoundsCheck((int32_T)emlrtIntegerCheckR2009b(supportlength, &i_emlrtDCI), 1, f->size[1], &y_emlrtBCI);
        i = emlrtDynamicBoundsCheck(f->size[1], 1, f->size[1], &x_emlrtBCI);
    }
    EMLRTPUSHRTSTACK(&t_emlrtRSI);
    EMLRTPUSHRTSTACK(&gj_emlrtRSI);
    EMLRTPUSHRTSTACK(&hj_emlrtRSI);
    float_colon_length(1.0, ((real_T)vec->size[1] - supportlength) + 1.0, &n, &anew, &bnew, &innerDimOk);
    EMLRTPUSHRTSTACK(&ij_emlrtRSI);
    if (!innerDimOk) {
    } else {
        EMLRTPUSHRTSTACK(&x_emlrtRSI);
        b_y = NULL;
        m3 = mxCreateCharArray(2, iv5);
        emlrtInitCharArray(21, m3, cv3);
        emlrtAssign(&b_y, m3);
        c_error(message(b_y, &d_emlrtMCI), &e_emlrtMCI);
        EMLRTPOPRTSTACK(&x_emlrtRSI);
    }
    EMLRTPOPRTSTACK(&ij_emlrtRSI);
    emlrtNonNegativeCheckR2009b((real_T)n, &f_emlrtDCI);
    b_vec = coef->size[0] * coef->size[1];
    coef->size[0] = 1;
    coef->size[1] = n;
    emxEnsureCapacity((emxArray__common *)coef, b_vec, (int32_T)sizeof(real_T), &emlrtRTEI);
    if (n > 0) {
        emlrtDynamicBoundsCheck(1, 1, coef->size[1], &t_emlrtBCI);
        coef->data[0] = anew;
        if (n > 1) {
            coef->data[emlrtDynamicBoundsCheck(n, 1, coef->size[1], &fb_emlrtBCI) - 1] = bnew;
            nm1 = n - 1;
            b_vec = nm1;
            nm1d2 = (int32_T)((uint32_T)b_vec >> 1);
            for (k = 1; k <= nm1d2 - 1; k++) {
                coef->data[emlrtDynamicBoundsCheck(k + 1, 1, coef->size[1], &gc_emlrtBCI) - 1] = anew + (real_T)k;
                coef->data[emlrtDynamicBoundsCheck(n - k, 1, coef->size[1], &hc_emlrtBCI) - 1] = bnew - (real_T)k;
            }
            if (nm1d2 << 1 == nm1) {
                coef->data[emlrtDynamicBoundsCheck(nm1d2 + 1, 1, coef->size[1], &ib_emlrtBCI) - 1] = (anew + bnew) / 2.0;
            } else {
                coef->data[emlrtDynamicBoundsCheck(nm1d2 + 1, 1, coef->size[1], &gb_emlrtBCI) - 1] = anew + (real_T)nm1d2;
                coef->data[emlrtDynamicBoundsCheck(nm1d2 + 2, 1, coef->size[1], &hb_emlrtBCI) - 1] = bnew - (real_T)nm1d2;
            }
        }
    }
    emxInit_int32_T(&r2, 2, &g_emlrtRTEI, TRUE);
    EMLRTPOPRTSTACK(&hj_emlrtRSI);
    EMLRTPOPRTSTACK(&gj_emlrtRSI);
    b_vec = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = coef->size[1];
    emxEnsureCapacity((emxArray__common *)r2, b_vec, (int32_T)sizeof(int32_T), &g_emlrtRTEI);
    loop_ub = coef->size[0] * coef->size[1] - 1;
    for (b_vec = 0; b_vec <= loop_ub; b_vec++) {
        r2->data[b_vec] = emlrtDynamicBoundsCheck((int32_T)emlrtIntegerCheckR2009b(s + coef->data[b_vec], &j_emlrtDCI), 1, (int32_T)uv0[1], &jb_emlrtBCI);
    }
    b_emxInit_int32_T(&r3, 1, &g_emlrtRTEI, TRUE);
    EMLRTPOPRTSTACK(&t_emlrtRSI);
    b_vec = r3->size[0];
    r3->size[0] = (i - i1) + 1;
    emxEnsureCapacity((emxArray__common *)r3, b_vec, (int32_T)sizeof(int32_T), &g_emlrtRTEI);
    loop_ub = i - i1;
    for (b_vec = 0; b_vec <= loop_ub; b_vec++) {
        r3->data[b_vec] = i1 + b_vec;
    }
    emxInit_real_T(&b_f, 2, &g_emlrtRTEI, TRUE);
    iv6[0] = 1;
    iv6[1] = r3->size[0];
    b_vec = b_f->size[0] * b_f->size[1];
    b_f->size[0] = iv6[0];
    b_f->size[1] = iv6[1];
    emxEnsureCapacity((emxArray__common *)b_f, b_vec, (int32_T)sizeof(real_T), &g_emlrtRTEI);
    loop_ub = iv6[1] - 1;
    for (b_vec = 0; b_vec <= loop_ub; b_vec++) {
        nm1d2 = iv6[0] - 1;
        for (n = 0; n <= nm1d2; n++) {
            r4 = *r3;
            r4.size = (int32_T *)&iv6;
            r4.numDimensions = 1;
            b_f->data[n + b_f->size[0] * b_vec] = f->data[r4.data[n + r4.size[0] * b_vec] - 1];
        }
    }
    emxFree_int32_T(&r3);
    b_emxInit_int32_T(&r5, 1, &g_emlrtRTEI, TRUE);
    emlrtSizeEqCheck1D(r2->size[1], b_f->size[1], &emlrtECI);
    b_vec = r5->size[0];
    r5->size[0] = (i - i1) + 1;
    emxEnsureCapacity((emxArray__common *)r5, b_vec, (int32_T)sizeof(int32_T), &g_emlrtRTEI);
    emxFree_real_T(&b_f);
    loop_ub = i - i1;
    for (i = 0; i <= loop_ub; i++) {
        r5->data[i] = i1 + i;
    }
    loop_ub = r5->size[0] - 1;
    for (i1 = 0; i1 <= loop_ub; i1++) {
        Dvec->data[r2->data[i1] - 1] = f->data[r5->data[i1] - 1];
    }
    emxFree_int32_T(&r5);
    /*  patch each end */
    /* 'movingslope:188' vec = vec(:); */
    /* 'movingslope:189' for i = 1:s */
    emlrtForLoopVectorCheckR2011b(1.0, 1.0, s, mxDOUBLE_CLASS, (int32_T)s, &dc_emlrtRTEI, &emlrtContextGlobal, 0);
    i = 0;
    b_emxInit_real_T(&b, 1, &g_emlrtRTEI, TRUE);
    b_emxInit_real_T(&d_coef, 1, &g_emlrtRTEI, TRUE);
    b_emxInit_real_T(&e_coef, 1, &g_emlrtRTEI, TRUE);
    b_emxInit_int32_T(&r6, 1, &g_emlrtRTEI, TRUE);
    emxInit_int32_T(&r7, 2, &g_emlrtRTEI, TRUE);
    emxInit_int32_T(&r8, 2, &g_emlrtRTEI, TRUE);
    emxInit_int32_T(&r9, 2, &g_emlrtRTEI, TRUE);
    emxInit_int32_T(&r10, 2, &g_emlrtRTEI, TRUE);
    emxInit_int32_T(&r11, 2, &g_emlrtRTEI, TRUE);
    emxInit_int32_T(&r12, 2, &g_emlrtRTEI, TRUE);
    b_emxInit_real_T(&c_vec, 1, &g_emlrtRTEI, TRUE);
    b_emxInit_real_T(&d_vec, 1, &g_emlrtRTEI, TRUE);
    b_emxInit_real_T(&e_vec, 1, &g_emlrtRTEI, TRUE);
    b_emxInit_real_T(&f_vec, 1, &g_emlrtRTEI, TRUE);
    b_emxInit_real_T(&g_vec, 1, &g_emlrtRTEI, TRUE);
    b_emxInit_real_T(&h_vec, 1, &g_emlrtRTEI, TRUE);
    b_emxInit_real_T(&i_vec, 1, &g_emlrtRTEI, TRUE);
    while (i <= (int32_T)s - 1) {
        /*  patch the first few points */
        /* 'movingslope:191' t = (1:supportlength)' - i; */
        EMLRTPUSHRTSTACK(&m_emlrtRSI);
        EMLRTPUSHRTSTACK(&gj_emlrtRSI);
        EMLRTPUSHRTSTACK(&hj_emlrtRSI);
        float_colon_length(1.0, supportlength, &n, &anew, &bnew, &innerDimOk);
        EMLRTPUSHRTSTACK(&ij_emlrtRSI);
        if (!innerDimOk) {
        } else {
            EMLRTPUSHRTSTACK(&x_emlrtRSI);
            c_y = NULL;
            m3 = mxCreateCharArray(2, iv7);
            emlrtInitCharArray(21, m3, cv3);
            emlrtAssign(&c_y, m3);
            c_error(message(c_y, &d_emlrtMCI), &e_emlrtMCI);
            EMLRTPOPRTSTACK(&x_emlrtRSI);
        }
        EMLRTPOPRTSTACK(&ij_emlrtRSI);
        emlrtNonNegativeCheckR2009b((real_T)n, &e_emlrtDCI);
        i1 = coef->size[0] * coef->size[1];
        coef->size[0] = 1;
        coef->size[1] = n;
        emxEnsureCapacity((emxArray__common *)coef, i1, (int32_T)sizeof(real_T), &emlrtRTEI);
        if (n > 0) {
            emlrtDynamicBoundsCheck(1, 1, coef->size[1], &s_emlrtBCI);
            coef->data[0] = anew;
            if (n > 1) {
                coef->data[emlrtDynamicBoundsCheck(n, 1, coef->size[1], &kb_emlrtBCI) - 1] = bnew;
                nm1 = n - 1;
                i1 = nm1;
                nm1d2 = (int32_T)((uint32_T)i1 >> 1);
                for (k = 1; k <= nm1d2 - 1; k++) {
                    coef->data[emlrtDynamicBoundsCheck(k + 1, 1, coef->size[1], &ec_emlrtBCI) - 1] = anew + (real_T)k;
                    coef->data[emlrtDynamicBoundsCheck(n - k, 1, coef->size[1], &fc_emlrtBCI) - 1] = bnew - (real_T)k;
                }
                if (nm1d2 << 1 == nm1) {
                    coef->data[emlrtDynamicBoundsCheck(nm1d2 + 1, 1, coef->size[1], &nb_emlrtBCI) - 1] = (anew + bnew) / 2.0;
                } else {
                    coef->data[emlrtDynamicBoundsCheck(nm1d2 + 1, 1, coef->size[1], &lb_emlrtBCI) - 1] = anew + (real_T)nm1d2;
                    coef->data[emlrtDynamicBoundsCheck(nm1d2 + 2, 1, coef->size[1], &mb_emlrtBCI) - 1] = bnew - (real_T)nm1d2;
                }
            }
        }
        EMLRTPOPRTSTACK(&hj_emlrtRSI);
        EMLRTPOPRTSTACK(&gj_emlrtRSI);
        EMLRTPOPRTSTACK(&m_emlrtRSI);
        /* 'movingslope:192' coef = getcoef(t,supportlength,modelorder); */
        EMLRTPUSHRTSTACK(&n_emlrtRSI);
        i1 = e_coef->size[0];
        e_coef->size[0] = coef->size[1];
        emxEnsureCapacity((emxArray__common *)e_coef, i1, (int32_T)sizeof(real_T), &g_emlrtRTEI);
        loop_ub = coef->size[1] - 1;
        for (i1 = 0; i1 <= loop_ub; i1++) {
            e_coef->data[i1] = coef->data[i1] - (1.0 + (real_T)i);
        }
        getcoef(e_coef, supportlength, coef);
        EMLRTPOPRTSTACK(&n_emlrtRSI);
        /* 'movingslope:194' Dvec(i) = coef*vec(1:supportlength); */
        nm1d2 = vec->size[1];
        emlrtDynamicBoundsCheck(1, 1, nm1d2, &w_emlrtBCI);
        nm1d2 = vec->size[1];
        emlrtDynamicBoundsCheck((int32_T)emlrtIntegerCheckR2009b(supportlength, &h_emlrtDCI), 1, nm1d2, &v_emlrtBCI);
        i1 = r6->size[0];
        r6->size[0] = (int32_T)supportlength;
        emxEnsureCapacity((emxArray__common *)r6, i1, (int32_T)sizeof(int32_T), &g_emlrtRTEI);
        loop_ub = (int32_T)supportlength - 1;
        for (i1 = 0; i1 <= loop_ub; i1++) {
            r6->data[i1] = 1 + i1;
        }
        i1 = r2->size[0] * r2->size[1];
        r2->size[0] = 1;
        emxEnsureCapacity((emxArray__common *)r2, i1, (int32_T)sizeof(int32_T), &g_emlrtRTEI);
        nm1d2 = r6->size[0];
        i1 = r2->size[0] * r2->size[1];
        r2->size[1] = nm1d2;
        emxEnsureCapacity((emxArray__common *)r2, i1, (int32_T)sizeof(int32_T), &g_emlrtRTEI);
        loop_ub = r6->size[0] - 1;
        for (i1 = 0; i1 <= loop_ub; i1++) {
            r2->data[i1] = r6->data[i1];
        }
        nm1d2 = vec->size[1];
        emlrtVectorVectorIndexCheck(nm1d2, 1, 1, r2->size[1], &c_emlrtECI);
        EMLRTPUSHRTSTACK(&o_emlrtRSI);
        i1 = b->size[0];
        b->size[0] = r2->size[1];
        emxEnsureCapacity((emxArray__common *)b, i1, (int32_T)sizeof(real_T), &g_emlrtRTEI);
        loop_ub = r2->size[1] - 1;
        for (i1 = 0; i1 <= loop_ub; i1++) {
            b->data[i1] = vec->data[r2->data[i1] - 1];
        }
        EMLRTPUSHRTSTACK(&kj_emlrtRSI);
        nm1d2 = r2->size[1];
        i1 = c_vec->size[0];
        c_vec->size[0] = nm1d2;
        emxEnsureCapacity((emxArray__common *)c_vec, i1, (int32_T)sizeof(real_T), &g_emlrtRTEI);
        loop_ub = nm1d2 - 1;
        for (i1 = 0; i1 <= loop_ub; i1++) {
            c_vec->data[i1] = vec->data[r2->data[i1] - 1];
        }
        innerDimOk = (coef->size[1] == c_vec->size[0]);
        if (!innerDimOk) {
            guard4 = FALSE;
            if (coef->size[1] == 1) {
                guard4 = TRUE;
            } else {
                nm1d2 = r2->size[1];
                i1 = d_vec->size[0];
                d_vec->size[0] = nm1d2;
                emxEnsureCapacity((emxArray__common *)d_vec, i1, (int32_T)sizeof(real_T), &g_emlrtRTEI);
                loop_ub = nm1d2 - 1;
                for (i1 = 0; i1 <= loop_ub; i1++) {
                    d_vec->data[i1] = vec->data[r2->data[i1] - 1];
                }
                if (d_vec->size[0] == 1) {
                    guard4 = TRUE;
                } else {
                    EMLRTPUSHRTSTACK(&mj_emlrtRSI);
                    d_y = NULL;
                    m3 = mxCreateCharArray(2, iv8);
                    emlrtInitCharArray(21, m3, cv4);
                    emlrtAssign(&d_y, m3);
                    c_error(message(d_y, &ab_emlrtMCI), &bb_emlrtMCI);
                    EMLRTPOPRTSTACK(&mj_emlrtRSI);
                }
            }
            if (guard4 == TRUE) {
                EMLRTPUSHRTSTACK(&lj_emlrtRSI);
                e_y = NULL;
                m3 = mxCreateCharArray(2, iv9);
                emlrtInitCharArray(45, m3, cv5);
                emlrtAssign(&e_y, m3);
                c_error(message(e_y, &x_emlrtMCI), &y_emlrtMCI);
                EMLRTPOPRTSTACK(&lj_emlrtRSI);
            }
        }
        EMLRTPOPRTSTACK(&kj_emlrtRSI);
        guard3 = FALSE;
        if (coef->size[1] == 1) {
            guard3 = TRUE;
        } else {
            nm1d2 = r2->size[1];
            i1 = e_vec->size[0];
            e_vec->size[0] = nm1d2;
            emxEnsureCapacity((emxArray__common *)e_vec, i1, (int32_T)sizeof(real_T), &g_emlrtRTEI);
            loop_ub = nm1d2 - 1;
            for (i1 = 0; i1 <= loop_ub; i1++) {
                e_vec->data[i1] = vec->data[r2->data[i1] - 1];
            }
            if (e_vec->size[0] == 1) {
                guard3 = TRUE;
            } else {
                k = coef->size[1];
                EMLRTPUSHRTSTACK(&jj_emlrtRSI);
                EMLRTPUSHRTSTACK(&nj_emlrtRSI);
                EMLRTPUSHRTSTACK(&oj_emlrtRSI);
                if (k < 1) {
                    anew = 0.0;
                } else {
                    EMLRTPUSHRTSTACK(&qj_emlrtRSI);
                    n = 1;
                    nm1 = 1;
                    emlrtDynamicBoundsCheck(1, 1, coef->size[1], &r_emlrtBCI);
                    anew = ddot32(&k, &coef->data[0], &n, &b->data[0], &nm1);
                    EMLRTPOPRTSTACK(&qj_emlrtRSI);
                }
                EMLRTPOPRTSTACK(&oj_emlrtRSI);
                EMLRTPOPRTSTACK(&nj_emlrtRSI);
                EMLRTPOPRTSTACK(&jj_emlrtRSI);
            }
        }
        if (guard3 == TRUE) {
            anew = 0.0;
            loop_ub = coef->size[1] - 1;
            for (i1 = 0; i1 <= loop_ub; i1++) {
                anew += coef->data[coef->size[0] * i1] * vec->data[r2->data[i1] - 1];
            }
        }
        Dvec->data[emlrtDynamicBoundsCheck((int32_T)(1.0 + (real_T)i), 1, Dvec->size[1], &ob_emlrtBCI) - 1] = anew;
        EMLRTPOPRTSTACK(&o_emlrtRSI);
        /*  patch the end points */
        /* 'movingslope:197' if i<(s + parity) */
        if (1.0 + (real_T)i < s + (real_T)parity) {
            /* 'movingslope:198' t = (1:supportlength)' - supportlength + i - 1; */
            EMLRTPUSHRTSTACK(&p_emlrtRSI);
            EMLRTPUSHRTSTACK(&gj_emlrtRSI);
            EMLRTPUSHRTSTACK(&hj_emlrtRSI);
            float_colon_length(1.0, supportlength, &n, &anew, &bnew, &innerDimOk);
            EMLRTPUSHRTSTACK(&ij_emlrtRSI);
            if (!innerDimOk) {
            } else {
                EMLRTPUSHRTSTACK(&x_emlrtRSI);
                f_y = NULL;
                m3 = mxCreateCharArray(2, iv10);
                emlrtInitCharArray(21, m3, cv3);
                emlrtAssign(&f_y, m3);
                c_error(message(f_y, &d_emlrtMCI), &e_emlrtMCI);
                EMLRTPOPRTSTACK(&x_emlrtRSI);
            }
            EMLRTPOPRTSTACK(&ij_emlrtRSI);
            emlrtNonNegativeCheckR2009b((real_T)n, &d_emlrtDCI);
            i1 = coef->size[0] * coef->size[1];
            coef->size[0] = 1;
            coef->size[1] = n;
            emxEnsureCapacity((emxArray__common *)coef, i1, (int32_T)sizeof(real_T), &emlrtRTEI);
            if (n > 0) {
                emlrtDynamicBoundsCheck(1, 1, coef->size[1], &q_emlrtBCI);
                coef->data[0] = anew;
                if (n > 1) {
                    coef->data[emlrtDynamicBoundsCheck(n, 1, coef->size[1], &pb_emlrtBCI) - 1] = bnew;
                    nm1 = n - 1;
                    i1 = nm1;
                    nm1d2 = (int32_T)((uint32_T)i1 >> 1);
                    for (k = 1; k <= nm1d2 - 1; k++) {
                        coef->data[emlrtDynamicBoundsCheck(k + 1, 1, coef->size[1], &cc_emlrtBCI) - 1] = anew + (real_T)k;
                        coef->data[emlrtDynamicBoundsCheck(n - k, 1, coef->size[1], &dc_emlrtBCI) - 1] = bnew - (real_T)k;
                    }
                    if (nm1d2 << 1 == nm1) {
                        coef->data[emlrtDynamicBoundsCheck(nm1d2 + 1, 1, coef->size[1], &sb_emlrtBCI) - 1] = (anew + bnew) / 2.0;
                    } else {
                        coef->data[emlrtDynamicBoundsCheck(nm1d2 + 1, 1, coef->size[1], &qb_emlrtBCI) - 1] = anew + (real_T)nm1d2;
                        coef->data[emlrtDynamicBoundsCheck(nm1d2 + 2, 1, coef->size[1], &rb_emlrtBCI) - 1] = bnew - (real_T)nm1d2;
                    }
                }
            }
            EMLRTPOPRTSTACK(&hj_emlrtRSI);
            EMLRTPOPRTSTACK(&gj_emlrtRSI);
            EMLRTPOPRTSTACK(&p_emlrtRSI);
            /* 'movingslope:199' coef = getcoef(t,supportlength,modelorder); */
            EMLRTPUSHRTSTACK(&q_emlrtRSI);
            i1 = d_coef->size[0];
            d_coef->size[0] = coef->size[1];
            emxEnsureCapacity((emxArray__common *)d_coef, i1, (int32_T)sizeof(real_T), &g_emlrtRTEI);
            loop_ub = coef->size[1] - 1;
            for (i1 = 0; i1 <= loop_ub; i1++) {
                d_coef->data[i1] = ((coef->data[i1] - supportlength) + (1.0 + (real_T)i)) - 1.0;
            }
            getcoef(d_coef, supportlength, coef);
            EMLRTPOPRTSTACK(&q_emlrtRSI);
            /* 'movingslope:200' Dvec(n - i + 1) = coef*vec(n + (0:(supportlength-1)) + 1 - supportlength); */
            EMLRTPUSHRTSTACK(&r_emlrtRSI);
            EMLRTPUSHRTSTACK(&sj_emlrtRSI);
            EMLRTPUSHRTSTACK(&tj_emlrtRSI);
            float_colon_length(0.0, supportlength - 1.0, &n, &anew, &bnew, &innerDimOk);
            EMLRTPUSHRTSTACK(&uj_emlrtRSI);
            if (!innerDimOk) {
            } else {
                EMLRTPUSHRTSTACK(&x_emlrtRSI);
                g_y = NULL;
                m3 = mxCreateCharArray(2, iv11);
                emlrtInitCharArray(21, m3, cv3);
                emlrtAssign(&g_y, m3);
                c_error(message(g_y, &d_emlrtMCI), &e_emlrtMCI);
                EMLRTPOPRTSTACK(&x_emlrtRSI);
            }
            EMLRTPOPRTSTACK(&uj_emlrtRSI);
            emlrtNonNegativeCheckR2009b((real_T)n, &c_emlrtDCI);
            i1 = f->size[0] * f->size[1];
            f->size[0] = 1;
            f->size[1] = n;
            emxEnsureCapacity((emxArray__common *)f, i1, (int32_T)sizeof(real_T), &h_emlrtRTEI);
            if (n > 0) {
                emlrtDynamicBoundsCheck(1, 1, f->size[1], &p_emlrtBCI);
                f->data[0] = anew;
                if (n > 1) {
                    f->data[emlrtDynamicBoundsCheck(n, 1, f->size[1], &tb_emlrtBCI) - 1] = bnew;
                    nm1 = n - 1;
                    i1 = nm1;
                    nm1d2 = (int32_T)((uint32_T)i1 >> 1);
                    for (k = 1; k <= nm1d2 - 1; k++) {
                        f->data[emlrtDynamicBoundsCheck(k + 1, 1, f->size[1], &ac_emlrtBCI) - 1] = anew + (real_T)k;
                        f->data[emlrtDynamicBoundsCheck(n - k, 1, f->size[1], &bc_emlrtBCI) - 1] = bnew - (real_T)k;
                    }
                    if (nm1d2 << 1 == nm1) {
                        f->data[emlrtDynamicBoundsCheck(nm1d2 + 1, 1, f->size[1], &wb_emlrtBCI) - 1] = (anew + bnew) / 2.0;
                    } else {
                        f->data[emlrtDynamicBoundsCheck(nm1d2 + 1, 1, f->size[1], &ub_emlrtBCI) - 1] = anew + (real_T)nm1d2;
                        f->data[emlrtDynamicBoundsCheck(nm1d2 + 2, 1, f->size[1], &vb_emlrtBCI) - 1] = bnew - (real_T)nm1d2;
                    }
                }
            }
            EMLRTPOPRTSTACK(&tj_emlrtRSI);
            EMLRTPOPRTSTACK(&sj_emlrtRSI);
            EMLRTPOPRTSTACK(&r_emlrtRSI);
            nm1d2 = vec->size[1];
            emlrtVectorVectorIndexCheck(nm1d2, 1, 1, f->size[1], &b_emlrtECI);
            EMLRTPUSHRTSTACK(&s_emlrtRSI);
            i1 = r7->size[0] * r7->size[1];
            r7->size[0] = 1;
            r7->size[1] = f->size[1];
            emxEnsureCapacity((emxArray__common *)r7, i1, (int32_T)sizeof(int32_T), &g_emlrtRTEI);
            b_vec = vec->size[1];
            nm1d2 = vec->size[1];
            loop_ub = f->size[0] * f->size[1] - 1;
            for (i1 = 0; i1 <= loop_ub; i1++) {
                r7->data[i1] = emlrtDynamicBoundsCheck((int32_T)emlrtIntegerCheckR2009b((((real_T)b_vec + f->data[i1]) + 1.0) - supportlength, &k_emlrtDCI), 1, nm1d2, &xb_emlrtBCI);
            }
            i1 = b->size[0];
            b->size[0] = r7->size[1];
            emxEnsureCapacity((emxArray__common *)b, i1, (int32_T)sizeof(real_T), &g_emlrtRTEI);
            loop_ub = r7->size[1] - 1;
            for (i1 = 0; i1 <= loop_ub; i1++) {
                b->data[i1] = vec->data[r7->data[i1] - 1];
            }
            EMLRTPUSHRTSTACK(&kj_emlrtRSI);
            i1 = r8->size[0] * r8->size[1];
            r8->size[0] = 1;
            r8->size[1] = f->size[1];
            emxEnsureCapacity((emxArray__common *)r8, i1, (int32_T)sizeof(int32_T), &g_emlrtRTEI);
            b_vec = vec->size[1];
            loop_ub = f->size[0] * f->size[1] - 1;
            for (i1 = 0; i1 <= loop_ub; i1++) {
                r8->data[i1] = (int32_T)((((real_T)b_vec + f->data[i1]) + 1.0) - supportlength);
            }
            nm1d2 = r8->size[1];
            i1 = f_vec->size[0];
            f_vec->size[0] = nm1d2;
            emxEnsureCapacity((emxArray__common *)f_vec, i1, (int32_T)sizeof(real_T), &g_emlrtRTEI);
            loop_ub = nm1d2 - 1;
            for (i1 = 0; i1 <= loop_ub; i1++) {
                f_vec->data[i1] = vec->data[r8->data[i1] - 1];
            }
            innerDimOk = (coef->size[1] == f_vec->size[0]);
            if (!innerDimOk) {
                guard2 = FALSE;
                if (coef->size[1] == 1) {
                    guard2 = TRUE;
                } else {
                    i1 = r9->size[0] * r9->size[1];
                    r9->size[0] = 1;
                    r9->size[1] = f->size[1];
                    emxEnsureCapacity((emxArray__common *)r9, i1, (int32_T)sizeof(int32_T), &g_emlrtRTEI);
                    b_vec = vec->size[1];
                    loop_ub = f->size[0] * f->size[1] - 1;
                    for (i1 = 0; i1 <= loop_ub; i1++) {
                        r9->data[i1] = (int32_T)((((real_T)b_vec + f->data[i1]) + 1.0) - supportlength);
                    }
                    nm1d2 = r9->size[1];
                    i1 = g_vec->size[0];
                    g_vec->size[0] = nm1d2;
                    emxEnsureCapacity((emxArray__common *)g_vec, i1, (int32_T)sizeof(real_T), &g_emlrtRTEI);
                    loop_ub = nm1d2 - 1;
                    for (i1 = 0; i1 <= loop_ub; i1++) {
                        g_vec->data[i1] = vec->data[r9->data[i1] - 1];
                    }
                    if (g_vec->size[0] == 1) {
                        guard2 = TRUE;
                    } else {
                        EMLRTPUSHRTSTACK(&mj_emlrtRSI);
                        h_y = NULL;
                        m3 = mxCreateCharArray(2, iv12);
                        emlrtInitCharArray(21, m3, cv4);
                        emlrtAssign(&h_y, m3);
                        c_error(message(h_y, &ab_emlrtMCI), &bb_emlrtMCI);
                        EMLRTPOPRTSTACK(&mj_emlrtRSI);
                    }
                }
                if (guard2 == TRUE) {
                    EMLRTPUSHRTSTACK(&lj_emlrtRSI);
                    i_y = NULL;
                    m3 = mxCreateCharArray(2, iv13);
                    emlrtInitCharArray(45, m3, cv5);
                    emlrtAssign(&i_y, m3);
                    c_error(message(i_y, &x_emlrtMCI), &y_emlrtMCI);
                    EMLRTPOPRTSTACK(&lj_emlrtRSI);
                }
            }
            EMLRTPOPRTSTACK(&kj_emlrtRSI);
            guard1 = FALSE;
            if (coef->size[1] == 1) {
                guard1 = TRUE;
            } else {
                i1 = r10->size[0] * r10->size[1];
                r10->size[0] = 1;
                r10->size[1] = f->size[1];
                emxEnsureCapacity((emxArray__common *)r10, i1, (int32_T)sizeof(int32_T), &g_emlrtRTEI);
                b_vec = vec->size[1];
                loop_ub = f->size[0] * f->size[1] - 1;
                for (i1 = 0; i1 <= loop_ub; i1++) {
                    r10->data[i1] = (int32_T)((((real_T)b_vec + f->data[i1]) + 1.0) - supportlength);
                }
                nm1d2 = r10->size[1];
                i1 = h_vec->size[0];
                h_vec->size[0] = nm1d2;
                emxEnsureCapacity((emxArray__common *)h_vec, i1, (int32_T)sizeof(real_T), &g_emlrtRTEI);
                loop_ub = nm1d2 - 1;
                for (i1 = 0; i1 <= loop_ub; i1++) {
                    h_vec->data[i1] = vec->data[r10->data[i1] - 1];
                }
                if (h_vec->size[0] == 1) {
                    guard1 = TRUE;
                } else {
                    k = coef->size[1];
                    EMLRTPUSHRTSTACK(&jj_emlrtRSI);
                    EMLRTPUSHRTSTACK(&nj_emlrtRSI);
                    EMLRTPUSHRTSTACK(&oj_emlrtRSI);
                    if (k < 1) {
                        anew = 0.0;
                    } else {
                        EMLRTPUSHRTSTACK(&qj_emlrtRSI);
                        n = 1;
                        nm1 = 1;
                        emlrtDynamicBoundsCheck(1, 1, coef->size[1], &o_emlrtBCI);
                        i1 = r12->size[0] * r12->size[1];
                        r12->size[0] = 1;
                        r12->size[1] = f->size[1];
                        emxEnsureCapacity((emxArray__common *)r12, i1, (int32_T)sizeof(int32_T), &g_emlrtRTEI);
                        b_vec = vec->size[1];
                        loop_ub = f->size[0] * f->size[1] - 1;
                        for (i1 = 0; i1 <= loop_ub; i1++) {
                            r12->data[i1] = (int32_T)((((real_T)b_vec + f->data[i1]) + 1.0) - supportlength);
                        }
                        nm1d2 = r12->size[1];
                        i1 = i_vec->size[0];
                        i_vec->size[0] = nm1d2;
                        emxEnsureCapacity((emxArray__common *)i_vec, i1, (int32_T)sizeof(real_T), &g_emlrtRTEI);
                        loop_ub = nm1d2 - 1;
                        for (i1 = 0; i1 <= loop_ub; i1++) {
                            i_vec->data[i1] = vec->data[r12->data[i1] - 1];
                        }
                        emlrtDynamicBoundsCheck(1, 1, i_vec->size[0], &n_emlrtBCI);
                        anew = ddot32(&k, &coef->data[0], &n, &b->data[0], &nm1);
                        EMLRTPOPRTSTACK(&qj_emlrtRSI);
                    }
                    EMLRTPOPRTSTACK(&oj_emlrtRSI);
                    EMLRTPOPRTSTACK(&nj_emlrtRSI);
                    EMLRTPOPRTSTACK(&jj_emlrtRSI);
                }
            }
            if (guard1 == TRUE) {
                i1 = r11->size[0] * r11->size[1];
                r11->size[0] = 1;
                r11->size[1] = f->size[1];
                emxEnsureCapacity((emxArray__common *)r11, i1, (int32_T)sizeof(int32_T), &g_emlrtRTEI);
                b_vec = vec->size[1];
                loop_ub = f->size[0] * f->size[1] - 1;
                for (i1 = 0; i1 <= loop_ub; i1++) {
                    r11->data[i1] = (int32_T)((((real_T)b_vec + f->data[i1]) + 1.0) - supportlength);
                }
                anew = 0.0;
                loop_ub = coef->size[1] - 1;
                for (i1 = 0; i1 <= loop_ub; i1++) {
                    anew += coef->data[coef->size[0] * i1] * vec->data[r11->data[i1] - 1];
                }
            }
            Dvec->data[emlrtDynamicBoundsCheck((int32_T)(((real_T)vec->size[1] - (1.0 + (real_T)i)) + 1.0), 1, Dvec->size[1], &yb_emlrtBCI) - 1] = anew;
            EMLRTPOPRTSTACK(&s_emlrtRSI);
        }
        i++;
        emlrtBreakCheck();
    }
    emxFree_real_T(&i_vec);
    emxFree_real_T(&h_vec);
    emxFree_real_T(&g_vec);
    emxFree_real_T(&f_vec);
    emxFree_real_T(&e_vec);
    emxFree_real_T(&d_vec);
    emxFree_real_T(&c_vec);
    emxFree_int32_T(&r12);
    emxFree_int32_T(&r11);
    emxFree_int32_T(&r10);
    emxFree_int32_T(&r9);
    emxFree_int32_T(&r8);
    emxFree_int32_T(&r7);
    emxFree_int32_T(&r6);
    emxFree_real_T(&e_coef);
    emxFree_real_T(&d_coef);
    emxFree_real_T(&b);
    emxFree_int32_T(&r2);
    emxFree_real_T(&f);
    emxFree_real_T(&coef);
    /*  scale by the supplied spacing */
    /* 'movingslope:205' Dvec = Dvec/dt; */
    /*  all done */
    emlrtHeapReferenceStackLeaveFcn();
}
/* End of code generation (movingslope.c) */
