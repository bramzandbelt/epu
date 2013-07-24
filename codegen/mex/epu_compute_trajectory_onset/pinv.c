/*
 * pinv.c
 *
 * Code generation for function 'pinv'
 *
 * C source code generated on: Fri Aug 31 09:24:08 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_compute_trajectory_onset.h"
#include "pinv.h"
#include "median.h"
#include "epu_compute_trajectory_onset_emxutil.h"
#include "sqrt.h"
#include "epu_compute_trajectory_onset_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo ob_emlrtRSI = { 40, "pinv", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/pinv.m" };
static emlrtRSInfo pb_emlrtRSI = { 64, "pinv", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/pinv.m" };
static emlrtRSInfo qb_emlrtRSI = { 67, "pinv", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/pinv.m" };
static emlrtRSInfo rb_emlrtRSI = { 14, "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m" };
static emlrtRSInfo sb_emlrtRSI = { 58, "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m" };
static emlrtRSInfo tb_emlrtRSI = { 20, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtRSInfo ub_emlrtRSI = { 19, "eml_xgesvd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m" };
static emlrtRSInfo vb_emlrtRSI = { 9, "eml_lapack_xgesvd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m" };
static emlrtRSInfo wb_emlrtRSI = { 71, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo xb_emlrtRSI = { 75, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo yb_emlrtRSI = { 87, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo ac_emlrtRSI = { 90, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo bc_emlrtRSI = { 107, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo cc_emlrtRSI = { 113, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo dc_emlrtRSI = { 129, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo ec_emlrtRSI = { 135, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo fc_emlrtRSI = { 177, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo gc_emlrtRSI = { 180, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo hc_emlrtRSI = { 208, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo ic_emlrtRSI = { 211, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo jc_emlrtRSI = { 233, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo kc_emlrtRSI = { 244, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo lc_emlrtRSI = { 261, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo mc_emlrtRSI = { 358, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo nc_emlrtRSI = { 371, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo oc_emlrtRSI = { 383, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo pc_emlrtRSI = { 394, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo qc_emlrtRSI = { 396, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo rc_emlrtRSI = { 405, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo sc_emlrtRSI = { 345, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo tc_emlrtRSI = { 352, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo uc_emlrtRSI = { 326, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo vc_emlrtRSI = { 336, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo wc_emlrtRSI = { 417, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo xc_emlrtRSI = { 430, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo yc_emlrtRSI = { 436, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo ad_emlrtRSI = { 19, "eml_xnrm2", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m" };
static emlrtRSInfo cd_emlrtRSI = { 24, "eml_blas_xnrm2", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m" };
static emlrtRSInfo dd_emlrtRSI = { 28, "eml_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m" };
static emlrtRSInfo fd_emlrtRSI = { 20, "eml_blas_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m" };
static emlrtRSInfo gd_emlrtRSI = { 55, "eml_blas_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m" };
static emlrtRSInfo hd_emlrtRSI = { 31, "eml_xdotc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m" };
static emlrtRSInfo id_emlrtRSI = { 28, "eml_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m" };
static emlrtRSInfo kd_emlrtRSI = { 28, "eml_blas_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m" };
static emlrtRSInfo md_emlrtRSI = { 42, "eml_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m" };
static emlrtRSInfo od_emlrtRSI = { 25, "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m" };
static emlrtRSInfo pd_emlrtRSI = { 63, "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m" };
static emlrtRSInfo qd_emlrtRSI = { 19, "eml_xnrm2", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m" };
static emlrtRSInfo sd_emlrtRSI = { 24, "eml_blas_xnrm2", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m" };
static emlrtRSInfo td_emlrtRSI = { 28, "eml_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m" };
static emlrtRSInfo vd_emlrtRSI = { 20, "eml_blas_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m" };
static emlrtRSInfo wd_emlrtRSI = { 55, "eml_blas_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m" };
static emlrtRSInfo xd_emlrtRSI = { 42, "eml_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m" };
static emlrtRSInfo yd_emlrtRSI = { 19, "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m" };
static emlrtRSInfo ae_emlrtRSI = { 42, "eml_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m" };
static emlrtRSInfo be_emlrtRSI = { 19, "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m" };
static emlrtRSInfo ce_emlrtRSI = { 31, "eml_xdotc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m" };
static emlrtRSInfo de_emlrtRSI = { 28, "eml_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m" };
static emlrtRSInfo fe_emlrtRSI = { 28, "eml_blas_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m" };
static emlrtRSInfo he_emlrtRSI = { 42, "eml_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m" };
static emlrtRSInfo je_emlrtRSI = { 25, "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m" };
static emlrtRSInfo ke_emlrtRSI = { 63, "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m" };
static emlrtRSInfo le_emlrtRSI = { 28, "eml_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m" };
static emlrtRSInfo ne_emlrtRSI = { 20, "eml_blas_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m" };
static emlrtRSInfo oe_emlrtRSI = { 55, "eml_blas_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m" };
static emlrtRSInfo pe_emlrtRSI = { 20, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtRSInfo qe_emlrtRSI = { 16, "max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/max.m" };
static emlrtRSInfo re_emlrtRSI = { 18, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtRSInfo se_emlrtRSI = { 88, "eml_min_or_max", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtRSInfo ve_emlrtRSI = { 18, "eml_xrotg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m" };
static emlrtRSInfo xe_emlrtRSI = { 13, "eml_blas_xrotg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m" };
static emlrtRSInfo af_emlrtRSI = { 38, "eml_blas_xrotg", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m" };
static emlrtRSInfo bf_emlrtRSI = { 28, "eml_xrot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m" };
static emlrtRSInfo df_emlrtRSI = { 24, "eml_blas_xrot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m" };
static emlrtRSInfo ef_emlrtRSI = { 62, "eml_blas_xrot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m" };
static emlrtRSInfo ff_emlrtRSI = { 28, "eml_xrot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m" };
static emlrtRSInfo gf_emlrtRSI = { 17, "eml_blas_xrot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m" };
static emlrtRSInfo hf_emlrtRSI = { 26, "eml_xswap", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m" };
static emlrtRSInfo if_emlrtRSI = { 15, "eml_blas_xswap", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m" };
static emlrtRSInfo jf_emlrtRSI = { 26, "eml_xswap", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m" };
static emlrtRSInfo kf_emlrtRSI = { 15, "eml_blas_xswap", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m" };
static emlrtRSInfo lf_emlrtRSI = { 54, "eml_xgemm", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m" };
static emlrtRSInfo nf_emlrtRSI = { 32, "eml_blas_xgemm", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m" };
static emlrtRSInfo of_emlrtRSI = { 103, "eml_blas_xgemm", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m" };
static emlrtRSInfo pf_emlrtRSI = { 40, "pinv", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/pinv.m" };
static emlrtRSInfo qf_emlrtRSI = { 64, "pinv", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/pinv.m" };
static emlrtRSInfo rf_emlrtRSI = { 67, "pinv", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/pinv.m" };
static emlrtRSInfo sf_emlrtRSI = { 14, "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m" };
static emlrtRSInfo tf_emlrtRSI = { 58, "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m" };
static emlrtRSInfo uf_emlrtRSI = { 19, "eml_xgesvd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m" };
static emlrtRSInfo vf_emlrtRSI = { 9, "eml_lapack_xgesvd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m" };
static emlrtRSInfo wf_emlrtRSI = { 71, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo xf_emlrtRSI = { 75, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo yf_emlrtRSI = { 87, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo ag_emlrtRSI = { 90, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo fg_emlrtRSI = { 177, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo gg_emlrtRSI = { 180, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo jg_emlrtRSI = { 233, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo kg_emlrtRSI = { 244, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo lg_emlrtRSI = { 261, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo mg_emlrtRSI = { 358, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo ng_emlrtRSI = { 371, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo og_emlrtRSI = { 383, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo pg_emlrtRSI = { 394, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo qg_emlrtRSI = { 396, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo rg_emlrtRSI = { 405, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo sg_emlrtRSI = { 345, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo tg_emlrtRSI = { 352, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo ug_emlrtRSI = { 326, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo vg_emlrtRSI = { 336, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo wg_emlrtRSI = { 417, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo xg_emlrtRSI = { 430, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo yg_emlrtRSI = { 436, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRSInfo ah_emlrtRSI = { 19, "eml_xnrm2", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m" };
static emlrtRSInfo ch_emlrtRSI = { 24, "eml_blas_xnrm2", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m" };
static emlrtRSInfo dh_emlrtRSI = { 28, "eml_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m" };
static emlrtRSInfo fh_emlrtRSI = { 20, "eml_blas_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m" };
static emlrtRSInfo gh_emlrtRSI = { 55, "eml_blas_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m" };
static emlrtRSInfo hh_emlrtRSI = { 31, "eml_xdotc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m" };
static emlrtRSInfo ih_emlrtRSI = { 28, "eml_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m" };
static emlrtRSInfo kh_emlrtRSI = { 28, "eml_blas_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m" };
static emlrtRSInfo mh_emlrtRSI = { 42, "eml_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m" };
static emlrtRSInfo oh_emlrtRSI = { 25, "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m" };
static emlrtRSInfo ph_emlrtRSI = { 63, "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m" };
static emlrtRSInfo ji_emlrtRSI = { 28, "eml_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m" };
static emlrtRSInfo ki_emlrtRSI = { 14, "eml_blas_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m" };
static emlrtRSInfo li_emlrtRSI = { 28, "eml_xrot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m" };
static emlrtRSInfo mi_emlrtRSI = { 17, "eml_blas_xrot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m" };
static emlrtRSInfo ni_emlrtRSI = { 26, "eml_xswap", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m" };
static emlrtRSInfo oi_emlrtRSI = { 15, "eml_blas_xswap", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m" };
static emlrtRSInfo pi_emlrtRSI = { 54, "eml_xgemm", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m" };
static emlrtRSInfo ri_emlrtRSI = { 32, "eml_blas_xgemm", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m" };
static emlrtRSInfo si_emlrtRSI = { 103, "eml_blas_xgemm", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m" };
static emlrtMCInfo n_emlrtMCI = { 20, 19, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo o_emlrtMCI = { 20, 5, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo p_emlrtMCI = { 20, 19, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo q_emlrtMCI = { 20, 5, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtRTEInfo q_emlrtRTEI = { 32, 14, "pinv", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/pinv.m" };
static emlrtRTEInfo r_emlrtRTEI = { 40, 6, "pinv", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/pinv.m" };
static emlrtRTEInfo s_emlrtRTEI = { 1, 20, "eml_xgesvd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m" };
static emlrtRTEInfo t_emlrtRTEI = { 447, 1, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRTEInfo u_emlrtRTEI = { 452, 5, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRTEInfo v_emlrtRTEI = { 32, 1, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRTEInfo w_emlrtRTEI = { 33, 1, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRTEInfo x_emlrtRTEI = { 41, 5, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRTEInfo fb_emlrtRTEI = { 1, 18, "eml_xrot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m" };
static emlrtRTEInfo jb_emlrtRTEI = { 32, 14, "pinv", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/pinv.m" };
static emlrtRTEInfo kb_emlrtRTEI = { 1, 20, "eml_xgesvd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m" };
static emlrtRTEInfo lb_emlrtRTEI = { 447, 1, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtRTEInfo mb_emlrtRTEI = { 452, 5, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m" };
static emlrtBCInfo sc_emlrtBCI = { -1, -1, 107, 23, "", "eml_blas_xgemm", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m", 0 };
static emlrtBCInfo tc_emlrtBCI = { -1, -1, 106, 5, "", "eml_blas_xgemm", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m", 0 };
static emlrtBCInfo uc_emlrtBCI = { -1, -1, 105, 24, "", "eml_blas_xgemm", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m", 0 };
static emlrtBCInfo vc_emlrtBCI = { 0, MAX_int32_T, 59, 9, "", "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m", 0 };
static emlrtBCInfo wc_emlrtBCI = { -1, -1, 13, 18, "", "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m", 0 };
static emlrtBCInfo xc_emlrtBCI = { 0, MAX_int32_T, 12, 13, "", "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m", 0 };
static emlrtBCInfo yc_emlrtBCI = { -1, -1, 64, 39, "", "pinv", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/pinv.m", 0 };
static emlrtBCInfo ad_emlrtBCI = { -1, -1, 64, 37, "", "pinv", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/pinv.m", 0 };
static emlrtBCInfo bd_emlrtBCI = { -1, -1, 47, 27, "", "pinv", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/pinv.m", 0 };
static emlrtBCInfo cd_emlrtBCI = { -1, -1, 47, 25, "", "pinv", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/pinv.m", 0 };
static emlrtDCInfo m_emlrtDCI = { 63, 19, "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m", 4 };
static emlrtDCInfo n_emlrtDCI = { 63, 19, "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m", 4 };
static emlrtDCInfo o_emlrtDCI = { 63, 19, "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m", 4 };
static emlrtDCInfo p_emlrtDCI = { 63, 19, "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m", 4 };
static emlrtDCInfo q_emlrtDCI = { 63, 19, "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m", 4 };
static emlrtDCInfo r_emlrtDCI = { 63, 19, "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m", 4 };
static emlrtBCInfo dd_emlrtBCI = { -1, -1, 52, 12, "", "pinv", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/pinv.m", 0 };
static emlrtBCInfo ed_emlrtBCI = { -1, -1, 52, 14, "", "pinv", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/pinv.m", 0 };
static emlrtBCInfo fd_emlrtBCI = { -1, -1, 68, 11, "", "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m", 0 };
static emlrtBCInfo gd_emlrtBCI = { -1, -1, 68, 13, "", "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m", 0 };
static emlrtBCInfo hd_emlrtBCI = { -1, -1, 68, 18, "", "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m", 0 };
static emlrtBCInfo id_emlrtBCI = { -1, -1, 73, 34, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo jd_emlrtBCI = { -1, -1, 73, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo kd_emlrtBCI = { -1, -1, 75, 47, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ld_emlrtBCI = { -1, -1, 77, 25, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo md_emlrtBCI = { -1, -1, 77, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo nd_emlrtBCI = { -1, -1, 79, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo od_emlrtBCI = { -1, -1, 84, 31, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo pd_emlrtBCI = { -1, -1, 88, 36, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo qd_emlrtBCI = { -1, -1, 99, 32, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo rd_emlrtBCI = { -1, -1, 111, 34, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo sd_emlrtBCI = { -1, -1, 132, 46, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo td_emlrtBCI = { -1, -1, 152, 9, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ud_emlrtBCI = { -1, -1, 173, 16, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo vd_emlrtBCI = { -1, -1, 99, 22, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo wd_emlrtBCI = { -1, -1, 178, 36, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo xd_emlrtBCI = { -1, -1, 184, 37, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo yd_emlrtBCI = { -1, -1, 184, 26, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ae_emlrtBCI = { -1, -1, 186, 25, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo be_emlrtBCI = { -1, -1, 186, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ce_emlrtBCI = { -1, -1, 192, 26, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo de_emlrtBCI = { -1, -1, 194, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ee_emlrtBCI = { -1, -1, 223, 22, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo fe_emlrtBCI = { -1, -1, 238, 26, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ge_emlrtBCI = { -1, -1, 241, 42, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo he_emlrtBCI = { -1, -1, 256, 41, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ie_emlrtBCI = { -1, -1, 256, 58, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo je_emlrtBCI = { -1, -1, 279, 30, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ke_emlrtBCI = { -1, -1, 279, 49, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo le_emlrtBCI = { -1, -1, 280, 31, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo me_emlrtBCI = { -1, -1, 298, 44, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ne_emlrtBCI = { -1, -1, 301, 44, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo oe_emlrtBCI = { -1, -1, 303, 34, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo pe_emlrtBCI = { -1, -1, 358, 39, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo qe_emlrtBCI = { -1, -1, 358, 55, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo re_emlrtBCI = { -1, -1, 359, 30, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo se_emlrtBCI = { -1, -1, 360, 30, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo te_emlrtBCI = { -1, -1, 360, 46, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ue_emlrtBCI = { -1, -1, 385, 25, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ve_emlrtBCI = { -1, -1, 387, 33, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo we_emlrtBCI = { -1, -1, 387, 49, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo xe_emlrtBCI = { -1, -1, 388, 31, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ye_emlrtBCI = { -1, -1, 388, 41, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo af_emlrtBCI = { -1, -1, 390, 30, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo bf_emlrtBCI = { -1, -1, 398, 33, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo cf_emlrtBCI = { -1, -1, 398, 49, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo df_emlrtBCI = { -1, -1, 399, 34, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ef_emlrtBCI = { -1, -1, 399, 44, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ff_emlrtBCI = { -1, -1, 400, 35, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo gf_emlrtBCI = { -1, -1, 401, 30, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo hf_emlrtBCI = { -1, -1, 344, 31, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo if_emlrtBCI = { -1, -1, 347, 36, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo jf_emlrtBCI = { -1, -1, 348, 28, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo kf_emlrtBCI = { -1, -1, 325, 31, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo lf_emlrtBCI = { -1, -1, 330, 40, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo mf_emlrtBCI = { -1, -1, 331, 34, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo nf_emlrtBCI = { -1, -1, 331, 25, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo of_emlrtBCI = { -1, -1, 149, 9, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo pf_emlrtBCI = { -1, -1, 149, 28, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo qf_emlrtBCI = { -1, -1, 155, 9, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo rf_emlrtBCI = { -1, -1, 155, 28, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo sf_emlrtBCI = { -1, -1, 157, 5, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo tf_emlrtBCI = { -1, -1, 283, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo uf_emlrtBCI = { -1, -1, 305, 21, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo vf_emlrtBCI = { -1, -1, 412, 25, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo wf_emlrtBCI = { -1, -1, 413, 21, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo xf_emlrtBCI = { -1, -1, 413, 34, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo yf_emlrtBCI = { -1, -1, 422, 41, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ag_emlrtBCI = { -1, -1, 422, 54, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo bg_emlrtBCI = { -1, -1, 423, 31, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo cg_emlrtBCI = { -1, -1, 424, 21, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo dg_emlrtBCI = { -1, -1, 424, 33, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo eg_emlrtBCI = { -1, -1, 425, 21, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo fg_emlrtBCI = { -1, -1, 322, 26, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo gg_emlrtBCI = { -1, -1, 323, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo hg_emlrtBCI = { -1, -1, 327, 21, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ig_emlrtBCI = { -1, -1, 341, 26, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo jg_emlrtBCI = { -1, -1, 342, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo kg_emlrtBCI = { -1, -1, 346, 21, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo lg_emlrtBCI = { -1, -1, 348, 21, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo mg_emlrtBCI = { -1, -1, 361, 35, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ng_emlrtBCI = { -1, -1, 362, 37, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo og_emlrtBCI = { -1, -1, 363, 37, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo pg_emlrtBCI = { -1, -1, 364, 37, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo qg_emlrtBCI = { -1, -1, 365, 37, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo rg_emlrtBCI = { -1, -1, 408, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo sg_emlrtBCI = { -1, -1, 388, 21, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo tg_emlrtBCI = { -1, -1, 389, 35, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ug_emlrtBCI = { -1, -1, 390, 21, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo vg_emlrtBCI = { -1, -1, 397, 21, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo wg_emlrtBCI = { -1, -1, 399, 21, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo xg_emlrtBCI = { -1, -1, 401, 21, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo yg_emlrtBCI = { -1, -1, 222, 12, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ah_emlrtBCI = { -1, -1, 224, 25, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo bh_emlrtBCI = { -1, -1, 225, 13, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ch_emlrtBCI = { -1, -1, 227, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo dh_emlrtBCI = { -1, -1, 227, 32, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo eh_emlrtBCI = { -1, -1, 237, 16, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo fh_emlrtBCI = { -1, -1, 239, 32, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo gh_emlrtBCI = { -1, -1, 240, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo hh_emlrtBCI = { -1, -1, 241, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ih_emlrtBCI = { -1, -1, 201, 31, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo jh_emlrtBCI = { -1, -1, 217, 16, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo kh_emlrtBCI = { -1, -1, 217, 18, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo lh_emlrtBCI = { -1, -1, 215, 20, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo mh_emlrtBCI = { -1, -1, 215, 23, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo nh_emlrtBCI = { -1, -1, 209, 36, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo oh_emlrtBCI = { -1, -1, 165, 22, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ph_emlrtBCI = { -1, -1, 163, 26, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo qh_emlrtBCI = { -1, -1, 76, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo rh_emlrtBCI = { -1, -1, 76, 25, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo sh_emlrtBCI = { -1, -1, 111, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo th_emlrtBCI = { -1, -1, 113, 45, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo uh_emlrtBCI = { -1, -1, 114, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo vh_emlrtBCI = { -1, -1, 114, 26, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo wh_emlrtBCI = { -1, -1, 109, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo xh_emlrtBCI = { -1, -1, 117, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo yh_emlrtBCI = { -1, -1, 117, 25, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ai_emlrtBCI = { -1, -1, 121, 31, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo bi_emlrtBCI = { -1, -1, 141, 24, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ci_emlrtBCI = { -1, -1, 141, 27, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo di_emlrtBCI = { -1, -1, 141, 32, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ei_emlrtBCI = { -1, -1, 132, 40, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo fi_emlrtBCI = { -1, -1, 129, 42, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo gi_emlrtBCI = { -1, -1, 94, 13, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo hi_emlrtBCI = { -1, -1, 94, 26, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtDCInfo s_emlrtDCI = { 452, 41, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 4 };
static emlrtBCInfo ii_emlrtBCI = { -1, -1, 455, 15, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ji_emlrtBCI = { -1, -1, 455, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ki_emlrtBCI = { -1, -1, 455, 25, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo li_emlrtBCI = { -1, -1, 455, 27, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo mi_emlrtBCI = { -1, -1, 449, 5, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ni_emlrtBCI = { -1, -1, 449, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo oi_emlrtBCI = { -1, -1, 51, 16, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo pi_emlrtBCI = { -1, -1, 51, 19, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo qi_emlrtBCI = { -1, -1, 46, 18, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ri_emlrtBCI = { -1, -1, 59, 35, "", "eml_blas_xnrm2", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m", 0 };
static emlrtBCInfo si_emlrtBCI = { -1, -1, 58, 35, "", "eml_blas_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m", 0 };
static emlrtBCInfo ti_emlrtBCI = { -1, -1, 59, 5, "", "eml_blas_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m", 0 };
static emlrtBCInfo ui_emlrtBCI = { -1, -1, 59, 35, "", "eml_blas_xnrm2", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m", 0 };
static emlrtBCInfo vi_emlrtBCI = { -1, -1, 58, 35, "", "eml_blas_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m", 0 };
static emlrtBCInfo wi_emlrtBCI = { -1, -1, 59, 5, "", "eml_blas_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m", 0 };
static emlrtBCInfo xi_emlrtBCI = { -1, -1, 107, 23, "", "eml_blas_xgemm", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m", 0 };
static emlrtBCInfo yi_emlrtBCI = { -1, -1, 106, 5, "", "eml_blas_xgemm", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m", 0 };
static emlrtBCInfo aj_emlrtBCI = { -1, -1, 105, 24, "", "eml_blas_xgemm", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m", 0 };
static emlrtBCInfo bj_emlrtBCI = { 0, MAX_int32_T, 59, 9, "", "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m", 0 };
static emlrtBCInfo cj_emlrtBCI = { -1, -1, 13, 18, "", "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m", 0 };
static emlrtBCInfo dj_emlrtBCI = { 0, MAX_int32_T, 12, 13, "", "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m", 0 };
static emlrtBCInfo ej_emlrtBCI = { -1, -1, 64, 39, "", "pinv", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/pinv.m", 0 };
static emlrtBCInfo fj_emlrtBCI = { -1, -1, 64, 37, "", "pinv", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/pinv.m", 0 };
static emlrtBCInfo gj_emlrtBCI = { -1, -1, 47, 27, "", "pinv", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/pinv.m", 0 };
static emlrtBCInfo hj_emlrtBCI = { -1, -1, 47, 25, "", "pinv", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/pinv.m", 0 };
static emlrtDCInfo t_emlrtDCI = { 63, 19, "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m", 4 };
static emlrtDCInfo u_emlrtDCI = { 63, 19, "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m", 4 };
static emlrtDCInfo v_emlrtDCI = { 63, 19, "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m", 4 };
static emlrtDCInfo w_emlrtDCI = { 63, 19, "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m", 4 };
static emlrtDCInfo x_emlrtDCI = { 63, 19, "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m", 4 };
static emlrtDCInfo y_emlrtDCI = { 63, 19, "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m", 4 };
static emlrtBCInfo ij_emlrtBCI = { -1, -1, 52, 12, "", "pinv", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/pinv.m", 0 };
static emlrtBCInfo jj_emlrtBCI = { -1, -1, 52, 14, "", "pinv", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/pinv.m", 0 };
static emlrtBCInfo kj_emlrtBCI = { -1, -1, 68, 11, "", "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m", 0 };
static emlrtBCInfo lj_emlrtBCI = { -1, -1, 68, 13, "", "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m", 0 };
static emlrtBCInfo mj_emlrtBCI = { -1, -1, 68, 18, "", "svd", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/matfun/svd.m", 0 };
static emlrtBCInfo nj_emlrtBCI = { -1, -1, 73, 34, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo oj_emlrtBCI = { -1, -1, 155, 22, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo pj_emlrtBCI = { 1, 2, 157, 5, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo qj_emlrtBCI = { -1, -1, 188, 23, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo rj_emlrtBCI = { -1, -1, 223, 22, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo sj_emlrtBCI = { -1, -1, 241, 42, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo tj_emlrtBCI = { -1, -1, 241, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo uj_emlrtBCI = { -1, -1, 256, 41, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo vj_emlrtBCI = { -1, -1, 279, 30, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo wj_emlrtBCI = { -1, -1, 279, 49, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo xj_emlrtBCI = { 1, 2, 298, 44, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo yj_emlrtBCI = { -1, -1, 303, 34, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ak_emlrtBCI = { -1, -1, 358, 39, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo bk_emlrtBCI = { -1, -1, 358, 55, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ck_emlrtBCI = { 1, 2, 359, 30, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo dk_emlrtBCI = { -1, -1, 360, 30, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ek_emlrtBCI = { -1, -1, 362, 37, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo fk_emlrtBCI = { -1, -1, 387, 33, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo gk_emlrtBCI = { -1, -1, 388, 41, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo hk_emlrtBCI = { -1, -1, 389, 35, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ik_emlrtBCI = { -1, -1, 390, 30, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo jk_emlrtBCI = { -1, -1, 390, 21, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo kk_emlrtBCI = { -1, -1, 397, 21, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo lk_emlrtBCI = { -1, -1, 398, 49, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo mk_emlrtBCI = { -1, -1, 399, 44, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo nk_emlrtBCI = { -1, -1, 399, 21, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ok_emlrtBCI = { 1, 2, 408, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo pk_emlrtBCI = { -1, -1, 344, 31, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo qk_emlrtBCI = { 1, 2, 322, 26, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo rk_emlrtBCI = { 1, 2, 323, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo sk_emlrtBCI = { -1, -1, 325, 31, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo tk_emlrtBCI = { -1, -1, 327, 21, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo uk_emlrtBCI = { -1, -1, 422, 41, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo vk_emlrtBCI = { -1, -1, 422, 54, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo wk_emlrtBCI = { -1, -1, 423, 31, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo xk_emlrtBCI = { -1, -1, 424, 33, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo yk_emlrtBCI = { -1, -1, 424, 21, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo al_emlrtBCI = { -1, -1, 425, 21, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtDCInfo ab_emlrtDCI = { 32, 22, "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 4 };
static emlrtBCInfo bl_emlrtBCI = { -1, -1, 149, 9, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo cl_emlrtBCI = { -1, -1, 149, 22, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo dl_emlrtBCI = { 1, 2, 149, 28, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo el_emlrtBCI = { -1, -1, 152, 9, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo fl_emlrtBCI = { -1, -1, 305, 21, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo gl_emlrtBCI = { -1, -1, 412, 25, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo hl_emlrtBCI = { -1, -1, 413, 21, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo il_emlrtBCI = { -1, -1, 413, 34, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo jl_emlrtBCI = { 1, 2, 341, 26, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo kl_emlrtBCI = { -1, -1, 346, 21, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ll_emlrtBCI = { -1, -1, 361, 35, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ml_emlrtBCI = { -1, -1, 364, 37, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo nl_emlrtBCI = { -1, -1, 222, 12, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ol_emlrtBCI = { -1, -1, 224, 25, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo pl_emlrtBCI = { -1, -1, 225, 13, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ql_emlrtBCI = { -1, -1, 173, 16, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo rl_emlrtBCI = { -1, -1, 194, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo sl_emlrtBCI = { -1, -1, 192, 23, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo tl_emlrtBCI = { -1, -1, 192, 26, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ul_emlrtBCI = { -1, -1, 186, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo vl_emlrtBCI = { -1, -1, 186, 25, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo wl_emlrtBCI = { -1, -1, 188, 26, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo xl_emlrtBCI = { -1, -1, 184, 23, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo yl_emlrtBCI = { -1, -1, 184, 26, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo am_emlrtBCI = { -1, -1, 184, 34, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo bm_emlrtBCI = { -1, -1, 184, 37, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo cm_emlrtBCI = { -1, -1, 178, 36, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo dm_emlrtBCI = { -1, -1, 165, 19, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo em_emlrtBCI = { -1, -1, 165, 22, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo fm_emlrtBCI = { -1, -1, 163, 23, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo gm_emlrtBCI = { -1, -1, 163, 26, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo hm_emlrtBCI = { -1, -1, 79, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo im_emlrtBCI = { -1, -1, 73, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo jm_emlrtBCI = { -1, -1, 75, 47, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo km_emlrtBCI = { -1, -1, 76, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo lm_emlrtBCI = { -1, -1, 76, 25, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo mm_emlrtBCI = { -1, -1, 77, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo nm_emlrtBCI = { -1, -1, 77, 25, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo om_emlrtBCI = { -1, -1, 99, 19, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo pm_emlrtBCI = { -1, -1, 99, 22, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo qm_emlrtBCI = { -1, -1, 99, 29, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo rm_emlrtBCI = { -1, -1, 84, 31, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo sm_emlrtBCI = { -1, -1, 88, 34, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo tm_emlrtBCI = { -1, -1, 94, 26, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo um_emlrtBCI = { -1, -1, 455, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo vm_emlrtBCI = { -1, -1, 449, 5, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo wm_emlrtBCI = { -1, -1, 449, 17, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo xm_emlrtBCI = { -1, -1, 46, 15, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo ym_emlrtBCI = { -1, -1, 46, 18, "", "eml_matlab_zsvdc", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m", 0 };
static emlrtBCInfo an_emlrtBCI = { -1, -1, 59, 35, "", "eml_blas_xnrm2", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m", 0 };
static emlrtBCInfo bn_emlrtBCI = { -1, -1, 58, 35, "", "eml_blas_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m", 0 };
static emlrtBCInfo cn_emlrtBCI = { -1, -1, 59, 5, "", "eml_blas_xdot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m", 0 };
static emlrtBCInfo ip_emlrtBCI = { -1, -1, 55, 45, "", "eml_blas_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m", 0 };
static emlrtBCInfo jp_emlrtBCI = { -1, -1, 63, 49, "", "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m", 0 };
static emlrtBCInfo kp_emlrtBCI = { -1, -1, 64, 26, "", "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m", 0 };
static emlrtBCInfo lp_emlrtBCI = { -1, -1, 55, 45, "", "eml_blas_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m", 0 };
static emlrtBCInfo mp_emlrtBCI = { 1, 2, 36, 13, "", "eml_refblas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m", 0 };
static emlrtBCInfo np_emlrtBCI = { 1, 2, 37, 17, "", "eml_refblas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m", 0 };
static emlrtBCInfo op_emlrtBCI = { -1, -1, 37, 46, "", "eml_refblas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m", 0 };
static emlrtBCInfo pp_emlrtBCI = { -1, -1, 36, 13, "", "eml_refblas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m", 0 };
static emlrtBCInfo qp_emlrtBCI = { -1, -1, 37, 17, "", "eml_refblas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m", 0 };
static emlrtBCInfo rp_emlrtBCI = { 1, 2, 37, 46, "", "eml_refblas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m", 0 };
static emlrtBCInfo sp_emlrtBCI = { -1, -1, 63, 49, "", "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m", 0 };
static emlrtBCInfo tp_emlrtBCI = { -1, -1, 64, 26, "", "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m", 0 };
static emlrtBCInfo up_emlrtBCI = { -1, -1, 55, 45, "", "eml_blas_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m", 0 };
static emlrtBCInfo vp_emlrtBCI = { -1, -1, 62, 35, "", "eml_blas_xrot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m", 0 };
static emlrtBCInfo wp_emlrtBCI = { -1, -1, 63, 9, "", "eml_blas_xrot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m", 0 };
static emlrtBCInfo xp_emlrtBCI = { -1, -1, 25, 18, "", "eml_refblas_xrot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m", 0 };
static emlrtBCInfo yp_emlrtBCI = { -1, -1, 25, 28, "", "eml_refblas_xrot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m", 0 };
static emlrtBCInfo aq_emlrtBCI = { -1, -1, 26, 19, "", "eml_refblas_xrot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m", 0 };
static emlrtBCInfo bq_emlrtBCI = { -1, -1, 26, 29, "", "eml_refblas_xrot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m", 0 };
static emlrtBCInfo cq_emlrtBCI = { -1, -1, 26, 9, "", "eml_refblas_xrot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m", 0 };
static emlrtBCInfo dq_emlrtBCI = { -1, -1, 31, 5, "", "eml_refblas_xrot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m", 0 };
static emlrtBCInfo eq_emlrtBCI = { -1, -1, 20, 12, "", "eml_refblas_xswap", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m", 0 };
static emlrtBCInfo fq_emlrtBCI = { -1, -1, 22, 9, "", "eml_refblas_xswap", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m", 0 };
static emlrtBCInfo gq_emlrtBCI = { -1, -1, 22, 17, "", "eml_refblas_xswap", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m", 0 };
static emlrtBCInfo hq_emlrtBCI = { -1, -1, 23, 9, "", "eml_refblas_xswap", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m", 0 };
static emlrtBCInfo iq_emlrtBCI = { -1, -1, 20, 12, "", "eml_refblas_xswap", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m", 0 };
static emlrtBCInfo jq_emlrtBCI = { -1, -1, 22, 9, "", "eml_refblas_xswap", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m", 0 };
static emlrtBCInfo kq_emlrtBCI = { -1, -1, 22, 17, "", "eml_refblas_xswap", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m", 0 };
static emlrtBCInfo lq_emlrtBCI = { -1, -1, 23, 9, "", "eml_refblas_xswap", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m", 0 };
static emlrtBCInfo mq_emlrtBCI = { -1, -1, 55, 45, "", "eml_blas_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m", 0 };
static emlrtBCInfo nq_emlrtBCI = { -1, -1, 63, 49, "", "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m", 0 };
static emlrtBCInfo oq_emlrtBCI = { -1, -1, 64, 26, "", "eml_blas_xaxpy", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m", 0 };
static emlrtBCInfo yq_emlrtBCI = { 1, 4, 20, 5, "", "eml_refblas_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m", 0 };
static emlrtBCInfo ar_emlrtBCI = { 1, 4, 20, 15, "", "eml_refblas_xscal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m", 0 };
static emlrtBCInfo br_emlrtBCI = { 1, 4, 25, 18, "", "eml_refblas_xrot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m", 0 };
static emlrtBCInfo cr_emlrtBCI = { 1, 4, 25, 28, "", "eml_refblas_xrot", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m", 0 };
static emlrtBCInfo dr_emlrtBCI = { 1, 4, 20, 12, "", "eml_refblas_xswap", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m", 0 };
static emlrtBCInfo er_emlrtBCI = { 1, 4, 22, 17, "", "eml_refblas_xswap", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m", 0 };

/* Function Declarations */
static void b_eml_error(void);
static void b_eml_xaxpy(int32_T n, real_T a, const emxArray_real_T *x, int32_T ix0, real_T y[2], int32_T iy0);
static real_T b_eml_xdotc(int32_T n, const emxArray_real_T *x, int32_T ix0, const emxArray_real_T *y, int32_T iy0);
static void b_eml_xgesvd(const emxArray_real_T *A, emxArray_real_T *U, emxArray_real_T *S, emxArray_real_T *V);
static real_T b_eml_xnrm2(int32_T n, const emxArray_real_T *x, int32_T ix0);
static void b_eml_xrot(emxArray_real_T *x, int32_T ix0, int32_T iy0, real_T c, real_T s);
static void b_eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0);
static void b_eml_xswap(emxArray_real_T *x, int32_T ix0, int32_T iy0);
static void c_eml_error(void);
static void c_eml_xaxpy(int32_T n, real_T a, const real_T x[2], int32_T ix0, emxArray_real_T *y, int32_T iy0);
static real_T c_eml_xdotc(int32_T n, const emxArray_real_T *x, int32_T ix0, const emxArray_real_T *y, int32_T iy0);
static real_T c_eml_xnrm2(int32_T n, const emxArray_real_T *x, int32_T ix0);
static void c_eml_xrot(real_T x[4], int32_T ix0, int32_T iy0, real_T c, real_T s);
static void c_eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0);
static void c_eml_xswap(real_T x[4], int32_T ix0, int32_T iy0);
static void d_eml_xaxpy(int32_T n, real_T a, int32_T ix0, emxArray_real_T *y, int32_T iy0);
static void d_eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0);
static void e_eml_xaxpy(int32_T n, real_T a, int32_T ix0, emxArray_real_T *y, int32_T iy0);
static void e_eml_xscal(real_T a, real_T x[4], int32_T ix0);
static real_T eml_div(real_T x, real_T y);
static void eml_xaxpy(int32_T n, real_T a, int32_T ix0, emxArray_real_T *y, int32_T iy0);
static real_T eml_xdotc(int32_T n, const emxArray_real_T *x, int32_T ix0, const emxArray_real_T *y, int32_T iy0);
static void eml_xgesvd(const emxArray_real_T *A, emxArray_real_T *U, emxArray_real_T *S, emxArray_real_T *V);
static real_T eml_xnrm2(int32_T n, const emxArray_real_T *x, int32_T ix0);
static void eml_xrot(int32_T n, emxArray_real_T *x, int32_T ix0, int32_T iy0, real_T c, real_T s);
static void eml_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
static void eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0);
static void eml_xswap(int32_T n, emxArray_real_T *x, int32_T ix0, int32_T iy0);

/* Function Definitions */

/*
 * 
 */
static void b_eml_error(void)
{
    const mxArray *y;
    static const int32_T iv19[2] = { 1, 33 };
    const mxArray *m6;
    static const char_T cv10[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'v', 'd', '_', 'm', 'a', 't', 'r', 'i', 'x', 'W', 'i', 't', 'h', 'N', 'a', 'N', 'I', 'n', 'f' };
    EMLRTPUSHRTSTACK(&tb_emlrtRSI);
    y = NULL;
    m6 = mxCreateCharArray(2, iv19);
    emlrtInitCharArray(33, m6, cv10);
    emlrtAssign(&y, m6);
    c_error(message(y, &n_emlrtMCI), &o_emlrtMCI);
    EMLRTPOPRTSTACK(&tb_emlrtRSI);
}

/*
 * 
 */
static void b_eml_xaxpy(int32_T n, real_T a, const emxArray_real_T *x, int32_T ix0, real_T y[2], int32_T iy0)
{
    int32_T ix;
    int32_T iy;
    int32_T k;
    EMLRTPUSHRTSTACK(&xd_emlrtRSI);
    EMLRTPUSHRTSTACK(&yd_emlrtRSI);
    if ((n < 1) || (a == 0.0)) {
    } else {
        ix = ix0;
        iy = iy0;
        for (k = 0; k <= n - 1; k++) {
            y[emlrtBoundsCheck(iy, &mp_emlrtBCI) - 1] = y[emlrtBoundsCheck(iy, &np_emlrtBCI) - 1] + a * x->data[emlrtDynamicBoundsCheck(ix, 1, x->size[1] << 1, &op_emlrtBCI) - 1];
            ix++;
            iy++;
        }
    }
    EMLRTPOPRTSTACK(&yd_emlrtRSI);
    EMLRTPOPRTSTACK(&xd_emlrtRSI);
}

/*
 * 
 */
static real_T b_eml_xdotc(int32_T n, const emxArray_real_T *x, int32_T ix0, const emxArray_real_T *y, int32_T iy0)
{
    real_T d;
    int32_T incx;
    int32_T incy;
    EMLRTPUSHRTSTACK(&ce_emlrtRSI);
    EMLRTPUSHRTSTACK(&de_emlrtRSI);
    if (n < 1) {
        d = 0.0;
    } else {
        EMLRTPUSHRTSTACK(&fe_emlrtRSI);
        incx = 1;
        incy = 1;
        d = ddot32(&n, &x->data[emlrtDynamicBoundsCheck(ix0, 1, x->size[0] * x->size[1], &vi_emlrtBCI) - 1], &incx, &y->data[emlrtDynamicBoundsCheck(iy0, 1, y->size[0] * y->size[1], &wi_emlrtBCI) - 1], &incy);
        EMLRTPOPRTSTACK(&fe_emlrtRSI);
    }
    EMLRTPOPRTSTACK(&de_emlrtRSI);
    EMLRTPOPRTSTACK(&ce_emlrtRSI);
    return d;
}

/*
 * 
 */
static void b_eml_xgesvd(const emxArray_real_T *A, emxArray_real_T *U, emxArray_real_T *S, emxArray_real_T *V)
{
    emxArray_real_T *b_A;
    int32_T i;
    int32_T qs;
    int32_T n;
    int32_T minnp;
    int32_T iv23[2];
    int32_T iv24[2];
    emxArray_real_T *s;
    real_T e[2];
    real_T Vf[4];
    int32_T ii;
    int32_T nct;
    int32_T nctp1;
    int32_T q;
    int32_T qq;
    real_T ztest0;
    int32_T m;
    real_T ztest;
    real_T tiny;
    real_T snorm;
    boolean_T exitg1;
    boolean_T exitg5;
    boolean_T exitg4;
    real_T sn;
    real_T sm;
    real_T varargin_1[5];
    boolean_T exitg2;
    real_T sqds;
    real_T b;
    boolean_T exitg3;
    emlrtHeapReferenceStackEnterFcn();
    emxInit_real_T(&b_A, 2, &kb_emlrtRTEI, TRUE);
    EMLRTPUSHRTSTACK(&uf_emlrtRSI);
    EMLRTPUSHRTSTACK(&vf_emlrtRSI);
    i = b_A->size[0] * b_A->size[1];
    b_A->size[0] = A->size[0];
    b_A->size[1] = 2;
    emxEnsureCapacity((emxArray__common *)b_A, i, (int32_T)sizeof(real_T), &kb_emlrtRTEI);
    qs = A->size[0] * A->size[1] - 1;
    for (i = 0; i <= qs; i++) {
        b_A->data[i] = A->data[i];
    }
    n = A->size[0];
    minnp = muIntScalarMin_sint32(n, 2);
    iv23[0] = muIntScalarMin_sint32(n + 1, 2);
    iv23[1] = 1;
    for (i = 0; i < 2; i++) {
        iv24[i] = (int32_T)emlrtNonNegativeCheckR2009b((real_T)iv23[i], &ab_emlrtDCI);
    }
    b_emxInit_real_T(&s, 1, &v_emlrtRTEI, TRUE);
    i = s->size[0];
    s->size[0] = iv24[0];
    emxEnsureCapacity((emxArray__common *)s, i, (int32_T)sizeof(real_T), &kb_emlrtRTEI);
    qs = iv24[0] - 1;
    for (i = 0; i <= qs; i++) {
        s->data[i] = 0.0;
    }
    for (i = 0; i < 2; i++) {
        e[i] = 0.0;
    }
    iv24[0] = n;
    iv24[1] = minnp;
    i = U->size[0] * U->size[1];
    U->size[0] = iv24[0];
    emxEnsureCapacity((emxArray__common *)U, i, (int32_T)sizeof(real_T), &kb_emlrtRTEI);
    i = U->size[0] * U->size[1];
    U->size[1] = iv24[1];
    emxEnsureCapacity((emxArray__common *)U, i, (int32_T)sizeof(real_T), &kb_emlrtRTEI);
    qs = iv24[0] * iv24[1] - 1;
    for (i = 0; i <= qs; i++) {
        U->data[i] = 0.0;
    }
    for (i = 0; i < 4; i++) {
        Vf[i] = 0.0;
    }
    if (A->size[0] == 0) {
        i = muIntScalarMin_sint32(n, minnp);
        for (ii = 1; ii <= i; ii++) {
            U->data[(emlrtDynamicBoundsCheck(ii, 1, U->size[0], &xm_emlrtBCI) + U->size[0] * (emlrtDynamicBoundsCheck(ii, 1, U->size[1], &ym_emlrtBCI) - 1)) - 1] = 1.0;
        }
        for (ii = 0; ii < 2; ii++) {
            Vf[ii + (ii << 1)] = 1.0;
        }
    } else {
        if (n < 1) {
            qs = 1;
        } else {
            qs = n;
        }
        nct = muIntScalarMin_sint32(qs - 1, 2);
        nctp1 = nct + 1;
        for (q = 1; q <= nct; q++) {
            qq = q + n * (q - 1);
            i = n - q;
            if (q <= nct) {
                EMLRTPUSHRTSTACK(&wf_emlrtRSI);
                ztest0 = c_eml_xnrm2(i + 1, b_A, qq);
                EMLRTPOPRTSTACK(&wf_emlrtRSI);
                if (ztest0 > 0.0) {
                    emlrtDynamicBoundsCheck(qq, 1, b_A->size[0] << 1, &nj_emlrtBCI);
                    if (b_A->data[qq - 1] < 0.0) {
                        ztest0 = -ztest0;
                    }
                    s->data[emlrtDynamicBoundsCheck(q, 1, s->size[0], &im_emlrtBCI) - 1] = ztest0;
                    EMLRTPUSHRTSTACK(&xf_emlrtRSI);
                    d_eml_xscal(i + 1, eml_div(1.0, s->data[emlrtDynamicBoundsCheck(q, 1, s->size[0], &jm_emlrtBCI) - 1]), b_A, qq);
                    EMLRTPOPRTSTACK(&xf_emlrtRSI);
                    b_A->data[emlrtDynamicBoundsCheck(qq, 1, b_A->size[0] << 1, &km_emlrtBCI) - 1] = b_A->data[emlrtDynamicBoundsCheck(qq, 1, b_A->size[0] << 1, &lm_emlrtBCI) - 1] + 1.0;
                    s->data[emlrtDynamicBoundsCheck(q, 1, s->size[0], &mm_emlrtBCI) - 1] = -s->data[emlrtDynamicBoundsCheck(q, 1, s->size[0], &nm_emlrtBCI) - 1];
                } else {
                    s->data[emlrtDynamicBoundsCheck(q, 1, s->size[0], &hm_emlrtBCI) - 1] = 0.0;
                }
            }
            qs = q;
            while (qs + 1 < 3) {
                qs = q + n;
                if ((q <= nct) && (s->data[emlrtDynamicBoundsCheck(q, 1, s->size[0], &rm_emlrtBCI) - 1] != 0.0)) {
                    EMLRTPUSHRTSTACK(&yf_emlrtRSI);
                    ztest0 = c_eml_xdotc(i + 1, b_A, qq, b_A, qs);
                    EMLRTPOPRTSTACK(&yf_emlrtRSI);
                    ztest0 = -eml_div(ztest0, b_A->data[(emlrtDynamicBoundsCheck(q, 1, b_A->size[0], &sm_emlrtBCI) + b_A->size[0] * (q - 1)) - 1]);
                    EMLRTPUSHRTSTACK(&ag_emlrtRSI);
                    e_eml_xaxpy(i + 1, ztest0, qq, b_A, qs);
                    EMLRTPOPRTSTACK(&ag_emlrtRSI);
                }
                e[1] = b_A->data[emlrtDynamicBoundsCheck(qs, 1, b_A->size[0] << 1, &tm_emlrtBCI) - 1];
                qs = 2;
            }
            if (q <= nct) {
                for (ii = q; ii <= n; ii++) {
                    U->data[(emlrtDynamicBoundsCheck(ii, 1, U->size[0], &om_emlrtBCI) + U->size[0] * (emlrtDynamicBoundsCheck(q, 1, U->size[1], &pm_emlrtBCI) - 1)) - 1] = b_A->data[(emlrtDynamicBoundsCheck(ii, 1, b_A->size[0], &qm_emlrtBCI) + b_A->size[0] * (q - 1)) - 1];
                }
            }
        }
        m = muIntScalarMin_sint32(2, n + 1);
        if (nct < 2) {
            s->data[emlrtDynamicBoundsCheck(nctp1, 1, s->size[0], &bl_emlrtBCI) - 1] = b_A->data[(emlrtDynamicBoundsCheck(nctp1, 1, b_A->size[0], &cl_emlrtBCI) + b_A->size[0] * (emlrtBoundsCheck(nctp1, &dl_emlrtBCI) - 1)) - 1];
        }
        if (n < m) {
            s->data[emlrtDynamicBoundsCheck(m, 1, s->size[0], &el_emlrtBCI) - 1] = 0.0;
        }
        if (1 < m) {
            emlrtDynamicBoundsCheck(1, 1, b_A->size[0], &oj_emlrtBCI);
            e[0] = b_A->data[b_A->size[0]];
        }
        e[emlrtBoundsCheck(m, &pj_emlrtBCI) - 1] = 0.0;
        if (nctp1 <= minnp) {
            while (nctp1 <= minnp) {
                for (ii = 1; ii <= n; ii++) {
                    U->data[(emlrtDynamicBoundsCheck(ii, 1, U->size[0], &fm_emlrtBCI) + U->size[0] * (emlrtDynamicBoundsCheck(nctp1, 1, U->size[1], &gm_emlrtBCI) - 1)) - 1] = 0.0;
                }
                U->data[(emlrtDynamicBoundsCheck(nctp1, 1, U->size[0], &dm_emlrtBCI) + U->size[0] * (emlrtDynamicBoundsCheck(nctp1, 1, U->size[1], &em_emlrtBCI) - 1)) - 1] = 1.0;
                nctp1++;
            }
        }
        while (nct > 0) {
            i = (n - nct) + 1;
            qq = nct + n * (nct - 1);
            if (s->data[emlrtDynamicBoundsCheck(nct, 1, s->size[0], &ql_emlrtBCI) - 1] != 0.0) {
                qs = nct + 1;
                while (qs <= minnp) {
                    qs = nct + n;
                    EMLRTPUSHRTSTACK(&fg_emlrtRSI);
                    ztest0 = b_eml_xdotc(i, U, qq, U, qs);
                    EMLRTPOPRTSTACK(&fg_emlrtRSI);
                    ztest0 = -eml_div(ztest0, U->data[emlrtDynamicBoundsCheck(qq, 1, U->size[0] * U->size[1], &cm_emlrtBCI) - 1]);
                    EMLRTPUSHRTSTACK(&gg_emlrtRSI);
                    d_eml_xaxpy(i, ztest0, qq, U, qs);
                    EMLRTPOPRTSTACK(&gg_emlrtRSI);
                    qs = 3;
                }
                for (ii = nct; ii <= n; ii++) {
                    U->data[(emlrtDynamicBoundsCheck(ii, 1, U->size[0], &xl_emlrtBCI) + U->size[0] * (emlrtDynamicBoundsCheck(nct, 1, U->size[1], &yl_emlrtBCI) - 1)) - 1] = -U->data[(emlrtDynamicBoundsCheck(ii, 1, U->size[0], &am_emlrtBCI) + U->size[0] * (emlrtDynamicBoundsCheck(nct, 1, U->size[1], &bm_emlrtBCI) - 1)) - 1];
                }
                U->data[emlrtDynamicBoundsCheck(qq, 1, U->size[0] * U->size[1], &ul_emlrtBCI) - 1] = U->data[emlrtDynamicBoundsCheck(qq, 1, U->size[0] * U->size[1], &vl_emlrtBCI) - 1] + 1.0;
                ii = 1;
                while (ii <= nct - 1) {
                    emlrtDynamicBoundsCheck(1, 1, U->size[0], &qj_emlrtBCI);
                    U->data[U->size[0] * (emlrtDynamicBoundsCheck(nct, 1, U->size[1], &wl_emlrtBCI) - 1)] = 0.0;
                    ii = 2;
                }
            } else {
                for (ii = 1; ii <= n; ii++) {
                    U->data[(emlrtDynamicBoundsCheck(ii, 1, U->size[0], &sl_emlrtBCI) + U->size[0] * (emlrtDynamicBoundsCheck(nct, 1, U->size[1], &tl_emlrtBCI) - 1)) - 1] = 0.0;
                }
                U->data[emlrtDynamicBoundsCheck(qq, 1, U->size[0] * U->size[1], &rl_emlrtBCI) - 1] = 1.0;
            }
            nct--;
        }
        for (q = 1; q > -1; q += -1) {
            for (ii = 0; ii < 2; ii++) {
                Vf[ii + (q << 1)] = 0.0;
            }
            Vf[q + (q << 1)] = 1.0;
        }
        for (q = 1; q <= m; q++) {
            if (s->data[emlrtDynamicBoundsCheck(q, 1, s->size[0], &nl_emlrtBCI) - 1] != 0.0) {
                emlrtDynamicBoundsCheck(q, 1, s->size[0], &rj_emlrtBCI);
                ztest = muDoubleScalarAbs(s->data[q - 1]);
                ztest0 = eml_div(s->data[emlrtDynamicBoundsCheck(q, 1, s->size[0], &ol_emlrtBCI) - 1], ztest);
                s->data[emlrtDynamicBoundsCheck(q, 1, s->size[0], &pl_emlrtBCI) - 1] = ztest;
                if (q < m) {
                    e[0] = eml_div(e[0], ztest0);
                }
                if (q <= n) {
                    EMLRTPUSHRTSTACK(&jg_emlrtRSI);
                    c_eml_xscal(n, ztest0, U, 1 + n * (q - 1));
                    EMLRTPOPRTSTACK(&jg_emlrtRSI);
                }
            }
            if ((q < m) && (e[0] != 0.0)) {
                ztest = muDoubleScalarAbs(e[0]);
                ztest0 = eml_div(ztest, e[0]);
                e[0] = ztest;
                emlrtDynamicBoundsCheck(2, 1, s->size[0], &sj_emlrtBCI);
                emlrtDynamicBoundsCheck(2, 1, s->size[0], &tj_emlrtBCI);
                s->data[1] *= ztest0;
                EMLRTPUSHRTSTACK(&kg_emlrtRSI);
                e_eml_xscal(ztest0, Vf, 3);
                EMLRTPOPRTSTACK(&kg_emlrtRSI);
            }
        }
        nct = m;
        nctp1 = 0;
        tiny = eml_div(2.2250738585072014E-308, 2.2204460492503131E-16);
        snorm = 0.0;
        for (ii = 1; ii <= m; ii++) {
            emlrtDynamicBoundsCheck(ii, 1, s->size[0], &uj_emlrtBCI);
            snorm = muDoubleScalarMax(snorm, muDoubleScalarMax(muDoubleScalarAbs(s->data[ii - 1]), muDoubleScalarAbs(e[ii - 1])));
        }
        exitg1 = 0U;
        while ((exitg1 == 0U) && (m > 0)) {
            if (nctp1 >= 75) {
                EMLRTPUSHRTSTACK(&lg_emlrtRSI);
                c_eml_error();
                EMLRTPOPRTSTACK(&lg_emlrtRSI);
                exitg1 = 1U;
            } else {
                q = m - 1;
                exitg5 = 0U;
                while (!((exitg5 == 1U) || (q == 0))) {
                    emlrtDynamicBoundsCheck(1, 1, s->size[0], &vj_emlrtBCI);
                    emlrtDynamicBoundsCheck(2, 1, s->size[0], &wj_emlrtBCI);
                    ztest0 = muDoubleScalarAbs(e[0]);
                    if ((ztest0 <= 2.2204460492503131E-16 * (muDoubleScalarAbs(s->data[0]) + muDoubleScalarAbs(s->data[1]))) || (ztest0 <= tiny) || ((nctp1 > 20) && (ztest0 <= 2.2204460492503131E-16 * snorm))) {
                        e[0] = 0.0;
                        exitg5 = 1U;
                    } else {
                        q = 0;
                    }
                }
                if (q == m - 1) {
                    i = 4;
                } else {
                    qs = m;
                    ii = m;
                    exitg4 = 0U;
                    while ((exitg4 == 0U) && (ii >= q)) {
                        qs = ii;
                        if (ii == q) {
                            exitg4 = 1U;
                        } else {
                            ztest0 = 0.0;
                            if (ii < m) {
                                emlrtBoundsCheck(ii, &xj_emlrtBCI);
                                ztest0 = muDoubleScalarAbs(e[0]);
                            }
                            if (ii > q + 1) {
                                ztest0 += muDoubleScalarAbs(e[0]);
                            }
                            emlrtDynamicBoundsCheck(ii, 1, s->size[0], &yj_emlrtBCI);
                            ztest = muDoubleScalarAbs(s->data[ii - 1]);
                            if ((ztest <= 2.2204460492503131E-16 * ztest0) || (ztest <= tiny)) {
                                s->data[emlrtDynamicBoundsCheck(ii, 1, s->size[0], &fl_emlrtBCI) - 1] = 0.0;
                                exitg4 = 1U;
                            } else {
                                ii--;
                            }
                        }
                    }
                    if (qs == q) {
                        i = 3;
                    } else if (qs == m) {
                        i = 1;
                    } else {
                        i = 2;
                        q = qs;
                    }
                }
                q++;
                switch (i) {
                  case 1:
                    emlrtBoundsCheck(m - 1, &qk_emlrtBCI);
                    ztest = e[0];
                    emlrtBoundsCheck(m - 1, &rk_emlrtBCI);
                    e[0] = 0.0;
                    i = m - 1;
                    while (i >= q) {
                        emlrtDynamicBoundsCheck(1, 1, s->size[0], &sk_emlrtBCI);
                        EMLRTPUSHRTSTACK(&ug_emlrtRSI);
                        ztest0 = s->data[0];
                        eml_xrotg(&ztest0, &ztest, &sm, &sn);
                        EMLRTPOPRTSTACK(&ug_emlrtRSI);
                        emlrtDynamicBoundsCheck(1, 1, s->size[0], &tk_emlrtBCI);
                        s->data[0] = ztest0;
                        EMLRTPUSHRTSTACK(&vg_emlrtRSI);
                        c_eml_xrot(Vf, 1, 1 + ((m - 1) << 1), sm, sn);
                        EMLRTPOPRTSTACK(&vg_emlrtRSI);
                        i = 0;
                    }
                    break;
                  case 2:
                    qs = q - 2;
                    ztest = e[emlrtBoundsCheck(qs + 1, &jl_emlrtBCI) - 1];
                    e[qs] = 0.0;
                    for (i = q - 1; i + 1 <= m; i++) {
                        emlrtDynamicBoundsCheck(i + 1, 1, s->size[0], &pk_emlrtBCI);
                        EMLRTPUSHRTSTACK(&sg_emlrtRSI);
                        ztest0 = s->data[i];
                        eml_xrotg(&ztest0, &ztest, &sm, &sn);
                        EMLRTPOPRTSTACK(&sg_emlrtRSI);
                        s->data[emlrtDynamicBoundsCheck(i + 1, 1, s->size[0], &kl_emlrtBCI) - 1] = ztest0;
                        ztest = -sn * e[i];
                        e[i] *= sm;
                        EMLRTPUSHRTSTACK(&tg_emlrtRSI);
                        eml_xrot(n, U, 1 + n * i, 1 + n * qs, sm, sn);
                        EMLRTPOPRTSTACK(&tg_emlrtRSI);
                    }
                    break;
                  case 3:
                    i = m - 1;
                    EMLRTPUSHRTSTACK(&mg_emlrtRSI);
                    emlrtDynamicBoundsCheck(m, 1, s->size[0], &ak_emlrtBCI);
                    emlrtDynamicBoundsCheck(i, 1, s->size[0], &bk_emlrtBCI);
                    emlrtBoundsCheck(i, &ck_emlrtBCI);
                    emlrtDynamicBoundsCheck(q, 1, s->size[0], &dk_emlrtBCI);
                    varargin_1[0] = muDoubleScalarAbs(s->data[m - 1]);
                    varargin_1[1] = muDoubleScalarAbs(s->data[0]);
                    varargin_1[2] = muDoubleScalarAbs(e[0]);
                    varargin_1[3] = muDoubleScalarAbs(s->data[q - 1]);
                    varargin_1[4] = muDoubleScalarAbs(e[q - 1]);
                    EMLRTPUSHRTSTACK(&qe_emlrtRSI);
                    EMLRTPUSHRTSTACK(&re_emlrtRSI);
                    EMLRTPUSHRTSTACK(&se_emlrtRSI);
                    i = 1;
                    sn = varargin_1[0];
                    if (muDoubleScalarIsNaN(varargin_1[0])) {
                        qs = 2;
                        exitg2 = 0U;
                        while ((exitg2 == 0U) && (qs < 6)) {
                            i = qs;
                            if (!muDoubleScalarIsNaN(varargin_1[qs - 1])) {
                                sn = varargin_1[qs - 1];
                                exitg2 = 1U;
                            } else {
                                qs++;
                            }
                        }
                    }
                    if (i < 5) {
                        while (i + 1 < 6) {
                            if (varargin_1[i] > sn) {
                                sn = varargin_1[i];
                            }
                            i++;
                        }
                    }
                    EMLRTPOPRTSTACK(&se_emlrtRSI);
                    EMLRTPOPRTSTACK(&re_emlrtRSI);
                    EMLRTPOPRTSTACK(&qe_emlrtRSI);
                    EMLRTPOPRTSTACK(&mg_emlrtRSI);
                    sm = eml_div(s->data[emlrtDynamicBoundsCheck(m, 1, s->size[0], &ll_emlrtBCI) - 1], sn);
                    emlrtDynamicBoundsCheck(1, 1, s->size[0], &ek_emlrtBCI);
                    ztest0 = eml_div(s->data[0], sn);
                    ztest = eml_div(e[0], sn);
                    sqds = eml_div(s->data[emlrtDynamicBoundsCheck(q, 1, s->size[0], &ml_emlrtBCI) - 1], sn);
                    b = eml_div((ztest0 + sm) * (ztest0 - sm) + ztest * ztest, 2.0);
                    ztest0 = sm * ztest;
                    ztest0 *= ztest0;
                    ztest = 0.0;
                    if ((b != 0.0) || (ztest0 != 0.0)) {
                        EMLRTPUSHRTSTACK(&ng_emlrtRSI);
                        ztest = b * b + ztest0;
                        b_sqrt(&ztest);
                        EMLRTPOPRTSTACK(&ng_emlrtRSI);
                        if (b < 0.0) {
                            ztest = -ztest;
                        }
                        ztest = eml_div(ztest0, b + ztest);
                    }
                    ztest += (sqds + sm) * (sqds - sm);
                    ztest0 = sqds * eml_div(e[q - 1], sn);
                    while (q <= 1) {
                        EMLRTPUSHRTSTACK(&og_emlrtRSI);
                        eml_xrotg(&ztest, &ztest0, &sm, &sn);
                        EMLRTPOPRTSTACK(&og_emlrtRSI);
                        emlrtDynamicBoundsCheck(1, 1, s->size[0], &fk_emlrtBCI);
                        ztest0 = sm * s->data[0];
                        ztest = sn * e[0];
                        emlrtDynamicBoundsCheck(1, 1, s->size[0], &gk_emlrtBCI);
                        e[0] = sm * e[0] - sn * s->data[0];
                        emlrtDynamicBoundsCheck(2, 1, s->size[0], &hk_emlrtBCI);
                        b = s->data[1];
                        emlrtDynamicBoundsCheck(2, 1, s->size[0], &ik_emlrtBCI);
                        emlrtDynamicBoundsCheck(2, 1, s->size[0], &jk_emlrtBCI);
                        s->data[1] *= sm;
                        EMLRTPUSHRTSTACK(&pg_emlrtRSI);
                        c_eml_xrot(Vf, 1, 3, sm, sn);
                        EMLRTPOPRTSTACK(&pg_emlrtRSI);
                        EMLRTPUSHRTSTACK(&qg_emlrtRSI);
                        ztest += ztest0;
                        ztest0 = sn * b;
                        eml_xrotg(&ztest, &ztest0, &sm, &sn);
                        EMLRTPOPRTSTACK(&qg_emlrtRSI);
                        emlrtDynamicBoundsCheck(1, 1, s->size[0], &kk_emlrtBCI);
                        s->data[0] = ztest;
                        emlrtDynamicBoundsCheck(2, 1, s->size[0], &lk_emlrtBCI);
                        ztest = sm * e[0] + sn * s->data[1];
                        emlrtDynamicBoundsCheck(2, 1, s->size[0], &mk_emlrtBCI);
                        emlrtDynamicBoundsCheck(2, 1, s->size[0], &nk_emlrtBCI);
                        s->data[1] = -sn * e[0] + sm * s->data[1];
                        ztest0 = sn * e[1];
                        e[1] *= sm;
                        if (1 < n) {
                            EMLRTPUSHRTSTACK(&rg_emlrtRSI);
                            eml_xrot(n, U, 1, 1 + n, sm, sn);
                            EMLRTPOPRTSTACK(&rg_emlrtRSI);
                        }
                        q = 2;
                    }
                    emlrtBoundsCheck(m - 1, &ok_emlrtBCI);
                    e[0] = ztest;
                    nctp1++;
                    break;
                  default:
                    if (s->data[emlrtDynamicBoundsCheck(q, 1, s->size[0], &gl_emlrtBCI) - 1] < 0.0) {
                        s->data[emlrtDynamicBoundsCheck(q, 1, s->size[0], &hl_emlrtBCI) - 1] = -s->data[emlrtDynamicBoundsCheck(q, 1, s->size[0], &il_emlrtBCI) - 1];
                        EMLRTPUSHRTSTACK(&wg_emlrtRSI);
                        e_eml_xscal(-1.0, Vf, 1 + ((q - 1) << 1));
                        EMLRTPOPRTSTACK(&wg_emlrtRSI);
                    }
                    qs = q + 1;
                    exitg3 = 0U;
                    while ((exitg3 == 0U) && (q < nct)) {
                        emlrtDynamicBoundsCheck(1, 1, s->size[0], &uk_emlrtBCI);
                        emlrtDynamicBoundsCheck(qs, 1, s->size[0], &vk_emlrtBCI);
                        if (s->data[0] < s->data[1]) {
                            emlrtDynamicBoundsCheck(1, 1, s->size[0], &wk_emlrtBCI);
                            ztest = s->data[0];
                            emlrtDynamicBoundsCheck(1, 1, s->size[0], &yk_emlrtBCI);
                            emlrtDynamicBoundsCheck(2, 1, s->size[0], &xk_emlrtBCI);
                            s->data[0] = s->data[1];
                            emlrtDynamicBoundsCheck(2, 1, s->size[0], &al_emlrtBCI);
                            s->data[1] = ztest;
                            EMLRTPUSHRTSTACK(&xg_emlrtRSI);
                            c_eml_xswap(Vf, 1, 3);
                            EMLRTPOPRTSTACK(&xg_emlrtRSI);
                            if (1 < n) {
                                EMLRTPUSHRTSTACK(&yg_emlrtRSI);
                                eml_xswap(n, U, 1, 1 + n);
                                EMLRTPOPRTSTACK(&yg_emlrtRSI);
                            }
                            q = 2;
                            qs = 3;
                        } else {
                            exitg3 = 1U;
                        }
                    }
                    nctp1 = 0;
                    m--;
                    break;
                }
            }
        }
    }
    emxFree_real_T(&b_A);
    i = S->size[0];
    S->size[0] = minnp;
    emxEnsureCapacity((emxArray__common *)S, i, (int32_T)sizeof(real_T), &lb_emlrtRTEI);
    for (i = 1; i <= minnp; i++) {
        S->data[emlrtDynamicBoundsCheck(i, 1, S->size[0], &vm_emlrtBCI) - 1] = s->data[emlrtDynamicBoundsCheck(i, 1, s->size[0], &wm_emlrtBCI) - 1];
    }
    emxFree_real_T(&s);
    iv24[0] = 2;
    iv24[1] = minnp;
    i = V->size[0] * V->size[1];
    V->size[0] = 2;
    V->size[1] = iv24[1];
    emxEnsureCapacity((emxArray__common *)V, i, (int32_T)sizeof(real_T), &mb_emlrtRTEI);
    for (qs = 1; qs <= minnp; qs++) {
        for (i = 0; i < 2; i++) {
            V->data[i + V->size[0] * (emlrtDynamicBoundsCheck(qs, 1, V->size[1], &um_emlrtBCI) - 1)] = Vf[i + ((qs - 1) << 1)];
        }
    }
    EMLRTPOPRTSTACK(&vf_emlrtRSI);
    EMLRTPOPRTSTACK(&uf_emlrtRSI);
    emlrtHeapReferenceStackLeaveFcn();
}

/*
 * 
 */
static real_T b_eml_xnrm2(int32_T n, const emxArray_real_T *x, int32_T ix0)
{
    real_T y;
    int32_T incx;
    EMLRTPUSHRTSTACK(&qd_emlrtRSI);
    if (n < 1) {
        y = 0.0;
    } else {
        EMLRTPUSHRTSTACK(&sd_emlrtRSI);
        incx = 1;
        y = dnrm232(&n, &x->data[emlrtDynamicBoundsCheck(ix0, 1, x->size[0], &ui_emlrtBCI) - 1], &incx);
        EMLRTPOPRTSTACK(&sd_emlrtRSI);
    }
    EMLRTPOPRTSTACK(&qd_emlrtRSI);
    return y;
}

/*
 * 
 */
static void b_eml_xrot(emxArray_real_T *x, int32_T ix0, int32_T iy0, real_T c, real_T s)
{
    int32_T ix;
    int32_T iy;
    int32_T k;
    real_T y;
    real_T b_y;
    EMLRTPUSHRTSTACK(&ff_emlrtRSI);
    EMLRTPUSHRTSTACK(&gf_emlrtRSI);
    ix = ix0;
    iy = iy0;
    for (k = 0; k < 2; k++) {
        emlrtDynamicBoundsCheck(ix, 1, x->size[1] << 1, &xp_emlrtBCI);
        y = c * x->data[ix - 1];
        emlrtDynamicBoundsCheck(iy, 1, x->size[1] << 1, &yp_emlrtBCI);
        b_y = s * x->data[iy - 1];
        emlrtDynamicBoundsCheck(iy, 1, x->size[1] << 1, &aq_emlrtBCI);
        emlrtDynamicBoundsCheck(ix, 1, x->size[1] << 1, &bq_emlrtBCI);
        x->data[emlrtDynamicBoundsCheck(iy, 1, x->size[1] << 1, &cq_emlrtBCI) - 1] = c * x->data[iy - 1] - s * x->data[ix - 1];
        x->data[emlrtDynamicBoundsCheck(ix, 1, x->size[1] << 1, &dq_emlrtBCI) - 1] = y + b_y;
        iy++;
        ix++;
    }
    EMLRTPOPRTSTACK(&gf_emlrtRSI);
    EMLRTPOPRTSTACK(&ff_emlrtRSI);
}

/*
 * 
 */
static void b_eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0)
{
    int32_T incx;
    EMLRTPUSHRTSTACK(&td_emlrtRSI);
    if (n < 1) {
    } else {
        EMLRTPUSHRTSTACK(&vd_emlrtRSI);
        incx = 1;
        EMLRTPUSHRTSTACK(&wd_emlrtRSI);
        dscal32(&n, &a, &x->data[emlrtDynamicBoundsCheck(ix0, 1, x->size[0], &lp_emlrtBCI) - 1], &incx);
        EMLRTPOPRTSTACK(&wd_emlrtRSI);
        EMLRTPOPRTSTACK(&vd_emlrtRSI);
    }
    EMLRTPOPRTSTACK(&td_emlrtRSI);
}

/*
 * 
 */
static void b_eml_xswap(emxArray_real_T *x, int32_T ix0, int32_T iy0)
{
    int32_T ix;
    int32_T iy;
    int32_T k;
    real_T temp;
    EMLRTPUSHRTSTACK(&jf_emlrtRSI);
    EMLRTPUSHRTSTACK(&kf_emlrtRSI);
    ix = ix0;
    iy = iy0;
    for (k = 0; k < 2; k++) {
        temp = x->data[emlrtDynamicBoundsCheck(ix, 1, x->size[1] << 1, &iq_emlrtBCI) - 1];
        x->data[emlrtDynamicBoundsCheck(ix, 1, x->size[1] << 1, &jq_emlrtBCI) - 1] = x->data[emlrtDynamicBoundsCheck(iy, 1, x->size[1] << 1, &kq_emlrtBCI) - 1];
        x->data[emlrtDynamicBoundsCheck(iy, 1, x->size[1] << 1, &lq_emlrtBCI) - 1] = temp;
        ix++;
        iy++;
    }
    EMLRTPOPRTSTACK(&kf_emlrtRSI);
    EMLRTPOPRTSTACK(&jf_emlrtRSI);
}

/*
 * 
 */
static void c_eml_error(void)
{
    const mxArray *y;
    static const int32_T iv21[2] = { 1, 30 };
    const mxArray *m7;
    static const char_T cv11[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'v', 'd', '_', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r', 'g', 'e', 'n', 'c', 'e' };
    EMLRTPUSHRTSTACK(&pe_emlrtRSI);
    y = NULL;
    m7 = mxCreateCharArray(2, iv21);
    emlrtInitCharArray(30, m7, cv11);
    emlrtAssign(&y, m7);
    c_error(message(y, &p_emlrtMCI), &q_emlrtMCI);
    EMLRTPOPRTSTACK(&pe_emlrtRSI);
}

/*
 * 
 */
static void c_eml_xaxpy(int32_T n, real_T a, const real_T x[2], int32_T ix0, emxArray_real_T *y, int32_T iy0)
{
    int32_T ix;
    int32_T iy;
    int32_T k;
    EMLRTPUSHRTSTACK(&ae_emlrtRSI);
    EMLRTPUSHRTSTACK(&be_emlrtRSI);
    if ((n < 1) || (a == 0.0)) {
    } else {
        ix = ix0;
        iy = iy0;
        for (k = 0; k <= n - 1; k++) {
            y->data[emlrtDynamicBoundsCheck(iy, 1, y->size[1] << 1, &pp_emlrtBCI) - 1] = y->data[emlrtDynamicBoundsCheck(iy, 1, y->size[1] << 1, &qp_emlrtBCI) - 1] + a * x[emlrtBoundsCheck(ix, &rp_emlrtBCI) - 1];
            ix++;
            iy++;
        }
    }
    EMLRTPOPRTSTACK(&be_emlrtRSI);
    EMLRTPOPRTSTACK(&ae_emlrtRSI);
}

/*
 * 
 */
static real_T c_eml_xdotc(int32_T n, const emxArray_real_T *x, int32_T ix0, const emxArray_real_T *y, int32_T iy0)
{
    real_T d;
    int32_T incx;
    int32_T incy;
    EMLRTPUSHRTSTACK(&hh_emlrtRSI);
    EMLRTPUSHRTSTACK(&ih_emlrtRSI);
    if (n < 1) {
        d = 0.0;
    } else {
        EMLRTPUSHRTSTACK(&kh_emlrtRSI);
        incx = 1;
        incy = 1;
        d = ddot32(&n, &x->data[emlrtDynamicBoundsCheck(ix0, 1, x->size[0] << 1, &bn_emlrtBCI) - 1], &incx, &y->data[emlrtDynamicBoundsCheck(iy0, 1, y->size[0] << 1, &cn_emlrtBCI) - 1], &incy);
        EMLRTPOPRTSTACK(&kh_emlrtRSI);
    }
    EMLRTPOPRTSTACK(&ih_emlrtRSI);
    EMLRTPOPRTSTACK(&hh_emlrtRSI);
    return d;
}

/*
 * 
 */
static real_T c_eml_xnrm2(int32_T n, const emxArray_real_T *x, int32_T ix0)
{
    real_T y;
    int32_T incx;
    EMLRTPUSHRTSTACK(&ah_emlrtRSI);
    if (n < 1) {
        y = 0.0;
    } else {
        EMLRTPUSHRTSTACK(&ch_emlrtRSI);
        incx = 1;
        y = dnrm232(&n, &x->data[emlrtDynamicBoundsCheck(ix0, 1, x->size[0] << 1, &an_emlrtBCI) - 1], &incx);
        EMLRTPOPRTSTACK(&ch_emlrtRSI);
    }
    EMLRTPOPRTSTACK(&ah_emlrtRSI);
    return y;
}

/*
 * 
 */
static void c_eml_xrot(real_T x[4], int32_T ix0, int32_T iy0, real_T c, real_T s)
{
    int32_T ix;
    int32_T iy;
    int32_T k;
    real_T y;
    real_T b_y;
    EMLRTPUSHRTSTACK(&li_emlrtRSI);
    EMLRTPUSHRTSTACK(&mi_emlrtRSI);
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < 2; k++) {
        emlrtBoundsCheck(ix + 1, &br_emlrtBCI);
        y = c * x[ix];
        emlrtBoundsCheck(iy + 1, &cr_emlrtBCI);
        b_y = s * x[iy];
        x[iy] = c * x[iy] - s * x[ix];
        x[ix] = y + b_y;
        iy++;
        ix++;
    }
    EMLRTPOPRTSTACK(&mi_emlrtRSI);
    EMLRTPOPRTSTACK(&li_emlrtRSI);
}

/*
 * 
 */
static void c_eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0)
{
    int32_T incx;
    EMLRTPUSHRTSTACK(&le_emlrtRSI);
    if (n < 1) {
    } else {
        EMLRTPUSHRTSTACK(&ne_emlrtRSI);
        incx = 1;
        EMLRTPUSHRTSTACK(&oe_emlrtRSI);
        dscal32(&n, &a, &x->data[emlrtDynamicBoundsCheck(ix0, 1, x->size[0] * x->size[1], &up_emlrtBCI) - 1], &incx);
        EMLRTPOPRTSTACK(&oe_emlrtRSI);
        EMLRTPOPRTSTACK(&ne_emlrtRSI);
    }
    EMLRTPOPRTSTACK(&le_emlrtRSI);
}

/*
 * 
 */
static void c_eml_xswap(real_T x[4], int32_T ix0, int32_T iy0)
{
    int32_T ix;
    int32_T iy;
    int32_T k;
    real_T temp;
    EMLRTPUSHRTSTACK(&ni_emlrtRSI);
    EMLRTPUSHRTSTACK(&oi_emlrtRSI);
    ix = ix0;
    iy = iy0;
    for (k = 0; k < 2; k++) {
        temp = x[emlrtBoundsCheck(ix, &dr_emlrtBCI) - 1];
        x[ix - 1] = x[emlrtBoundsCheck(iy, &er_emlrtBCI) - 1];
        x[iy - 1] = temp;
        ix++;
        iy++;
    }
    EMLRTPOPRTSTACK(&oi_emlrtRSI);
    EMLRTPOPRTSTACK(&ni_emlrtRSI);
}

/*
 * 
 */
static void d_eml_xaxpy(int32_T n, real_T a, int32_T ix0, emxArray_real_T *y, int32_T iy0)
{
    int32_T incx;
    int32_T incy;
    EMLRTPUSHRTSTACK(&he_emlrtRSI);
    if (n < 1) {
    } else {
        EMLRTPUSHRTSTACK(&je_emlrtRSI);
        incx = 1;
        incy = 1;
        EMLRTPUSHRTSTACK(&ke_emlrtRSI);
        daxpy32(&n, &a, &y->data[emlrtDynamicBoundsCheck(ix0, 1, y->size[0] * y->size[1], &sp_emlrtBCI) - 1], &incx, &y->data[emlrtDynamicBoundsCheck(iy0, 1, y->size[0] * y->size[1], &tp_emlrtBCI) - 1], &incy);
        EMLRTPOPRTSTACK(&ke_emlrtRSI);
        EMLRTPOPRTSTACK(&je_emlrtRSI);
    }
    EMLRTPOPRTSTACK(&he_emlrtRSI);
}

/*
 * 
 */
static void d_eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0)
{
    int32_T incx;
    EMLRTPUSHRTSTACK(&dh_emlrtRSI);
    if (n < 1) {
    } else {
        EMLRTPUSHRTSTACK(&fh_emlrtRSI);
        incx = 1;
        EMLRTPUSHRTSTACK(&gh_emlrtRSI);
        dscal32(&n, &a, &x->data[emlrtDynamicBoundsCheck(ix0, 1, x->size[0] << 1, &mq_emlrtBCI) - 1], &incx);
        EMLRTPOPRTSTACK(&gh_emlrtRSI);
        EMLRTPOPRTSTACK(&fh_emlrtRSI);
    }
    EMLRTPOPRTSTACK(&dh_emlrtRSI);
}

/*
 * 
 */
static void e_eml_xaxpy(int32_T n, real_T a, int32_T ix0, emxArray_real_T *y, int32_T iy0)
{
    int32_T incx;
    int32_T incy;
    EMLRTPUSHRTSTACK(&mh_emlrtRSI);
    if (n < 1) {
    } else {
        EMLRTPUSHRTSTACK(&oh_emlrtRSI);
        incx = 1;
        incy = 1;
        EMLRTPUSHRTSTACK(&ph_emlrtRSI);
        daxpy32(&n, &a, &y->data[emlrtDynamicBoundsCheck(ix0, 1, y->size[0] << 1, &nq_emlrtBCI) - 1], &incx, &y->data[emlrtDynamicBoundsCheck(iy0, 1, y->size[0] << 1, &oq_emlrtBCI) - 1], &incy);
        EMLRTPOPRTSTACK(&ph_emlrtRSI);
        EMLRTPOPRTSTACK(&oh_emlrtRSI);
    }
    EMLRTPOPRTSTACK(&mh_emlrtRSI);
}

/*
 * 
 */
static void e_eml_xscal(real_T a, real_T x[4], int32_T ix0)
{
    int32_T k;
    EMLRTPUSHRTSTACK(&ji_emlrtRSI);
    EMLRTPUSHRTSTACK(&ki_emlrtRSI);
    for (k = ix0; k <= ix0 + 1; k++) {
        x[emlrtBoundsCheck(k, &yq_emlrtBCI) - 1] = a * x[emlrtBoundsCheck(k, &ar_emlrtBCI) - 1];
    }
    EMLRTPOPRTSTACK(&ki_emlrtRSI);
    EMLRTPOPRTSTACK(&ji_emlrtRSI);
}

/*
 * 
 */
static real_T eml_div(real_T x, real_T y)
{
    return x / y;
}

/*
 * 
 */
static void eml_xaxpy(int32_T n, real_T a, int32_T ix0, emxArray_real_T *y, int32_T iy0)
{
    int32_T incx;
    int32_T incy;
    EMLRTPUSHRTSTACK(&md_emlrtRSI);
    if (n < 1) {
    } else {
        EMLRTPUSHRTSTACK(&od_emlrtRSI);
        incx = 1;
        incy = 1;
        EMLRTPUSHRTSTACK(&pd_emlrtRSI);
        daxpy32(&n, &a, &y->data[emlrtDynamicBoundsCheck(ix0, 1, y->size[1] << 1, &jp_emlrtBCI) - 1], &incx, &y->data[emlrtDynamicBoundsCheck(iy0, 1, y->size[1] << 1, &kp_emlrtBCI) - 1], &incy);
        EMLRTPOPRTSTACK(&pd_emlrtRSI);
        EMLRTPOPRTSTACK(&od_emlrtRSI);
    }
    EMLRTPOPRTSTACK(&md_emlrtRSI);
}

/*
 * 
 */
static real_T eml_xdotc(int32_T n, const emxArray_real_T *x, int32_T ix0, const emxArray_real_T *y, int32_T iy0)
{
    real_T d;
    int32_T incx;
    int32_T incy;
    EMLRTPUSHRTSTACK(&hd_emlrtRSI);
    EMLRTPUSHRTSTACK(&id_emlrtRSI);
    if (n < 1) {
        d = 0.0;
    } else {
        EMLRTPUSHRTSTACK(&kd_emlrtRSI);
        incx = 1;
        incy = 1;
        d = ddot32(&n, &x->data[emlrtDynamicBoundsCheck(ix0, 1, x->size[1] << 1, &si_emlrtBCI) - 1], &incx, &y->data[emlrtDynamicBoundsCheck(iy0, 1, y->size[1] << 1, &ti_emlrtBCI) - 1], &incy);
        EMLRTPOPRTSTACK(&kd_emlrtRSI);
    }
    EMLRTPOPRTSTACK(&id_emlrtRSI);
    EMLRTPOPRTSTACK(&hd_emlrtRSI);
    return d;
}

/*
 * 
 */
static void eml_xgesvd(const emxArray_real_T *A, emxArray_real_T *U, emxArray_real_T *S, emxArray_real_T *V)
{
    emxArray_real_T *b_A;
    int32_T mm;
    int32_T i;
    emxArray_real_T *s;
    int32_T p;
    int32_T minnp;
    int32_T iv20[2];
    emxArray_real_T *e;
    real_T work[2];
    emxArray_real_T *Vf;
    int32_T nrt;
    int32_T nct;
    int32_T nctp1;
    int32_T q;
    int32_T qp1;
    int32_T iter;
    int32_T qs;
    real_T ztest0;
    int32_T jj;
    int32_T mm1;
    int32_T m;
    real_T ztest;
    real_T tiny;
    real_T snorm;
    boolean_T exitg1;
    boolean_T exitg4;
    boolean_T exitg3;
    real_T sm;
    real_T emm1;
    real_T varargin_1[5];
    boolean_T exitg2;
    real_T sqds;
    real_T eqds;
    real_T b;
    int32_T b_p[2];
    emlrtHeapReferenceStackEnterFcn();
    emxInit_real_T(&b_A, 2, &s_emlrtRTEI, TRUE);
    EMLRTPUSHRTSTACK(&ub_emlrtRSI);
    EMLRTPUSHRTSTACK(&vb_emlrtRSI);
    mm = b_A->size[0] * b_A->size[1];
    b_A->size[0] = 2;
    b_A->size[1] = A->size[1];
    emxEnsureCapacity((emxArray__common *)b_A, mm, (int32_T)sizeof(real_T), &s_emlrtRTEI);
    i = A->size[0] * A->size[1] - 1;
    for (mm = 0; mm <= i; mm++) {
        b_A->data[mm] = A->data[mm];
    }
    b_emxInit_real_T(&s, 1, &v_emlrtRTEI, TRUE);
    p = A->size[1];
    minnp = muIntScalarMin_sint32(2, p);
    iv20[0] = muIntScalarMin_sint32(3, p);
    iv20[1] = 1;
    mm = s->size[0];
    s->size[0] = iv20[0];
    emxEnsureCapacity((emxArray__common *)s, mm, (int32_T)sizeof(real_T), &s_emlrtRTEI);
    i = iv20[0] - 1;
    for (mm = 0; mm <= i; mm++) {
        s->data[mm] = 0.0;
    }
    b_emxInit_real_T(&e, 1, &w_emlrtRTEI, TRUE);
    iv20[0] = p;
    iv20[1] = 1;
    mm = e->size[0];
    e->size[0] = iv20[0];
    emxEnsureCapacity((emxArray__common *)e, mm, (int32_T)sizeof(real_T), &s_emlrtRTEI);
    i = iv20[0] - 1;
    for (mm = 0; mm <= i; mm++) {
        e->data[mm] = 0.0;
    }
    for (i = 0; i < 2; i++) {
        work[i] = 0.0;
    }
    iv20[0] = 2;
    iv20[1] = minnp;
    mm = U->size[0] * U->size[1];
    U->size[0] = 2;
    emxEnsureCapacity((emxArray__common *)U, mm, (int32_T)sizeof(real_T), &s_emlrtRTEI);
    mm = U->size[0] * U->size[1];
    U->size[1] = iv20[1];
    emxEnsureCapacity((emxArray__common *)U, mm, (int32_T)sizeof(real_T), &s_emlrtRTEI);
    i = (iv20[1] << 1) - 1;
    for (mm = 0; mm <= i; mm++) {
        U->data[mm] = 0.0;
    }
    emxInit_real_T(&Vf, 2, &x_emlrtRTEI, TRUE);
    iv20[0] = p;
    iv20[1] = p;
    mm = Vf->size[0] * Vf->size[1];
    Vf->size[0] = iv20[0];
    emxEnsureCapacity((emxArray__common *)Vf, mm, (int32_T)sizeof(real_T), &s_emlrtRTEI);
    mm = Vf->size[0] * Vf->size[1];
    Vf->size[1] = iv20[1];
    emxEnsureCapacity((emxArray__common *)Vf, mm, (int32_T)sizeof(real_T), &s_emlrtRTEI);
    i = iv20[0] * iv20[1] - 1;
    for (mm = 0; mm <= i; mm++) {
        Vf->data[mm] = 0.0;
    }
    if (A->size[1] == 0) {
        mm = muIntScalarMin_sint32(2, minnp);
        for (i = 1; i <= mm; i++) {
            U->data[(i + U->size[0] * (emlrtDynamicBoundsCheck(i, 1, U->size[1], &qi_emlrtBCI) - 1)) - 1] = 1.0;
        }
        mm = muIntScalarMin_sint32(p, p);
        for (i = 1; i <= mm; i++) {
            Vf->data[(emlrtDynamicBoundsCheck(i, 1, Vf->size[0], &oi_emlrtBCI) + Vf->size[0] * (emlrtDynamicBoundsCheck(i, 1, Vf->size[1], &pi_emlrtBCI) - 1)) - 1] = 1.0;
        }
    } else {
        if (p < 2) {
            i = 2;
        } else {
            i = p;
        }
        nrt = muIntScalarMin_sint32(i - 2, 2);
        nct = muIntScalarMin_sint32(1, p);
        nctp1 = nct + 1;
        mm = muIntScalarMax_sint32(nct, nrt);
        for (q = 1; q <= mm; q++) {
            qp1 = q + 1;
            i = q + ((q - 1) << 1);
            iter = 2 - q;
            qs = iter + 1;
            if (q <= nct) {
                EMLRTPUSHRTSTACK(&wb_emlrtRSI);
                ztest0 = eml_xnrm2(qs, b_A, i);
                EMLRTPOPRTSTACK(&wb_emlrtRSI);
                if (ztest0 > 0.0) {
                    emlrtDynamicBoundsCheck(i, 1, b_A->size[1] << 1, &id_emlrtBCI);
                    if (b_A->data[i - 1] < 0.0) {
                        ztest0 = -ztest0;
                    }
                    emlrtDynamicBoundsCheck(1, 1, s->size[0], &jd_emlrtBCI);
                    s->data[0] = ztest0;
                    EMLRTPUSHRTSTACK(&xb_emlrtRSI);
                    emlrtDynamicBoundsCheck(1, 1, s->size[0], &kd_emlrtBCI);
                    eml_xscal(qs, eml_div(1.0, s->data[0]), b_A, i);
                    EMLRTPOPRTSTACK(&xb_emlrtRSI);
                    b_A->data[emlrtDynamicBoundsCheck(i, 1, b_A->size[1] << 1, &qh_emlrtBCI) - 1] = b_A->data[emlrtDynamicBoundsCheck(i, 1, b_A->size[1] << 1, &rh_emlrtBCI) - 1] + 1.0;
                    emlrtDynamicBoundsCheck(1, 1, s->size[0], &md_emlrtBCI);
                    emlrtDynamicBoundsCheck(1, 1, s->size[0], &ld_emlrtBCI);
                    s->data[0] = -s->data[0];
                } else {
                    emlrtDynamicBoundsCheck(1, 1, s->size[0], &nd_emlrtBCI);
                    s->data[0] = 0.0;
                }
            }
            for (jj = qp1; jj <= p; jj++) {
                mm1 = q + ((jj - 1) << 1);
                if (q <= nct) {
                    emlrtDynamicBoundsCheck(1, 1, s->size[0], &od_emlrtBCI);
                    if (s->data[0] != 0.0) {
                        EMLRTPUSHRTSTACK(&yb_emlrtRSI);
                        ztest0 = eml_xdotc(qs, b_A, i, b_A, mm1);
                        EMLRTPOPRTSTACK(&yb_emlrtRSI);
                        emlrtDynamicBoundsCheck(1, 1, b_A->size[1], &pd_emlrtBCI);
                        ztest0 = -eml_div(ztest0, b_A->data[0]);
                        EMLRTPUSHRTSTACK(&ac_emlrtRSI);
                        eml_xaxpy(qs, ztest0, i, b_A, mm1);
                        EMLRTPOPRTSTACK(&ac_emlrtRSI);
                    }
                }
                e->data[emlrtDynamicBoundsCheck(jj, 1, e->size[0], &gi_emlrtBCI) - 1] = b_A->data[emlrtDynamicBoundsCheck(mm1, 1, b_A->size[1] << 1, &hi_emlrtBCI) - 1];
            }
            if (q <= nct) {
                for (i = 0; i + 1 < 3; i++) {
                    emlrtDynamicBoundsCheck(1, 1, U->size[1], &vd_emlrtBCI);
                    emlrtDynamicBoundsCheck(1, 1, b_A->size[1], &qd_emlrtBCI);
                    U->data[i] = b_A->data[i];
                }
            }
            if (q <= nrt) {
                mm1 = p - q;
                EMLRTPUSHRTSTACK(&bc_emlrtRSI);
                ztest0 = b_eml_xnrm2(mm1, e, qp1);
                EMLRTPOPRTSTACK(&bc_emlrtRSI);
                if (ztest0 == 0.0) {
                    e->data[emlrtDynamicBoundsCheck(q, 1, e->size[0], &wh_emlrtBCI) - 1] = 0.0;
                } else {
                    emlrtDynamicBoundsCheck(qp1, 1, e->size[0], &rd_emlrtBCI);
                    if (e->data[qp1 - 1] < 0.0) {
                        ztest0 = -ztest0;
                    }
                    e->data[emlrtDynamicBoundsCheck(q, 1, e->size[0], &sh_emlrtBCI) - 1] = ztest0;
                    EMLRTPUSHRTSTACK(&cc_emlrtRSI);
                    ztest0 = eml_div(1.0, e->data[emlrtDynamicBoundsCheck(q, 1, e->size[0], &th_emlrtBCI) - 1]);
                    b_eml_xscal(mm1, ztest0, e, qp1);
                    EMLRTPOPRTSTACK(&cc_emlrtRSI);
                    e->data[emlrtDynamicBoundsCheck(qp1, 1, e->size[0], &uh_emlrtBCI) - 1] = e->data[emlrtDynamicBoundsCheck(qp1, 1, e->size[0], &vh_emlrtBCI) - 1] + 1.0;
                }
                e->data[emlrtDynamicBoundsCheck(q, 1, e->size[0], &xh_emlrtBCI) - 1] = -e->data[emlrtDynamicBoundsCheck(q, 1, e->size[0], &yh_emlrtBCI) - 1];
                if ((qp1 <= 2) && (e->data[emlrtDynamicBoundsCheck(q, 1, e->size[0], &ai_emlrtBCI) - 1] != 0.0)) {
                    work[1] = 0.0;
                    for (jj = 2; jj <= p; jj++) {
                        EMLRTPUSHRTSTACK(&dc_emlrtRSI);
                        b_eml_xaxpy(iter, e->data[emlrtDynamicBoundsCheck(jj, 1, e->size[0], &fi_emlrtBCI) - 1], b_A, 2 + ((jj - 1) << 1), work, 2);
                        EMLRTPOPRTSTACK(&dc_emlrtRSI);
                    }
                    for (jj = 2; jj <= p; jj++) {
                        emlrtDynamicBoundsCheck(2, 1, e->size[0], &sd_emlrtBCI);
                        ztest0 = eml_div(-e->data[emlrtDynamicBoundsCheck(jj, 1, e->size[0], &ei_emlrtBCI) - 1], e->data[1]);
                        EMLRTPUSHRTSTACK(&ec_emlrtRSI);
                        c_eml_xaxpy(iter, ztest0, work, 2, b_A, 2 + ((jj - 1) << 1));
                        EMLRTPOPRTSTACK(&ec_emlrtRSI);
                    }
                }
                while (qp1 <= p) {
                    Vf->data[(emlrtDynamicBoundsCheck(qp1, 1, Vf->size[0], &bi_emlrtBCI) + Vf->size[0] * (emlrtDynamicBoundsCheck(q, 1, Vf->size[1], &ci_emlrtBCI) - 1)) - 1] = e->data[emlrtDynamicBoundsCheck(qp1, 1, e->size[0], &di_emlrtBCI) - 1];
                    qp1++;
                }
            }
        }
        m = muIntScalarMin_sint32(p, 3);
        if (nct < p) {
            s->data[emlrtDynamicBoundsCheck(nctp1, 1, s->size[0], &of_emlrtBCI) - 1] = b_A->data[(nctp1 + b_A->size[0] * (emlrtDynamicBoundsCheck(nctp1, 1, b_A->size[1], &pf_emlrtBCI) - 1)) - 1];
        }
        if (2 < m) {
            emlrtDynamicBoundsCheck(3, 1, s->size[0], &td_emlrtBCI);
            s->data[2] = 0.0;
        }
        if (nrt + 1 < m) {
            e->data[emlrtDynamicBoundsCheck(nrt + 1, 1, e->size[0], &qf_emlrtBCI) - 1] = b_A->data[nrt + b_A->size[0] * (emlrtDynamicBoundsCheck(m, 1, b_A->size[1], &rf_emlrtBCI) - 1)];
        }
        e->data[emlrtDynamicBoundsCheck(m, 1, e->size[0], &sf_emlrtBCI) - 1] = 0.0;
        if (nctp1 <= minnp) {
            while (nctp1 <= minnp) {
                for (i = 0; i < 2; i++) {
                    U->data[i + U->size[0] * (emlrtDynamicBoundsCheck(nctp1, 1, U->size[1], &ph_emlrtBCI) - 1)] = 0.0;
                }
                U->data[(nctp1 + U->size[0] * (emlrtDynamicBoundsCheck(nctp1, 1, U->size[1], &oh_emlrtBCI) - 1)) - 1] = 1.0;
                nctp1++;
            }
        }
        while (nct > 0) {
            emlrtDynamicBoundsCheck(1, 1, s->size[0], &ud_emlrtBCI);
            if (s->data[0] != 0.0) {
                jj = 2;
                while (jj <= minnp) {
                    EMLRTPUSHRTSTACK(&fc_emlrtRSI);
                    ztest0 = eml_xdotc(2, U, 1, U, 3);
                    EMLRTPOPRTSTACK(&fc_emlrtRSI);
                    emlrtDynamicBoundsCheck(1, 1, U->size[1] << 1, &wd_emlrtBCI);
                    ztest0 = -eml_div(ztest0, U->data[0]);
                    EMLRTPUSHRTSTACK(&gc_emlrtRSI);
                    eml_xaxpy(2, ztest0, 1, U, 3);
                    EMLRTPOPRTSTACK(&gc_emlrtRSI);
                    jj = 3;
                }
                for (i = 0; i + 1 < 3; i++) {
                    emlrtDynamicBoundsCheck(1, 1, U->size[1], &yd_emlrtBCI);
                    emlrtDynamicBoundsCheck(1, 1, U->size[1], &xd_emlrtBCI);
                    U->data[i] = -U->data[i];
                }
                emlrtDynamicBoundsCheck(1, 1, U->size[1] << 1, &be_emlrtBCI);
                emlrtDynamicBoundsCheck(1, 1, U->size[1] << 1, &ae_emlrtBCI);
                U->data[0]++;
            } else {
                for (i = 0; i < 2; i++) {
                    emlrtDynamicBoundsCheck(1, 1, U->size[1], &ce_emlrtBCI);
                    U->data[i] = 0.0;
                }
                emlrtDynamicBoundsCheck(1, 1, U->size[1] << 1, &de_emlrtBCI);
                U->data[0] = 1.0;
            }
            nct = 0;
        }
        for (q = p; q > 0; q--) {
            if ((q <= nrt) && (e->data[emlrtDynamicBoundsCheck(q, 1, e->size[0], &ih_emlrtBCI) - 1] != 0.0)) {
                qp1 = q + 1;
                mm1 = p - q;
                i = qp1 + p * (q - 1);
                for (jj = qp1; jj <= p; jj++) {
                    qs = qp1 + p * (jj - 1);
                    EMLRTPUSHRTSTACK(&hc_emlrtRSI);
                    ztest0 = b_eml_xdotc(mm1, Vf, i, Vf, qs);
                    EMLRTPOPRTSTACK(&hc_emlrtRSI);
                    ztest0 = -eml_div(ztest0, Vf->data[emlrtDynamicBoundsCheck(i, 1, Vf->size[0] * Vf->size[1], &nh_emlrtBCI) - 1]);
                    EMLRTPUSHRTSTACK(&ic_emlrtRSI);
                    d_eml_xaxpy(mm1, ztest0, i, Vf, qs);
                    EMLRTPOPRTSTACK(&ic_emlrtRSI);
                }
            }
            for (i = 1; i <= p; i++) {
                Vf->data[(emlrtDynamicBoundsCheck(i, 1, Vf->size[0], &lh_emlrtBCI) + Vf->size[0] * (emlrtDynamicBoundsCheck(q, 1, Vf->size[1], &mh_emlrtBCI) - 1)) - 1] = 0.0;
            }
            Vf->data[(emlrtDynamicBoundsCheck(q, 1, Vf->size[0], &jh_emlrtBCI) + Vf->size[0] * (emlrtDynamicBoundsCheck(q, 1, Vf->size[1], &kh_emlrtBCI) - 1)) - 1] = 1.0;
        }
        for (q = 1; q <= m; q++) {
            if (s->data[emlrtDynamicBoundsCheck(q, 1, s->size[0], &yg_emlrtBCI) - 1] != 0.0) {
                emlrtDynamicBoundsCheck(q, 1, s->size[0], &ee_emlrtBCI);
                ztest = muDoubleScalarAbs(s->data[q - 1]);
                ztest0 = eml_div(s->data[emlrtDynamicBoundsCheck(q, 1, s->size[0], &ah_emlrtBCI) - 1], ztest);
                s->data[emlrtDynamicBoundsCheck(q, 1, s->size[0], &bh_emlrtBCI) - 1] = ztest;
                if (q < m) {
                    e->data[emlrtDynamicBoundsCheck(q, 1, e->size[0], &ch_emlrtBCI) - 1] = eml_div(e->data[emlrtDynamicBoundsCheck(q, 1, e->size[0], &dh_emlrtBCI) - 1], ztest0);
                }
                if (q <= 2) {
                    EMLRTPUSHRTSTACK(&jc_emlrtRSI);
                    eml_xscal(2, ztest0, U, 1 + ((q - 1) << 1));
                    EMLRTPOPRTSTACK(&jc_emlrtRSI);
                }
            }
            if ((q < m) && (e->data[emlrtDynamicBoundsCheck(q, 1, e->size[0], &eh_emlrtBCI) - 1] != 0.0)) {
                emlrtDynamicBoundsCheck(q, 1, e->size[0], &fe_emlrtBCI);
                ztest = muDoubleScalarAbs(e->data[q - 1]);
                ztest0 = eml_div(ztest, e->data[emlrtDynamicBoundsCheck(q, 1, e->size[0], &fh_emlrtBCI) - 1]);
                e->data[emlrtDynamicBoundsCheck(q, 1, e->size[0], &gh_emlrtBCI) - 1] = ztest;
                emlrtDynamicBoundsCheck(q + 1, 1, s->size[0], &ge_emlrtBCI);
                s->data[emlrtDynamicBoundsCheck(q + 1, 1, s->size[0], &hh_emlrtBCI) - 1] = s->data[q] * ztest0;
                EMLRTPUSHRTSTACK(&kc_emlrtRSI);
                c_eml_xscal(p, ztest0, Vf, 1 + p * q);
                EMLRTPOPRTSTACK(&kc_emlrtRSI);
            }
        }
        mm = m;
        iter = 0;
        tiny = eml_div(2.2250738585072014E-308, 2.2204460492503131E-16);
        snorm = 0.0;
        for (i = 1; i <= m; i++) {
            emlrtDynamicBoundsCheck(i, 1, s->size[0], &he_emlrtBCI);
            emlrtDynamicBoundsCheck(i, 1, e->size[0], &ie_emlrtBCI);
            snorm = muDoubleScalarMax(snorm, muDoubleScalarMax(muDoubleScalarAbs(s->data[i - 1]), muDoubleScalarAbs(e->data[i - 1])));
        }
        exitg1 = 0U;
        while ((exitg1 == 0U) && (m > 0)) {
            if (iter >= 75) {
                EMLRTPUSHRTSTACK(&lc_emlrtRSI);
                c_eml_error();
                EMLRTPOPRTSTACK(&lc_emlrtRSI);
                exitg1 = 1U;
            } else {
                q = m - 1;
                exitg4 = 0U;
                while (!((exitg4 == 1U) || (q == 0))) {
                    emlrtDynamicBoundsCheck(q, 1, s->size[0], &je_emlrtBCI);
                    emlrtDynamicBoundsCheck(q + 1, 1, s->size[0], &ke_emlrtBCI);
                    emlrtDynamicBoundsCheck(q, 1, e->size[0], &le_emlrtBCI);
                    ztest0 = muDoubleScalarAbs(e->data[q - 1]);
                    if ((ztest0 <= 2.2204460492503131E-16 * (muDoubleScalarAbs(s->data[q - 1]) + muDoubleScalarAbs(s->data[q]))) || (ztest0 <= tiny) || ((iter > 20) && (ztest0 <= 2.2204460492503131E-16 * snorm))) {
                        e->data[emlrtDynamicBoundsCheck(q, 1, e->size[0], &tf_emlrtBCI) - 1] = 0.0;
                        exitg4 = 1U;
                    } else {
                        q--;
                    }
                }
                if (q == m - 1) {
                    i = 4;
                } else {
                    qs = m;
                    i = m;
                    exitg3 = 0U;
                    while ((exitg3 == 0U) && (i >= q)) {
                        qs = i;
                        if (i == q) {
                            exitg3 = 1U;
                        } else {
                            ztest0 = 0.0;
                            if (i < m) {
                                emlrtDynamicBoundsCheck(i, 1, e->size[0], &me_emlrtBCI);
                                ztest0 = muDoubleScalarAbs(e->data[i - 1]);
                            }
                            if (i > q + 1) {
                                emlrtDynamicBoundsCheck(i - 1, 1, e->size[0], &ne_emlrtBCI);
                                ztest0 += muDoubleScalarAbs(e->data[i - 2]);
                            }
                            emlrtDynamicBoundsCheck(i, 1, s->size[0], &oe_emlrtBCI);
                            ztest = muDoubleScalarAbs(s->data[i - 1]);
                            if ((ztest <= 2.2204460492503131E-16 * ztest0) || (ztest <= tiny)) {
                                s->data[emlrtDynamicBoundsCheck(i, 1, s->size[0], &uf_emlrtBCI) - 1] = 0.0;
                                exitg3 = 1U;
                            } else {
                                i--;
                            }
                        }
                    }
                    if (qs == q) {
                        i = 3;
                    } else if (qs == m) {
                        i = 1;
                    } else {
                        i = 2;
                        q = qs;
                    }
                }
                q++;
                switch (i) {
                  case 1:
                    ztest = e->data[emlrtDynamicBoundsCheck(m - 1, 1, e->size[0], &fg_emlrtBCI) - 1];
                    e->data[emlrtDynamicBoundsCheck(m - 1, 1, e->size[0], &gg_emlrtBCI) - 1] = 0.0;
                    for (i = m - 1; i >= q; i--) {
                        emlrtDynamicBoundsCheck(i, 1, s->size[0], &kf_emlrtBCI);
                        EMLRTPUSHRTSTACK(&uc_emlrtRSI);
                        ztest0 = s->data[i - 1];
                        eml_xrotg(&ztest0, &ztest, &emm1, &sm);
                        EMLRTPOPRTSTACK(&uc_emlrtRSI);
                        s->data[emlrtDynamicBoundsCheck(i, 1, s->size[0], &hg_emlrtBCI) - 1] = ztest0;
                        if (i > q) {
                            emlrtDynamicBoundsCheck(1, 1, e->size[0], &lf_emlrtBCI);
                            ztest = -sm * e->data[0];
                            emlrtDynamicBoundsCheck(1, 1, e->size[0], &mf_emlrtBCI);
                            emlrtDynamicBoundsCheck(1, 1, e->size[0], &nf_emlrtBCI);
                            e->data[0] *= emm1;
                        }
                        EMLRTPUSHRTSTACK(&vc_emlrtRSI);
                        eml_xrot(p, Vf, 1 + p * (i - 1), 1 + p * (m - 1), emm1, sm);
                        EMLRTPOPRTSTACK(&vc_emlrtRSI);
                    }
                    break;
                  case 2:
                    i = q - 1;
                    ztest = e->data[emlrtDynamicBoundsCheck(i, 1, e->size[0], &ig_emlrtBCI) - 1];
                    e->data[emlrtDynamicBoundsCheck(i, 1, e->size[0], &jg_emlrtBCI) - 1] = 0.0;
                    while (q <= m) {
                        emlrtDynamicBoundsCheck(q, 1, s->size[0], &hf_emlrtBCI);
                        EMLRTPUSHRTSTACK(&sc_emlrtRSI);
                        ztest0 = s->data[q - 1];
                        eml_xrotg(&ztest0, &ztest, &emm1, &sm);
                        EMLRTPOPRTSTACK(&sc_emlrtRSI);
                        s->data[emlrtDynamicBoundsCheck(q, 1, s->size[0], &kg_emlrtBCI) - 1] = ztest0;
                        emlrtDynamicBoundsCheck(q, 1, e->size[0], &if_emlrtBCI);
                        ztest = -sm * e->data[q - 1];
                        emlrtDynamicBoundsCheck(q, 1, e->size[0], &jf_emlrtBCI);
                        e->data[emlrtDynamicBoundsCheck(q, 1, e->size[0], &lg_emlrtBCI) - 1] = e->data[q - 1] * emm1;
                        EMLRTPUSHRTSTACK(&tc_emlrtRSI);
                        b_eml_xrot(U, 1 + ((q - 1) << 1), 1 + ((i - 1) << 1), emm1, sm);
                        EMLRTPOPRTSTACK(&tc_emlrtRSI);
                        q++;
                    }
                    break;
                  case 3:
                    mm1 = m - 1;
                    EMLRTPUSHRTSTACK(&mc_emlrtRSI);
                    emlrtDynamicBoundsCheck(m, 1, s->size[0], &pe_emlrtBCI);
                    emlrtDynamicBoundsCheck(mm1, 1, s->size[0], &qe_emlrtBCI);
                    emlrtDynamicBoundsCheck(mm1, 1, e->size[0], &re_emlrtBCI);
                    emlrtDynamicBoundsCheck(q, 1, s->size[0], &se_emlrtBCI);
                    emlrtDynamicBoundsCheck(q, 1, e->size[0], &te_emlrtBCI);
                    varargin_1[0] = muDoubleScalarAbs(s->data[m - 1]);
                    varargin_1[1] = muDoubleScalarAbs(s->data[mm1 - 1]);
                    varargin_1[2] = muDoubleScalarAbs(e->data[mm1 - 1]);
                    varargin_1[3] = muDoubleScalarAbs(s->data[q - 1]);
                    varargin_1[4] = muDoubleScalarAbs(e->data[q - 1]);
                    EMLRTPUSHRTSTACK(&qe_emlrtRSI);
                    EMLRTPUSHRTSTACK(&re_emlrtRSI);
                    EMLRTPUSHRTSTACK(&se_emlrtRSI);
                    i = 1;
                    ztest0 = varargin_1[0];
                    if (muDoubleScalarIsNaN(varargin_1[0])) {
                        qs = 2;
                        exitg2 = 0U;
                        while ((exitg2 == 0U) && (qs < 6)) {
                            i = qs;
                            if (!muDoubleScalarIsNaN(varargin_1[qs - 1])) {
                                ztest0 = varargin_1[qs - 1];
                                exitg2 = 1U;
                            } else {
                                qs++;
                            }
                        }
                    }
                    if (i < 5) {
                        while (i + 1 < 6) {
                            if (varargin_1[i] > ztest0) {
                                ztest0 = varargin_1[i];
                            }
                            i++;
                        }
                    }
                    EMLRTPOPRTSTACK(&se_emlrtRSI);
                    EMLRTPOPRTSTACK(&re_emlrtRSI);
                    EMLRTPOPRTSTACK(&qe_emlrtRSI);
                    EMLRTPOPRTSTACK(&mc_emlrtRSI);
                    sm = eml_div(s->data[emlrtDynamicBoundsCheck(m, 1, s->size[0], &mg_emlrtBCI) - 1], ztest0);
                    ztest = eml_div(s->data[emlrtDynamicBoundsCheck(mm1, 1, s->size[0], &ng_emlrtBCI) - 1], ztest0);
                    emm1 = eml_div(e->data[emlrtDynamicBoundsCheck(mm1, 1, e->size[0], &og_emlrtBCI) - 1], ztest0);
                    sqds = eml_div(s->data[emlrtDynamicBoundsCheck(q, 1, s->size[0], &pg_emlrtBCI) - 1], ztest0);
                    eqds = eml_div(e->data[emlrtDynamicBoundsCheck(q, 1, e->size[0], &qg_emlrtBCI) - 1], ztest0);
                    b = eml_div((ztest + sm) * (ztest - sm) + emm1 * emm1, 2.0);
                    ztest0 = sm * emm1;
                    ztest0 *= ztest0;
                    ztest = 0.0;
                    if ((b != 0.0) || (ztest0 != 0.0)) {
                        EMLRTPUSHRTSTACK(&nc_emlrtRSI);
                        ztest = b * b + ztest0;
                        b_sqrt(&ztest);
                        EMLRTPOPRTSTACK(&nc_emlrtRSI);
                        if (b < 0.0) {
                            ztest = -ztest;
                        }
                        ztest = eml_div(ztest0, b + ztest);
                    }
                    ztest += (sqds + sm) * (sqds - sm);
                    ztest0 = sqds * eqds;
                    for (i = q; i <= mm1; i++) {
                        qs = i + 1;
                        EMLRTPUSHRTSTACK(&oc_emlrtRSI);
                        eml_xrotg(&ztest, &ztest0, &emm1, &sm);
                        EMLRTPOPRTSTACK(&oc_emlrtRSI);
                        if (i > q) {
                            emlrtDynamicBoundsCheck(1, 1, e->size[0], &ue_emlrtBCI);
                            e->data[0] = ztest;
                        }
                        emlrtDynamicBoundsCheck(i, 1, s->size[0], &ve_emlrtBCI);
                        ztest0 = emm1 * s->data[i - 1];
                        emlrtDynamicBoundsCheck(i, 1, e->size[0], &we_emlrtBCI);
                        ztest = sm * e->data[i - 1];
                        emlrtDynamicBoundsCheck(i, 1, e->size[0], &xe_emlrtBCI);
                        emlrtDynamicBoundsCheck(i, 1, s->size[0], &ye_emlrtBCI);
                        e->data[emlrtDynamicBoundsCheck(i, 1, e->size[0], &sg_emlrtBCI) - 1] = emm1 * e->data[i - 1] - sm * s->data[i - 1];
                        b = s->data[emlrtDynamicBoundsCheck(qs, 1, s->size[0], &tg_emlrtBCI) - 1];
                        emlrtDynamicBoundsCheck(qs, 1, s->size[0], &af_emlrtBCI);
                        s->data[emlrtDynamicBoundsCheck(qs, 1, s->size[0], &ug_emlrtBCI) - 1] = s->data[qs - 1] * emm1;
                        EMLRTPUSHRTSTACK(&pc_emlrtRSI);
                        eml_xrot(p, Vf, 1 + p * (i - 1), 1 + p * i, emm1, sm);
                        EMLRTPOPRTSTACK(&pc_emlrtRSI);
                        EMLRTPUSHRTSTACK(&qc_emlrtRSI);
                        ztest += ztest0;
                        ztest0 = sm * b;
                        eml_xrotg(&ztest, &ztest0, &emm1, &sm);
                        EMLRTPOPRTSTACK(&qc_emlrtRSI);
                        s->data[emlrtDynamicBoundsCheck(i, 1, s->size[0], &vg_emlrtBCI) - 1] = ztest;
                        emlrtDynamicBoundsCheck(i, 1, e->size[0], &bf_emlrtBCI);
                        emlrtDynamicBoundsCheck(qs, 1, s->size[0], &cf_emlrtBCI);
                        ztest = emm1 * e->data[i - 1] + sm * s->data[qs - 1];
                        emlrtDynamicBoundsCheck(i, 1, e->size[0], &df_emlrtBCI);
                        emlrtDynamicBoundsCheck(qs, 1, s->size[0], &ef_emlrtBCI);
                        s->data[emlrtDynamicBoundsCheck(qs, 1, s->size[0], &wg_emlrtBCI) - 1] = -sm * e->data[i - 1] + emm1 * s->data[qs - 1];
                        emlrtDynamicBoundsCheck(qs, 1, e->size[0], &ff_emlrtBCI);
                        ztest0 = sm * e->data[qs - 1];
                        emlrtDynamicBoundsCheck(qs, 1, e->size[0], &gf_emlrtBCI);
                        e->data[emlrtDynamicBoundsCheck(qs, 1, e->size[0], &xg_emlrtBCI) - 1] = e->data[qs - 1] * emm1;
                        if (i < 2) {
                            EMLRTPUSHRTSTACK(&rc_emlrtRSI);
                            b_eml_xrot(U, 1, 3, emm1, sm);
                            EMLRTPOPRTSTACK(&rc_emlrtRSI);
                        }
                    }
                    e->data[emlrtDynamicBoundsCheck(m - 1, 1, e->size[0], &rg_emlrtBCI) - 1] = ztest;
                    iter++;
                    break;
                  default:
                    if (s->data[emlrtDynamicBoundsCheck(q, 1, s->size[0], &vf_emlrtBCI) - 1] < 0.0) {
                        s->data[emlrtDynamicBoundsCheck(q, 1, s->size[0], &wf_emlrtBCI) - 1] = -s->data[emlrtDynamicBoundsCheck(q, 1, s->size[0], &xf_emlrtBCI) - 1];
                        EMLRTPUSHRTSTACK(&wc_emlrtRSI);
                        c_eml_xscal(p, -1.0, Vf, 1 + p * (q - 1));
                        EMLRTPOPRTSTACK(&wc_emlrtRSI);
                    }
                    qp1 = q + 1;
                    while ((q < mm) && (s->data[emlrtDynamicBoundsCheck(q, 1, s->size[0], &yf_emlrtBCI) - 1] < s->data[emlrtDynamicBoundsCheck(qp1, 1, s->size[0], &ag_emlrtBCI) - 1])) {
                        ztest = s->data[emlrtDynamicBoundsCheck(q, 1, s->size[0], &bg_emlrtBCI) - 1];
                        s->data[emlrtDynamicBoundsCheck(q, 1, s->size[0], &cg_emlrtBCI) - 1] = s->data[emlrtDynamicBoundsCheck(qp1, 1, s->size[0], &dg_emlrtBCI) - 1];
                        s->data[emlrtDynamicBoundsCheck(qp1, 1, s->size[0], &eg_emlrtBCI) - 1] = ztest;
                        if (q < p) {
                            EMLRTPUSHRTSTACK(&xc_emlrtRSI);
                            eml_xswap(p, Vf, 1 + p * (q - 1), 1 + p * q);
                            EMLRTPOPRTSTACK(&xc_emlrtRSI);
                        }
                        if (q < 2) {
                            EMLRTPUSHRTSTACK(&yc_emlrtRSI);
                            b_eml_xswap(U, 1, 3);
                            EMLRTPOPRTSTACK(&yc_emlrtRSI);
                        }
                        q = qp1;
                        qp1++;
                    }
                    iter = 0;
                    m--;
                    break;
                }
            }
        }
    }
    emxFree_real_T(&e);
    emxFree_real_T(&b_A);
    mm = S->size[0];
    S->size[0] = minnp;
    emxEnsureCapacity((emxArray__common *)S, mm, (int32_T)sizeof(real_T), &t_emlrtRTEI);
    for (i = 1; i <= minnp; i++) {
        S->data[emlrtDynamicBoundsCheck(i, 1, S->size[0], &mi_emlrtBCI) - 1] = s->data[emlrtDynamicBoundsCheck(i, 1, s->size[0], &ni_emlrtBCI) - 1];
    }
    emxFree_real_T(&s);
    b_p[0] = p;
    b_p[1] = minnp;
    for (mm = 0; mm < 2; mm++) {
        iv20[mm] = (int32_T)emlrtNonNegativeCheckR2009b((real_T)b_p[mm], &s_emlrtDCI);
    }
    mm = V->size[0] * V->size[1];
    V->size[0] = iv20[0];
    V->size[1] = iv20[1];
    emxEnsureCapacity((emxArray__common *)V, mm, (int32_T)sizeof(real_T), &u_emlrtRTEI);
    for (qs = 1; qs <= minnp; qs++) {
        for (i = 1; i <= p; i++) {
            V->data[(emlrtDynamicBoundsCheck(i, 1, V->size[0], &ii_emlrtBCI) + V->size[0] * (emlrtDynamicBoundsCheck(qs, 1, V->size[1], &ji_emlrtBCI) - 1)) - 1] = Vf->data[(emlrtDynamicBoundsCheck(i, 1, Vf->size[0], &ki_emlrtBCI) + Vf->size[0] * (emlrtDynamicBoundsCheck(qs, 1, Vf->size[1], &li_emlrtBCI) - 1)) - 1];
        }
    }
    emxFree_real_T(&Vf);
    EMLRTPOPRTSTACK(&vb_emlrtRSI);
    EMLRTPOPRTSTACK(&ub_emlrtRSI);
    emlrtHeapReferenceStackLeaveFcn();
}

/*
 * 
 */
static real_T eml_xnrm2(int32_T n, const emxArray_real_T *x, int32_T ix0)
{
    real_T y;
    int32_T incx;
    EMLRTPUSHRTSTACK(&ad_emlrtRSI);
    if (n < 1) {
        y = 0.0;
    } else {
        EMLRTPUSHRTSTACK(&cd_emlrtRSI);
        incx = 1;
        y = dnrm232(&n, &x->data[emlrtDynamicBoundsCheck(ix0, 1, x->size[1] << 1, &ri_emlrtBCI) - 1], &incx);
        EMLRTPOPRTSTACK(&cd_emlrtRSI);
    }
    EMLRTPOPRTSTACK(&ad_emlrtRSI);
    return y;
}

/*
 * 
 */
static void eml_xrot(int32_T n, emxArray_real_T *x, int32_T ix0, int32_T iy0, real_T c, real_T s)
{
    emxArray_real_T *b_x;
    int32_T incx;
    int32_T incy;
    int32_T i5;
    int32_T loop_ub;
    int32_T b_loop_ub;
    int32_T i6;
    emlrtHeapReferenceStackEnterFcn();
    EMLRTPUSHRTSTACK(&bf_emlrtRSI);
    if (n < 1) {
    } else {
        emxInit_real_T(&b_x, 2, &fb_emlrtRTEI, TRUE);
        EMLRTPUSHRTSTACK(&df_emlrtRSI);
        incx = 1;
        incy = 1;
        i5 = b_x->size[0] * b_x->size[1];
        b_x->size[0] = x->size[0];
        b_x->size[1] = x->size[1];
        emxEnsureCapacity((emxArray__common *)b_x, i5, (int32_T)sizeof(real_T), &fb_emlrtRTEI);
        loop_ub = x->size[1] - 1;
        for (i5 = 0; i5 <= loop_ub; i5++) {
            b_loop_ub = x->size[0] - 1;
            for (i6 = 0; i6 <= b_loop_ub; i6++) {
                b_x->data[i6 + b_x->size[0] * i5] = x->data[i6 + x->size[0] * i5];
            }
        }
        EMLRTPUSHRTSTACK(&ef_emlrtRSI);
        drot32(&n, &b_x->data[emlrtDynamicBoundsCheck(ix0, 1, x->size[0] * x->size[1], &vp_emlrtBCI) - 1], &incx, &b_x->data[emlrtDynamicBoundsCheck(iy0, 1, x->size[0] * x->size[1], &wp_emlrtBCI) - 1], &incy, &c, &s);
        EMLRTPOPRTSTACK(&ef_emlrtRSI);
        EMLRTPOPRTSTACK(&df_emlrtRSI);
        i5 = x->size[0] * x->size[1];
        x->size[0] = b_x->size[0];
        x->size[1] = b_x->size[1];
        emxEnsureCapacity((emxArray__common *)x, i5, (int32_T)sizeof(real_T), &fb_emlrtRTEI);
        loop_ub = b_x->size[1] - 1;
        for (i5 = 0; i5 <= loop_ub; i5++) {
            b_loop_ub = b_x->size[0] - 1;
            for (i6 = 0; i6 <= b_loop_ub; i6++) {
                x->data[i6 + x->size[0] * i5] = b_x->data[i6 + b_x->size[0] * i5];
            }
        }
        emxFree_real_T(&b_x);
    }
    EMLRTPOPRTSTACK(&bf_emlrtRSI);
    emlrtHeapReferenceStackLeaveFcn();
}

/*
 * 
 */
static void eml_xrotg(real_T *a, real_T *b, real_T *c, real_T *s)
{
    real_T b_b;
    real_T b_a;
    EMLRTPUSHRTSTACK(&ve_emlrtRSI);
    EMLRTPUSHRTSTACK(&xe_emlrtRSI);
    b_b = *b;
    b_a = *a;
    *c = 0.0;
    *s = 0.0;
    EMLRTPUSHRTSTACK(&af_emlrtRSI);
    drotg32(&b_a, &b_b, c, s);
    EMLRTPOPRTSTACK(&af_emlrtRSI);
    EMLRTPOPRTSTACK(&xe_emlrtRSI);
    EMLRTPOPRTSTACK(&ve_emlrtRSI);
    *a = b_a;
    *b = b_b;
}

/*
 * 
 */
static void eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0)
{
    int32_T incx;
    EMLRTPUSHRTSTACK(&dd_emlrtRSI);
    if (n < 1) {
    } else {
        EMLRTPUSHRTSTACK(&fd_emlrtRSI);
        incx = 1;
        EMLRTPUSHRTSTACK(&gd_emlrtRSI);
        dscal32(&n, &a, &x->data[emlrtDynamicBoundsCheck(ix0, 1, x->size[1] << 1, &ip_emlrtBCI) - 1], &incx);
        EMLRTPOPRTSTACK(&gd_emlrtRSI);
        EMLRTPOPRTSTACK(&fd_emlrtRSI);
    }
    EMLRTPOPRTSTACK(&dd_emlrtRSI);
}

/*
 * 
 */
static void eml_xswap(int32_T n, emxArray_real_T *x, int32_T ix0, int32_T iy0)
{
    int32_T ix;
    int32_T iy;
    int32_T k;
    real_T temp;
    EMLRTPUSHRTSTACK(&hf_emlrtRSI);
    EMLRTPUSHRTSTACK(&if_emlrtRSI);
    ix = ix0;
    iy = iy0;
    for (k = 1; k <= n; k++) {
        temp = x->data[emlrtDynamicBoundsCheck(ix, 1, x->size[0] * x->size[1], &eq_emlrtBCI) - 1];
        x->data[emlrtDynamicBoundsCheck(ix, 1, x->size[0] * x->size[1], &fq_emlrtBCI) - 1] = x->data[emlrtDynamicBoundsCheck(iy, 1, x->size[0] * x->size[1], &gq_emlrtBCI) - 1];
        x->data[emlrtDynamicBoundsCheck(iy, 1, x->size[0] * x->size[1], &hq_emlrtBCI) - 1] = temp;
        ix++;
        iy++;
    }
    EMLRTPOPRTSTACK(&if_emlrtRSI);
    EMLRTPOPRTSTACK(&hf_emlrtRSI);
}

/*
 * 
 */
void b_eml_pinv(const emxArray_real_T *A, emxArray_real_T *X)
{
    int32_T m;
    int32_T j;
    int32_T vcol;
    emxArray_real_T *V;
    emxArray_real_T *U;
    emxArray_real_T *s;
    emxArray_real_T *r14;
    emxArray_real_T *S;
    real_T tol;
    int32_T r;
    real_T beta1;
    int32_T ldc;
    char_T TRANSA;
    char_T TRANSB;
    emlrtHeapReferenceStackEnterFcn();
    m = A->size[0];
    j = X->size[0] * X->size[1];
    X->size[0] = 2;
    emxEnsureCapacity((emxArray__common *)X, j, (int32_T)sizeof(real_T), &jb_emlrtRTEI);
    j = X->size[0] * X->size[1];
    X->size[1] = m;
    emxEnsureCapacity((emxArray__common *)X, j, (int32_T)sizeof(real_T), &jb_emlrtRTEI);
    vcol = (m << 1) - 1;
    for (j = 0; j <= vcol; j++) {
        X->data[j] = 0.0;
    }
    if (A->size[0] == 0) {
    } else {
        EMLRTPUSHRTSTACK(&pf_emlrtRSI);
        j = emlrtBoundsCheck(A->size[0] << 1, &dj_emlrtBCI);
        for (vcol = 1; vcol <= j; vcol++) {
            emlrtDynamicBoundsCheck(vcol, 1, A->size[0] << 1, &cj_emlrtBCI);
            if (!((!muDoubleScalarIsInf(A->data[vcol - 1])) && (!muDoubleScalarIsNaN(A->data[vcol - 1])))) {
                EMLRTPUSHRTSTACK(&sf_emlrtRSI);
                b_eml_error();
                EMLRTPOPRTSTACK(&sf_emlrtRSI);
            }
        }
        emxInit_real_T(&V, 2, &r_emlrtRTEI, TRUE);
        emxInit_real_T(&U, 2, &jb_emlrtRTEI, TRUE);
        b_emxInit_real_T(&s, 1, &jb_emlrtRTEI, TRUE);
        emxInit_real_T(&r14, 2, &jb_emlrtRTEI, TRUE);
        EMLRTPUSHRTSTACK(&tf_emlrtRSI);
        b_eml_xgesvd(A, U, s, r14);
        j = V->size[0] * V->size[1];
        V->size[0] = 2;
        V->size[1] = r14->size[1];
        emxEnsureCapacity((emxArray__common *)V, j, (int32_T)sizeof(real_T), &jb_emlrtRTEI);
        vcol = r14->size[0] * r14->size[1] - 1;
        for (j = 0; j <= vcol; j++) {
            V->data[j] = r14->data[j];
        }
        emxFree_real_T(&r14);
        emxInit_real_T(&S, 2, &jb_emlrtRTEI, TRUE);
        EMLRTPOPRTSTACK(&tf_emlrtRSI);
        emlrtBoundsCheck(s->size[0], &bj_emlrtBCI);
        vcol = (int32_T)emlrtNonNegativeCheckR2009b((real_T)s->size[0], &t_emlrtDCI);
        emlrtNonNegativeCheckR2009b((real_T)s->size[0], &u_emlrtDCI);
        j = S->size[0] * S->size[1];
        S->size[0] = vcol;
        emxEnsureCapacity((emxArray__common *)S, j, (int32_T)sizeof(real_T), &jb_emlrtRTEI);
        emlrtNonNegativeCheckR2009b((real_T)s->size[0], &v_emlrtDCI);
        vcol = (int32_T)emlrtNonNegativeCheckR2009b((real_T)s->size[0], &w_emlrtDCI);
        j = S->size[0] * S->size[1];
        S->size[1] = vcol;
        emxEnsureCapacity((emxArray__common *)S, j, (int32_T)sizeof(real_T), &jb_emlrtRTEI);
        vcol = (int32_T)emlrtNonNegativeCheckR2009b((real_T)s->size[0], &x_emlrtDCI) * (int32_T)emlrtNonNegativeCheckR2009b((real_T)s->size[0], &y_emlrtDCI) - 1;
        for (j = 0; j <= vcol; j++) {
            S->data[j] = 0.0;
        }
        for (vcol = 0; vcol <= s->size[0] - 1; vcol++) {
            S->data[(emlrtDynamicBoundsCheck((int32_T)(1.0 + (real_T)vcol), 1, S->size[0], &kj_emlrtBCI) + S->size[0] * (emlrtDynamicBoundsCheck((int32_T)(1.0 + (real_T)vcol), 1, S->size[1], &lj_emlrtBCI) - 1)) - 1] = s->data[emlrtDynamicBoundsCheck((int32_T)(1.0 + (real_T)vcol), 1, s->size[0], &mj_emlrtBCI) - 1];
        }
        emxFree_real_T(&s);
        EMLRTPOPRTSTACK(&pf_emlrtRSI);
        emlrtDynamicBoundsCheck(1, 1, S->size[0], &hj_emlrtBCI);
        emlrtDynamicBoundsCheck(1, 1, S->size[1], &gj_emlrtBCI);
        tol = (real_T)m * S->data[0] * 2.2204460492503131E-16;
        r = 0;
        vcol = 1;
        while ((vcol < 3) && (S->data[(emlrtDynamicBoundsCheck(vcol, 1, S->size[0], &ij_emlrtBCI) + S->size[0] * (emlrtDynamicBoundsCheck(vcol, 1, S->size[1], &jj_emlrtBCI) - 1)) - 1] > tol)) {
            r++;
            vcol++;
        }
        if (r > 0) {
            vcol = 1;
            for (j = 1; j <= r; j++) {
                EMLRTPUSHRTSTACK(&qf_emlrtRSI);
                emlrtDynamicBoundsCheck(j, 1, S->size[0], &fj_emlrtBCI);
                emlrtDynamicBoundsCheck(j, 1, S->size[1], &ej_emlrtBCI);
                eml_xscal(2, 1.0 / S->data[(j + S->size[0] * (j - 1)) - 1], V, vcol);
                EMLRTPOPRTSTACK(&qf_emlrtRSI);
                vcol += 2;
            }
            EMLRTPUSHRTSTACK(&rf_emlrtRSI);
            EMLRTPUSHRTSTACK(&pi_emlrtRSI);
            if (m < 1) {
            } else {
                EMLRTPUSHRTSTACK(&ri_emlrtRSI);
                vcol = 2;
                tol = 1.0;
                j = 2;
                beta1 = 0.0;
                ldc = 2;
                TRANSA = 'N';
                TRANSB = 'C';
                EMLRTPUSHRTSTACK(&si_emlrtRSI);
                emlrtDynamicBoundsCheck(1, 1, V->size[1] << 1, &aj_emlrtBCI);
                emlrtDynamicBoundsCheck(1, 1, U->size[0] * U->size[1], &yi_emlrtBCI);
                emlrtDynamicBoundsCheck(1, 1, m << 1, &xi_emlrtBCI);
                dgemm32(&TRANSA, &TRANSB, &vcol, &m, &r, &tol, &V->data[0], &j, &U->data[0], &m, &beta1, &X->data[0], &ldc);
                EMLRTPOPRTSTACK(&si_emlrtRSI);
                EMLRTPOPRTSTACK(&ri_emlrtRSI);
            }
            EMLRTPOPRTSTACK(&pi_emlrtRSI);
            EMLRTPOPRTSTACK(&rf_emlrtRSI);
        }
        emxFree_real_T(&U);
        emxFree_real_T(&S);
        emxFree_real_T(&V);
    }
    emlrtHeapReferenceStackLeaveFcn();
}

/*
 * 
 */
void eml_pinv(const emxArray_real_T *A, emxArray_real_T *X)
{
    int32_T n;
    int32_T j;
    int32_T vcol;
    emxArray_real_T *V;
    emxArray_real_T *U;
    emxArray_real_T *s;
    emxArray_real_T *r13;
    emxArray_real_T *S;
    real_T tol;
    int32_T r;
    real_T beta1;
    char_T TRANSA;
    char_T TRANSB;
    emlrtHeapReferenceStackEnterFcn();
    n = A->size[1];
    j = X->size[0] * X->size[1];
    X->size[0] = n;
    X->size[1] = 2;
    emxEnsureCapacity((emxArray__common *)X, j, (int32_T)sizeof(real_T), &q_emlrtRTEI);
    vcol = (n << 1) - 1;
    for (j = 0; j <= vcol; j++) {
        X->data[j] = 0.0;
    }
    if (A->size[1] == 0) {
    } else {
        EMLRTPUSHRTSTACK(&ob_emlrtRSI);
        j = emlrtBoundsCheck(A->size[1] << 1, &xc_emlrtBCI);
        for (vcol = 1; vcol <= j; vcol++) {
            emlrtDynamicBoundsCheck(vcol, 1, A->size[1] << 1, &wc_emlrtBCI);
            if (!((!muDoubleScalarIsInf(A->data[vcol - 1])) && (!muDoubleScalarIsNaN(A->data[vcol - 1])))) {
                EMLRTPUSHRTSTACK(&rb_emlrtRSI);
                b_eml_error();
                EMLRTPOPRTSTACK(&rb_emlrtRSI);
            }
        }
        emxInit_real_T(&V, 2, &r_emlrtRTEI, TRUE);
        emxInit_real_T(&U, 2, &q_emlrtRTEI, TRUE);
        b_emxInit_real_T(&s, 1, &q_emlrtRTEI, TRUE);
        emxInit_real_T(&r13, 2, &q_emlrtRTEI, TRUE);
        EMLRTPUSHRTSTACK(&sb_emlrtRSI);
        eml_xgesvd(A, U, s, r13);
        j = V->size[0] * V->size[1];
        V->size[0] = r13->size[0];
        V->size[1] = r13->size[1];
        emxEnsureCapacity((emxArray__common *)V, j, (int32_T)sizeof(real_T), &q_emlrtRTEI);
        vcol = r13->size[0] * r13->size[1] - 1;
        for (j = 0; j <= vcol; j++) {
            V->data[j] = r13->data[j];
        }
        emxFree_real_T(&r13);
        emxInit_real_T(&S, 2, &q_emlrtRTEI, TRUE);
        EMLRTPOPRTSTACK(&sb_emlrtRSI);
        emlrtBoundsCheck(s->size[0], &vc_emlrtBCI);
        vcol = (int32_T)emlrtNonNegativeCheckR2009b((real_T)s->size[0], &m_emlrtDCI);
        emlrtNonNegativeCheckR2009b((real_T)s->size[0], &n_emlrtDCI);
        j = S->size[0] * S->size[1];
        S->size[0] = vcol;
        emxEnsureCapacity((emxArray__common *)S, j, (int32_T)sizeof(real_T), &q_emlrtRTEI);
        emlrtNonNegativeCheckR2009b((real_T)s->size[0], &o_emlrtDCI);
        vcol = (int32_T)emlrtNonNegativeCheckR2009b((real_T)s->size[0], &p_emlrtDCI);
        j = S->size[0] * S->size[1];
        S->size[1] = vcol;
        emxEnsureCapacity((emxArray__common *)S, j, (int32_T)sizeof(real_T), &q_emlrtRTEI);
        vcol = (int32_T)emlrtNonNegativeCheckR2009b((real_T)s->size[0], &q_emlrtDCI) * (int32_T)emlrtNonNegativeCheckR2009b((real_T)s->size[0], &r_emlrtDCI) - 1;
        for (j = 0; j <= vcol; j++) {
            S->data[j] = 0.0;
        }
        for (vcol = 0; vcol <= s->size[0] - 1; vcol++) {
            S->data[(emlrtDynamicBoundsCheck((int32_T)(1.0 + (real_T)vcol), 1, S->size[0], &fd_emlrtBCI) + S->size[0] * (emlrtDynamicBoundsCheck((int32_T)(1.0 + (real_T)vcol), 1, S->size[1], &gd_emlrtBCI) - 1)) - 1] = s->data[emlrtDynamicBoundsCheck((int32_T)(1.0 + (real_T)vcol), 1, s->size[0], &hd_emlrtBCI) - 1];
        }
        emxFree_real_T(&s);
        EMLRTPOPRTSTACK(&ob_emlrtRSI);
        emlrtDynamicBoundsCheck(1, 1, S->size[0], &cd_emlrtBCI);
        emlrtDynamicBoundsCheck(1, 1, S->size[1], &bd_emlrtBCI);
        tol = 2.0 * S->data[0] * 2.2204460492503131E-16;
        r = 0;
        vcol = 1;
        while ((vcol <= n) && (S->data[(emlrtDynamicBoundsCheck(vcol, 1, S->size[0], &dd_emlrtBCI) + S->size[0] * (emlrtDynamicBoundsCheck(vcol, 1, S->size[1], &ed_emlrtBCI) - 1)) - 1] > tol)) {
            r++;
            vcol++;
        }
        if (r > 0) {
            vcol = 1;
            for (j = 1; j <= r; j++) {
                EMLRTPUSHRTSTACK(&pb_emlrtRSI);
                emlrtDynamicBoundsCheck(j, 1, S->size[0], &ad_emlrtBCI);
                emlrtDynamicBoundsCheck(j, 1, S->size[1], &yc_emlrtBCI);
                c_eml_xscal(n, 1.0 / S->data[(j + S->size[0] * (j - 1)) - 1], V, vcol);
                EMLRTPOPRTSTACK(&pb_emlrtRSI);
                vcol += n;
            }
            EMLRTPUSHRTSTACK(&qb_emlrtRSI);
            EMLRTPUSHRTSTACK(&lf_emlrtRSI);
            if (n < 1) {
            } else {
                EMLRTPUSHRTSTACK(&nf_emlrtRSI);
                vcol = 2;
                tol = 1.0;
                j = 2;
                beta1 = 0.0;
                TRANSA = 'N';
                TRANSB = 'C';
                EMLRTPUSHRTSTACK(&of_emlrtRSI);
                emlrtDynamicBoundsCheck(1, 1, V->size[0] * V->size[1], &uc_emlrtBCI);
                emlrtDynamicBoundsCheck(1, 1, U->size[1] << 1, &tc_emlrtBCI);
                emlrtDynamicBoundsCheck(1, 1, n << 1, &sc_emlrtBCI);
                dgemm32(&TRANSA, &TRANSB, &n, &vcol, &r, &tol, &V->data[0], &n, &U->data[0], &j, &beta1, &X->data[0], &n);
                EMLRTPOPRTSTACK(&of_emlrtRSI);
                EMLRTPOPRTSTACK(&nf_emlrtRSI);
            }
            EMLRTPOPRTSTACK(&lf_emlrtRSI);
            EMLRTPOPRTSTACK(&qb_emlrtRSI);
        }
        emxFree_real_T(&U);
        emxFree_real_T(&S);
        emxFree_real_T(&V);
    }
    emlrtHeapReferenceStackLeaveFcn();
}
/* End of code generation (pinv.c) */
