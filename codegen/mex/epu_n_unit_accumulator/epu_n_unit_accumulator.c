/*
 * epu_n_unit_accumulator.c
 *
 * Code generation for function 'epu_n_unit_accumulator'
 *
 * C source code generated on: Fri Aug 31 09:23:48 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_accumulator.h"
#include "randn.h"
#include "epu_n_unit_accumulator_emxutil.h"
#include "interp1.h"
#include "colon.h"
#include "rdivide.h"
#include "interp1q.h"
#include "all.h"
#include "mrdivide.h"
#include "sum.h"
#include "sqrt.h"
#include "mean.h"
#include "epu_n_unit_accumulator_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 150, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtRSInfo b_emlrtRSI = { 159, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtRSInfo c_emlrtRSI = { 162, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtRSInfo d_emlrtRSI = { 165, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtRSInfo e_emlrtRSI = { 168, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtRSInfo f_emlrtRSI = { 170, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtRSInfo g_emlrtRSI = { 174, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtRSInfo h_emlrtRSI = { 174, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtRSInfo i_emlrtRSI = { 174, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtRSInfo j_emlrtRSI = { 181, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtRSInfo k_emlrtRSI = { 204, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtRSInfo l_emlrtRSI = { 208, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtRSInfo m_emlrtRSI = { 211, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtRSInfo n_emlrtRSI = { 214, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtRSInfo o_emlrtRSI = { 217, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtRSInfo p_emlrtRSI = { 224, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtRSInfo q_emlrtRSI = { 253, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtRSInfo r_emlrtRSI = { 254, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtRSInfo gb_emlrtRSI = { 55, "mtimes", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };
static emlrtRSInfo hb_emlrtRSI = { 21, "mtimes", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };
static emlrtRSInfo ib_emlrtRSI = { 84, "mtimes", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };
static emlrtRSInfo jb_emlrtRSI = { 89, "mtimes", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };
static emlrtRSInfo kb_emlrtRSI = { 54, "eml_xgemm", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m" };
static emlrtRSInfo mb_emlrtRSI = { 32, "eml_blas_xgemm", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m" };
static emlrtRSInfo nb_emlrtRSI = { 103, "eml_blas_xgemm", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m" };
static emlrtRSInfo qb_emlrtRSI = { 11, "eml_li_find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m" };
static emlrtRSInfo rb_emlrtRSI = { 14, "eml_li_find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m" };
static emlrtRSInfo vb_emlrtRSI = { 16, "min", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/min.m" };
static emlrtRSInfo wb_emlrtRSI = { 18, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtRSInfo xb_emlrtRSI = { 38, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtRSInfo yb_emlrtRSI = { 73, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtRSInfo ac_emlrtRSI = { 88, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtRSInfo bc_emlrtRSI = { 41, "find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/find.m" };
static emlrtRSInfo dc_emlrtRSI = { 239, "find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/find.m" };
static emlrtRSInfo nc_emlrtRSI = { 79, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRSInfo oc_emlrtRSI = { 117, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRSInfo pc_emlrtRSI = { 233, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRSInfo qc_emlrtRSI = { 21, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRSInfo rc_emlrtRSI = { 79, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRSInfo sc_emlrtRSI = { 117, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRSInfo tc_emlrtRSI = { 32, "interp1", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1.m" };
static emlrtMCInfo e_emlrtMCI = { 85, 13, "mtimes", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };
static emlrtMCInfo f_emlrtMCI = { 84, 23, "mtimes", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };
static emlrtMCInfo g_emlrtMCI = { 90, 13, "mtimes", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };
static emlrtMCInfo h_emlrtMCI = { 89, 23, "mtimes", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };
static emlrtMCInfo k_emlrtMCI = { 14, 5, "eml_li_find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m" };
static emlrtMCInfo p_emlrtMCI = { 41, 9, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtMCInfo q_emlrtMCI = { 38, 19, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtMCInfo r_emlrtMCI = { 74, 9, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtMCInfo s_emlrtMCI = { 73, 19, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtMCInfo u_emlrtMCI = { 239, 9, "find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/find.m" };
static emlrtMCInfo ab_emlrtMCI = { 234, 5, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtMCInfo bb_emlrtMCI = { 233, 15, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRTEInfo emlrtRTEI = { 1, 28, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtRTEInfo b_emlrtRTEI = { 118, 1, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRTEInfo c_emlrtRTEI = { 46, 1, "mtimes", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };
static emlrtRTEInfo d_emlrtRTEI = { 118, 1, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRTEInfo e_emlrtRTEI = { 111, 5, "find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/find.m" };
static emlrtRTEInfo f_emlrtRTEI = { 173, 10, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtRTEInfo g_emlrtRTEI = { 174, 10, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtRTEInfo h_emlrtRTEI = { 203, 4, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtRTEInfo i_emlrtRTEI = { 33, 6, "find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/find.m" };
static emlrtRTEInfo k_emlrtRTEI = { 17, 9, "eml_li_find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m" };
static emlrtDCInfo emlrtDCI = { 143, 21, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 4 };
static emlrtDCInfo b_emlrtDCI = { 143, 48, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 4 };
static emlrtECInfo emlrtECI = { 2, 143, 14, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtECInfo b_emlrtECI = { 2, 159, 12, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtBCInfo emlrtBCI = { -1, -1, 162, 38, "activation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtBCInfo b_emlrtBCI = { -1, -1, 162, 75, "activation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtECInfo c_emlrtECI = { 2, 162, 61, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtECInfo d_emlrtECI = { 2, 162, 59, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtECInfo e_emlrtECI = { 2, 162, 27, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtECInfo f_emlrtECI = { 2, 162, 27, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtBCInfo c_emlrtBCI = { -1, -1, 162, 18, "activation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtECInfo g_emlrtECI = { -1, 162, 7, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtBCInfo d_emlrtBCI = { -1, -1, 165, 18, "activation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtBCInfo e_emlrtBCI = { -1, -1, 165, 34, "activation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtBCInfo f_emlrtBCI = { -1, -1, 168, 29, "activation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtECInfo h_emlrtECI = { 2, 168, 18, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtBCInfo g_emlrtBCI = { -1, -1, 173, 32, "activation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtECInfo i_emlrtECI = { 2, 173, 21, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtBCInfo h_emlrtBCI = { -1, -1, 174, 38, "activation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtECInfo j_emlrtECI = { 2, 174, 27, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtBCInfo i_emlrtBCI = { -1, -1, 174, 71, "activation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtECInfo k_emlrtECI = { 2, 174, 60, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtBCInfo j_emlrtBCI = { -1, -1, 175, 22, "iCritical", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtBCInfo k_emlrtBCI = { -1, -1, 177, 48, "activation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtBCInfo l_emlrtBCI = { -1, -1, 179, 22, "theta", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtECInfo l_emlrtECI = { 2, 208, 12, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtBCInfo m_emlrtBCI = { -1, -1, 211, 38, "activation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtBCInfo n_emlrtBCI = { -1, -1, 211, 75, "activation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtECInfo m_emlrtECI = { 2, 211, 61, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtECInfo n_emlrtECI = { 2, 211, 59, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtECInfo o_emlrtECI = { 2, 211, 27, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtECInfo p_emlrtECI = { 2, 211, 27, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtBCInfo o_emlrtBCI = { -1, -1, 211, 18, "activation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtECInfo q_emlrtECI = { -1, 211, 7, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtBCInfo p_emlrtBCI = { -1, -1, 214, 18, "activation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtBCInfo q_emlrtBCI = { -1, -1, 214, 34, "activation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtBCInfo r_emlrtBCI = { -1, -1, 217, 42, "activation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtECInfo r_emlrtECI = { -1, 221, 27, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m" };
static emlrtBCInfo s_emlrtBCI = { -1, -1, 105, 24, "", "eml_blas_xgemm", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m", 0 };
static emlrtBCInfo t_emlrtBCI = { -1, -1, 106, 5, "", "eml_blas_xgemm", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m", 0 };
static emlrtBCInfo u_emlrtBCI = { -1, -1, 107, 23, "", "eml_blas_xgemm", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m", 0 };
static emlrtBCInfo v_emlrtBCI = { -1, -1, 105, 24, "", "eml_blas_xgemm", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m", 0 };
static emlrtBCInfo w_emlrtBCI = { -1, -1, 106, 5, "", "eml_blas_xgemm", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m", 0 };
static emlrtBCInfo x_emlrtBCI = { -1, -1, 107, 23, "", "eml_blas_xgemm", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m", 0 };
static emlrtBCInfo y_emlrtBCI = { -1, -1, 178, 12, "", "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m", 0 };
static emlrtBCInfo ab_emlrtBCI = { -1, -1, 198, 27, "", "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m", 0 };
static emlrtBCInfo bb_emlrtBCI = { -1, -1, 218, 32, "", "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m", 0 };
static emlrtBCInfo cb_emlrtBCI = { -1, -1, 249, 17, "", "find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/find.m", 0 };
static emlrtBCInfo db_emlrtBCI = { -1, -1, 249, 17, "", "find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/find.m", 0 };
static emlrtDCInfo c_emlrtDCI = { 118, 28, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 4 };
static emlrtBCInfo eb_emlrtBCI = { -1, -1, 120, 5, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtDCInfo d_emlrtDCI = { 118, 28, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 4 };
static emlrtBCInfo fb_emlrtBCI = { -1, -1, 120, 5, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtDCInfo e_emlrtDCI = { 203, 24, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 1 };
static emlrtDCInfo f_emlrtDCI = { 203, 24, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 4 };
static emlrtDCInfo g_emlrtDCI = { 203, 24, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 1 };
static emlrtDCInfo h_emlrtDCI = { 203, 24, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 4 };
static emlrtBCInfo gb_emlrtBCI = { -1, -1, 214, 23, "activation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtBCInfo hb_emlrtBCI = { -1, -1, 217, 7, "mActivation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtBCInfo ib_emlrtBCI = { -1, -1, 219, 27, "mActivation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtBCInfo jb_emlrtBCI = { -1, -1, 221, 27, "mActivation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtBCInfo kb_emlrtBCI = { -1, -1, 240, 36, "activation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtDCInfo i_emlrtDCI = { 240, 36, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 1 };
static emlrtBCInfo lb_emlrtBCI = { -1, -1, 230, 36, "activation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtDCInfo j_emlrtDCI = { 230, 36, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 1 };
static emlrtBCInfo mb_emlrtBCI = { -1, -1, 165, 23, "activation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtBCInfo nb_emlrtBCI = { -1, -1, 174, 75, "activation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtBCInfo ob_emlrtBCI = { -1, -1, 174, 85, "theta", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtBCInfo pb_emlrtBCI = { -1, -1, 199, 32, "", "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m", 0 };
static emlrtBCInfo qb_emlrtBCI = { -1, -1, 231, 33, "", "find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/find.m", 0 };
static emlrtBCInfo rb_emlrtBCI = { -1, -1, 233, 17, "", "find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/find.m", 0 };
static emlrtBCInfo sb_emlrtBCI = { -1, -1, 177, 38, "activation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtBCInfo tb_emlrtBCI = { -1, -1, 195, 36, "activation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtDCInfo k_emlrtDCI = { 195, 36, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 1 };
static emlrtBCInfo ub_emlrtBCI = { -1, -1, 188, 39, "activation", "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 0 };
static emlrtDCInfo l_emlrtDCI = { 188, 39, "epu_n_unit_accumulator", "/Users/bram/Documents/EPU/Simulation_2012Aug28/m-files/epu_n_unit_accumulator.m", 1 };
static emlrtBCInfo vb_emlrtBCI = { -1, -1, 122, 9, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo wb_emlrtBCI = { -1, -1, 134, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo xb_emlrtBCI = { -1, -1, 135, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo yb_emlrtBCI = { -1, -1, 131, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo ac_emlrtBCI = { -1, -1, 122, 9, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo bc_emlrtBCI = { -1, -1, 134, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo cc_emlrtBCI = { -1, -1, 135, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo dc_emlrtBCI = { -1, -1, 131, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo ec_emlrtBCI = { -1, -1, 127, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo fc_emlrtBCI = { -1, -1, 128, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo gc_emlrtBCI = { -1, -1, 127, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo hc_emlrtBCI = { -1, -1, 128, 13, "", "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m", 0 };
static emlrtBCInfo ic_emlrtBCI = { -1, -1, 219, 28, "", "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m", 0 };
static emlrtDCInfo o_emlrtDCI = { 17, 37, "eml_li_find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m", 4 };
static emlrtBCInfo mc_emlrtBCI = { -1, -1, 27, 12, "", "eml_li_find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m", 0 };
static emlrtBCInfo nc_emlrtBCI = { -1, -1, 28, 13, "", "eml_li_find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m", 0 };
static emlrtBCInfo oc_emlrtBCI = { -1, -1, 40, 12, "", "eml_li_find", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m", 0 };

/* Function Declarations */
static void eml_li_find(const emxArray_boolean_T *x, emxArray_int32_T *y);

/* Function Definitions */

/*
 * 
 */
static void eml_li_find(const emxArray_boolean_T *x, emxArray_int32_T *y)
{
    int32_T n;
    int32_T k;
    int32_T i;
    const mxArray *b_y;
    const mxArray *m3;
    int32_T j;
    n = x->size[1];
    EMLRTPUSHRTSTACK(&qb_emlrtRSI);
    k = 0;
    for (i = 1; i <= n; i++) {
        if (x->data[emlrtDynamicBoundsCheck(i, 1, x->size[1], &oc_emlrtBCI) - 1]) {
            k++;
        }
    }
    EMLRTPOPRTSTACK(&qb_emlrtRSI);
    if (k <= n) {
    } else {
        EMLRTPUSHRTSTACK(&rb_emlrtRSI);
        b_y = NULL;
        m3 = mxCreateString("Assertion failed.");
        emlrtAssign(&b_y, m3);
        error(b_y, &k_emlrtMCI);
        EMLRTPOPRTSTACK(&rb_emlrtRSI);
    }
    emlrtNonNegativeCheckR2009b((real_T)k, &o_emlrtDCI);
    j = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = k;
    emxEnsureCapacity((emxArray__common *)y, j, (int32_T)sizeof(int32_T), &k_emlrtRTEI);
    j = 1;
    for (i = 1; i <= n; i++) {
        if (x->data[emlrtDynamicBoundsCheck(i, 1, x->size[1], &mc_emlrtBCI) - 1]) {
            y->data[emlrtDynamicBoundsCheck(j, 1, y->size[1], &nc_emlrtBCI) - 1] = i;
            j++;
        }
    }
}

/*
 * function [rt,activation] = epu_n_unit_accumulator(nTP,v,dt,sigmaXi,SigmaXi,theta,k,affTime,effTime,pN,dMeth,iAT)
 */
void epu_n_unit_accumulator(epu_n_unit_accumulatorStackData *SD, real_T nTP, const emxArray_real_T *v, real_T dt, real_T sigmaXi, const emxArray_real_T *SigmaXi, const emxArray_real_T *theta, const emxArray_real_T *k, real_T affTime, real_T effTime, emxArray_real_T *pN, real_T dMeth, const emxArray_real_T *iAT, real_T *rt, emxArray_real_T *activation)
{
    real_T prop;
    real_T x;
    int32_T nm1d2;
    int32_T ixstart;
    int32_T i0;
    int32_T loop_ub;
    int32_T idx;
    emxArray_boolean_T *b_pN;
    real_T iTP;
    boolean_T innerDimOk;
    emxArray_real_T *iCritical;
    emxArray_real_T *C;
    emxArray_real_T *r0;
    emxArray_int32_T *r1;
    emxArray_int32_T *ii;
    emxArray_boolean_T *iCrossed;
    emxArray_boolean_T *b_prop;
    emxArray_boolean_T *b_activation;
    emxArray_boolean_T *c_activation;
    emxArray_int32_T *r2;
    emxArray_real_T *r3;
    emxArray_real_T *r4;
    emxArray_int32_T *r5;
    emxArray_int32_T *r6;
    emxArray_real_T *d_activation;
    emxArray_real_T *e_activation;
    emxArray_real_T *f_activation;
    emxArray_real_T *g_activation;
    emxArray_real_T *h_activation;
    emxArray_real_T *i_activation;
    emxArray_real_T *j_activation;
    emxArray_real_T *k_activation;
    emxArray_int32_T *b_ii;
    emxArray_real_T *l_activation;
    emxArray_real_T *m_activation;
    boolean_T exitg2;
    const mxArray *y;
    static const int32_T iv0[2] = { 1, 45 };
    const mxArray *m0;
    static const char_T cv0[45] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'm', 't', 'i', 'm', 'e', 's', '_', 'n', 'o', 'D', 'y', 'n', 'a', 'm', 'i', 'c', 'S', 'c', 'a', 'l', 'a', 'r', 'E', 'x', 'p', 'a', 'n', 's', 'i', 'o', 'n' };
    const mxArray *b_y;
    static const int32_T iv1[2] = { 1, 21 };
    static const char_T cv1[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'n', 'n', 'e', 'r', 'd', 'i', 'm' };
    int32_T b_k;
    uint32_T unnamed_idx_1;
    int32_T n;
    char_T TRANSA;
    char_T TRANSB;
    int32_T b_C[2];
    int32_T iv2[2];
    int32_T n_activation[2];
    const mxArray *c_y;
    static const int32_T iv3[2] = { 1, 36 };
    static const char_T cv2[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };
    const mxArray *d_y;
    static const int32_T iv4[2] = { 1, 39 };
    static const char_T cv3[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r', '_', 'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };
    boolean_T exitg4;
    boolean_T exitg3;
    boolean_T guard1 = FALSE;
    const mxArray *e_y;
    int32_T iv5[2];
    emxArray_int32_T r7;
    real_T mActivation[2];
    real_T b_dt[2];
    emxArray_real_T *b_mActivation;
    real_T mThreshold;
    emxArray_real_T *o_activation;
    emxArray_boolean_T *p_activation;
    emxArray_int32_T *r8;
    emxArray_real_T *r9;
    emxArray_real_T *r10;
    emxArray_real_T *q_activation;
    emxArray_real_T *r_activation;
    emxArray_real_T *s_activation;
    emxArray_real_T *t_activation;
    emxArray_real_T *u_activation;
    emxArray_real_T *v_activation;
    emxArray_real_T *w_activation;
    boolean_T exitg1;
    const mxArray *f_y;
    static const int32_T iv6[2] = { 1, 45 };
    const mxArray *g_y;
    static const int32_T iv7[2] = { 1, 21 };
    const mxArray *h_y;
    static const int32_T iv8[2] = { 1, 21 };
    static const char_T cv4[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };
    const mxArray *i_y;
    static const int32_T iv9[2] = { 1, 21 };
    emxArray_real_T *x_activation;
    emlrtHeapReferenceStackEnterFcn();
    /* % N-UNIT REDUNDANT ACCUMULATOR MODEL WITHOUT LATERAL INHIBITION */
    /*  INPUTS */
    /*  nTP           - number of time points (TP) for which to log data (in ms from */
    /*                  target onset) */
    /*  v             - vector with accumulation rates across accumulators */
    /*                  * units:          spikes s-1 ms-1 */
    /*                  * size & class:   1xnA double, where nA is number of */
    /*                                    accumulators */
    /*                  * support:        v ? ?: (0,+?) */
    /*  dt            - time step size of stochastic differential equation */
    /*                  * units:          ms */
    /*                  * size & class:   1x1 double */
    /*                  * support:        dt ? ?: [0,+?) */
    /*  sigmaXi       - scale parameter of the Gaussian noise distribution */
    /*                  * units:          spikes s-1 */
    /*                  * size & class:   1x1 double */
    /*                  * support:        sigmaXi ? ?: (0,+?) */
    /*  SigmaXi       - Cholesky-like decomposed covariance matrix */
    /*                  * units:          ? */
    /*                  * size & class:   nAxnA double */
    /*                  * support:        SigmaXi */
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
    /*  */
    /*  EXAMPLE USAGE: */
    /*  nTP = 1500; */
    /*  v = 1+randn(1,10); */
    /*  sigmaXi = .2; */
    /*  rXi = .5; */
    /*  theta = 100.*ones(1,10); */
    /*  k = zeros(1,10); */
    /*  affTime = 100; */
    /*  effTime = 10; */
    /*  pN = 0; */
    /*  dMeth = 1; */
    /*  iAT = [1,3,5]; */
    /*  */
    /*  [rt,activation] = ... */
    /*  epu_n_unit_accumulator(nTP,v,sigmaXi,SigmaXi,theta,k,affTime,effTime,pN,dMeth,iAT); */
    /*  */
    /*  */
    /*  */
    /*  THESE EXAMPLES NEED TO BE UPDATED AND ADJUSTED! */
    /*  */
    /*  */
    /* % Example 1: Perfect integration of evidence, polling-based RT generation, very */
    /* % first accumulator reaching threshold determines RT */
    /*  */
    /*  muRate = 1+randn(1,10); */
    /*  wnF = 0; */
    /*  nTP = 1500; */
    /*  k = zeros(1,10); */
    /*  theta = 100 .* ones(1,10); */
    /*  t0 = 100; */
    /*  dMeth = 1; */
    /*  q = 0; */
    /*  iAT = [1 3 4]; */
    /*  */
    /*  [rt,activation] = ... */
    /*  epu_n_unit_accumulator(muRate,wnF,nTP,k,theta,t0,dMeth,q,iAT); */
    /*  */
    /* % Example 2: Leaky integration of evidence, polling-based RT generation, median */
    /* % accumulator reaching threshold determines RT */
    /*  */
    /*  muRate = 1+randn(1,10); */
    /*  wnF = 1; */
    /*  nTP = 1500 */
    /*  theta = 100 .* ones(1,10); */
    /*  k = 0.5.*muRate./theta; */
    /*  t0 = 100; */
    /*  dMeth = 1; */
    /*  q = 0.5; */
    /*  iAT = [1 3 4]; */
    /*  */
    /*  [rt,activation] = ... */
    /*  epu_n_unit_accumulator(muRate,wnF,nTP,k,theta,t0,dMeth,q,iAT); */
    /*  */
    /* % Example 3: Leaky integration of evidence, pooling-based RT generation */
    /*  */
    /*  muRate = 1+randn(1,10); */
    /*  wnF = 1; */
    /*  nTP = 1500; */
    /*  theta = 100 .* ones(1,10); */
    /*  k = 0.5.*muRate./theta; */
    /*  t0 = 100; */
    /*  dMeth = 2; */
    /*  q = 0.5; */
    /*  iAT = 10; */
    /*  */
    /*  [rt,activation] = ... */
    /*  epu_n_unit_accumulator(muRate,wnF,nTP,k,theta,t0,dMeth,q,iAT); */
    /*  */
    /*  Bram Zandbelt, April 2012 */
    /* % */
    /* % 1. Parameter settings & array pre-allocation */
    /*  warning off */
    /*  Constants */
    /* 'epu_n_unit_accumulator:137' TAU = 1; */
    /*  Time scale (in ms), see Usher & McClelland 2001, p. 558 */
    /*  User-defined parameters */
    /* 'epu_n_unit_accumulator:140' nA = size(v,2); */
    /*  Number of accumulator units */
    /*  Arrays for logging data */
    /* 'epu_n_unit_accumulator:143' activation = [zeros(floor(affTime./dt),nA);nan(ceil((nTP-affTime)./dt),nA)]; */
    prop = muDoubleScalarFloor(rdivide(affTime, dt));
    emlrtNonNegativeCheckR2009b(prop, &emlrtDCI);
    x = muDoubleScalarCeil(rdivide(nTP - affTime, dt));
    emlrtNonNegativeCheckR2009b(x, &b_emlrtDCI);
    nm1d2 = v->size[1];
    ixstart = v->size[1];
    emlrtDimSizeEqCheck(nm1d2, ixstart, &emlrtECI);
    nm1d2 = v->size[1];
    ixstart = v->size[1];
    i0 = activation->size[0] * activation->size[1];
    activation->size[0] = (int32_T)prop + (int32_T)x;
    activation->size[1] = nm1d2;
    emxEnsureCapacity((emxArray__common *)activation, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
    loop_ub = nm1d2 - 1;
    for (i0 = 0; i0 <= loop_ub; i0++) {
        idx = (int32_T)prop - 1;
        for (nm1d2 = 0; nm1d2 <= idx; nm1d2++) {
            activation->data[nm1d2 + activation->size[0] * i0] = 0.0;
        }
    }
    loop_ub = ixstart - 1;
    for (i0 = 0; i0 <= loop_ub; i0++) {
        idx = (int32_T)x - 1;
        for (nm1d2 = 0; nm1d2 <= idx; nm1d2++) {
            activation->data[(nm1d2 + (int32_T)prop) + activation->size[0] * i0] = rtNaN;
        }
    }
    emxInit_boolean_T(&b_pN, 2, &emlrtRTEI, TRUE);
    /*  Activation */
    /* 'epu_n_unit_accumulator:144' rt = Inf; */
    *rt = rtInf;
    /* % 2. Accumulator trajectories */
    /*  iTP = affTime+1; % Before affTime, activation is zero */
    /* 'epu_n_unit_accumulator:148' iTP = floor(affTime./dt)+1; */
    iTP = muDoubleScalarFloor(rdivide(affTime, dt)) + 1.0;
    /*  Before affTime, activation is zero */
    /* 'epu_n_unit_accumulator:150' if all(pN == 0) */
    EMLRTPUSHRTSTACK(&emlrtRSI);
    i0 = b_pN->size[0] * b_pN->size[1];
    b_pN->size[0] = 1;
    b_pN->size[1] = pN->size[1];
    emxEnsureCapacity((emxArray__common *)b_pN, i0, (int32_T)sizeof(boolean_T), &emlrtRTEI);
    loop_ub = pN->size[0] * pN->size[1] - 1;
    for (i0 = 0; i0 <= loop_ub; i0++) {
        b_pN->data[i0] = (pN->data[i0] == 0.0);
    }
    innerDimOk = all(b_pN);
    EMLRTPOPRTSTACK(&emlrtRSI);
    emxFree_boolean_T(&b_pN);
    if (innerDimOk) {
        /* 'epu_n_unit_accumulator:151' pN = realmin; */
        i0 = pN->size[0] * pN->size[1];
        pN->size[0] = 1;
        pN->size[1] = 1;
        emxEnsureCapacity((emxArray__common *)pN, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
        pN->data[0] = 2.2250738585072014E-308;
        /*  This ensures that very first accumulator determines RT */
    }
    /* 'epu_n_unit_accumulator:154' if dMeth == 1 */
    emxInit_real_T(&iCritical, 2, &g_emlrtRTEI, TRUE);
    emxInit_real_T(&C, 2, &emlrtRTEI, TRUE);
    emxInit_real_T(&r0, 2, &emlrtRTEI, TRUE);
    emxInit_int32_T(&r1, 1, &emlrtRTEI, TRUE);
    b_emxInit_int32_T(&ii, 2, &i_emlrtRTEI, TRUE);
    if (dMeth == 1.0) {
        /*  Polling */
        /* 'epu_n_unit_accumulator:156' while iTP < Inf */
        emxInit_boolean_T(&iCrossed, 2, &f_emlrtRTEI, TRUE);
        emxInit_boolean_T(&b_prop, 2, &emlrtRTEI, TRUE);
        emxInit_boolean_T(&b_activation, 2, &emlrtRTEI, TRUE);
        emxInit_boolean_T(&c_activation, 2, &emlrtRTEI, TRUE);
        b_emxInit_int32_T(&r2, 2, &emlrtRTEI, TRUE);
        emxInit_real_T(&r3, 2, &emlrtRTEI, TRUE);
        emxInit_real_T(&r4, 2, &emlrtRTEI, TRUE);
        b_emxInit_int32_T(&r5, 2, &emlrtRTEI, TRUE);
        emxInit_int32_T(&r6, 1, &emlrtRTEI, TRUE);
        emxInit_real_T(&d_activation, 2, &emlrtRTEI, TRUE);
        emxInit_real_T(&e_activation, 2, &emlrtRTEI, TRUE);
        emxInit_real_T(&f_activation, 2, &emlrtRTEI, TRUE);
        emxInit_real_T(&g_activation, 2, &emlrtRTEI, TRUE);
        emxInit_real_T(&h_activation, 2, &emlrtRTEI, TRUE);
        emxInit_real_T(&i_activation, 2, &emlrtRTEI, TRUE);
        emxInit_real_T(&j_activation, 2, &emlrtRTEI, TRUE);
        emxInit_real_T(&k_activation, 2, &emlrtRTEI, TRUE);
        b_emxInit_int32_T(&b_ii, 2, &emlrtRTEI, TRUE);
        emxInit_real_T(&l_activation, 2, &emlrtRTEI, TRUE);
        emxInit_real_T(&m_activation, 2, &emlrtRTEI, TRUE);
        exitg2 = 0U;
        while ((exitg2 == 0U) && (iTP < rtInf)) {
            /*  Generate correlated Gaussian noise */
            /* 'epu_n_unit_accumulator:159' Xi = randn(1,size(SigmaXi,1)) * SigmaXi + zeros(1,nA); */
            EMLRTPUSHRTSTACK(&b_emlrtRSI);
            randn(SD, (real_T)SigmaXi->size[0], iCritical);
            EMLRTPUSHRTSTACK(&hb_emlrtRSI);
            innerDimOk = (iCritical->size[1] == SigmaXi->size[0]);
            if (!innerDimOk) {
                if ((iCritical->size[1] == 1) || ((SigmaXi->size[0] == 1) && (SigmaXi->size[1] == 1))) {
                    EMLRTPUSHRTSTACK(&ib_emlrtRSI);
                    y = NULL;
                    m0 = mxCreateCharArray(2, iv0);
                    emlrtInitCharArray(45, m0, cv0);
                    emlrtAssign(&y, m0);
                    error(message(y, &e_emlrtMCI), &f_emlrtMCI);
                    EMLRTPOPRTSTACK(&ib_emlrtRSI);
                } else {
                    EMLRTPUSHRTSTACK(&jb_emlrtRSI);
                    b_y = NULL;
                    m0 = mxCreateCharArray(2, iv1);
                    emlrtInitCharArray(21, m0, cv1);
                    emlrtAssign(&b_y, m0);
                    error(message(b_y, &g_emlrtMCI), &h_emlrtMCI);
                    EMLRTPOPRTSTACK(&jb_emlrtRSI);
                }
            }
            EMLRTPOPRTSTACK(&hb_emlrtRSI);
            if ((iCritical->size[1] == 1) || (SigmaXi->size[0] == 1)) {
                i0 = C->size[0] * C->size[1];
                C->size[0] = 1;
                C->size[1] = SigmaXi->size[1];
                emxEnsureCapacity((emxArray__common *)C, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                loop_ub = SigmaXi->size[1] - 1;
                for (i0 = 0; i0 <= loop_ub; i0++) {
                    C->data[C->size[0] * i0] = 0.0;
                    idx = iCritical->size[1] - 1;
                    for (nm1d2 = 0; nm1d2 <= idx; nm1d2++) {
                        C->data[C->size[0] * i0] += iCritical->data[iCritical->size[0] * nm1d2] * SigmaXi->data[nm1d2 + SigmaXi->size[0] * i0];
                    }
                }
            } else {
                b_k = iCritical->size[1];
                unnamed_idx_1 = (uint32_T)SigmaXi->size[1];
                i0 = C->size[0] * C->size[1];
                C->size[0] = 1;
                C->size[1] = (int32_T)unnamed_idx_1;
                emxEnsureCapacity((emxArray__common *)C, i0, (int32_T)sizeof(real_T), &c_emlrtRTEI);
                n = SigmaXi->size[1];
                i0 = C->size[0] * C->size[1];
                C->size[0] = 1;
                emxEnsureCapacity((emxArray__common *)C, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                loop_ub = C->size[1] - 1;
                for (i0 = 0; i0 <= loop_ub; i0++) {
                    C->data[C->size[0] * i0] = 0.0;
                }
                EMLRTPUSHRTSTACK(&gb_emlrtRSI);
                EMLRTPUSHRTSTACK(&kb_emlrtRSI);
                if ((n < 1) || (b_k < 1)) {
                } else {
                    EMLRTPUSHRTSTACK(&mb_emlrtRSI);
                    ixstart = 1;
                    x = 1.0;
                    idx = 1;
                    prop = 0.0;
                    nm1d2 = 1;
                    TRANSA = 'N';
                    TRANSB = 'N';
                    EMLRTPUSHRTSTACK(&nb_emlrtRSI);
                    emlrtDynamicBoundsCheck(1, 1, iCritical->size[1], &v_emlrtBCI);
                    emlrtDynamicBoundsCheck(1, 1, SigmaXi->size[0] * SigmaXi->size[1], &w_emlrtBCI);
                    emlrtDynamicBoundsCheck(1, 1, C->size[1], &x_emlrtBCI);
                    dgemm32(&TRANSA, &TRANSB, &ixstart, &n, &b_k, &x, &iCritical->data[0], &idx, &SigmaXi->data[0], &b_k, &prop, &C->data[0], &nm1d2);
                    EMLRTPOPRTSTACK(&nb_emlrtRSI);
                    EMLRTPOPRTSTACK(&mb_emlrtRSI);
                }
                EMLRTPOPRTSTACK(&kb_emlrtRSI);
                EMLRTPOPRTSTACK(&gb_emlrtRSI);
            }
            EMLRTPOPRTSTACK(&b_emlrtRSI);
            for (i0 = 0; i0 < 2; i0++) {
                b_C[i0] = C->size[i0];
            }
            iv2[0] = 1;
            iv2[1] = v->size[1];
            emlrtSizeEqCheckND(b_C, iv2, &b_emlrtECI);
            /*  Compute activation level */
            /* 'epu_n_unit_accumulator:162' activation(iTP,:) = activation(iTP-1,:) + dt./TAU.*(v-k.*activation(iTP-1,:)) + sqrt(dt./TAU).*Xi; */
            emlrtDynamicBoundsCheck((int32_T)(iTP - 1.0), 1, activation->size[0], &b_emlrtBCI);
            for (i0 = 0; i0 < 2; i0++) {
                b_C[i0] = k->size[i0];
            }
            i0 = activation->size[1];
            nm1d2 = d_activation->size[0] * d_activation->size[1];
            d_activation->size[0] = 1;
            d_activation->size[1] = i0;
            emxEnsureCapacity((emxArray__common *)d_activation, nm1d2, (int32_T)sizeof(real_T), &emlrtRTEI);
            loop_ub = i0 - 1;
            for (i0 = 0; i0 <= loop_ub; i0++) {
                d_activation->data[d_activation->size[0] * i0] = activation->data[((int32_T)(iTP - 1.0) + activation->size[0] * i0) - 1];
            }
            for (i0 = 0; i0 < 2; i0++) {
                n_activation[i0] = d_activation->size[i0];
            }
            emlrtSizeEqCheckND(b_C, n_activation, &c_emlrtECI);
            i0 = r0->size[0] * r0->size[1];
            r0->size[0] = 1;
            r0->size[1] = k->size[1];
            emxEnsureCapacity((emxArray__common *)r0, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
            loop_ub = k->size[1] - 1;
            for (i0 = 0; i0 <= loop_ub; i0++) {
                r0->data[r0->size[0] * i0] = k->data[k->size[0] * i0] * activation->data[((int32_T)(iTP - 1.0) + activation->size[0] * i0) - 1];
            }
            for (i0 = 0; i0 < 2; i0++) {
                b_C[i0] = v->size[i0];
            }
            for (i0 = 0; i0 < 2; i0++) {
                iv2[i0] = r0->size[i0];
            }
            emlrtSizeEqCheckND(b_C, iv2, &d_emlrtECI);
            emlrtDynamicBoundsCheck((int32_T)(iTP - 1.0), 1, activation->size[0], &emlrtBCI);
            i0 = r0->size[0] * r0->size[1];
            r0->size[0] = 1;
            r0->size[1] = v->size[1];
            emxEnsureCapacity((emxArray__common *)r0, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
            x = rdivide(dt, 1.0);
            loop_ub = v->size[0] * v->size[1] - 1;
            for (i0 = 0; i0 <= loop_ub; i0++) {
                r0->data[i0] = x * (v->data[i0] - r0->data[i0]);
            }
            i0 = activation->size[1];
            nm1d2 = e_activation->size[0] * e_activation->size[1];
            e_activation->size[0] = 1;
            e_activation->size[1] = i0;
            emxEnsureCapacity((emxArray__common *)e_activation, nm1d2, (int32_T)sizeof(real_T), &emlrtRTEI);
            loop_ub = i0 - 1;
            for (i0 = 0; i0 <= loop_ub; i0++) {
                e_activation->data[e_activation->size[0] * i0] = activation->data[((int32_T)(iTP - 1.0) + activation->size[0] * i0) - 1];
            }
            for (i0 = 0; i0 < 2; i0++) {
                n_activation[i0] = e_activation->size[i0];
            }
            for (i0 = 0; i0 < 2; i0++) {
                iv2[i0] = r0->size[i0];
            }
            emlrtSizeEqCheckND(n_activation, iv2, &e_emlrtECI);
            EMLRTPUSHRTSTACK(&c_emlrtRSI);
            x = rdivide(dt, 1.0);
            b_sqrt(&x);
            i0 = C->size[0] * C->size[1];
            C->size[0] = 1;
            emxEnsureCapacity((emxArray__common *)C, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
            nm1d2 = C->size[0];
            ixstart = C->size[1];
            loop_ub = nm1d2 * ixstart - 1;
            for (i0 = 0; i0 <= loop_ub; i0++) {
                C->data[i0] *= x;
            }
            EMLRTPOPRTSTACK(&c_emlrtRSI);
            i0 = activation->size[1];
            nm1d2 = f_activation->size[0] * f_activation->size[1];
            f_activation->size[0] = 1;
            f_activation->size[1] = i0;
            emxEnsureCapacity((emxArray__common *)f_activation, nm1d2, (int32_T)sizeof(real_T), &emlrtRTEI);
            loop_ub = i0 - 1;
            for (i0 = 0; i0 <= loop_ub; i0++) {
                f_activation->data[f_activation->size[0] * i0] = activation->data[((int32_T)(iTP - 1.0) + activation->size[0] * i0) - 1];
            }
            for (i0 = 0; i0 < 2; i0++) {
                n_activation[i0] = f_activation->size[i0];
            }
            for (i0 = 0; i0 < 2; i0++) {
                b_C[i0] = C->size[i0];
            }
            emlrtSizeEqCheckND(n_activation, b_C, &f_emlrtECI);
            emlrtDynamicBoundsCheck((int32_T)iTP, 1, activation->size[0], &c_emlrtBCI);
            i0 = activation->size[1];
            nm1d2 = r1->size[0];
            r1->size[0] = i0;
            emxEnsureCapacity((emxArray__common *)r1, nm1d2, (int32_T)sizeof(int32_T), &emlrtRTEI);
            loop_ub = i0 - 1;
            for (i0 = 0; i0 <= loop_ub; i0++) {
                r1->data[i0] = i0;
            }
            iv2[0] = 1;
            iv2[1] = r1->size[0];
            i0 = activation->size[1];
            nm1d2 = g_activation->size[0] * g_activation->size[1];
            g_activation->size[0] = 1;
            g_activation->size[1] = i0;
            emxEnsureCapacity((emxArray__common *)g_activation, nm1d2, (int32_T)sizeof(real_T), &emlrtRTEI);
            loop_ub = i0 - 1;
            for (i0 = 0; i0 <= loop_ub; i0++) {
                g_activation->data[g_activation->size[0] * i0] = activation->data[((int32_T)iTP + activation->size[0] * i0) - 2];
            }
            for (i0 = 0; i0 < 2; i0++) {
                n_activation[i0] = g_activation->size[i0];
            }
            emlrtSubAssignSizeCheck(iv2, 2, n_activation, 2, &g_emlrtECI);
            ixstart = activation->size[1];
            i0 = h_activation->size[0] * h_activation->size[1];
            h_activation->size[0] = 1;
            h_activation->size[1] = ixstart;
            emxEnsureCapacity((emxArray__common *)h_activation, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
            loop_ub = ixstart - 1;
            for (i0 = 0; i0 <= loop_ub; i0++) {
                h_activation->data[h_activation->size[0] * i0] = (activation->data[((int32_T)iTP + activation->size[0] * i0) - 2] + r0->data[r0->size[0] * i0]) + C->data[C->size[0] * i0];
            }
            loop_ub = h_activation->size[1] - 1;
            for (i0 = 0; i0 <= loop_ub; i0++) {
                activation->data[((int32_T)iTP + activation->size[0] * r1->data[i0]) - 1] = h_activation->data[h_activation->size[0] * i0];
            }
            /*  Reset activation level if it goes below zero */
            /* 'epu_n_unit_accumulator:165' activation(iTP,(activation(iTP,:) < 0)) = 0; */
            EMLRTPUSHRTSTACK(&d_emlrtRSI);
            i0 = activation->size[1];
            ixstart = emlrtDynamicBoundsCheck((int32_T)iTP, 1, activation->size[0], &e_emlrtBCI);
            nm1d2 = c_activation->size[0] * c_activation->size[1];
            c_activation->size[0] = 1;
            c_activation->size[1] = i0;
            emxEnsureCapacity((emxArray__common *)c_activation, nm1d2, (int32_T)sizeof(boolean_T), &emlrtRTEI);
            loop_ub = i0 - 1;
            for (i0 = 0; i0 <= loop_ub; i0++) {
                c_activation->data[c_activation->size[0] * i0] = (activation->data[(ixstart + activation->size[0] * i0) - 1] < 0.0);
            }
            eml_li_find(c_activation, ii);
            i0 = r2->size[0] * r2->size[1];
            r2->size[0] = 1;
            r2->size[1] = ii->size[1];
            emxEnsureCapacity((emxArray__common *)r2, i0, (int32_T)sizeof(int32_T), &emlrtRTEI);
            loop_ub = ii->size[0] * ii->size[1] - 1;
            for (i0 = 0; i0 <= loop_ub; i0++) {
                r2->data[i0] = emlrtDynamicBoundsCheck(ii->data[i0], 1, activation->size[1], &mb_emlrtBCI);
            }
            i0 = r1->size[0];
            r1->size[0] = r2->size[1];
            emxEnsureCapacity((emxArray__common *)r1, i0, (int32_T)sizeof(int32_T), &emlrtRTEI);
            loop_ub = r2->size[1] - 1;
            for (i0 = 0; i0 <= loop_ub; i0++) {
                r1->data[i0] = r2->data[i0];
            }
            EMLRTPOPRTSTACK(&d_emlrtRSI);
            ixstart = activation->size[0];
            emlrtDynamicBoundsCheck((int32_T)iTP, 1, ixstart, &d_emlrtBCI);
            nm1d2 = r1->size[0];
            loop_ub = nm1d2 - 1;
            for (i0 = 0; i0 <= loop_ub; i0++) {
                activation->data[((int32_T)iTP + activation->size[0] * (r1->data[i0] - 1)) - 1] = 0.0;
            }
            /*  Proportion of accumulators above threshold */
            /* 'epu_n_unit_accumulator:168' prop = sum(activation(iTP,:) > theta)/nA; */
            emlrtDynamicBoundsCheck((int32_T)iTP, 1, activation->size[0], &f_emlrtBCI);
            i0 = activation->size[1];
            nm1d2 = i_activation->size[0] * i_activation->size[1];
            i_activation->size[0] = 1;
            i_activation->size[1] = i0;
            emxEnsureCapacity((emxArray__common *)i_activation, nm1d2, (int32_T)sizeof(real_T), &emlrtRTEI);
            loop_ub = i0 - 1;
            for (i0 = 0; i0 <= loop_ub; i0++) {
                i_activation->data[i_activation->size[0] * i0] = activation->data[((int32_T)iTP + activation->size[0] * i0) - 1];
            }
            for (i0 = 0; i0 < 2; i0++) {
                n_activation[i0] = i_activation->size[i0];
            }
            for (i0 = 0; i0 < 2; i0++) {
                b_C[i0] = theta->size[i0];
            }
            emlrtSizeEqCheckND(n_activation, b_C, &h_emlrtECI);
            EMLRTPUSHRTSTACK(&e_emlrtRSI);
            i0 = activation->size[1];
            nm1d2 = b_activation->size[0] * b_activation->size[1];
            b_activation->size[0] = 1;
            b_activation->size[1] = i0;
            emxEnsureCapacity((emxArray__common *)b_activation, nm1d2, (int32_T)sizeof(boolean_T), &emlrtRTEI);
            loop_ub = i0 - 1;
            for (i0 = 0; i0 <= loop_ub; i0++) {
                b_activation->data[b_activation->size[0] * i0] = (activation->data[((int32_T)iTP + activation->size[0] * i0) - 1] > theta->data[theta->size[0] * i0]);
            }
            prop = mrdivide(sum(b_activation), (real_T)v->size[1]);
            EMLRTPOPRTSTACK(&e_emlrtRSI);
            /* 'epu_n_unit_accumulator:170' if isinf(rt) && all(prop >= pN) */
            if (muDoubleScalarIsInf(*rt)) {
                EMLRTPUSHRTSTACK(&f_emlrtRSI);
                i0 = b_prop->size[0] * b_prop->size[1];
                b_prop->size[0] = 1;
                b_prop->size[1] = pN->size[1];
                emxEnsureCapacity((emxArray__common *)b_prop, i0, (int32_T)sizeof(boolean_T), &emlrtRTEI);
                loop_ub = pN->size[0] * pN->size[1] - 1;
                for (i0 = 0; i0 <= loop_ub; i0++) {
                    b_prop->data[i0] = (prop >= pN->data[i0]);
                }
                innerDimOk = all(b_prop);
                EMLRTPOPRTSTACK(&f_emlrtRSI);
                if (innerDimOk) {
                    /*  Determine RT if sufficient number of accumulators have reached threshold */
                    /*  Identify critical accumulator (i.e. crossed threshold most recently) and determine RT */
                    /* 'epu_n_unit_accumulator:173' iCrossed = activation(iTP,:) - theta > 0; */
                    emlrtDynamicBoundsCheck((int32_T)iTP, 1, activation->size[0], &g_emlrtBCI);
                    i0 = activation->size[1];
                    nm1d2 = j_activation->size[0] * j_activation->size[1];
                    j_activation->size[0] = 1;
                    j_activation->size[1] = i0;
                    emxEnsureCapacity((emxArray__common *)j_activation, nm1d2, (int32_T)sizeof(real_T), &emlrtRTEI);
                    loop_ub = i0 - 1;
                    for (i0 = 0; i0 <= loop_ub; i0++) {
                        j_activation->data[j_activation->size[0] * i0] = activation->data[((int32_T)iTP + activation->size[0] * i0) - 1];
                    }
                    for (i0 = 0; i0 < 2; i0++) {
                        n_activation[i0] = j_activation->size[i0];
                    }
                    for (i0 = 0; i0 < 2; i0++) {
                        b_C[i0] = theta->size[i0];
                    }
                    emlrtSizeEqCheckND(n_activation, b_C, &i_emlrtECI);
                    i0 = activation->size[1];
                    nm1d2 = iCrossed->size[0] * iCrossed->size[1];
                    iCrossed->size[0] = 1;
                    iCrossed->size[1] = i0;
                    emxEnsureCapacity((emxArray__common *)iCrossed, nm1d2, (int32_T)sizeof(boolean_T), &emlrtRTEI);
                    loop_ub = i0 - 1;
                    for (i0 = 0; i0 <= loop_ub; i0++) {
                        iCrossed->data[iCrossed->size[0] * i0] = (activation->data[((int32_T)iTP + activation->size[0] * i0) - 1] - theta->data[theta->size[0] * i0] > 0.0);
                    }
                    /* 'epu_n_unit_accumulator:174' iCritical = find(activation(iTP,:) - theta == min(activation(iTP,iCrossed)-theta(iCrossed))); */
                    emlrtDynamicBoundsCheck((int32_T)iTP, 1, activation->size[0], &h_emlrtBCI);
                    i0 = activation->size[1];
                    nm1d2 = k_activation->size[0] * k_activation->size[1];
                    k_activation->size[0] = 1;
                    k_activation->size[1] = i0;
                    emxEnsureCapacity((emxArray__common *)k_activation, nm1d2, (int32_T)sizeof(real_T), &emlrtRTEI);
                    loop_ub = i0 - 1;
                    for (i0 = 0; i0 <= loop_ub; i0++) {
                        k_activation->data[k_activation->size[0] * i0] = activation->data[((int32_T)iTP + activation->size[0] * i0) - 1];
                    }
                    for (i0 = 0; i0 < 2; i0++) {
                        n_activation[i0] = k_activation->size[i0];
                    }
                    for (i0 = 0; i0 < 2; i0++) {
                        b_C[i0] = theta->size[i0];
                    }
                    emlrtSizeEqCheckND(n_activation, b_C, &j_emlrtECI);
                    EMLRTPUSHRTSTACK(&g_emlrtRSI);
                    eml_li_find(iCrossed, ii);
                    i0 = r5->size[0] * r5->size[1];
                    r5->size[0] = 1;
                    r5->size[1] = ii->size[1];
                    emxEnsureCapacity((emxArray__common *)r5, i0, (int32_T)sizeof(int32_T), &emlrtRTEI);
                    loop_ub = ii->size[0] * ii->size[1] - 1;
                    for (i0 = 0; i0 <= loop_ub; i0++) {
                        r5->data[i0] = emlrtDynamicBoundsCheck(ii->data[i0], 1, activation->size[1], &nb_emlrtBCI);
                    }
                    nm1d2 = r5->size[1];
                    ixstart = emlrtDynamicBoundsCheck((int32_T)iTP, 1, activation->size[0], &i_emlrtBCI);
                    i0 = iCritical->size[0] * iCritical->size[1];
                    iCritical->size[0] = 1;
                    iCritical->size[1] = nm1d2;
                    emxEnsureCapacity((emxArray__common *)iCritical, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                    loop_ub = nm1d2 - 1;
                    for (i0 = 0; i0 <= loop_ub; i0++) {
                        iCritical->data[iCritical->size[0] * i0] = activation->data[(ixstart + activation->size[0] * (r5->data[i0] - 1)) - 1];
                    }
                    EMLRTPOPRTSTACK(&g_emlrtRSI);
                    EMLRTPUSHRTSTACK(&h_emlrtRSI);
                    eml_li_find(iCrossed, ii);
                    i0 = r0->size[0] * r0->size[1];
                    r0->size[0] = 1;
                    r0->size[1] = ii->size[1];
                    emxEnsureCapacity((emxArray__common *)r0, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                    loop_ub = ii->size[0] * ii->size[1] - 1;
                    for (i0 = 0; i0 <= loop_ub; i0++) {
                        r0->data[i0] = theta->data[emlrtDynamicBoundsCheck(ii->data[i0], 1, theta->size[1], &ob_emlrtBCI) - 1];
                    }
                    EMLRTPOPRTSTACK(&h_emlrtRSI);
                    for (i0 = 0; i0 < 2; i0++) {
                        b_C[i0] = iCritical->size[i0];
                    }
                    for (i0 = 0; i0 < 2; i0++) {
                        iv2[i0] = r0->size[i0];
                    }
                    emlrtSizeEqCheckND(b_C, iv2, &k_emlrtECI);
                    EMLRTPUSHRTSTACK(&i_emlrtRSI);
                    i0 = iCritical->size[0] * iCritical->size[1];
                    iCritical->size[0] = 1;
                    emxEnsureCapacity((emxArray__common *)iCritical, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                    ixstart = iCritical->size[0];
                    nm1d2 = iCritical->size[1];
                    loop_ub = ixstart * nm1d2 - 1;
                    for (i0 = 0; i0 <= loop_ub; i0++) {
                        iCritical->data[i0] -= r0->data[i0];
                    }
                    EMLRTPUSHRTSTACK(&vb_emlrtRSI);
                    EMLRTPUSHRTSTACK(&wb_emlrtRSI);
                    if ((iCritical->size[1] == 1) || (iCritical->size[1] != 1)) {
                        innerDimOk = TRUE;
                    } else {
                        innerDimOk = FALSE;
                    }
                    if (innerDimOk) {
                    } else {
                        EMLRTPUSHRTSTACK(&xb_emlrtRSI);
                        c_y = NULL;
                        m0 = mxCreateCharArray(2, iv3);
                        emlrtInitCharArray(36, m0, cv2);
                        emlrtAssign(&c_y, m0);
                        error(message(c_y, &p_emlrtMCI), &q_emlrtMCI);
                        EMLRTPOPRTSTACK(&xb_emlrtRSI);
                    }
                    if (iCritical->size[1] > 0) {
                    } else {
                        EMLRTPUSHRTSTACK(&yb_emlrtRSI);
                        d_y = NULL;
                        m0 = mxCreateCharArray(2, iv4);
                        emlrtInitCharArray(39, m0, cv3);
                        emlrtAssign(&d_y, m0);
                        error(message(d_y, &r_emlrtMCI), &s_emlrtMCI);
                        EMLRTPOPRTSTACK(&yb_emlrtRSI);
                    }
                    EMLRTPUSHRTSTACK(&ac_emlrtRSI);
                    ixstart = 1;
                    n = iCritical->size[1];
                    emlrtDynamicBoundsCheck(1, 1, iCritical->size[1], &y_emlrtBCI);
                    x = iCritical->data[0];
                    if (n > 1) {
                        if (muDoubleScalarIsNaN(iCritical->data[0])) {
                            nm1d2 = 2;
                            exitg4 = 0U;
                            while ((exitg4 == 0U) && (nm1d2 <= n)) {
                                ixstart = nm1d2;
                                emlrtDynamicBoundsCheck(nm1d2, 1, iCritical->size[1], &ab_emlrtBCI);
                                if (!muDoubleScalarIsNaN(iCritical->data[nm1d2 - 1])) {
                                    x = iCritical->data[emlrtDynamicBoundsCheck(nm1d2, 1, iCritical->size[1], &pb_emlrtBCI) - 1];
                                    exitg4 = 1U;
                                } else {
                                    nm1d2++;
                                }
                            }
                        }
                        if (ixstart < n) {
                            for (nm1d2 = ixstart + 1; nm1d2 <= n; nm1d2++) {
                                emlrtDynamicBoundsCheck(nm1d2, 1, iCritical->size[1], &bb_emlrtBCI);
                                if (iCritical->data[nm1d2 - 1] < x) {
                                    x = iCritical->data[emlrtDynamicBoundsCheck(nm1d2, 1, iCritical->size[1], &ic_emlrtBCI) - 1];
                                }
                            }
                        }
                    }
                    EMLRTPOPRTSTACK(&ac_emlrtRSI);
                    EMLRTPOPRTSTACK(&wb_emlrtRSI);
                    EMLRTPOPRTSTACK(&vb_emlrtRSI);
                    i0 = activation->size[1];
                    nm1d2 = iCrossed->size[0] * iCrossed->size[1];
                    iCrossed->size[0] = 1;
                    iCrossed->size[1] = i0;
                    emxEnsureCapacity((emxArray__common *)iCrossed, nm1d2, (int32_T)sizeof(boolean_T), &emlrtRTEI);
                    loop_ub = i0 - 1;
                    for (i0 = 0; i0 <= loop_ub; i0++) {
                        iCrossed->data[iCrossed->size[0] * i0] = (activation->data[((int32_T)iTP + activation->size[0] * i0) - 1] - theta->data[theta->size[0] * i0] == x);
                    }
                    EMLRTPUSHRTSTACK(&bc_emlrtRSI);
                    ixstart = iCrossed->size[1];
                    idx = 0;
                    i0 = ii->size[0] * ii->size[1];
                    ii->size[0] = 1;
                    ii->size[1] = ixstart;
                    emxEnsureCapacity((emxArray__common *)ii, i0, (int32_T)sizeof(int32_T), &e_emlrtRTEI);
                    nm1d2 = 1;
                    exitg3 = 0U;
                    while ((exitg3 == 0U) && (nm1d2 <= ixstart)) {
                        guard1 = FALSE;
                        if (iCrossed->data[emlrtDynamicBoundsCheck(nm1d2, 1, iCrossed->size[1], &qb_emlrtBCI) - 1]) {
                            idx++;
                            ii->data[emlrtDynamicBoundsCheck(idx, 1, ii->size[1], &rb_emlrtBCI) - 1] = nm1d2;
                            if (idx >= ixstart) {
                                exitg3 = 1U;
                            } else {
                                guard1 = TRUE;
                            }
                        } else {
                            guard1 = TRUE;
                        }
                        if (guard1 == TRUE) {
                            nm1d2++;
                        }
                    }
                    if (idx <= ixstart) {
                    } else {
                        EMLRTPUSHRTSTACK(&dc_emlrtRSI);
                        e_y = NULL;
                        m0 = mxCreateString("Assertion failed.");
                        emlrtAssign(&e_y, m0);
                        error(e_y, &u_emlrtMCI);
                        EMLRTPOPRTSTACK(&dc_emlrtRSI);
                    }
                    if (ixstart == 1) {
                        if (idx == 0) {
                            i0 = ii->size[0] * ii->size[1];
                            ii->size[0] = 1;
                            ii->size[1] = 0;
                            emxEnsureCapacity((emxArray__common *)ii, i0, (int32_T)sizeof(int32_T), &emlrtRTEI);
                        }
                    } else {
                        if (1 > idx) {
                            i0 = 0;
                        } else {
                            emlrtDynamicBoundsCheck(1, 1, ii->size[1], &cb_emlrtBCI);
                            i0 = emlrtDynamicBoundsCheck(idx, 1, ii->size[1], &db_emlrtBCI);
                        }
                        nm1d2 = r6->size[0];
                        r6->size[0] = i0;
                        emxEnsureCapacity((emxArray__common *)r6, nm1d2, (int32_T)sizeof(int32_T), &emlrtRTEI);
                        loop_ub = i0 - 1;
                        for (i0 = 0; i0 <= loop_ub; i0++) {
                            r6->data[i0] = 1 + i0;
                        }
                        iv5[0] = 1;
                        iv5[1] = r6->size[0];
                        i0 = b_ii->size[0] * b_ii->size[1];
                        b_ii->size[0] = iv5[0];
                        b_ii->size[1] = iv5[1];
                        emxEnsureCapacity((emxArray__common *)b_ii, i0, (int32_T)sizeof(int32_T), &emlrtRTEI);
                        loop_ub = iv5[1] - 1;
                        for (i0 = 0; i0 <= loop_ub; i0++) {
                            idx = iv5[0] - 1;
                            for (nm1d2 = 0; nm1d2 <= idx; nm1d2++) {
                                r7 = *r6;
                                r7.size = (int32_T *)&iv5;
                                r7.numDimensions = 1;
                                b_ii->data[nm1d2 + b_ii->size[0] * i0] = ii->data[r7.data[nm1d2 + r7.size[0] * i0] - 1];
                            }
                        }
                        i0 = ii->size[0] * ii->size[1];
                        ii->size[0] = 1;
                        ii->size[1] = b_ii->size[1];
                        emxEnsureCapacity((emxArray__common *)ii, i0, (int32_T)sizeof(int32_T), &emlrtRTEI);
                        loop_ub = b_ii->size[1] - 1;
                        for (i0 = 0; i0 <= loop_ub; i0++) {
                            ii->data[ii->size[0] * i0] = b_ii->data[b_ii->size[0] * i0];
                        }
                    }
                    EMLRTPOPRTSTACK(&bc_emlrtRSI);
                    i0 = iCritical->size[0] * iCritical->size[1];
                    iCritical->size[0] = 1;
                    iCritical->size[1] = ii->size[1];
                    emxEnsureCapacity((emxArray__common *)iCritical, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                    loop_ub = ii->size[0] * ii->size[1] - 1;
                    for (i0 = 0; i0 <= loop_ub; i0++) {
                        iCritical->data[i0] = (real_T)ii->data[i0];
                    }
                    EMLRTPOPRTSTACK(&i_emlrtRSI);
                    /* 'epu_n_unit_accumulator:175' iCritical = iCritical(1); */
                    emlrtDynamicBoundsCheck(1, 1, iCritical->size[1], &j_emlrtBCI);
                    /*  This is because when r equals 1, all accumulators cross at the same time */
                    /* 'epu_n_unit_accumulator:177' actAroundThres = activation(iTP-1:iTP,iCritical); */
                    emlrtDynamicBoundsCheck((int32_T)iCritical->data[0], 1, activation->size[1], &k_emlrtBCI);
                    for (i0 = 0; i0 < 2; i0++) {
                        emlrtDynamicBoundsCheck((int32_T)(iTP + (-1.0 + (real_T)i0)), 1, activation->size[0], &sb_emlrtBCI);
                    }
                    /* 'epu_n_unit_accumulator:178' tAroundThres = dt.*[iTP-1,iTP]'; */
                    /* 'epu_n_unit_accumulator:179' critThres = theta(iCritical); */
                    emlrtDynamicBoundsCheck((int32_T)iCritical->data[0], 1, theta->size[1], &l_emlrtBCI);
                    /* 'epu_n_unit_accumulator:181' rt = interp1q(actAroundThres,tAroundThres,critThres) + effTime; */
                    EMLRTPUSHRTSTACK(&j_emlrtRSI);
                    ixstart = (int32_T)iCritical->data[0];
                    for (i0 = 0; i0 < 2; i0++) {
                        mActivation[i0] = activation->data[((int32_T)(iTP + (-1.0 + (real_T)i0)) + activation->size[0] * (ixstart - 1)) - 1];
                    }
                    b_dt[0] = dt * (iTP - 1.0);
                    b_dt[1] = dt * iTP;
                    *rt = interp1q(mActivation, b_dt, theta->data[(int32_T)iCritical->data[0] - 1]) + effTime;
                    EMLRTPOPRTSTACK(&j_emlrtRSI);
                    /* 'epu_n_unit_accumulator:183' rt = rt(1); */
                    /*  If interp1q returns vector rather than scalar */
                }
            }
            /* 'epu_n_unit_accumulator:186' if iTP*dt > rt */
            if (iTP * dt > *rt) {
                /*  Keep data from selected accumulators */
                /* 'epu_n_unit_accumulator:188' activation = activation(:,iAT); */
                i0 = r3->size[0] * r3->size[1];
                r3->size[0] = 1;
                r3->size[1] = iAT->size[1];
                emxEnsureCapacity((emxArray__common *)r3, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                loop_ub = iAT->size[0] * iAT->size[1] - 1;
                for (i0 = 0; i0 <= loop_ub; i0++) {
                    r3->data[i0] = (real_T)emlrtDynamicBoundsCheck((int32_T)emlrtIntegerCheckR2009b(iAT->data[i0], &l_emlrtDCI), 1, activation->size[1], &ub_emlrtBCI);
                }
                ixstart = activation->size[0];
                nm1d2 = r3->size[1];
                i0 = m_activation->size[0] * m_activation->size[1];
                m_activation->size[0] = ixstart;
                m_activation->size[1] = nm1d2;
                emxEnsureCapacity((emxArray__common *)m_activation, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                loop_ub = nm1d2 - 1;
                for (i0 = 0; i0 <= loop_ub; i0++) {
                    idx = ixstart - 1;
                    for (nm1d2 = 0; nm1d2 <= idx; nm1d2++) {
                        m_activation->data[nm1d2 + m_activation->size[0] * i0] = activation->data[nm1d2 + activation->size[0] * ((int32_T)r3->data[i0] - 1)];
                    }
                }
                i0 = activation->size[0] * activation->size[1];
                activation->size[0] = m_activation->size[0];
                activation->size[1] = m_activation->size[1];
                emxEnsureCapacity((emxArray__common *)activation, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                loop_ub = m_activation->size[1] - 1;
                for (i0 = 0; i0 <= loop_ub; i0++) {
                    idx = m_activation->size[0] - 1;
                    for (nm1d2 = 0; nm1d2 <= idx; nm1d2++) {
                        activation->data[nm1d2 + activation->size[0] * i0] = m_activation->data[nm1d2 + m_activation->size[0] * i0];
                    }
                }
                exitg2 = 1U;
            } else {
                /* 'epu_n_unit_accumulator:192' if iTP > floor(nTP./dt)-1 */
                if (iTP > muDoubleScalarFloor(rdivide(nTP, dt)) - 1.0) {
                    /*  If trial end (i.e. maximum number of time points) has been reached */
                    /*  Keep data from selected accumulators */
                    /* 'epu_n_unit_accumulator:194' rt = nan; */
                    *rt = rtNaN;
                    /* 'epu_n_unit_accumulator:195' activation = activation(:,iAT); */
                    i0 = r4->size[0] * r4->size[1];
                    r4->size[0] = 1;
                    r4->size[1] = iAT->size[1];
                    emxEnsureCapacity((emxArray__common *)r4, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                    loop_ub = iAT->size[0] * iAT->size[1] - 1;
                    for (i0 = 0; i0 <= loop_ub; i0++) {
                        r4->data[i0] = (real_T)emlrtDynamicBoundsCheck((int32_T)emlrtIntegerCheckR2009b(iAT->data[i0], &k_emlrtDCI), 1, activation->size[1], &tb_emlrtBCI);
                    }
                    ixstart = activation->size[0];
                    nm1d2 = r4->size[1];
                    i0 = l_activation->size[0] * l_activation->size[1];
                    l_activation->size[0] = ixstart;
                    l_activation->size[1] = nm1d2;
                    emxEnsureCapacity((emxArray__common *)l_activation, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                    loop_ub = nm1d2 - 1;
                    for (i0 = 0; i0 <= loop_ub; i0++) {
                        idx = ixstart - 1;
                        for (nm1d2 = 0; nm1d2 <= idx; nm1d2++) {
                            l_activation->data[nm1d2 + l_activation->size[0] * i0] = activation->data[nm1d2 + activation->size[0] * ((int32_T)r4->data[i0] - 1)];
                        }
                    }
                    i0 = activation->size[0] * activation->size[1];
                    activation->size[0] = l_activation->size[0];
                    activation->size[1] = l_activation->size[1];
                    emxEnsureCapacity((emxArray__common *)activation, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                    loop_ub = l_activation->size[1] - 1;
                    for (i0 = 0; i0 <= loop_ub; i0++) {
                        idx = l_activation->size[0] - 1;
                        for (nm1d2 = 0; nm1d2 <= idx; nm1d2++) {
                            activation->data[nm1d2 + activation->size[0] * i0] = l_activation->data[nm1d2 + l_activation->size[0] * i0];
                        }
                    }
                    exitg2 = 1U;
                } else {
                    /* 'epu_n_unit_accumulator:199' iTP = iTP + 1; */
                    iTP++;
                    emlrtBreakCheck();
                }
            }
        }
        emxFree_real_T(&m_activation);
        emxFree_real_T(&l_activation);
        emxFree_int32_T(&b_ii);
        emxFree_real_T(&k_activation);
        emxFree_real_T(&j_activation);
        emxFree_real_T(&i_activation);
        emxFree_real_T(&h_activation);
        emxFree_real_T(&g_activation);
        emxFree_real_T(&f_activation);
        emxFree_real_T(&e_activation);
        emxFree_real_T(&d_activation);
        emxFree_int32_T(&r6);
        emxFree_int32_T(&r5);
        emxFree_real_T(&r4);
        emxFree_real_T(&r3);
        emxFree_int32_T(&r2);
        emxFree_boolean_T(&c_activation);
        emxFree_boolean_T(&b_activation);
        emxFree_boolean_T(&b_prop);
        emxFree_boolean_T(&iCrossed);
    } else {
        if (dMeth == 2.0) {
            b_emxInit_real_T(&b_mActivation, 1, &h_emlrtRTEI, TRUE);
            /* 'epu_n_unit_accumulator:202' elseif dMeth == 2 */
            /*  Pooling */
            /* 'epu_n_unit_accumulator:203' mActivation = zeros(nTP,1); */
            i0 = b_mActivation->size[0];
            b_mActivation->size[0] = (int32_T)emlrtIntegerCheckR2009b(emlrtNonNegativeCheckR2009b(nTP, &f_emlrtDCI), &e_emlrtDCI);
            emxEnsureCapacity((emxArray__common *)b_mActivation, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
            loop_ub = (int32_T)emlrtIntegerCheckR2009b(emlrtNonNegativeCheckR2009b(nTP, &h_emlrtDCI), &g_emlrtDCI) - 1;
            for (i0 = 0; i0 <= loop_ub; i0++) {
                b_mActivation->data[i0] = 0.0;
            }
            /* 'epu_n_unit_accumulator:204' mThreshold = mean(theta); */
            EMLRTPUSHRTSTACK(&k_emlrtRSI);
            mThreshold = mean(theta);
            EMLRTPOPRTSTACK(&k_emlrtRSI);
            /* 'epu_n_unit_accumulator:205' while iTP < Inf */
            emxInit_real_T(&o_activation, 2, &emlrtRTEI, TRUE);
            emxInit_boolean_T(&p_activation, 2, &emlrtRTEI, TRUE);
            b_emxInit_int32_T(&r8, 2, &emlrtRTEI, TRUE);
            emxInit_real_T(&r9, 2, &emlrtRTEI, TRUE);
            emxInit_real_T(&r10, 2, &emlrtRTEI, TRUE);
            emxInit_real_T(&q_activation, 2, &emlrtRTEI, TRUE);
            emxInit_real_T(&r_activation, 2, &emlrtRTEI, TRUE);
            emxInit_real_T(&s_activation, 2, &emlrtRTEI, TRUE);
            emxInit_real_T(&t_activation, 2, &emlrtRTEI, TRUE);
            emxInit_real_T(&u_activation, 2, &emlrtRTEI, TRUE);
            emxInit_real_T(&v_activation, 2, &emlrtRTEI, TRUE);
            emxInit_real_T(&w_activation, 2, &emlrtRTEI, TRUE);
            exitg1 = 0U;
            while ((exitg1 == 0U) && (iTP < rtInf)) {
                /*  Generate correlated Gaussian noise */
                /* 'epu_n_unit_accumulator:208' Xi = randn(1,size(SigmaXi,1)) * SigmaXi + zeros(1,nA); */
                EMLRTPUSHRTSTACK(&l_emlrtRSI);
                randn(SD, (real_T)SigmaXi->size[0], iCritical);
                EMLRTPUSHRTSTACK(&hb_emlrtRSI);
                innerDimOk = (iCritical->size[1] == SigmaXi->size[0]);
                if (!innerDimOk) {
                    if ((iCritical->size[1] == 1) || ((SigmaXi->size[0] == 1) && (SigmaXi->size[1] == 1))) {
                        EMLRTPUSHRTSTACK(&ib_emlrtRSI);
                        f_y = NULL;
                        m0 = mxCreateCharArray(2, iv6);
                        emlrtInitCharArray(45, m0, cv0);
                        emlrtAssign(&f_y, m0);
                        error(message(f_y, &e_emlrtMCI), &f_emlrtMCI);
                        EMLRTPOPRTSTACK(&ib_emlrtRSI);
                    } else {
                        EMLRTPUSHRTSTACK(&jb_emlrtRSI);
                        g_y = NULL;
                        m0 = mxCreateCharArray(2, iv7);
                        emlrtInitCharArray(21, m0, cv1);
                        emlrtAssign(&g_y, m0);
                        error(message(g_y, &g_emlrtMCI), &h_emlrtMCI);
                        EMLRTPOPRTSTACK(&jb_emlrtRSI);
                    }
                }
                EMLRTPOPRTSTACK(&hb_emlrtRSI);
                if ((iCritical->size[1] == 1) || (SigmaXi->size[0] == 1)) {
                    i0 = C->size[0] * C->size[1];
                    C->size[0] = 1;
                    C->size[1] = SigmaXi->size[1];
                    emxEnsureCapacity((emxArray__common *)C, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                    loop_ub = SigmaXi->size[1] - 1;
                    for (i0 = 0; i0 <= loop_ub; i0++) {
                        C->data[C->size[0] * i0] = 0.0;
                        idx = iCritical->size[1] - 1;
                        for (nm1d2 = 0; nm1d2 <= idx; nm1d2++) {
                            C->data[C->size[0] * i0] += iCritical->data[iCritical->size[0] * nm1d2] * SigmaXi->data[nm1d2 + SigmaXi->size[0] * i0];
                        }
                    }
                } else {
                    b_k = iCritical->size[1];
                    unnamed_idx_1 = (uint32_T)SigmaXi->size[1];
                    i0 = C->size[0] * C->size[1];
                    C->size[0] = 1;
                    C->size[1] = (int32_T)unnamed_idx_1;
                    emxEnsureCapacity((emxArray__common *)C, i0, (int32_T)sizeof(real_T), &c_emlrtRTEI);
                    n = SigmaXi->size[1];
                    i0 = C->size[0] * C->size[1];
                    C->size[0] = 1;
                    emxEnsureCapacity((emxArray__common *)C, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                    loop_ub = C->size[1] - 1;
                    for (i0 = 0; i0 <= loop_ub; i0++) {
                        C->data[C->size[0] * i0] = 0.0;
                    }
                    EMLRTPUSHRTSTACK(&gb_emlrtRSI);
                    EMLRTPUSHRTSTACK(&kb_emlrtRSI);
                    if ((n < 1) || (b_k < 1)) {
                    } else {
                        EMLRTPUSHRTSTACK(&mb_emlrtRSI);
                        ixstart = 1;
                        x = 1.0;
                        idx = 1;
                        prop = 0.0;
                        nm1d2 = 1;
                        TRANSA = 'N';
                        TRANSB = 'N';
                        EMLRTPUSHRTSTACK(&nb_emlrtRSI);
                        emlrtDynamicBoundsCheck(1, 1, iCritical->size[1], &s_emlrtBCI);
                        emlrtDynamicBoundsCheck(1, 1, SigmaXi->size[0] * SigmaXi->size[1], &t_emlrtBCI);
                        emlrtDynamicBoundsCheck(1, 1, C->size[1], &u_emlrtBCI);
                        dgemm32(&TRANSA, &TRANSB, &ixstart, &n, &b_k, &x, &iCritical->data[0], &idx, &SigmaXi->data[0], &b_k, &prop, &C->data[0], &nm1d2);
                        EMLRTPOPRTSTACK(&nb_emlrtRSI);
                        EMLRTPOPRTSTACK(&mb_emlrtRSI);
                    }
                    EMLRTPOPRTSTACK(&kb_emlrtRSI);
                    EMLRTPOPRTSTACK(&gb_emlrtRSI);
                }
                EMLRTPOPRTSTACK(&l_emlrtRSI);
                for (i0 = 0; i0 < 2; i0++) {
                    b_C[i0] = C->size[i0];
                }
                iv2[0] = 1;
                iv2[1] = v->size[1];
                emlrtSizeEqCheckND(b_C, iv2, &l_emlrtECI);
                /*  Compute activation level */
                /* 'epu_n_unit_accumulator:211' activation(iTP,:) = activation(iTP-1,:) + dt./TAU.*(v-k.*activation(iTP-1,:)) + sqrt(dt./TAU).*Xi; */
                emlrtDynamicBoundsCheck((int32_T)(iTP - 1.0), 1, activation->size[0], &n_emlrtBCI);
                for (i0 = 0; i0 < 2; i0++) {
                    b_C[i0] = k->size[i0];
                }
                i0 = activation->size[1];
                nm1d2 = q_activation->size[0] * q_activation->size[1];
                q_activation->size[0] = 1;
                q_activation->size[1] = i0;
                emxEnsureCapacity((emxArray__common *)q_activation, nm1d2, (int32_T)sizeof(real_T), &emlrtRTEI);
                loop_ub = i0 - 1;
                for (i0 = 0; i0 <= loop_ub; i0++) {
                    q_activation->data[q_activation->size[0] * i0] = activation->data[((int32_T)(iTP - 1.0) + activation->size[0] * i0) - 1];
                }
                for (i0 = 0; i0 < 2; i0++) {
                    n_activation[i0] = q_activation->size[i0];
                }
                emlrtSizeEqCheckND(b_C, n_activation, &m_emlrtECI);
                i0 = r0->size[0] * r0->size[1];
                r0->size[0] = 1;
                r0->size[1] = k->size[1];
                emxEnsureCapacity((emxArray__common *)r0, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                loop_ub = k->size[1] - 1;
                for (i0 = 0; i0 <= loop_ub; i0++) {
                    r0->data[r0->size[0] * i0] = k->data[k->size[0] * i0] * activation->data[((int32_T)(iTP - 1.0) + activation->size[0] * i0) - 1];
                }
                for (i0 = 0; i0 < 2; i0++) {
                    b_C[i0] = v->size[i0];
                }
                for (i0 = 0; i0 < 2; i0++) {
                    iv2[i0] = r0->size[i0];
                }
                emlrtSizeEqCheckND(b_C, iv2, &n_emlrtECI);
                emlrtDynamicBoundsCheck((int32_T)(iTP - 1.0), 1, activation->size[0], &m_emlrtBCI);
                i0 = r0->size[0] * r0->size[1];
                r0->size[0] = 1;
                r0->size[1] = v->size[1];
                emxEnsureCapacity((emxArray__common *)r0, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                x = rdivide(dt, 1.0);
                loop_ub = v->size[0] * v->size[1] - 1;
                for (i0 = 0; i0 <= loop_ub; i0++) {
                    r0->data[i0] = x * (v->data[i0] - r0->data[i0]);
                }
                i0 = activation->size[1];
                nm1d2 = r_activation->size[0] * r_activation->size[1];
                r_activation->size[0] = 1;
                r_activation->size[1] = i0;
                emxEnsureCapacity((emxArray__common *)r_activation, nm1d2, (int32_T)sizeof(real_T), &emlrtRTEI);
                loop_ub = i0 - 1;
                for (i0 = 0; i0 <= loop_ub; i0++) {
                    r_activation->data[r_activation->size[0] * i0] = activation->data[((int32_T)(iTP - 1.0) + activation->size[0] * i0) - 1];
                }
                for (i0 = 0; i0 < 2; i0++) {
                    n_activation[i0] = r_activation->size[i0];
                }
                for (i0 = 0; i0 < 2; i0++) {
                    iv2[i0] = r0->size[i0];
                }
                emlrtSizeEqCheckND(n_activation, iv2, &o_emlrtECI);
                EMLRTPUSHRTSTACK(&m_emlrtRSI);
                x = dt;
                b_sqrt(&x);
                i0 = C->size[0] * C->size[1];
                C->size[0] = 1;
                emxEnsureCapacity((emxArray__common *)C, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                nm1d2 = C->size[0];
                ixstart = C->size[1];
                loop_ub = nm1d2 * ixstart - 1;
                for (i0 = 0; i0 <= loop_ub; i0++) {
                    C->data[i0] *= x;
                }
                EMLRTPOPRTSTACK(&m_emlrtRSI);
                i0 = activation->size[1];
                nm1d2 = s_activation->size[0] * s_activation->size[1];
                s_activation->size[0] = 1;
                s_activation->size[1] = i0;
                emxEnsureCapacity((emxArray__common *)s_activation, nm1d2, (int32_T)sizeof(real_T), &emlrtRTEI);
                loop_ub = i0 - 1;
                for (i0 = 0; i0 <= loop_ub; i0++) {
                    s_activation->data[s_activation->size[0] * i0] = activation->data[((int32_T)(iTP - 1.0) + activation->size[0] * i0) - 1];
                }
                for (i0 = 0; i0 < 2; i0++) {
                    n_activation[i0] = s_activation->size[i0];
                }
                for (i0 = 0; i0 < 2; i0++) {
                    b_C[i0] = C->size[i0];
                }
                emlrtSizeEqCheckND(n_activation, b_C, &p_emlrtECI);
                emlrtDynamicBoundsCheck((int32_T)iTP, 1, activation->size[0], &o_emlrtBCI);
                i0 = activation->size[1];
                nm1d2 = r1->size[0];
                r1->size[0] = i0;
                emxEnsureCapacity((emxArray__common *)r1, nm1d2, (int32_T)sizeof(int32_T), &emlrtRTEI);
                loop_ub = i0 - 1;
                for (i0 = 0; i0 <= loop_ub; i0++) {
                    r1->data[i0] = i0;
                }
                iv2[0] = 1;
                iv2[1] = r1->size[0];
                i0 = activation->size[1];
                nm1d2 = t_activation->size[0] * t_activation->size[1];
                t_activation->size[0] = 1;
                t_activation->size[1] = i0;
                emxEnsureCapacity((emxArray__common *)t_activation, nm1d2, (int32_T)sizeof(real_T), &emlrtRTEI);
                loop_ub = i0 - 1;
                for (i0 = 0; i0 <= loop_ub; i0++) {
                    t_activation->data[t_activation->size[0] * i0] = activation->data[((int32_T)iTP + activation->size[0] * i0) - 2];
                }
                for (i0 = 0; i0 < 2; i0++) {
                    n_activation[i0] = t_activation->size[i0];
                }
                emlrtSubAssignSizeCheck(iv2, 2, n_activation, 2, &q_emlrtECI);
                ixstart = activation->size[1];
                i0 = u_activation->size[0] * u_activation->size[1];
                u_activation->size[0] = 1;
                u_activation->size[1] = ixstart;
                emxEnsureCapacity((emxArray__common *)u_activation, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                loop_ub = ixstart - 1;
                for (i0 = 0; i0 <= loop_ub; i0++) {
                    u_activation->data[u_activation->size[0] * i0] = (activation->data[((int32_T)iTP + activation->size[0] * i0) - 2] + r0->data[r0->size[0] * i0]) + C->data[C->size[0] * i0];
                }
                loop_ub = u_activation->size[1] - 1;
                for (i0 = 0; i0 <= loop_ub; i0++) {
                    activation->data[((int32_T)iTP + activation->size[0] * r1->data[i0]) - 1] = u_activation->data[u_activation->size[0] * i0];
                }
                /*  Reset activation level if it goes below zero */
                /* 'epu_n_unit_accumulator:214' activation(iTP,(activation(iTP,:) < 0)) = 0; */
                EMLRTPUSHRTSTACK(&n_emlrtRSI);
                i0 = activation->size[1];
                ixstart = emlrtDynamicBoundsCheck((int32_T)iTP, 1, activation->size[0], &q_emlrtBCI);
                nm1d2 = p_activation->size[0] * p_activation->size[1];
                p_activation->size[0] = 1;
                p_activation->size[1] = i0;
                emxEnsureCapacity((emxArray__common *)p_activation, nm1d2, (int32_T)sizeof(boolean_T), &emlrtRTEI);
                loop_ub = i0 - 1;
                for (i0 = 0; i0 <= loop_ub; i0++) {
                    p_activation->data[p_activation->size[0] * i0] = (activation->data[(ixstart + activation->size[0] * i0) - 1] < 0.0);
                }
                eml_li_find(p_activation, ii);
                i0 = r8->size[0] * r8->size[1];
                r8->size[0] = 1;
                r8->size[1] = ii->size[1];
                emxEnsureCapacity((emxArray__common *)r8, i0, (int32_T)sizeof(int32_T), &emlrtRTEI);
                loop_ub = ii->size[0] * ii->size[1] - 1;
                for (i0 = 0; i0 <= loop_ub; i0++) {
                    r8->data[i0] = emlrtDynamicBoundsCheck(ii->data[i0], 1, activation->size[1], &gb_emlrtBCI);
                }
                i0 = r1->size[0];
                r1->size[0] = r8->size[1];
                emxEnsureCapacity((emxArray__common *)r1, i0, (int32_T)sizeof(int32_T), &emlrtRTEI);
                loop_ub = r8->size[1] - 1;
                for (i0 = 0; i0 <= loop_ub; i0++) {
                    r1->data[i0] = r8->data[i0];
                }
                EMLRTPOPRTSTACK(&n_emlrtRSI);
                ixstart = activation->size[0];
                emlrtDynamicBoundsCheck((int32_T)iTP, 1, ixstart, &p_emlrtBCI);
                nm1d2 = r1->size[0];
                loop_ub = nm1d2 - 1;
                for (i0 = 0; i0 <= loop_ub; i0++) {
                    activation->data[((int32_T)iTP + activation->size[0] * (r1->data[i0] - 1)) - 1] = 0.0;
                }
                /*  Compute mean activation level across all accumulators */
                /* 'epu_n_unit_accumulator:217' mActivation(iTP) = mean(activation(iTP,:)); */
                EMLRTPUSHRTSTACK(&o_emlrtRSI);
                i0 = activation->size[1];
                ixstart = emlrtDynamicBoundsCheck((int32_T)iTP, 1, activation->size[0], &r_emlrtBCI);
                nm1d2 = o_activation->size[0] * o_activation->size[1];
                o_activation->size[0] = 1;
                o_activation->size[1] = i0;
                emxEnsureCapacity((emxArray__common *)o_activation, nm1d2, (int32_T)sizeof(real_T), &emlrtRTEI);
                loop_ub = i0 - 1;
                for (i0 = 0; i0 <= loop_ub; i0++) {
                    o_activation->data[o_activation->size[0] * i0] = activation->data[(ixstart + activation->size[0] * i0) - 1];
                }
                b_mActivation->data[emlrtDynamicBoundsCheck((int32_T)iTP, 1, b_mActivation->size[0], &hb_emlrtBCI) - 1] = mean(o_activation);
                EMLRTPOPRTSTACK(&o_emlrtRSI);
                /* 'epu_n_unit_accumulator:219' if isinf(rt) && all(mActivation(iTP) > mThreshold) */
                if (muDoubleScalarIsInf(*rt)) {
                    innerDimOk = (b_mActivation->data[emlrtDynamicBoundsCheck((int32_T)iTP, 1, b_mActivation->size[0], &ib_emlrtBCI) - 1] > mThreshold);
                    if (innerDimOk) {
                        /* 'epu_n_unit_accumulator:221' actAroundThres = mActivation(iTP-1:iTP); */
                        emlrtVectorVectorIndexCheck(b_mActivation->size[0], 1, 1, 2, &r_emlrtECI);
                        for (i0 = 0; i0 < 2; i0++) {
                            emlrtDynamicBoundsCheck((int32_T)(iTP + (-1.0 + (real_T)i0)), 1, b_mActivation->size[0], &jb_emlrtBCI);
                        }
                        /* 'epu_n_unit_accumulator:222' tAroundThres = dt.*[iTP-1,iTP]'; */
                        /* 'epu_n_unit_accumulator:224' rt = interp1q(actAroundThres,tAroundThres,mThreshold) + effTime; */
                        EMLRTPUSHRTSTACK(&p_emlrtRSI);
                        for (i0 = 0; i0 < 2; i0++) {
                            mActivation[i0] = b_mActivation->data[(int32_T)(iTP + (-1.0 + (real_T)i0)) - 1];
                        }
                        b_dt[0] = dt * (iTP - 1.0);
                        b_dt[1] = dt * iTP;
                        *rt = interp1q(mActivation, b_dt, mThreshold) + effTime;
                        EMLRTPOPRTSTACK(&p_emlrtRSI);
                        /* 'epu_n_unit_accumulator:226' rt = rt(1); */
                        /*  In case inetrp1q returns vector rather than scalar */
                    }
                }
                /* 'epu_n_unit_accumulator:229' if iTP*dt > rt */
                if (iTP * dt > *rt) {
                    /* 'epu_n_unit_accumulator:230' activation = activation(:,iAT); */
                    i0 = r9->size[0] * r9->size[1];
                    r9->size[0] = 1;
                    r9->size[1] = iAT->size[1];
                    emxEnsureCapacity((emxArray__common *)r9, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                    loop_ub = iAT->size[0] * iAT->size[1] - 1;
                    for (i0 = 0; i0 <= loop_ub; i0++) {
                        r9->data[i0] = (real_T)emlrtDynamicBoundsCheck((int32_T)emlrtIntegerCheckR2009b(iAT->data[i0], &j_emlrtDCI), 1, activation->size[1], &lb_emlrtBCI);
                    }
                    ixstart = activation->size[0];
                    nm1d2 = r9->size[1];
                    i0 = w_activation->size[0] * w_activation->size[1];
                    w_activation->size[0] = ixstart;
                    w_activation->size[1] = nm1d2;
                    emxEnsureCapacity((emxArray__common *)w_activation, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                    loop_ub = nm1d2 - 1;
                    for (i0 = 0; i0 <= loop_ub; i0++) {
                        idx = ixstart - 1;
                        for (nm1d2 = 0; nm1d2 <= idx; nm1d2++) {
                            w_activation->data[nm1d2 + w_activation->size[0] * i0] = activation->data[nm1d2 + activation->size[0] * ((int32_T)r9->data[i0] - 1)];
                        }
                    }
                    i0 = activation->size[0] * activation->size[1];
                    activation->size[0] = w_activation->size[0];
                    activation->size[1] = w_activation->size[1];
                    emxEnsureCapacity((emxArray__common *)activation, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                    loop_ub = w_activation->size[1] - 1;
                    for (i0 = 0; i0 <= loop_ub; i0++) {
                        idx = w_activation->size[0] - 1;
                        for (nm1d2 = 0; nm1d2 <= idx; nm1d2++) {
                            activation->data[nm1d2 + activation->size[0] * i0] = w_activation->data[nm1d2 + w_activation->size[0] * i0];
                        }
                    }
                    exitg1 = 1U;
                } else {
                    /* 'epu_n_unit_accumulator:237' if iTP > floor(nTP./dt)-1 */
                    if (iTP > muDoubleScalarFloor(nTP / dt) - 1.0) {
                        /*  Keep data from selected accumulators */
                        /* 'epu_n_unit_accumulator:239' rt = nan; */
                        *rt = rtNaN;
                        /* 'epu_n_unit_accumulator:240' activation = activation(:,iAT); */
                        i0 = r10->size[0] * r10->size[1];
                        r10->size[0] = 1;
                        r10->size[1] = iAT->size[1];
                        emxEnsureCapacity((emxArray__common *)r10, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                        loop_ub = iAT->size[0] * iAT->size[1] - 1;
                        for (i0 = 0; i0 <= loop_ub; i0++) {
                            r10->data[i0] = (real_T)emlrtDynamicBoundsCheck((int32_T)emlrtIntegerCheckR2009b(iAT->data[i0], &i_emlrtDCI), 1, activation->size[1], &kb_emlrtBCI);
                        }
                        ixstart = activation->size[0];
                        nm1d2 = r10->size[1];
                        i0 = v_activation->size[0] * v_activation->size[1];
                        v_activation->size[0] = ixstart;
                        v_activation->size[1] = nm1d2;
                        emxEnsureCapacity((emxArray__common *)v_activation, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                        loop_ub = nm1d2 - 1;
                        for (i0 = 0; i0 <= loop_ub; i0++) {
                            idx = ixstart - 1;
                            for (nm1d2 = 0; nm1d2 <= idx; nm1d2++) {
                                v_activation->data[nm1d2 + v_activation->size[0] * i0] = activation->data[nm1d2 + activation->size[0] * ((int32_T)r10->data[i0] - 1)];
                            }
                        }
                        i0 = activation->size[0] * activation->size[1];
                        activation->size[0] = v_activation->size[0];
                        activation->size[1] = v_activation->size[1];
                        emxEnsureCapacity((emxArray__common *)activation, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                        loop_ub = v_activation->size[1] - 1;
                        for (i0 = 0; i0 <= loop_ub; i0++) {
                            idx = v_activation->size[0] - 1;
                            for (nm1d2 = 0; nm1d2 <= idx; nm1d2++) {
                                activation->data[nm1d2 + activation->size[0] * i0] = v_activation->data[nm1d2 + v_activation->size[0] * i0];
                            }
                        }
                        exitg1 = 1U;
                    } else {
                        /* 'epu_n_unit_accumulator:247' iTP = iTP + 1; */
                        iTP++;
                        emlrtBreakCheck();
                    }
                }
            }
            emxFree_real_T(&w_activation);
            emxFree_real_T(&v_activation);
            emxFree_real_T(&u_activation);
            emxFree_real_T(&t_activation);
            emxFree_real_T(&s_activation);
            emxFree_real_T(&r_activation);
            emxFree_real_T(&q_activation);
            emxFree_real_T(&r10);
            emxFree_real_T(&r9);
            emxFree_int32_T(&r8);
            emxFree_boolean_T(&p_activation);
            emxFree_real_T(&o_activation);
            emxFree_real_T(&b_mActivation);
        }
    }
    emxFree_int32_T(&ii);
    emxFree_int32_T(&r1);
    emxFree_real_T(&r0);
    /*  Transform to 1-ms steps */
    /* 'epu_n_unit_accumulator:253' t = dt:dt:nTP; */
    EMLRTPUSHRTSTACK(&q_emlrtRSI);
    EMLRTPUSHRTSTACK(&nc_emlrtRSI);
    float_colon_length(dt, dt, nTP, &n, &x, &prop, &innerDimOk);
    EMLRTPUSHRTSTACK(&oc_emlrtRSI);
    if (!innerDimOk) {
    } else {
        EMLRTPUSHRTSTACK(&pc_emlrtRSI);
        h_y = NULL;
        m0 = mxCreateCharArray(2, iv8);
        emlrtInitCharArray(21, m0, cv4);
        emlrtAssign(&h_y, m0);
        error(message(h_y, &ab_emlrtMCI), &bb_emlrtMCI);
        EMLRTPOPRTSTACK(&pc_emlrtRSI);
    }
    EMLRTPOPRTSTACK(&oc_emlrtRSI);
    emlrtNonNegativeCheckR2009b((real_T)n, &c_emlrtDCI);
    i0 = iCritical->size[0] * iCritical->size[1];
    iCritical->size[0] = 1;
    iCritical->size[1] = n;
    emxEnsureCapacity((emxArray__common *)iCritical, i0, (int32_T)sizeof(real_T), &b_emlrtRTEI);
    if (n > 0) {
        emlrtDynamicBoundsCheck(1, 1, iCritical->size[1], &eb_emlrtBCI);
        iCritical->data[0] = x;
        if (n > 1) {
            iCritical->data[emlrtDynamicBoundsCheck(n, 1, iCritical->size[1], &vb_emlrtBCI) - 1] = prop;
            ixstart = n - 1;
            i0 = ixstart;
            nm1d2 = (int32_T)((uint32_T)i0 >> 1);
            for (b_k = 1; b_k <= nm1d2 - 1; b_k++) {
                mThreshold = (real_T)b_k * dt;
                iCritical->data[emlrtDynamicBoundsCheck(b_k + 1, 1, iCritical->size[1], &gc_emlrtBCI) - 1] = x + mThreshold;
                iCritical->data[emlrtDynamicBoundsCheck(n - b_k, 1, iCritical->size[1], &hc_emlrtBCI) - 1] = prop - mThreshold;
            }
            if (nm1d2 << 1 == ixstart) {
                iCritical->data[emlrtDynamicBoundsCheck(nm1d2 + 1, 1, iCritical->size[1], &yb_emlrtBCI) - 1] = (x + prop) / 2.0;
            } else {
                mThreshold = (real_T)nm1d2 * dt;
                iCritical->data[emlrtDynamicBoundsCheck(nm1d2 + 1, 1, iCritical->size[1], &wb_emlrtBCI) - 1] = x + mThreshold;
                iCritical->data[emlrtDynamicBoundsCheck(nm1d2 + 2, 1, iCritical->size[1], &xb_emlrtBCI) - 1] = prop - mThreshold;
            }
        }
    }
    EMLRTPOPRTSTACK(&nc_emlrtRSI);
    EMLRTPOPRTSTACK(&q_emlrtRSI);
    /* 'epu_n_unit_accumulator:254' activation = interp1(t,activation,colon(1,nTP)); */
    EMLRTPUSHRTSTACK(&r_emlrtRSI);
    EMLRTPUSHRTSTACK(&qc_emlrtRSI);
    EMLRTPUSHRTSTACK(&rc_emlrtRSI);
    float_colon_length(1.0, 1.0, nTP, &n, &x, &prop, &innerDimOk);
    EMLRTPUSHRTSTACK(&sc_emlrtRSI);
    if (!innerDimOk) {
    } else {
        EMLRTPUSHRTSTACK(&pc_emlrtRSI);
        i_y = NULL;
        m0 = mxCreateCharArray(2, iv9);
        emlrtInitCharArray(21, m0, cv4);
        emlrtAssign(&i_y, m0);
        error(message(i_y, &ab_emlrtMCI), &bb_emlrtMCI);
        EMLRTPOPRTSTACK(&pc_emlrtRSI);
    }
    EMLRTPOPRTSTACK(&sc_emlrtRSI);
    emlrtNonNegativeCheckR2009b((real_T)n, &d_emlrtDCI);
    i0 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = n;
    emxEnsureCapacity((emxArray__common *)C, i0, (int32_T)sizeof(real_T), &d_emlrtRTEI);
    if (n > 0) {
        emlrtDynamicBoundsCheck(1, 1, C->size[1], &fb_emlrtBCI);
        C->data[0] = x;
        if (n > 1) {
            C->data[emlrtDynamicBoundsCheck(n, 1, C->size[1], &ac_emlrtBCI) - 1] = prop;
            ixstart = n - 1;
            i0 = ixstart;
            nm1d2 = (int32_T)((uint32_T)i0 >> 1);
            for (b_k = 1; b_k <= nm1d2 - 1; b_k++) {
                C->data[emlrtDynamicBoundsCheck(b_k + 1, 1, C->size[1], &ec_emlrtBCI) - 1] = x + (real_T)b_k;
                C->data[emlrtDynamicBoundsCheck(n - b_k, 1, C->size[1], &fc_emlrtBCI) - 1] = prop - (real_T)b_k;
            }
            if (nm1d2 << 1 == ixstart) {
                C->data[emlrtDynamicBoundsCheck(nm1d2 + 1, 1, C->size[1], &dc_emlrtBCI) - 1] = (x + prop) / 2.0;
            } else {
                C->data[emlrtDynamicBoundsCheck(nm1d2 + 1, 1, C->size[1], &bc_emlrtBCI) - 1] = x + (real_T)nm1d2;
                C->data[emlrtDynamicBoundsCheck(nm1d2 + 2, 1, C->size[1], &cc_emlrtBCI) - 1] = prop - (real_T)nm1d2;
            }
        }
    }
    emxInit_real_T(&x_activation, 2, &emlrtRTEI, TRUE);
    EMLRTPOPRTSTACK(&rc_emlrtRSI);
    EMLRTPOPRTSTACK(&qc_emlrtRSI);
    EMLRTPUSHRTSTACK(&tc_emlrtRSI);
    i0 = x_activation->size[0] * x_activation->size[1];
    x_activation->size[0] = activation->size[0];
    x_activation->size[1] = activation->size[1];
    emxEnsureCapacity((emxArray__common *)x_activation, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
    loop_ub = activation->size[0] * activation->size[1] - 1;
    for (i0 = 0; i0 <= loop_ub; i0++) {
        x_activation->data[i0] = activation->data[i0];
    }
    interp1_work(x_activation, C, iCritical, activation);
    EMLRTPOPRTSTACK(&tc_emlrtRSI);
    EMLRTPOPRTSTACK(&r_emlrtRSI);
    emxFree_real_T(&x_activation);
    emxFree_real_T(&C);
    emxFree_real_T(&iCritical);
    emlrtHeapReferenceStackLeaveFcn();
}
/* End of code generation (epu_n_unit_accumulator.c) */
