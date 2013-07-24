/*
 * epu_compute_trajectory_onset_data.c
 *
 * Code generation for function 'epu_compute_trajectory_onset_data'
 *
 * C source code generated on: Fri Aug 31 09:24:08 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_compute_trajectory_onset.h"
#include "epu_compute_trajectory_onset_data.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
emlrtRSInfo f_emlrtRSI = { 12, "error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/lang/error.m" };
emlrtRSInfo x_emlrtRSI = { 233, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
emlrtRSInfo bb_emlrtRSI = { 117, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
emlrtRSInfo bd_emlrtRSI = { 18, "eml_blas_xnrm2", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m" };
emlrtRSInfo ed_emlrtRSI = { 14, "eml_blas_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m" };
emlrtRSInfo jd_emlrtRSI = { 21, "eml_blas_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m" };
emlrtRSInfo ld_emlrtRSI = { 14, "eml_refblas_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m" };
emlrtRSInfo nd_emlrtRSI = { 19, "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m" };
emlrtRSInfo rd_emlrtRSI = { 18, "eml_blas_xnrm2", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m" };
emlrtRSInfo ud_emlrtRSI = { 14, "eml_blas_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m" };
emlrtRSInfo ee_emlrtRSI = { 21, "eml_blas_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m" };
emlrtRSInfo ge_emlrtRSI = { 14, "eml_refblas_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m" };
emlrtRSInfo ie_emlrtRSI = { 19, "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m" };
emlrtRSInfo me_emlrtRSI = { 14, "eml_blas_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m" };
emlrtRSInfo we_emlrtRSI = { 11, "eml_blas_xrotg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m" };
emlrtRSInfo ye_emlrtRSI = { 33, "eml_refblas_xrotg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m" };
emlrtRSInfo cf_emlrtRSI = { 17, "eml_blas_xrot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m" };
emlrtRSInfo mf_emlrtRSI = { 20, "eml_blas_xgemm", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m" };
emlrtRSInfo bg_emlrtRSI = { 107, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
emlrtRSInfo cg_emlrtRSI = { 113, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
emlrtRSInfo dg_emlrtRSI = { 129, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
emlrtRSInfo eg_emlrtRSI = { 135, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
emlrtRSInfo hg_emlrtRSI = { 208, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
emlrtRSInfo ig_emlrtRSI = { 211, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
emlrtRSInfo bh_emlrtRSI = { 18, "eml_blas_xnrm2", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m" };
emlrtRSInfo eh_emlrtRSI = { 14, "eml_blas_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m" };
emlrtRSInfo jh_emlrtRSI = { 21, "eml_blas_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m" };
emlrtRSInfo lh_emlrtRSI = { 14, "eml_refblas_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m" };
emlrtRSInfo nh_emlrtRSI = { 19, "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m" };
emlrtRSInfo qh_emlrtRSI = { 19, "eml_xnrm2", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m" };
emlrtRSInfo rh_emlrtRSI = { 18, "eml_blas_xnrm2", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m" };
emlrtRSInfo sh_emlrtRSI = { 28, "eml_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m" };
emlrtRSInfo th_emlrtRSI = { 14, "eml_blas_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m" };
emlrtRSInfo uh_emlrtRSI = { 42, "eml_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m" };
emlrtRSInfo vh_emlrtRSI = { 19, "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m" };
emlrtRSInfo wh_emlrtRSI = { 25, "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m" };
emlrtRSInfo xh_emlrtRSI = { 66, "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m" };
emlrtRSInfo yh_emlrtRSI = { 42, "eml_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m" };
emlrtRSInfo ai_emlrtRSI = { 19, "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m" };
emlrtRSInfo bi_emlrtRSI = { 25, "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m" };
emlrtRSInfo ci_emlrtRSI = { 66, "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m" };
emlrtRSInfo di_emlrtRSI = { 31, "eml_xdotc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m" };
emlrtRSInfo ei_emlrtRSI = { 28, "eml_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m" };
emlrtRSInfo fi_emlrtRSI = { 21, "eml_blas_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m" };
emlrtRSInfo gi_emlrtRSI = { 14, "eml_refblas_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m" };
emlrtRSInfo hi_emlrtRSI = { 42, "eml_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m" };
emlrtRSInfo ii_emlrtRSI = { 19, "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m" };
emlrtRSInfo qi_emlrtRSI = { 20, "eml_blas_xgemm", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m" };
emlrtRSInfo yi_emlrtRSI = { 19, "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m" };
emlrtRSInfo dj_emlrtRSI = { 19, "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m" };
emlrtRSInfo gj_emlrtRSI = { 21, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
emlrtRSInfo hj_emlrtRSI = { 79, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
emlrtRSInfo ij_emlrtRSI = { 117, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
emlrtRSInfo pj_emlrtRSI = { 21, "eml_blas_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m" };
emlrtRSInfo rj_emlrtRSI = { 14, "eml_refblas_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m" };
emlrtMCInfo c_emlrtMCI = { 12, 7, "error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/lang/error.m" };
emlrtMCInfo d_emlrtMCI = { 234, 5, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
emlrtMCInfo e_emlrtMCI = { 233, 15, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
emlrtRTEInfo emlrtRTEI = { 118, 1, "colon", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/colon.m" };
emlrtRTEInfo y_emlrtRTEI = { 1, 14, "eml_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m" };
emlrtRTEInfo ab_emlrtRTEI = { 1, 14, "eml_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m" };
emlrtRTEInfo bb_emlrtRTEI = { 1, 14, "eml_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m" };
emlrtRTEInfo cb_emlrtRTEI = { 1, 14, "eml_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m" };
emlrtRTEInfo db_emlrtRTEI = { 1, 14, "eml_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m" };
emlrtRTEInfo eb_emlrtRTEI = { 1, 14, "eml_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m" };
emlrtRTEInfo gb_emlrtRTEI = { 1, 18, "eml_xrot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m" };
emlrtRTEInfo hb_emlrtRTEI = { 1, 18, "eml_xswap", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m" };
emlrtRTEInfo ib_emlrtRTEI = { 1, 18, "eml_xswap", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m" };
emlrtRTEInfo nb_emlrtRTEI = { 1, 14, "eml_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m" };
emlrtRTEInfo ob_emlrtRTEI = { 1, 14, "eml_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m" };
emlrtRTEInfo pb_emlrtRTEI = { 1, 14, "eml_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m" };
emlrtRTEInfo qb_emlrtRTEI = { 1, 14, "eml_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m" };
emlrtBCInfo dn_emlrtBCI = { 1, 2, 20, 13, "", "eml_refblas_xnrm2", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m", 0 };
emlrtBCInfo en_emlrtBCI = { 1, 2, 36, 22, "", "eml_refblas_xnrm2", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m", 0 };
emlrtBCInfo fn_emlrtBCI = { 1, 4, 45, 21, "", "eml_refblas_xdotx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m", 0 };
emlrtBCInfo gn_emlrtBCI = { 1, 4, 45, 28, "", "eml_refblas_xdotx", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m", 0 };
emlrtBCInfo pq_emlrtBCI = { 1, 2, 20, 5, "", "eml_refblas_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m", 0 };
emlrtBCInfo qq_emlrtBCI = { 1, 2, 20, 15, "", "eml_refblas_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m", 0 };
emlrtBCInfo rq_emlrtBCI = { -1, -1, 66, 49, "", "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m", 0 };
emlrtBCInfo sq_emlrtBCI = { -1, -1, 67, 26, "", "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m", 0 };
emlrtBCInfo tq_emlrtBCI = { -1, -1, 66, 49, "", "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m", 0 };
emlrtBCInfo uq_emlrtBCI = { -1, -1, 67, 26, "", "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m", 0 };
emlrtBCInfo vq_emlrtBCI = { 1, 4, 33, 13, "", "eml_refblas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m", 0 };
emlrtBCInfo wq_emlrtBCI = { 1, 4, 34, 17, "", "eml_refblas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m", 0 };
emlrtBCInfo xq_emlrtBCI = { 1, 4, 34, 46, "", "eml_refblas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m", 0 };

/* Function Declarations */

/* Function Definitions */
/* End of code generation (epu_compute_trajectory_onset_data.c) */
