/*
 * epu_n_unit_ba.c
 *
 * Code generation for function 'epu_n_unit_ba'
 *
 * C source code generated on: Tue Oct 30 14:49:26 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_ba.h"
#include "epu_n_unit_ba_emxutil.h"
#include "rdivide.h"
#include "repmat.h"
#include "exp.h"
#include "ceil.h"
#include "all.h"
#include "mean.h"
#include "log.h"
#include "epu_n_unit_ba_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 63, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRSInfo b_emlrtRSI = { 63, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRSInfo c_emlrtRSI = { 70, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRSInfo d_emlrtRSI = { 73, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRSInfo e_emlrtRSI = { 79, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRSInfo f_emlrtRSI = { 89, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRSInfo g_emlrtRSI = { 92, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRSInfo h_emlrtRSI = { 92, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRSInfo i_emlrtRSI = { 92, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRSInfo j_emlrtRSI = { 92, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRSInfo k_emlrtRSI = { 92, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRSInfo l_emlrtRSI = { 92, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRSInfo m_emlrtRSI = { 97, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRSInfo n_emlrtRSI = { 100, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRSInfo o_emlrtRSI = { 103, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRSInfo p_emlrtRSI = { 103, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRSInfo q_emlrtRSI = { 103, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRSInfo r_emlrtRSI = { 103, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRSInfo s_emlrtRSI = { 103, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRSInfo t_emlrtRSI = { 103, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRSInfo u_emlrtRSI = { 106, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRSInfo v_emlrtRSI = { 107, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRSInfo bb_emlrtRSI = { 25, "sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/sort.m" };
static emlrtRSInfo cb_emlrtRSI = { 49, "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };
static emlrtRSInfo db_emlrtRSI = { 61, "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };
static emlrtRSInfo eb_emlrtRSI = { 63, "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };
static emlrtRSInfo fb_emlrtRSI = { 77, "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };
static emlrtRSInfo ib_emlrtRSI = { 91, "eml_matrix_vstride", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m" };
static emlrtRSInfo jb_emlrtRSI = { 16, "eml_matrix_npages", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m" };
static emlrtRSInfo kb_emlrtRSI = { 139, "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };
static emlrtRSInfo lb_emlrtRSI = { 161, "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };
static emlrtRSInfo tb_emlrtRSI = { 79, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRSInfo ub_emlrtRSI = { 117, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRSInfo vb_emlrtRSI = { 233, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRSInfo hc_emlrtRSI = { 16, "max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/max.m" };
static emlrtRSInfo ic_emlrtRSI = { 18, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtRSInfo jc_emlrtRSI = { 38, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtRSInfo kc_emlrtRSI = { 73, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtRSInfo lc_emlrtRSI = { 88, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtRSInfo pc_emlrtRSI = { 17, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtRSInfo qc_emlrtRSI = { 17, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtRSInfo rc_emlrtRSI = { 20, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtRSInfo sc_emlrtRSI = { 36, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtRSInfo tc_emlrtRSI = { 8, "isequal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/isequal.m" };
static emlrtRSInfo uc_emlrtRSI = { 30, "eml_isequal_core", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_isequal_core.m" };
static emlrtRSInfo vc_emlrtRSI = { 56, "eml_isequal_core", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_isequal_core.m" };
static emlrtRSInfo wc_emlrtRSI = { 34, "sum", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/sum.m" };
static emlrtRSInfo xc_emlrtRSI = { 32, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtRSInfo yc_emlrtRSI = { 91, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtRSInfo ad_emlrtRSI = { 121, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtRSInfo bd_emlrtRSI = { 134, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtRSInfo cd_emlrtRSI = { 143, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtRSInfo dd_emlrtRSI = { 150, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtRSInfo ed_emlrtRSI = { 243, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtRSInfo fd_emlrtRSI = { 20, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtRSInfo gd_emlrtRSI = { 20, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtRSInfo hd_emlrtRSI = { 31, "eml_bsearch", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_bsearch.m" };
static emlrtMCInfo k_emlrtMCI = { 234, 5, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtMCInfo l_emlrtMCI = { 233, 15, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtMCInfo q_emlrtMCI = { 41, 9, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtMCInfo r_emlrtMCI = { 38, 19, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtMCInfo s_emlrtMCI = { 74, 9, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtMCInfo t_emlrtMCI = { 73, 19, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtMCInfo u_emlrtMCI = { 18, 9, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtMCInfo v_emlrtMCI = { 17, 19, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtMCInfo w_emlrtMCI = { 23, 9, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtMCInfo x_emlrtMCI = { 20, 19, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtMCInfo y_emlrtMCI = { 92, 13, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtMCInfo ab_emlrtMCI = { 91, 23, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtMCInfo bb_emlrtMCI = { 122, 5, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtMCInfo cb_emlrtMCI = { 121, 15, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtMCInfo db_emlrtMCI = { 20, 19, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo eb_emlrtMCI = { 20, 5, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo fb_emlrtMCI = { 20, 19, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo gb_emlrtMCI = { 20, 5, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtRTEInfo emlrtRTEI = { 1, 28, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRTEInfo b_emlrtRTEI = { 51, 1, "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };
static emlrtRTEInfo c_emlrtRTEI = { 52, 1, "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };
static emlrtRTEInfo d_emlrtRTEI = { 60, 5, "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };
static emlrtRTEInfo e_emlrtRTEI = { 118, 1, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRTEInfo f_emlrtRTEI = { 27, 5, "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };
static emlrtRTEInfo g_emlrtRTEI = { 63, 1, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRTEInfo h_emlrtRTEI = { 106, 4, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRTEInfo i_emlrtRTEI = { 52, 1, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtRTEInfo j_emlrtRTEI = { 77, 13, "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };
static emlrtRTEInfo k_emlrtRTEI = { 1, 13, "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };
static emlrtRTEInfo l_emlrtRTEI = { 145, 5, "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };
static emlrtBCInfo emlrtBCI = { -1, -1, 74, 28, "", "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m", 0 };
static emlrtBCInfo b_emlrtBCI = { -1, -1, 74, 17, "", "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m", 0 };
static emlrtBCInfo c_emlrtBCI = { -1, -1, 43, 9, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo d_emlrtBCI = { -1, -1, 82, 27, "", "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m", 0 };
static emlrtBCInfo e_emlrtBCI = { -1, -1, 82, 17, "", "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m", 0 };
static emlrtBCInfo f_emlrtBCI = { -1, -1, 81, 31, "", "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m", 0 };
static emlrtBCInfo g_emlrtBCI = { -1, -1, 81, 25, "", "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m", 0 };
static emlrtBCInfo h_emlrtBCI = { -1, -1, 81, 17, "", "eml_sort", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort.m", 0 };
static emlrtBCInfo i_emlrtBCI = { -1, -1, 135, 9, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo j_emlrtBCI = { -1, -1, 142, 13, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo k_emlrtBCI = { -1, -1, 141, 13, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo l_emlrtBCI = { -1, -1, 167, 39, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo m_emlrtBCI = { -1, -1, 167, 29, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo n_emlrtBCI = { -1, -1, 162, 31, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo o_emlrtBCI = { -1, -1, 162, 21, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo p_emlrtBCI = { -1, -1, 177, 39, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo q_emlrtBCI = { -1, -1, 177, 29, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo r_emlrtBCI = { -1, -1, 172, 31, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo s_emlrtBCI = { -1, -1, 172, 21, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo t_emlrtBCI = { -1, -1, 186, 44, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo u_emlrtBCI = { -1, -1, 186, 17, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo v_emlrtBCI = { -1, -1, 128, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo w_emlrtBCI = { -1, -1, 127, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo x_emlrtBCI = { -1, -1, 92, 76, "k", "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m", 0 };
static emlrtBCInfo y_emlrtBCI = { -1, -1, 92, 51, "v", "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m", 0 };
static emlrtBCInfo ab_emlrtBCI = { -1, -1, 92, 183, "k", "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m", 0 };
static emlrtBCInfo bb_emlrtBCI = { -1, -1, 92, 152, "k", "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m", 0 };
static emlrtDCInfo emlrtDCI = { 92, 127, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m", 1 };
static emlrtBCInfo cb_emlrtBCI = { -1, -1, 92, 127, "v", "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m", 0 };
static emlrtBCInfo db_emlrtBCI = { -1, -1, 131, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo eb_emlrtBCI = { -1, -1, 135, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo fb_emlrtBCI = { -1, -1, 134, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo gb_emlrtBCI = { -1, -1, 122, 9, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtDCInfo b_emlrtDCI = { 79, 40, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m", 1 };
static emlrtBCInfo hb_emlrtBCI = { -1, -1, 79, 40, "dtAccumulation", "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m", 0 };
static emlrtBCInfo ib_emlrtBCI = { -1, -1, 219, 28, "", "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m", 0 };
static emlrtBCInfo jb_emlrtBCI = { -1, -1, 128, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo kb_emlrtBCI = { -1, -1, 127, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo lb_emlrtBCI = { -1, -1, 12, 5, "", "exp", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elfun/exp.m", 0 };
static emlrtDCInfo c_emlrtDCI = { 120, 28, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m", 1 };
static emlrtBCInfo mb_emlrtBCI = { -1, -1, 120, 28, "activation", "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m", 0 };
static emlrtDCInfo d_emlrtDCI = { 120, 37, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m", 1 };
static emlrtBCInfo nb_emlrtBCI = { -1, -1, 120, 37, "activation", "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m", 0 };
static emlrtBCInfo ob_emlrtBCI = { -1, -1, 20, 13, "", "fliplr", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/fliplr.m", 0 };
static emlrtBCInfo pb_emlrtBCI = { -1, -1, 19, 23, "", "fliplr", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/fliplr.m", 0 };
static emlrtBCInfo qb_emlrtBCI = { -1, -1, 19, 13, "", "fliplr", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/fliplr.m", 0 };
static emlrtBCInfo rb_emlrtBCI = { -1, -1, 18, 20, "", "fliplr", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/fliplr.m", 0 };
static emlrtBCInfo sb_emlrtBCI = { -1, -1, 149, 20, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo tb_emlrtBCI = { -1, -1, 149, 12, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo ub_emlrtBCI = { -1, -1, 252, 31, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo vb_emlrtBCI = { -1, -1, 252, 68, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo wb_emlrtBCI = { -1, -1, 252, 42, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo xb_emlrtBCI = { -1, -1, 32, 14, "", "eml_bsearch", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_bsearch.m", 0 };
static emlrtBCInfo yb_emlrtBCI = { -1, -1, 245, 46, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo ac_emlrtBCI = { -1, -1, 56, 22, "", "sum", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/sum.m", 0 };
static emlrtBCInfo bc_emlrtBCI = { -1, -1, 131, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo cc_emlrtBCI = { -1, -1, 135, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo dc_emlrtBCI = { -1, -1, 134, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo ec_emlrtBCI = { -1, -1, 122, 9, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo fc_emlrtBCI = { -1, -1, 199, 32, "", "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m", 0 };
static emlrtDCInfo e_emlrtDCI = { 60, 21, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m", 4 };
static emlrtECInfo emlrtECI = { 2, 60, 14, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtECInfo b_emlrtECI = { 2, 63, 23, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtBCInfo gc_emlrtBCI = { -1, -1, 80, 23, "accumulationTime", "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m", 0 };
static emlrtDCInfo f_emlrtDCI = { 92, 24, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m", 4 };
static emlrtECInfo c_emlrtECI = { 2, 92, 96, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtECInfo d_emlrtECI = { 2, 92, 175, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtECInfo e_emlrtECI = { 2, 92, 95, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtECInfo f_emlrtECI = { 2, 92, 44, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtECInfo g_emlrtECI = { 2, 92, 17, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtECInfo h_emlrtECI = { 2, 103, 59, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtECInfo i_emlrtECI = { 2, 103, 127, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtECInfo j_emlrtECI = { 2, 103, 58, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtECInfo k_emlrtECI = { 2, 103, 17, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtDCInfo g_emlrtDCI = { 114, 24, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m", 4 };
static emlrtECInfo l_emlrtECI = { 2, 114, 17, "epu_n_unit_ba", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_ba.m" };
static emlrtBCInfo hc_emlrtBCI = { -1, -1, 178, 12, "", "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m", 0 };
static emlrtBCInfo ic_emlrtBCI = { -1, -1, 198, 27, "", "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m", 0 };
static emlrtBCInfo jc_emlrtBCI = { -1, -1, 218, 32, "", "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m", 0 };
static emlrtDCInfo h_emlrtDCI = { 118, 28, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 4 };
static emlrtBCInfo kc_emlrtBCI = { -1, -1, 120, 5, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo lc_emlrtBCI = { 0, MAX_int32_T, 11, 11, "", "exp", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elfun/exp.m", 0 };
static emlrtBCInfo mc_emlrtBCI = { -1, -1, 12, 27, "", "exp", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elfun/exp.m", 0 };
static emlrtBCInfo nc_emlrtBCI = { -1, -1, 54, 14, "", "sum", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/sum.m", 0 };
static emlrtBCInfo oc_emlrtBCI = { 0, MAX_int32_T, 90, 19, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo pc_emlrtBCI = { -1, -1, 133, 18, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo qc_emlrtBCI = { -1, -1, 139, 8, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo rc_emlrtBCI = { -1, -1, 139, 15, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo sc_emlrtBCI = { 0, MAX_int32_T, 141, 15, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo tc_emlrtBCI = { -1, -1, 141, 13, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtECInfo m_emlrtECI = { -1, 141, 13, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtBCInfo uc_emlrtBCI = { -1, -1, 153, 11, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo vc_emlrtBCI = { 0, MAX_int32_T, 154, 13, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo wc_emlrtBCI = { -1, -1, 154, 11, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo xc_emlrtBCI = { -1, -1, 244, 26, "", "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m", 0 };
static emlrtBCInfo yc_emlrtBCI = { 0, MAX_int32_T, 21, 15, "", "eml_bsearch", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_bsearch.m", 0 };
static emlrtBCInfo ad_emlrtBCI = { -1, -1, 161, 38, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo bd_emlrtBCI = { -1, -1, 161, 45, "", "eml_sort_idx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m", 0 };
static emlrtBCInfo cd_emlrtBCI = { -1, -1, 20, 35, "", "eml_sort_le", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_le.m", 0 };
static emlrtBCInfo dd_emlrtBCI = { -1, -1, 20, 44, "", "eml_sort_le", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_le.m", 0 };
static emlrtBCInfo ed_emlrtBCI = { -1, -1, 20, 35, "", "eml_sort_le", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_le.m", 0 };
static emlrtBCInfo fd_emlrtBCI = { -1, -1, 20, 44, "", "eml_sort_le", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_sort_le.m", 0 };
static emlrtDCInfo i_emlrtDCI = { 118, 28, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 4 };
static emlrtBCInfo gd_emlrtBCI = { -1, -1, 120, 5, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };

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
    static const int32_T iv22[2] = { 1, 21 };
    const mxArray *m6;
    static const char_T cv15[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'n', 't', 'e', 'r', 'p', '1', ':', 'N', 'a', 'N', 'i', 'n', 'X' };
    EMLRTPUSHRTSTACK(&fd_emlrtRSI);
    y = NULL;
    m6 = mxCreateCharArray(2, iv22);
    emlrtInitCharArray(21, m6, cv15);
    emlrtAssign(&y, m6);
    error(message(y, &db_emlrtMCI), &eb_emlrtMCI);
    EMLRTPOPRTSTACK(&fd_emlrtRSI);
}

/*
 * 
 */
static void c_eml_error(void)
{
    const mxArray *y;
    static const int32_T iv23[2] = { 1, 35 };
    const mxArray *m7;
    static const char_T cv16[35] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'i', 'n', 't', 'e', 'r', 'p', '1', '_', 'n', 'o', 'n', 'M', 'o', 'n', 'o', 't', 'o', 'n', 'i', 'c', 'X' };
    EMLRTPUSHRTSTACK(&gd_emlrtRSI);
    y = NULL;
    m7 = mxCreateCharArray(2, iv23);
    emlrtInitCharArray(35, m7, cv16);
    emlrtAssign(&y, m7);
    error(message(y, &fb_emlrtMCI), &gb_emlrtMCI);
    EMLRTPOPRTSTACK(&gd_emlrtRSI);
}

/*
 * function [rt,activation] = epu_n_unit_ba(v,theta,k,affTime,effTime,pN,dMeth,iAT)
 */
void epu_n_unit_ba(const emxArray_real_T *v, const emxArray_real_T *theta, const emxArray_real_T *k, real_T affTime, real_T effTime, emxArray_real_T *pN, real_T dMeth, const emxArray_real_T *iAT, real_T *rt, emxArray_real_T *activation)
{
    real_T tMax;
    int32_T nm1d2;
    int32_T j2;
    int32_T qEnd;
    int32_T q;
    int32_T ixstart;
    int32_T pEnd;
    emxArray_real_T *r0;
    int32_T b_theta[2];
    int32_T iv0[2];
    emxArray_real_T *dtAccumulation;
    emxArray_real_T *c_theta;
    emxArray_real_T *r1;
    emxArray_real_T *b_k;
    emxArray_real_T *meanActivation;
    emxArray_real_T *r2;
    emxArray_real_T *x;
    emxArray_real_T *b_x;
    emxArray_real_T *r3;
    emxArray_real_T *r4;
    emxArray_real_T *r5;
    int32_T a;
    emxArray_real_T *y;
    emxArray_int32_T *idx;
    uint32_T low_i;
    int32_T vstride;
    int32_T c_k;
    emxArray_int32_T *iidx;
    emxArray_int32_T *idx0;
    int32_T i1;
    int32_T j;
    int32_T n;
    int32_T np1;
    boolean_T n_too_large;
    int32_T nx;
    int32_T kEnd;
    emxArray_boolean_T *b_pN;
    emxArray_real_T *r6;
    emxArray_real_T *accumulationTime;
    real_T r;
    real_T apnd;
    real_T ndbl;
    real_T cdiff;
    const mxArray *b_y;
    static const int32_T iv1[2] = { 1, 21 };
    const mxArray *m0;
    static const char_T cv0[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };
    emxArray_real_T *b_v;
    emxArray_real_T *d_k;
    emxArray_real_T *r7;
    emxArray_real_T *e_k;
    emxArray_real_T *b_dtAccumulation;
    emxArray_real_T *c_v;
    emxArray_real_T *f_k;
    emxArray_real_T *r8;
    const mxArray *c_y;
    static const int32_T iv2[2] = { 1, 36 };
    static const char_T cv1[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };
    const mxArray *d_y;
    static const int32_T iv3[2] = { 1, 39 };
    static const char_T cv2[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r', '_', 'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };
    boolean_T exitg3;
    const mxArray *e_y;
    static const int32_T iv4[2] = { 1, 21 };
    emxArray_real_T *r9;
    emxArray_real_T *g_k;
    emxArray_real_T *c_dtAccumulation;
    boolean_T p;
    int32_T exitg2;
    const mxArray *f_y;
    static const int32_T iv5[2] = { 1, 31 };
    static const char_T cv3[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'm', 'e', 'a', 'n', '_', 's', 'p', 'e', 'c', 'i', 'a', 'l', 'E', 'm', 'p', 't', 'y' };
    const mxArray *g_y;
    static const int32_T iv6[2] = { 1, 36 };
    const mxArray *h_y;
    static const int32_T iv7[2] = { 1, 35 };
    static const char_T cv4[35] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'n', 't', 'e', 'r', 'p', '1', '_', 'Y', 'I', 'n', 'v', 'a', 'l', 'i', 'd', 'L', 'e', 'n', 'g', 't', 'h' };
    const mxArray *i_y;
    static const int32_T iv8[2] = { 1, 27 };
    static const char_T cv5[27] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'n', 't', 'e', 'r', 'p', '1', ':', 'N', 'o', 't', 'E', 'n', 'o', 'u', 'g', 'h', 'P', 't', 's' };
    emxArray_int32_T *r10;
    emxArray_int32_T *r11;
    int32_T exitg1;
    uint32_T low_ip1;
    uint32_T high_i;
    uint32_T mid_i;
    emxArray_real_T *r12;
    emxArray_real_T *r13;
    emxArray_real_T *b_activation;
    emlrtHeapReferenceStackEnterFcn();
    /*  EPU redundant ballistic accumulator model */
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
    /*  k             - vector with leakage parameters */
    /*                  * units:           */
    /*                  * size & class:   1xnA double, where nA is number of */
    /*                                    accumulators */
    /*                  * support:        k ? ?: (0,+?) */
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
    /*  [rt,activation] = epu_n_unit_ba(v,theta,k,affTime,effTime,pN,dMeth,iAT); */
    /*  */
    /*  */
    /*  Bram Zandbelt, October 2012 */
    /* 'epu_n_unit_ba:51' rt = Inf; */
    *rt = rtInf;
    /* 'epu_n_unit_ba:52' accumulationTime = Inf; */
    /*  Number of accumulator units */
    /* 'epu_n_unit_ba:56' nA = size(v,2); */
    /* 'epu_n_unit_ba:57' nAT = numel(iAT); */
    /* 'epu_n_unit_ba:58' x0 = 0; */
    /*  Starting value of activation */
    /* 'epu_n_unit_ba:60' activation = [zeros(floor(affTime),nAT);nan(1,nAT)]; */
    tMax = muDoubleScalarFloor(affTime);
    emlrtNonNegativeCheckR2009b(tMax, &e_emlrtDCI);
    nm1d2 = iAT->size[1];
    j2 = iAT->size[1];
    emlrtDimSizeEqCheck(nm1d2, j2, &emlrtECI);
    nm1d2 = iAT->size[1];
    j2 = iAT->size[1];
    qEnd = activation->size[0] * activation->size[1];
    activation->size[0] = (int32_T)tMax + 1;
    activation->size[1] = nm1d2;
    emxEnsureCapacity((emxArray__common *)activation, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
    q = nm1d2 - 1;
    for (qEnd = 0; qEnd <= q; qEnd++) {
        ixstart = (int32_T)tMax - 1;
        for (pEnd = 0; pEnd <= ixstart; pEnd++) {
            activation->data[pEnd + activation->size[0] * qEnd] = 0.0;
        }
    }
    q = j2 - 1;
    for (qEnd = 0; qEnd <= q; qEnd++) {
        activation->data[(int32_T)tMax + activation->size[0] * qEnd] = rtNaN;
    }
    emxInit_real_T(&r0, 2, &emlrtRTEI, TRUE);
    /*  Activation */
    /*  Time to reach theta for each accumulator */
    /* 'epu_n_unit_ba:63' dtAccumulation = log((theta - v./k)./(x0 - v./k))./-k; */
    EMLRTPUSHRTSTACK(&emlrtRSI);
    rdivide(v, k, r0);
    EMLRTPOPRTSTACK(&emlrtRSI);
    for (qEnd = 0; qEnd < 2; qEnd++) {
        b_theta[qEnd] = theta->size[qEnd];
    }
    for (qEnd = 0; qEnd < 2; qEnd++) {
        iv0[qEnd] = r0->size[qEnd];
    }
    emxInit_real_T(&dtAccumulation, 2, &g_emlrtRTEI, TRUE);
    emxInit_real_T(&c_theta, 2, &emlrtRTEI, TRUE);
    emlrtSizeEqCheckND(b_theta, iv0, &b_emlrtECI);
    EMLRTPUSHRTSTACK(&b_emlrtRSI);
    rdivide(v, k, dtAccumulation);
    qEnd = c_theta->size[0] * c_theta->size[1];
    c_theta->size[0] = 1;
    c_theta->size[1] = theta->size[1];
    emxEnsureCapacity((emxArray__common *)c_theta, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
    q = theta->size[0] * theta->size[1] - 1;
    for (qEnd = 0; qEnd <= q; qEnd++) {
        c_theta->data[qEnd] = theta->data[qEnd] - r0->data[qEnd];
    }
    emxInit_real_T(&r1, 2, &emlrtRTEI, TRUE);
    qEnd = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    r1->size[1] = dtAccumulation->size[1];
    emxEnsureCapacity((emxArray__common *)r1, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
    q = dtAccumulation->size[0] * dtAccumulation->size[1] - 1;
    for (qEnd = 0; qEnd <= q; qEnd++) {
        r1->data[qEnd] = 0.0 - dtAccumulation->data[qEnd];
    }
    emxInit_real_T(&b_k, 2, &emlrtRTEI, TRUE);
    rdivide(c_theta, r1, r0);
    b_log(r0);
    qEnd = b_k->size[0] * b_k->size[1];
    b_k->size[0] = 1;
    b_k->size[1] = k->size[1];
    emxEnsureCapacity((emxArray__common *)b_k, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
    emxFree_real_T(&r1);
    emxFree_real_T(&c_theta);
    q = k->size[0] * k->size[1] - 1;
    for (qEnd = 0; qEnd <= q; qEnd++) {
        b_k->data[qEnd] = -k->data[qEnd];
    }
    rdivide(r0, b_k, dtAccumulation);
    EMLRTPOPRTSTACK(&b_emlrtRSI);
    /*  dtAccumulation = arrayfun(@log,(theta - v./k)./(x0 - v./k))./-k; */
    /* 'epu_n_unit_ba:66' if dMeth == 1 */
    emxFree_real_T(&b_k);
    b_emxInit_real_T(&meanActivation, 1, &h_emlrtRTEI, TRUE);
    emxInit_real_T(&r2, 2, &emlrtRTEI, TRUE);
    emxInit_real_T(&x, 2, &emlrtRTEI, TRUE);
    b_emxInit_real_T(&b_x, 1, &emlrtRTEI, TRUE);
    emxInit_real_T(&r3, 2, &emlrtRTEI, TRUE);
    emxInit_real_T(&r4, 2, &emlrtRTEI, TRUE);
    emxInit_real_T(&r5, 2, &emlrtRTEI, TRUE);
    if (dMeth == 1.0) {
        /*  Polling */
        /* 'epu_n_unit_ba:68' if nA > 1 */
        if (v->size[1] > 1) {
            /*  Per simulation, sort growth times in ascending order */
            /* 'epu_n_unit_ba:70' dtAccumulation = sort(dtAccumulation')'; */
            EMLRTPUSHRTSTACK(&c_emlrtRSI);
            qEnd = b_x->size[0];
            b_x->size[0] = dtAccumulation->size[1];
            emxEnsureCapacity((emxArray__common *)b_x, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
            q = dtAccumulation->size[1] - 1;
            for (qEnd = 0; qEnd <= q; qEnd++) {
                b_x->data[qEnd] = dtAccumulation->data[qEnd];
            }
            EMLRTPUSHRTSTACK(&bb_emlrtRSI);
            nm1d2 = 2;
            if (b_x->size[0] != 1) {
                nm1d2 = 1;
            }
            EMLRTPUSHRTSTACK(&cb_emlrtRSI);
            EMLRTPOPRTSTACK(&cb_emlrtRSI);
            if (nm1d2 <= 1) {
                a = b_x->size[0] - 1;
            } else {
                a = 0;
            }
            b_emxInit_real_T(&y, 1, &emlrtRTEI, TRUE);
            b_emxInit_int32_T(&idx, 1, &k_emlrtRTEI, TRUE);
            qEnd = meanActivation->size[0];
            meanActivation->size[0] = (int32_T)(uint32_T)(a + 1);
            emxEnsureCapacity((emxArray__common *)meanActivation, qEnd, (int32_T)sizeof(real_T), &b_emlrtRTEI);
            qEnd = y->size[0];
            y->size[0] = b_x->size[0];
            emxEnsureCapacity((emxArray__common *)y, qEnd, (int32_T)sizeof(real_T), &c_emlrtRTEI);
            low_i = (uint32_T)b_x->size[0];
            qEnd = idx->size[0];
            idx->size[0] = (int32_T)low_i;
            emxEnsureCapacity((emxArray__common *)idx, qEnd, (int32_T)sizeof(int32_T), &d_emlrtRTEI);
            EMLRTPUSHRTSTACK(&db_emlrtRSI);
            EMLRTPUSHRTSTACK(&ib_emlrtRSI);
            vstride = 1;
            c_k = 1;
            while (c_k <= nm1d2 - 1) {
                ixstart = b_x->size[0];
                vstride *= ixstart;
                c_k = 2;
            }
            EMLRTPOPRTSTACK(&ib_emlrtRSI);
            EMLRTPOPRTSTACK(&db_emlrtRSI);
            EMLRTPUSHRTSTACK(&eb_emlrtRSI);
            EMLRTPUSHRTSTACK(&jb_emlrtRSI);
            EMLRTPOPRTSTACK(&jb_emlrtRSI);
            EMLRTPOPRTSTACK(&eb_emlrtRSI);
            b_emxInit_int32_T(&iidx, 1, &j_emlrtRTEI, TRUE);
            b_emxInit_int32_T(&idx0, 1, &l_emlrtRTEI, TRUE);
            i1 = 0;
            for (j = 1; j <= vstride; j++) {
                i1++;
                nm1d2 = i1;
                for (c_k = 0; c_k <= a; c_k++) {
                    meanActivation->data[emlrtDynamicBoundsCheck(c_k + 1, 1, meanActivation->size[0], &b_emlrtBCI) - 1] = b_x->data[emlrtDynamicBoundsCheck(nm1d2, 1, b_x->size[0], &emlrtBCI) - 1];
                    nm1d2 += vstride;
                }
                EMLRTPUSHRTSTACK(&fb_emlrtRSI);
                n = meanActivation->size[0];
                low_i = (uint32_T)meanActivation->size[0];
                qEnd = iidx->size[0];
                iidx->size[0] = (int32_T)low_i;
                emxEnsureCapacity((emxArray__common *)iidx, qEnd, (int32_T)sizeof(int32_T), &f_emlrtRTEI);
                np1 = n + 1;
                if (meanActivation->size[0] == 0) {
                    for (c_k = 1; c_k <= n; c_k++) {
                        iidx->data[emlrtDynamicBoundsCheck(c_k, 1, iidx->size[0], &c_emlrtBCI) - 1] = c_k;
                    }
                } else {
                    for (c_k = 1; c_k <= n; c_k++) {
                        iidx->data[emlrtDynamicBoundsCheck(c_k, 1, iidx->size[0], &i_emlrtBCI) - 1] = c_k;
                    }
                    for (c_k = 1; c_k <= n - 1; c_k += 2) {
                        EMLRTPUSHRTSTACK(&kb_emlrtRSI);
                        emlrtDynamicBoundsCheck(c_k, 1, meanActivation->size[0], &ed_emlrtBCI);
                        emlrtDynamicBoundsCheck(c_k + 1, 1, meanActivation->size[0], &fd_emlrtBCI);
                        if ((meanActivation->data[c_k - 1] <= meanActivation->data[c_k]) || muDoubleScalarIsNaN(meanActivation->data[c_k])) {
                            n_too_large = TRUE;
                        } else {
                            n_too_large = FALSE;
                        }
                        EMLRTPOPRTSTACK(&kb_emlrtRSI);
                        if (n_too_large) {
                        } else {
                            iidx->data[emlrtDynamicBoundsCheck(c_k, 1, iidx->size[0], &k_emlrtBCI) - 1] = c_k + 1;
                            iidx->data[emlrtDynamicBoundsCheck(c_k + 1, 1, iidx->size[0], &j_emlrtBCI) - 1] = c_k;
                        }
                    }
                    qEnd = idx0->size[0];
                    idx0->size[0] = n;
                    emxEnsureCapacity((emxArray__common *)idx0, qEnd, (int32_T)sizeof(int32_T), &emlrtRTEI);
                    q = n - 1;
                    for (qEnd = 0; qEnd <= q; qEnd++) {
                        idx0->data[qEnd] = 1;
                    }
                    ixstart = 2;
                    while (ixstart < n) {
                        nm1d2 = ixstart << 1;
                        j2 = 1;
                        for (pEnd = 1 + ixstart; pEnd < np1; pEnd = qEnd + ixstart) {
                            nx = j2;
                            q = pEnd;
                            qEnd = j2 + nm1d2;
                            if (qEnd > np1) {
                                qEnd = np1;
                            }
                            c_k = 1;
                            kEnd = qEnd - j2;
                            while (c_k <= kEnd) {
                                EMLRTPUSHRTSTACK(&lb_emlrtRSI);
                                emlrtDynamicBoundsCheck(nx, 1, iidx->size[0], &ad_emlrtBCI);
                                emlrtDynamicBoundsCheck(q, 1, iidx->size[0], &bd_emlrtBCI);
                                emlrtDynamicBoundsCheck(iidx->data[nx - 1], 1, meanActivation->size[0], &cd_emlrtBCI);
                                emlrtDynamicBoundsCheck(iidx->data[q - 1], 1, meanActivation->size[0], &dd_emlrtBCI);
                                if ((meanActivation->data[iidx->data[nx - 1] - 1] <= meanActivation->data[iidx->data[q - 1] - 1]) || muDoubleScalarIsNaN(meanActivation->data[iidx->data[q - 1] - 1])) {
                                    n_too_large = TRUE;
                                } else {
                                    n_too_large = FALSE;
                                }
                                EMLRTPOPRTSTACK(&lb_emlrtRSI);
                                if (n_too_large) {
                                    idx0->data[emlrtDynamicBoundsCheck(c_k, 1, idx0->size[0], &o_emlrtBCI) - 1] = iidx->data[emlrtDynamicBoundsCheck(nx, 1, iidx->size[0], &n_emlrtBCI) - 1];
                                    nx++;
                                    if (nx == pEnd) {
                                        while (q < qEnd) {
                                            c_k++;
                                            idx0->data[emlrtDynamicBoundsCheck(c_k, 1, idx0->size[0], &m_emlrtBCI) - 1] = iidx->data[emlrtDynamicBoundsCheck(q, 1, iidx->size[0], &l_emlrtBCI) - 1];
                                            q++;
                                        }
                                    }
                                } else {
                                    idx0->data[emlrtDynamicBoundsCheck(c_k, 1, idx0->size[0], &s_emlrtBCI) - 1] = iidx->data[emlrtDynamicBoundsCheck(q, 1, iidx->size[0], &r_emlrtBCI) - 1];
                                    q++;
                                    if (q == qEnd) {
                                        while (nx < pEnd) {
                                            c_k++;
                                            idx0->data[emlrtDynamicBoundsCheck(c_k, 1, idx0->size[0], &q_emlrtBCI) - 1] = iidx->data[emlrtDynamicBoundsCheck(nx, 1, iidx->size[0], &p_emlrtBCI) - 1];
                                            nx++;
                                        }
                                    }
                                }
                                c_k++;
                            }
                            for (c_k = 1; c_k <= kEnd; c_k++) {
                                iidx->data[emlrtDynamicBoundsCheck((j2 + c_k) - 1, 1, iidx->size[0], &u_emlrtBCI) - 1] = idx0->data[emlrtDynamicBoundsCheck(c_k, 1, idx0->size[0], &t_emlrtBCI) - 1];
                            }
                            j2 = qEnd;
                        }
                        ixstart = nm1d2;
                    }
                }
                EMLRTPOPRTSTACK(&fb_emlrtRSI);
                nm1d2 = i1;
                for (c_k = 1; c_k - 1 <= a; c_k++) {
                    y->data[emlrtDynamicBoundsCheck(nm1d2, 1, y->size[0], &h_emlrtBCI) - 1] = meanActivation->data[emlrtDynamicBoundsCheck(iidx->data[emlrtDynamicBoundsCheck(c_k, 1, iidx->size[0], &f_emlrtBCI) - 1], 1, meanActivation->size[0], &g_emlrtBCI) - 1];
                    idx->data[emlrtDynamicBoundsCheck(nm1d2, 1, idx->size[0], &e_emlrtBCI) - 1] = iidx->data[emlrtDynamicBoundsCheck(c_k, 1, iidx->size[0], &d_emlrtBCI) - 1];
                    nm1d2 += vstride;
                }
            }
            emxFree_int32_T(&idx0);
            emxFree_int32_T(&idx);
            emxFree_int32_T(&iidx);
            EMLRTPOPRTSTACK(&bb_emlrtRSI);
            qEnd = dtAccumulation->size[0] * dtAccumulation->size[1];
            dtAccumulation->size[0] = 1;
            emxEnsureCapacity((emxArray__common *)dtAccumulation, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
            j2 = y->size[0];
            qEnd = dtAccumulation->size[0] * dtAccumulation->size[1];
            dtAccumulation->size[1] = j2;
            emxEnsureCapacity((emxArray__common *)dtAccumulation, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
            q = y->size[0] - 1;
            for (qEnd = 0; qEnd <= q; qEnd++) {
                dtAccumulation->data[qEnd] = y->data[qEnd];
            }
            emxFree_real_T(&y);
            EMLRTPOPRTSTACK(&c_emlrtRSI);
        }
        emxInit_boolean_T(&b_pN, 2, &emlrtRTEI, TRUE);
        /* 'epu_n_unit_ba:73' if all(pN == 0) */
        EMLRTPUSHRTSTACK(&d_emlrtRSI);
        qEnd = b_pN->size[0] * b_pN->size[1];
        b_pN->size[0] = 1;
        b_pN->size[1] = pN->size[1];
        emxEnsureCapacity((emxArray__common *)b_pN, qEnd, (int32_T)sizeof(boolean_T), &emlrtRTEI);
        q = pN->size[0] * pN->size[1] - 1;
        for (qEnd = 0; qEnd <= q; qEnd++) {
            b_pN->data[qEnd] = (pN->data[qEnd] == 0.0);
        }
        n_too_large = all(b_pN);
        EMLRTPOPRTSTACK(&d_emlrtRSI);
        emxFree_boolean_T(&b_pN);
        if (n_too_large) {
            /* 'epu_n_unit_ba:74' pN = realmin; */
            qEnd = pN->size[0] * pN->size[1];
            pN->size[0] = 1;
            pN->size[1] = 1;
            emxEnsureCapacity((emxArray__common *)pN, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
            pN->data[0] = 2.2250738585072014E-308;
            /*  This ensures that very first accumulator determines RT */
        }
        /*  Compute rt as the sum of afferent time, time for pN fraction of accumulators */
        /*  to reach threshold and efferent time */
        /* 'epu_n_unit_ba:79' accumulationTime = dtAccumulation(:,ceil(pN*nA)); */
        EMLRTPUSHRTSTACK(&e_emlrtRSI);
        qEnd = r0->size[0] * r0->size[1];
        r0->size[0] = 1;
        r0->size[1] = pN->size[1];
        emxEnsureCapacity((emxArray__common *)r0, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
        nm1d2 = v->size[1];
        q = pN->size[0] * pN->size[1] - 1;
        for (qEnd = 0; qEnd <= q; qEnd++) {
            r0->data[qEnd] = pN->data[qEnd] * (real_T)nm1d2;
        }
        emxInit_real_T(&r6, 2, &emlrtRTEI, TRUE);
        b_ceil(r0);
        qEnd = r6->size[0] * r6->size[1];
        r6->size[0] = 1;
        r6->size[1] = r0->size[1];
        emxEnsureCapacity((emxArray__common *)r6, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
        q = r0->size[0] * r0->size[1] - 1;
        for (qEnd = 0; qEnd <= q; qEnd++) {
            r6->data[qEnd] = (real_T)emlrtDynamicBoundsCheck((int32_T)emlrtIntegerCheckR2009b(r0->data[qEnd], &b_emlrtDCI), 1, dtAccumulation->size[1], &hb_emlrtBCI);
        }
        emxInit_real_T(&accumulationTime, 2, &i_emlrtRTEI, TRUE);
        nm1d2 = r6->size[1];
        qEnd = accumulationTime->size[0] * accumulationTime->size[1];
        accumulationTime->size[0] = 1;
        accumulationTime->size[1] = nm1d2;
        emxEnsureCapacity((emxArray__common *)accumulationTime, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
        q = nm1d2 - 1;
        for (qEnd = 0; qEnd <= q; qEnd++) {
            accumulationTime->data[accumulationTime->size[0] * qEnd] = dtAccumulation->data[dtAccumulation->size[0] * ((int32_T)r6->data[qEnd] - 1)];
        }
        emxFree_real_T(&r6);
        EMLRTPOPRTSTACK(&e_emlrtRSI);
        /* 'epu_n_unit_ba:80' accumulationTime = accumulationTime(1); */
        emlrtDynamicBoundsCheck(1, 1, accumulationTime->size[1], &gc_emlrtBCI);
        /*  Compute RT */
        /* 'epu_n_unit_ba:83' rt(1) = affTime + accumulationTime + effTime; */
        *rt = (affTime + accumulationTime->data[0]) + effTime;
        /*  Maximum time for trajectories */
        /* 'epu_n_unit_ba:86' tMax = ceil(rt); */
        tMax = muDoubleScalarCeil(*rt);
        /*  Time vector */
        /* 'epu_n_unit_ba:89' t = 0:1:tMax; */
        EMLRTPUSHRTSTACK(&f_emlrtRSI);
        EMLRTPUSHRTSTACK(&tb_emlrtRSI);
        emxFree_real_T(&accumulationTime);
        if (muDoubleScalarIsNaN(tMax)) {
            n = 1;
            r = rtNaN;
            apnd = tMax;
            n_too_large = FALSE;
        } else if (tMax < 0.0) {
            n = 0;
            r = 0.0;
            apnd = tMax;
            n_too_large = FALSE;
        } else if (muDoubleScalarIsInf(tMax)) {
            n = 1;
            r = rtNaN;
            apnd = tMax;
            if (0.0 == tMax) {
                n_too_large = TRUE;
            } else {
                n_too_large = FALSE;
            }
            n_too_large = !n_too_large;
        } else {
            r = 0.0;
            ndbl = muDoubleScalarFloor(tMax + 0.5);
            apnd = ndbl;
            cdiff = ndbl - tMax;
            if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * tMax) {
                ndbl++;
                apnd = tMax;
            } else if (cdiff > 0.0) {
                apnd = ndbl - 1.0;
            } else {
                ndbl++;
            }
            n_too_large = (ndbl > 2.147483647E+9);
            if (ndbl >= 0.0) {
                n = (int32_T)ndbl;
            } else {
                n = 0;
            }
        }
        EMLRTPUSHRTSTACK(&ub_emlrtRSI);
        if (!n_too_large) {
        } else {
            EMLRTPUSHRTSTACK(&vb_emlrtRSI);
            b_y = NULL;
            m0 = mxCreateCharArray(2, iv1);
            emlrtInitCharArray(21, m0, cv0);
            emlrtAssign(&b_y, m0);
            error(message(b_y, &k_emlrtMCI), &l_emlrtMCI);
            EMLRTPOPRTSTACK(&vb_emlrtRSI);
        }
        EMLRTPOPRTSTACK(&ub_emlrtRSI);
        emlrtNonNegativeCheckR2009b((real_T)n, &i_emlrtDCI);
        qEnd = dtAccumulation->size[0] * dtAccumulation->size[1];
        dtAccumulation->size[0] = 1;
        dtAccumulation->size[1] = n;
        emxEnsureCapacity((emxArray__common *)dtAccumulation, qEnd, (int32_T)sizeof(real_T), &e_emlrtRTEI);
        if (n > 0) {
            emlrtDynamicBoundsCheck(1, 1, dtAccumulation->size[1], &gd_emlrtBCI);
            dtAccumulation->data[0] = r;
            if (n > 1) {
                dtAccumulation->data[emlrtDynamicBoundsCheck(n, 1, dtAccumulation->size[1], &gb_emlrtBCI) - 1] = apnd;
                ixstart = n - 1;
                qEnd = ixstart;
                nm1d2 = (int32_T)((uint32_T)qEnd >> 1);
                for (c_k = 1; c_k <= nm1d2 - 1; c_k++) {
                    dtAccumulation->data[emlrtDynamicBoundsCheck(c_k + 1, 1, dtAccumulation->size[1], &w_emlrtBCI) - 1] = r + (real_T)c_k;
                    dtAccumulation->data[emlrtDynamicBoundsCheck(n - c_k, 1, dtAccumulation->size[1], &v_emlrtBCI) - 1] = apnd - (real_T)c_k;
                }
                if (nm1d2 << 1 == ixstart) {
                    dtAccumulation->data[emlrtDynamicBoundsCheck(nm1d2 + 1, 1, dtAccumulation->size[1], &db_emlrtBCI) - 1] = (r + apnd) / 2.0;
                } else {
                    dtAccumulation->data[emlrtDynamicBoundsCheck(nm1d2 + 1, 1, dtAccumulation->size[1], &fb_emlrtBCI) - 1] = r + (real_T)nm1d2;
                    dtAccumulation->data[emlrtDynamicBoundsCheck(nm1d2 + 2, 1, dtAccumulation->size[1], &eb_emlrtBCI) - 1] = apnd - (real_T)nm1d2;
                }
            }
        }
        emxInit_real_T(&b_v, 2, &emlrtRTEI, TRUE);
        EMLRTPOPRTSTACK(&tb_emlrtRSI);
        EMLRTPOPRTSTACK(&f_emlrtRSI);
        /*  Compute activation trajectories for all accumulators */
        /* 'epu_n_unit_ba:92' activation = [zeros(floor(affTime),nAT);repmat(v(iAT),tMax+1,1)./repmat(k(iAT),tMax+1,1) + (repmat(x0,tMax+1,nAT) - repmat(v(iAT),tMax+1,1)./repmat(k(iAT),tMax+1,1)).*exp(repmat(-k(iAT),tMax+1,1).*repmat(t',1,nAT))]; */
        EMLRTPUSHRTSTACK(&h_emlrtRSI);
        b_repmat(tMax + 1.0, (real_T)iAT->size[1], r2);
        EMLRTPOPRTSTACK(&h_emlrtRSI);
        EMLRTPUSHRTSTACK(&i_emlrtRSI);
        qEnd = b_v->size[0] * b_v->size[1];
        b_v->size[0] = 1;
        b_v->size[1] = iAT->size[1];
        emxEnsureCapacity((emxArray__common *)b_v, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
        q = iAT->size[0] * iAT->size[1] - 1;
        for (qEnd = 0; qEnd <= q; qEnd++) {
            b_v->data[qEnd] = v->data[emlrtDynamicBoundsCheck((int32_T)emlrtIntegerCheckR2009b(iAT->data[qEnd], &emlrtDCI), 1, v->size[1], &cb_emlrtBCI) - 1];
        }
        emxInit_real_T(&d_k, 2, &emlrtRTEI, TRUE);
        repmat(b_v, tMax + 1.0, r4);
        qEnd = d_k->size[0] * d_k->size[1];
        d_k->size[0] = 1;
        d_k->size[1] = iAT->size[1];
        emxEnsureCapacity((emxArray__common *)d_k, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
        emxFree_real_T(&b_v);
        q = iAT->size[0] * iAT->size[1] - 1;
        for (qEnd = 0; qEnd <= q; qEnd++) {
            d_k->data[qEnd] = k->data[emlrtDynamicBoundsCheck((int32_T)iAT->data[qEnd], 1, k->size[1], &bb_emlrtBCI) - 1];
        }
        emxInit_real_T(&r7, 2, &emlrtRTEI, TRUE);
        repmat(d_k, tMax + 1.0, r5);
        qEnd = r7->size[0] * r7->size[1];
        r7->size[0] = r4->size[0];
        r7->size[1] = r4->size[1];
        emxEnsureCapacity((emxArray__common *)r7, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
        emxFree_real_T(&d_k);
        q = r4->size[0] * r4->size[1] - 1;
        for (qEnd = 0; qEnd <= q; qEnd++) {
            r7->data[qEnd] = r4->data[qEnd];
        }
        b_rdivide(r7, r5, r4);
        EMLRTPOPRTSTACK(&i_emlrtRSI);
        emxFree_real_T(&r7);
        for (qEnd = 0; qEnd < 2; qEnd++) {
            iv0[qEnd] = r2->size[qEnd];
        }
        for (qEnd = 0; qEnd < 2; qEnd++) {
            b_theta[qEnd] = r4->size[qEnd];
        }
        emxInit_real_T(&e_k, 2, &emlrtRTEI, TRUE);
        emlrtSizeEqCheckND(iv0, b_theta, &c_emlrtECI);
        EMLRTPUSHRTSTACK(&j_emlrtRSI);
        qEnd = e_k->size[0] * e_k->size[1];
        e_k->size[0] = 1;
        e_k->size[1] = iAT->size[1];
        emxEnsureCapacity((emxArray__common *)e_k, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
        q = iAT->size[0] * iAT->size[1] - 1;
        for (qEnd = 0; qEnd <= q; qEnd++) {
            e_k->data[qEnd] = -k->data[emlrtDynamicBoundsCheck((int32_T)iAT->data[qEnd], 1, k->size[1], &ab_emlrtBCI) - 1];
        }
        b_emxInit_real_T(&b_dtAccumulation, 1, &emlrtRTEI, TRUE);
        repmat(e_k, tMax + 1.0, r5);
        EMLRTPOPRTSTACK(&j_emlrtRSI);
        EMLRTPUSHRTSTACK(&k_emlrtRSI);
        qEnd = b_dtAccumulation->size[0];
        b_dtAccumulation->size[0] = dtAccumulation->size[1];
        emxEnsureCapacity((emxArray__common *)b_dtAccumulation, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
        emxFree_real_T(&e_k);
        q = dtAccumulation->size[1] - 1;
        for (qEnd = 0; qEnd <= q; qEnd++) {
            b_dtAccumulation->data[qEnd] = dtAccumulation->data[qEnd];
        }
        c_repmat(b_dtAccumulation, (real_T)iAT->size[1], r3);
        EMLRTPOPRTSTACK(&k_emlrtRSI);
        emxFree_real_T(&b_dtAccumulation);
        for (qEnd = 0; qEnd < 2; qEnd++) {
            iv0[qEnd] = r5->size[qEnd];
        }
        for (qEnd = 0; qEnd < 2; qEnd++) {
            b_theta[qEnd] = r3->size[qEnd];
        }
        emlrtSizeEqCheckND(iv0, b_theta, &d_emlrtECI);
        EMLRTPUSHRTSTACK(&l_emlrtRSI);
        qEnd = r5->size[0] * r5->size[1];
        emxEnsureCapacity((emxArray__common *)r5, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
        qEnd = r5->size[0];
        pEnd = r5->size[1];
        q = qEnd * pEnd - 1;
        for (qEnd = 0; qEnd <= q; qEnd++) {
            r5->data[qEnd] *= r3->data[qEnd];
        }
        b_exp(r5);
        EMLRTPOPRTSTACK(&l_emlrtRSI);
        for (qEnd = 0; qEnd < 2; qEnd++) {
            iv0[qEnd] = r2->size[qEnd];
        }
        for (qEnd = 0; qEnd < 2; qEnd++) {
            b_theta[qEnd] = r5->size[qEnd];
        }
        emxInit_real_T(&c_v, 2, &emlrtRTEI, TRUE);
        emlrtSizeEqCheckND(iv0, b_theta, &e_emlrtECI);
        EMLRTPUSHRTSTACK(&g_emlrtRSI);
        qEnd = c_v->size[0] * c_v->size[1];
        c_v->size[0] = 1;
        c_v->size[1] = iAT->size[1];
        emxEnsureCapacity((emxArray__common *)c_v, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
        q = iAT->size[0] * iAT->size[1] - 1;
        for (qEnd = 0; qEnd <= q; qEnd++) {
            c_v->data[qEnd] = v->data[emlrtDynamicBoundsCheck((int32_T)iAT->data[qEnd], 1, v->size[1], &y_emlrtBCI) - 1];
        }
        emxInit_real_T(&f_k, 2, &emlrtRTEI, TRUE);
        repmat(c_v, tMax + 1.0, r3);
        qEnd = f_k->size[0] * f_k->size[1];
        f_k->size[0] = 1;
        f_k->size[1] = iAT->size[1];
        emxEnsureCapacity((emxArray__common *)f_k, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
        emxFree_real_T(&c_v);
        q = iAT->size[0] * iAT->size[1] - 1;
        for (qEnd = 0; qEnd <= q; qEnd++) {
            f_k->data[qEnd] = k->data[emlrtDynamicBoundsCheck((int32_T)iAT->data[qEnd], 1, k->size[1], &x_emlrtBCI) - 1];
        }
        emxInit_real_T(&r8, 2, &emlrtRTEI, TRUE);
        repmat(f_k, tMax + 1.0, x);
        qEnd = r8->size[0] * r8->size[1];
        r8->size[0] = r3->size[0];
        r8->size[1] = r3->size[1];
        emxEnsureCapacity((emxArray__common *)r8, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
        emxFree_real_T(&f_k);
        q = r3->size[0] * r3->size[1] - 1;
        for (qEnd = 0; qEnd <= q; qEnd++) {
            r8->data[qEnd] = r3->data[qEnd];
        }
        b_rdivide(r8, x, r3);
        EMLRTPOPRTSTACK(&g_emlrtRSI);
        qEnd = r2->size[0] * r2->size[1];
        emxEnsureCapacity((emxArray__common *)r2, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
        qEnd = r2->size[0];
        pEnd = r2->size[1];
        emxFree_real_T(&r8);
        q = qEnd * pEnd - 1;
        for (qEnd = 0; qEnd <= q; qEnd++) {
            r2->data[qEnd] = (r2->data[qEnd] - r4->data[qEnd]) * r5->data[qEnd];
        }
        for (qEnd = 0; qEnd < 2; qEnd++) {
            iv0[qEnd] = r3->size[qEnd];
        }
        for (qEnd = 0; qEnd < 2; qEnd++) {
            b_theta[qEnd] = r2->size[qEnd];
        }
        emlrtSizeEqCheckND(iv0, b_theta, &f_emlrtECI);
        tMax = muDoubleScalarFloor(affTime);
        emlrtNonNegativeCheckR2009b(tMax, &f_emlrtDCI);
        nm1d2 = iAT->size[1];
        emlrtDimSizeEqCheck(nm1d2, r3->size[1], &g_emlrtECI);
        nm1d2 = iAT->size[1];
        qEnd = activation->size[0] * activation->size[1];
        activation->size[0] = (int32_T)tMax + r3->size[0];
        activation->size[1] = nm1d2;
        emxEnsureCapacity((emxArray__common *)activation, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
        q = nm1d2 - 1;
        for (qEnd = 0; qEnd <= q; qEnd++) {
            ixstart = (int32_T)tMax - 1;
            for (pEnd = 0; pEnd <= ixstart; pEnd++) {
                activation->data[pEnd + activation->size[0] * qEnd] = 0.0;
            }
        }
        q = r3->size[1] - 1;
        for (qEnd = 0; qEnd <= q; qEnd++) {
            ixstart = r3->size[0] - 1;
            for (pEnd = 0; pEnd <= ixstart; pEnd++) {
                activation->data[(pEnd + (int32_T)tMax) + activation->size[0] * qEnd] = r3->data[pEnd + r3->size[0] * qEnd] + r2->data[pEnd + r2->size[0] * qEnd];
            }
        }
    } else {
        if (dMeth == 2.0) {
            /* 'epu_n_unit_ba:94' elseif dMeth == 2 */
            /*  Pooling */
            /*  Maximum time to reach theta across the population */
            /* 'epu_n_unit_ba:97' tMax = ceil(max(dtAccumulation)); */
            EMLRTPUSHRTSTACK(&m_emlrtRSI);
            EMLRTPUSHRTSTACK(&hc_emlrtRSI);
            EMLRTPUSHRTSTACK(&ic_emlrtRSI);
            if ((dtAccumulation->size[1] == 1) || (dtAccumulation->size[1] != 1)) {
                n_too_large = TRUE;
            } else {
                n_too_large = FALSE;
            }
            if (n_too_large) {
            } else {
                EMLRTPUSHRTSTACK(&jc_emlrtRSI);
                c_y = NULL;
                m0 = mxCreateCharArray(2, iv2);
                emlrtInitCharArray(36, m0, cv1);
                emlrtAssign(&c_y, m0);
                error(message(c_y, &q_emlrtMCI), &r_emlrtMCI);
                EMLRTPOPRTSTACK(&jc_emlrtRSI);
            }
            if (dtAccumulation->size[1] > 0) {
            } else {
                EMLRTPUSHRTSTACK(&kc_emlrtRSI);
                d_y = NULL;
                m0 = mxCreateCharArray(2, iv3);
                emlrtInitCharArray(39, m0, cv2);
                emlrtAssign(&d_y, m0);
                error(message(d_y, &s_emlrtMCI), &t_emlrtMCI);
                EMLRTPOPRTSTACK(&kc_emlrtRSI);
            }
            EMLRTPUSHRTSTACK(&lc_emlrtRSI);
            ixstart = 1;
            n = dtAccumulation->size[1];
            emlrtDynamicBoundsCheck(1, 1, dtAccumulation->size[1], &hc_emlrtBCI);
            tMax = dtAccumulation->data[0];
            if (n > 1) {
                if (muDoubleScalarIsNaN(dtAccumulation->data[0])) {
                    nm1d2 = 2;
                    exitg3 = 0U;
                    while ((exitg3 == 0U) && (nm1d2 <= n)) {
                        ixstart = nm1d2;
                        emlrtDynamicBoundsCheck(nm1d2, 1, dtAccumulation->size[1], &ic_emlrtBCI);
                        if (!muDoubleScalarIsNaN(dtAccumulation->data[nm1d2 - 1])) {
                            tMax = dtAccumulation->data[emlrtDynamicBoundsCheck(nm1d2, 1, dtAccumulation->size[1], &fc_emlrtBCI) - 1];
                            exitg3 = 1U;
                        } else {
                            nm1d2++;
                        }
                    }
                }
                if (ixstart < n) {
                    for (nm1d2 = ixstart + 1; nm1d2 <= n; nm1d2++) {
                        emlrtDynamicBoundsCheck(nm1d2, 1, dtAccumulation->size[1], &jc_emlrtBCI);
                        if (dtAccumulation->data[nm1d2 - 1] > tMax) {
                            tMax = dtAccumulation->data[emlrtDynamicBoundsCheck(nm1d2, 1, dtAccumulation->size[1], &ib_emlrtBCI) - 1];
                        }
                    }
                }
            }
            EMLRTPOPRTSTACK(&lc_emlrtRSI);
            EMLRTPOPRTSTACK(&ic_emlrtRSI);
            EMLRTPOPRTSTACK(&hc_emlrtRSI);
            tMax = muDoubleScalarCeil(tMax);
            EMLRTPOPRTSTACK(&m_emlrtRSI);
            /*  Time vector */
            /* 'epu_n_unit_ba:100' t = 0:1:tMax; */
            EMLRTPUSHRTSTACK(&n_emlrtRSI);
            EMLRTPUSHRTSTACK(&tb_emlrtRSI);
            if (muDoubleScalarIsNaN(tMax)) {
                n = 1;
                r = rtNaN;
                apnd = tMax;
                n_too_large = FALSE;
            } else if (tMax < 0.0) {
                n = 0;
                r = 0.0;
                apnd = tMax;
                n_too_large = FALSE;
            } else if (muDoubleScalarIsInf(tMax)) {
                n = 1;
                r = rtNaN;
                apnd = tMax;
                if (0.0 == tMax) {
                    n_too_large = TRUE;
                } else {
                    n_too_large = FALSE;
                }
                n_too_large = !n_too_large;
            } else {
                r = 0.0;
                ndbl = muDoubleScalarFloor(tMax + 0.5);
                apnd = ndbl;
                cdiff = ndbl - tMax;
                if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * tMax) {
                    ndbl++;
                    apnd = tMax;
                } else if (cdiff > 0.0) {
                    apnd = ndbl - 1.0;
                } else {
                    ndbl++;
                }
                n_too_large = (ndbl > 2.147483647E+9);
                if (ndbl >= 0.0) {
                    n = (int32_T)ndbl;
                } else {
                    n = 0;
                }
            }
            EMLRTPUSHRTSTACK(&ub_emlrtRSI);
            if (!n_too_large) {
            } else {
                EMLRTPUSHRTSTACK(&vb_emlrtRSI);
                e_y = NULL;
                m0 = mxCreateCharArray(2, iv4);
                emlrtInitCharArray(21, m0, cv0);
                emlrtAssign(&e_y, m0);
                error(message(e_y, &k_emlrtMCI), &l_emlrtMCI);
                EMLRTPOPRTSTACK(&vb_emlrtRSI);
            }
            EMLRTPOPRTSTACK(&ub_emlrtRSI);
            emlrtNonNegativeCheckR2009b((real_T)n, &h_emlrtDCI);
            qEnd = dtAccumulation->size[0] * dtAccumulation->size[1];
            dtAccumulation->size[0] = 1;
            dtAccumulation->size[1] = n;
            emxEnsureCapacity((emxArray__common *)dtAccumulation, qEnd, (int32_T)sizeof(real_T), &e_emlrtRTEI);
            if (n > 0) {
                emlrtDynamicBoundsCheck(1, 1, dtAccumulation->size[1], &kc_emlrtBCI);
                dtAccumulation->data[0] = r;
                if (n > 1) {
                    dtAccumulation->data[emlrtDynamicBoundsCheck(n, 1, dtAccumulation->size[1], &ec_emlrtBCI) - 1] = apnd;
                    ixstart = n - 1;
                    qEnd = ixstart;
                    nm1d2 = (int32_T)((uint32_T)qEnd >> 1);
                    for (c_k = 1; c_k <= nm1d2 - 1; c_k++) {
                        dtAccumulation->data[emlrtDynamicBoundsCheck(c_k + 1, 1, dtAccumulation->size[1], &kb_emlrtBCI) - 1] = r + (real_T)c_k;
                        dtAccumulation->data[emlrtDynamicBoundsCheck(n - c_k, 1, dtAccumulation->size[1], &jb_emlrtBCI) - 1] = apnd - (real_T)c_k;
                    }
                    if (nm1d2 << 1 == ixstart) {
                        dtAccumulation->data[emlrtDynamicBoundsCheck(nm1d2 + 1, 1, dtAccumulation->size[1], &bc_emlrtBCI) - 1] = (r + apnd) / 2.0;
                    } else {
                        dtAccumulation->data[emlrtDynamicBoundsCheck(nm1d2 + 1, 1, dtAccumulation->size[1], &dc_emlrtBCI) - 1] = r + (real_T)nm1d2;
                        dtAccumulation->data[emlrtDynamicBoundsCheck(nm1d2 + 2, 1, dtAccumulation->size[1], &cc_emlrtBCI) - 1] = apnd - (real_T)nm1d2;
                    }
                }
            }
            emxInit_real_T(&r9, 2, &emlrtRTEI, TRUE);
            EMLRTPOPRTSTACK(&tb_emlrtRSI);
            EMLRTPOPRTSTACK(&n_emlrtRSI);
            /*  Compute activation trajectories for all accumulators */
            /* 'epu_n_unit_ba:103' activation = repmat(v,tMax+1,1)./repmat(k,tMax+1,1) + (repmat(x0,tMax+1,nA) - repmat(v,tMax+1,1)./repmat(k,tMax+1,1)).*exp(repmat(-k,tMax+1,1).*repmat(t',1,nA)); */
            EMLRTPUSHRTSTACK(&p_emlrtRSI);
            b_repmat(tMax + 1.0, (real_T)v->size[1], r2);
            EMLRTPOPRTSTACK(&p_emlrtRSI);
            EMLRTPUSHRTSTACK(&q_emlrtRSI);
            repmat(v, tMax + 1.0, r4);
            repmat(k, tMax + 1.0, r5);
            qEnd = r9->size[0] * r9->size[1];
            r9->size[0] = r4->size[0];
            r9->size[1] = r4->size[1];
            emxEnsureCapacity((emxArray__common *)r9, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
            q = r4->size[0] * r4->size[1] - 1;
            for (qEnd = 0; qEnd <= q; qEnd++) {
                r9->data[qEnd] = r4->data[qEnd];
            }
            b_rdivide(r9, r5, r4);
            EMLRTPOPRTSTACK(&q_emlrtRSI);
            emxFree_real_T(&r9);
            for (qEnd = 0; qEnd < 2; qEnd++) {
                iv0[qEnd] = r2->size[qEnd];
            }
            for (qEnd = 0; qEnd < 2; qEnd++) {
                b_theta[qEnd] = r4->size[qEnd];
            }
            emxInit_real_T(&g_k, 2, &emlrtRTEI, TRUE);
            emlrtSizeEqCheckND(iv0, b_theta, &h_emlrtECI);
            EMLRTPUSHRTSTACK(&r_emlrtRSI);
            qEnd = g_k->size[0] * g_k->size[1];
            g_k->size[0] = 1;
            g_k->size[1] = k->size[1];
            emxEnsureCapacity((emxArray__common *)g_k, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
            q = k->size[0] * k->size[1] - 1;
            for (qEnd = 0; qEnd <= q; qEnd++) {
                g_k->data[qEnd] = -k->data[qEnd];
            }
            b_emxInit_real_T(&c_dtAccumulation, 1, &emlrtRTEI, TRUE);
            repmat(g_k, tMax + 1.0, x);
            EMLRTPOPRTSTACK(&r_emlrtRSI);
            EMLRTPUSHRTSTACK(&s_emlrtRSI);
            qEnd = c_dtAccumulation->size[0];
            c_dtAccumulation->size[0] = dtAccumulation->size[1];
            emxEnsureCapacity((emxArray__common *)c_dtAccumulation, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
            emxFree_real_T(&g_k);
            q = dtAccumulation->size[1] - 1;
            for (qEnd = 0; qEnd <= q; qEnd++) {
                c_dtAccumulation->data[qEnd] = dtAccumulation->data[qEnd];
            }
            c_repmat(c_dtAccumulation, (real_T)v->size[1], r5);
            EMLRTPOPRTSTACK(&s_emlrtRSI);
            emxFree_real_T(&c_dtAccumulation);
            for (qEnd = 0; qEnd < 2; qEnd++) {
                b_theta[qEnd] = x->size[qEnd];
            }
            for (qEnd = 0; qEnd < 2; qEnd++) {
                iv0[qEnd] = r5->size[qEnd];
            }
            emlrtSizeEqCheckND(b_theta, iv0, &i_emlrtECI);
            EMLRTPUSHRTSTACK(&t_emlrtRSI);
            qEnd = x->size[0] * x->size[1];
            emxEnsureCapacity((emxArray__common *)x, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
            ixstart = x->size[0];
            nm1d2 = x->size[1];
            q = ixstart * nm1d2 - 1;
            for (qEnd = 0; qEnd <= q; qEnd++) {
                x->data[qEnd] *= r5->data[qEnd];
            }
            qEnd = emlrtBoundsCheck(x->size[0] * x->size[1], &lc_emlrtBCI);
            for (c_k = 0; c_k <= qEnd - 1; c_k++) {
                emlrtDynamicBoundsCheck((int32_T)(1.0 + (real_T)c_k), 1, x->size[0] * x->size[1], &mc_emlrtBCI);
                x->data[emlrtDynamicBoundsCheck(1 + c_k, 1, x->size[0] * x->size[1], &lb_emlrtBCI) - 1] = muDoubleScalarExp(x->data[c_k]);
            }
            EMLRTPOPRTSTACK(&t_emlrtRSI);
            for (qEnd = 0; qEnd < 2; qEnd++) {
                iv0[qEnd] = r2->size[qEnd];
            }
            for (qEnd = 0; qEnd < 2; qEnd++) {
                b_theta[qEnd] = x->size[qEnd];
            }
            emlrtSizeEqCheckND(iv0, b_theta, &j_emlrtECI);
            EMLRTPUSHRTSTACK(&o_emlrtRSI);
            repmat(v, tMax + 1.0, r5);
            repmat(k, tMax + 1.0, r3);
            b_rdivide(r5, r3, activation);
            EMLRTPOPRTSTACK(&o_emlrtRSI);
            qEnd = r2->size[0] * r2->size[1];
            emxEnsureCapacity((emxArray__common *)r2, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
            qEnd = r2->size[0];
            pEnd = r2->size[1];
            q = qEnd * pEnd - 1;
            for (qEnd = 0; qEnd <= q; qEnd++) {
                r2->data[qEnd] = (r2->data[qEnd] - r4->data[qEnd]) * x->data[qEnd];
            }
            for (qEnd = 0; qEnd < 2; qEnd++) {
                b_theta[qEnd] = activation->size[qEnd];
            }
            for (qEnd = 0; qEnd < 2; qEnd++) {
                iv0[qEnd] = r2->size[qEnd];
            }
            emlrtSizeEqCheckND(b_theta, iv0, &k_emlrtECI);
            qEnd = activation->size[0] * activation->size[1];
            emxEnsureCapacity((emxArray__common *)activation, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
            j2 = activation->size[0];
            ixstart = activation->size[1];
            q = j2 * ixstart - 1;
            for (qEnd = 0; qEnd <= q; qEnd++) {
                activation->data[qEnd] += r2->data[qEnd];
            }
            /*  Compute average activation trajectory across accumulators */
            /* 'epu_n_unit_ba:106' meanActivation = mean(activation,2); */
            EMLRTPUSHRTSTACK(&u_emlrtRSI);
            mean(activation, meanActivation);
            EMLRTPOPRTSTACK(&u_emlrtRSI);
            /* 'epu_n_unit_ba:107' accumulationTime = interp1(meanActivation,t,mean(theta)); */
            EMLRTPUSHRTSTACK(&v_emlrtRSI);
            EMLRTPUSHRTSTACK(&pc_emlrtRSI);
            EMLRTPUSHRTSTACK(&tc_emlrtRSI);
            p = FALSE;
            EMLRTPUSHRTSTACK(&uc_emlrtRSI);
            EMLRTPUSHRTSTACK(&vc_emlrtRSI);
            n_too_large = FALSE;
            c_k = 0;
            do {
                exitg2 = 0U;
                if (c_k < 2) {
                    qEnd = theta->size[c_k];
                    if (qEnd != 0) {
                        exitg2 = 1U;
                    } else {
                        c_k++;
                    }
                } else {
                    n_too_large = TRUE;
                    exitg2 = 1U;
                }
            } while (exitg2 == 0U);
            EMLRTPOPRTSTACK(&vc_emlrtRSI);
            if (n_too_large) {
                n_too_large = TRUE;
            } else {
                n_too_large = FALSE;
            }
            EMLRTPOPRTSTACK(&uc_emlrtRSI);
            if (!n_too_large) {
            } else {
                p = TRUE;
            }
            EMLRTPOPRTSTACK(&tc_emlrtRSI);
            EMLRTPOPRTSTACK(&pc_emlrtRSI);
            if (!p) {
                n_too_large = TRUE;
            } else {
                n_too_large = FALSE;
            }
            if (n_too_large) {
            } else {
                EMLRTPUSHRTSTACK(&qc_emlrtRSI);
                f_y = NULL;
                m0 = mxCreateCharArray(2, iv5);
                emlrtInitCharArray(31, m0, cv3);
                emlrtAssign(&f_y, m0);
                error(message(f_y, &u_emlrtMCI), &v_emlrtMCI);
                EMLRTPOPRTSTACK(&qc_emlrtRSI);
            }
            if ((theta->size[1] == 1) || (theta->size[1] != 1)) {
                n_too_large = TRUE;
            } else {
                n_too_large = FALSE;
            }
            if (n_too_large) {
            } else {
                EMLRTPUSHRTSTACK(&rc_emlrtRSI);
                g_y = NULL;
                m0 = mxCreateCharArray(2, iv6);
                emlrtInitCharArray(36, m0, cv1);
                emlrtAssign(&g_y, m0);
                error(message(g_y, &w_emlrtMCI), &x_emlrtMCI);
                EMLRTPOPRTSTACK(&rc_emlrtRSI);
            }
            EMLRTPUSHRTSTACK(&sc_emlrtRSI);
            EMLRTPUSHRTSTACK(&wc_emlrtRSI);
            EMLRTPOPRTSTACK(&wc_emlrtRSI);
            if (theta->size[1] == 0) {
                tMax = 0.0;
            } else {
                ixstart = theta->size[1];
                emlrtDynamicBoundsCheck(1, 1, theta->size[1], &nc_emlrtBCI);
                tMax = theta->data[0];
                for (c_k = 2; c_k <= ixstart; c_k++) {
                    tMax += theta->data[emlrtDynamicBoundsCheck(c_k, 1, theta->size[1], &ac_emlrtBCI) - 1];
                }
            }
            tMax /= (real_T)theta->size[1];
            EMLRTPOPRTSTACK(&sc_emlrtRSI);
            EMLRTPUSHRTSTACK(&xc_emlrtRSI);
            qEnd = b_x->size[0];
            b_x->size[0] = meanActivation->size[0];
            emxEnsureCapacity((emxArray__common *)b_x, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
            q = meanActivation->size[0] - 1;
            for (qEnd = 0; qEnd <= q; qEnd++) {
                b_x->data[qEnd] = meanActivation->data[qEnd];
            }
            nx = emlrtBoundsCheck(meanActivation->size[0], &oc_emlrtBCI);
            if (nx == dtAccumulation->size[1]) {
            } else {
                EMLRTPUSHRTSTACK(&yc_emlrtRSI);
                h_y = NULL;
                m0 = mxCreateCharArray(2, iv7);
                emlrtInitCharArray(35, m0, cv4);
                emlrtAssign(&h_y, m0);
                error(message(h_y, &y_emlrtMCI), &ab_emlrtMCI);
                EMLRTPOPRTSTACK(&yc_emlrtRSI);
            }
            if (nx > 1) {
            } else {
                EMLRTPUSHRTSTACK(&ad_emlrtRSI);
                i_y = NULL;
                m0 = mxCreateCharArray(2, iv8);
                emlrtInitCharArray(27, m0, cv5);
                emlrtAssign(&i_y, m0);
                error(message(i_y, &bb_emlrtMCI), &cb_emlrtMCI);
                EMLRTPOPRTSTACK(&ad_emlrtRSI);
            }
            ndbl = rtNaN;
            c_k = 1;
            emxInit_int32_T(&r10, 2, &emlrtRTEI, TRUE);
            b_emxInit_int32_T(&r11, 1, &emlrtRTEI, TRUE);
            do {
                exitg1 = 0U;
                if (c_k <= nx) {
                    emlrtDynamicBoundsCheck(c_k, 1, meanActivation->size[0], &pc_emlrtBCI);
                    if (muDoubleScalarIsNaN(meanActivation->data[c_k - 1])) {
                        EMLRTPUSHRTSTACK(&bd_emlrtRSI);
                        b_eml_error();
                        EMLRTPOPRTSTACK(&bd_emlrtRSI);
                        exitg1 = 1U;
                    } else {
                        c_k++;
                    }
                } else {
                    emlrtDynamicBoundsCheck(2, 1, meanActivation->size[0], &qc_emlrtBCI);
                    emlrtDynamicBoundsCheck(1, 1, meanActivation->size[0], &rc_emlrtBCI);
                    if (meanActivation->data[1] < meanActivation->data[0]) {
                        emlrtBoundsCheck(meanActivation->size[0], &sc_emlrtBCI);
                        if (1 > meanActivation->size[0]) {
                            qEnd = 1;
                            pEnd = 1;
                            nm1d2 = 0;
                        } else {
                            qEnd = emlrtDynamicBoundsCheck(meanActivation->size[0], 1, meanActivation->size[0], &tc_emlrtBCI);
                            pEnd = -1;
                            nm1d2 = 1;
                        }
                        ixstart = r11->size[0];
                        r11->size[0] = (nm1d2 - qEnd) / pEnd + 1;
                        emxEnsureCapacity((emxArray__common *)r11, ixstart, (int32_T)sizeof(int32_T), &emlrtRTEI);
                        q = (nm1d2 - qEnd) / pEnd;
                        for (nm1d2 = 0; nm1d2 <= q; nm1d2++) {
                            r11->data[nm1d2] = qEnd + pEnd * nm1d2;
                        }
                        qEnd = r10->size[0] * r10->size[1];
                        r10->size[0] = 1;
                        emxEnsureCapacity((emxArray__common *)r10, qEnd, (int32_T)sizeof(int32_T), &emlrtRTEI);
                        j2 = r11->size[0];
                        qEnd = r10->size[0] * r10->size[1];
                        r10->size[1] = j2;
                        emxEnsureCapacity((emxArray__common *)r10, qEnd, (int32_T)sizeof(int32_T), &emlrtRTEI);
                        q = r11->size[0] - 1;
                        for (qEnd = 0; qEnd <= q; qEnd++) {
                            r10->data[qEnd] = r11->data[qEnd];
                        }
                        emlrtVectorVectorIndexCheck(meanActivation->size[0], 1, 1, r10->size[1], &m_emlrtECI);
                        qEnd = b_x->size[0];
                        b_x->size[0] = r10->size[1];
                        emxEnsureCapacity((emxArray__common *)b_x, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
                        q = r10->size[1] - 1;
                        for (qEnd = 0; qEnd <= q; qEnd++) {
                            b_x->data[qEnd] = meanActivation->data[r10->data[qEnd] - 1];
                        }
                        EMLRTPUSHRTSTACK(&cd_emlrtRSI);
                        n = dtAccumulation->size[1];
                        qEnd = n + (n < 0);
                        ixstart = qEnd >= 0 ? (int32_T)((uint32_T)qEnd >> 1) : ~(int32_T)((uint32_T)~qEnd >> 1);
                        for (nm1d2 = 1; nm1d2 <= ixstart; nm1d2++) {
                            j2 = (n - nm1d2) + 1;
                            r = dtAccumulation->data[dtAccumulation->size[0] * (emlrtDynamicBoundsCheck(nm1d2, 1, dtAccumulation->size[1], &rb_emlrtBCI) - 1)];
                            dtAccumulation->data[dtAccumulation->size[0] * (emlrtDynamicBoundsCheck(nm1d2, 1, dtAccumulation->size[1], &qb_emlrtBCI) - 1)] = dtAccumulation->data[dtAccumulation->size[0] * (emlrtDynamicBoundsCheck(j2, 1, dtAccumulation->size[1], &pb_emlrtBCI) - 1)];
                            dtAccumulation->data[dtAccumulation->size[0] * (emlrtDynamicBoundsCheck(j2, 1, dtAccumulation->size[1], &ob_emlrtBCI) - 1)] = r;
                        }
                        EMLRTPOPRTSTACK(&cd_emlrtRSI);
                    }
                    for (c_k = 2; c_k <= nx; c_k++) {
                        if (b_x->data[emlrtDynamicBoundsCheck(c_k, 1, b_x->size[0], &tb_emlrtBCI) - 1] <= b_x->data[emlrtDynamicBoundsCheck(c_k - 1, 1, b_x->size[0], &sb_emlrtBCI) - 1]) {
                            EMLRTPUSHRTSTACK(&dd_emlrtRSI);
                            c_eml_error();
                            EMLRTPOPRTSTACK(&dd_emlrtRSI);
                        }
                    }
                    emlrtDynamicBoundsCheck(1, 1, b_x->size[0], &uc_emlrtBCI);
                    emlrtDynamicBoundsCheck(emlrtBoundsCheck(b_x->size[0], &vc_emlrtBCI), 1, b_x->size[0], &wc_emlrtBCI);
                    n = 0;
                    if ((tMax > b_x->data[b_x->size[0] - 1]) || (tMax < b_x->data[0])) {
                    } else {
                        EMLRTPUSHRTSTACK(&ed_emlrtRSI);
                        low_i = 1U;
                        low_ip1 = 2U;
                        high_i = (uint32_T)emlrtBoundsCheck(b_x->size[0], &yc_emlrtBCI);
                        while (high_i > low_ip1) {
                            EMLRTPUSHRTSTACK(&hd_emlrtRSI);
                            mid_i = (low_i >> 1U) + (high_i >> 1U);
                            if (((low_i & 1U) == 1U) && ((high_i & 1U) == 1U)) {
                                mid_i++;
                            }
                            EMLRTPOPRTSTACK(&hd_emlrtRSI);
                            if (tMax >= b_x->data[(int32_T)(uint32_T)emlrtDynamicBoundsCheck((int32_T)mid_i, 1, b_x->size[0], &xb_emlrtBCI) - 1]) {
                                low_i = mid_i;
                                low_ip1 = mid_i + 1U;
                            } else {
                                high_i = mid_i;
                            }
                        }
                        n = (int32_T)low_i;
                        EMLRTPOPRTSTACK(&ed_emlrtRSI);
                        emlrtDynamicBoundsCheck((int32_T)low_i, 1, b_x->size[0], &xc_emlrtBCI);
                        r = (tMax - b_x->data[(int32_T)low_i - 1]) / (b_x->data[emlrtDynamicBoundsCheck((int32_T)low_i + 1, 1, b_x->size[0], &yb_emlrtBCI) - 1] - b_x->data[(int32_T)low_i - 1]);
                    }
                    if (n > 0) {
                        tMax = dtAccumulation->data[emlrtDynamicBoundsCheck(n + 1, 1, dtAccumulation->size[1], &wb_emlrtBCI) - 1] - dtAccumulation->data[emlrtDynamicBoundsCheck(n, 1, dtAccumulation->size[1], &vb_emlrtBCI) - 1];
                        ndbl = dtAccumulation->data[emlrtDynamicBoundsCheck(n, 1, dtAccumulation->size[1], &ub_emlrtBCI) - 1] + r * tMax;
                    }
                    exitg1 = 1U;
                }
            } while (exitg1 == 0U);
            emxFree_int32_T(&r11);
            emxFree_int32_T(&r10);
            emxInit_real_T(&r12, 2, &emlrtRTEI, TRUE);
            EMLRTPOPRTSTACK(&xc_emlrtRSI);
            EMLRTPOPRTSTACK(&v_emlrtRSI);
            /*  Compute RT  */
            /* 'epu_n_unit_ba:110' rt(1) = affTime + accumulationTime + effTime; */
            *rt = (affTime + ndbl) + effTime;
            /*  Compute activation trajectories for all accumulators, including affTime */
            /*  time points */
            /* 'epu_n_unit_ba:114' activation = [zeros(floor(affTime),nA);activation]; */
            tMax = muDoubleScalarFloor(affTime);
            emlrtNonNegativeCheckR2009b(tMax, &g_emlrtDCI);
            nm1d2 = v->size[1];
            emlrtDimSizeEqCheck(nm1d2, activation->size[1], &l_emlrtECI);
            nm1d2 = v->size[1];
            qEnd = r12->size[0] * r12->size[1];
            r12->size[0] = (int32_T)tMax + activation->size[0];
            r12->size[1] = nm1d2;
            emxEnsureCapacity((emxArray__common *)r12, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
            q = nm1d2 - 1;
            for (qEnd = 0; qEnd <= q; qEnd++) {
                ixstart = (int32_T)tMax - 1;
                for (pEnd = 0; pEnd <= ixstart; pEnd++) {
                    r12->data[pEnd + r12->size[0] * qEnd] = 0.0;
                }
            }
            q = activation->size[1] - 1;
            for (qEnd = 0; qEnd <= q; qEnd++) {
                ixstart = activation->size[0] - 1;
                for (pEnd = 0; pEnd <= ixstart; pEnd++) {
                    r12->data[(pEnd + (int32_T)tMax) + r12->size[0] * qEnd] = activation->data[pEnd + activation->size[0] * qEnd];
                }
            }
            qEnd = activation->size[0] * activation->size[1];
            activation->size[0] = r12->size[0];
            activation->size[1] = r12->size[1];
            emxEnsureCapacity((emxArray__common *)activation, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
            q = r12->size[1] - 1;
            for (qEnd = 0; qEnd <= q; qEnd++) {
                ixstart = r12->size[0] - 1;
                for (pEnd = 0; pEnd <= ixstart; pEnd++) {
                    activation->data[pEnd + activation->size[0] * qEnd] = r12->data[pEnd + r12->size[0] * qEnd];
                }
            }
            emxFree_real_T(&r12);
            emxInit_real_T(&r13, 2, &emlrtRTEI, TRUE);
            /*  Maximum time for trajectories */
            /* 'epu_n_unit_ba:117' tMax = ceil(rt); */
            /*  Only use activation trajectories of iAT */
            /* 'epu_n_unit_ba:120' activation = activation(1:tMax+1,iAT); */
            qEnd = r13->size[0] * r13->size[1];
            r13->size[0] = 1;
            r13->size[1] = iAT->size[1];
            emxEnsureCapacity((emxArray__common *)r13, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
            q = iAT->size[0] * iAT->size[1] - 1;
            for (qEnd = 0; qEnd <= q; qEnd++) {
                r13->data[qEnd] = (real_T)emlrtDynamicBoundsCheck((int32_T)emlrtIntegerCheckR2009b(iAT->data[qEnd], &d_emlrtDCI), 1, activation->size[1], &nb_emlrtBCI);
            }
            emxInit_real_T(&b_activation, 2, &emlrtRTEI, TRUE);
            tMax = muDoubleScalarCeil(*rt);
            j2 = activation->size[0];
            nm1d2 = r13->size[1];
            qEnd = b_activation->size[0] * b_activation->size[1];
            b_activation->size[0] = (int32_T)tMax + 1;
            b_activation->size[1] = nm1d2;
            emxEnsureCapacity((emxArray__common *)b_activation, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
            q = nm1d2 - 1;
            for (qEnd = 0; qEnd <= q; qEnd++) {
                for (pEnd = 0; pEnd <= (int32_T)tMax; pEnd++) {
                    b_activation->data[pEnd + b_activation->size[0] * qEnd] = activation->data[(emlrtDynamicBoundsCheck((int32_T)emlrtIntegerCheckR2009b(1.0 + (real_T)pEnd, &c_emlrtDCI), 1, j2, &mb_emlrtBCI) + activation->size[0] * ((int32_T)r13->data[qEnd] - 1)) - 1];
                }
            }
            emxFree_real_T(&r13);
            qEnd = activation->size[0] * activation->size[1];
            activation->size[0] = b_activation->size[0];
            activation->size[1] = b_activation->size[1];
            emxEnsureCapacity((emxArray__common *)activation, qEnd, (int32_T)sizeof(real_T), &emlrtRTEI);
            q = b_activation->size[1] - 1;
            for (qEnd = 0; qEnd <= q; qEnd++) {
                ixstart = b_activation->size[0] - 1;
                for (pEnd = 0; pEnd <= ixstart; pEnd++) {
                    activation->data[pEnd + activation->size[0] * qEnd] = b_activation->data[pEnd + b_activation->size[0] * qEnd];
                }
            }
            emxFree_real_T(&b_activation);
        }
    }
    emxFree_real_T(&r5);
    emxFree_real_T(&r4);
    emxFree_real_T(&r3);
    emxFree_real_T(&b_x);
    emxFree_real_T(&x);
    emxFree_real_T(&r2);
    emxFree_real_T(&r0);
    emxFree_real_T(&meanActivation);
    emxFree_real_T(&dtAccumulation);
    emlrtHeapReferenceStackLeaveFcn();
}
/* End of code generation (epu_n_unit_ba.c) */
