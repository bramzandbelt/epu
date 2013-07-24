/*
 * pinv.h
 *
 * Code generation for function 'pinv'
 *
 * C source code generated on: Fri Aug 31 09:24:08 2012
 *
 */

#ifndef __PINV_H__
#define __PINV_H__
/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"

#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blascompat32.h"
#include "rtwtypes.h"
#include "epu_compute_trajectory_onset_types.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern void b_eml_pinv(const emxArray_real_T *A, emxArray_real_T *X);
extern void eml_pinv(const emxArray_real_T *A, emxArray_real_T *X);
#endif
/* End of code generation (pinv.h) */
