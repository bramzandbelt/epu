/*
 * movingslope.h
 *
 * Code generation for function 'movingslope'
 *
 * C source code generated on: Fri Aug 31 09:24:08 2012
 *
 */

#ifndef __MOVINGSLOPE_H__
#define __MOVINGSLOPE_H__
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
extern void movingslope(const emxArray_real_T *vec, real_T supportlength, emxArray_real_T *Dvec);
#endif
/* End of code generation (movingslope.h) */
