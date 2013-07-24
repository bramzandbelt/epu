/*
 * repmat.h
 *
 * Code generation for function 'repmat'
 *
 * C source code generated on: Tue Oct 30 14:49:26 2012
 *
 */

#ifndef __REPMAT_H__
#define __REPMAT_H__
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
#include "epu_n_unit_ba_types.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern void b_repmat(real_T m, real_T n, emxArray_real_T *b);
extern void c_repmat(const emxArray_real_T *a, real_T n, emxArray_real_T *b);
extern void repmat(const emxArray_real_T *a, real_T m, emxArray_real_T *b);
#endif
/* End of code generation (repmat.h) */
