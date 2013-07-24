/*
 * epu_align_to_event.h
 *
 * Code generation for function 'epu_align_to_event'
 *
 * C source code generated on: Fri Aug 31 09:30:57 2012
 *
 */

#ifndef __EPU_ALIGN_TO_EVENT_H__
#define __EPU_ALIGN_TO_EVENT_H__
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
#include "epu_align_to_event_types.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern void eml_assert_valid_size_arg(real_T varargin_1);
extern void epu_align_to_event(real_T rt, real_T outputTimeFrame[2], real_T minTrialTime, const emxArray_real_T *trajectories, emxArray_real_T *alignedArray);
#endif
/* End of code generation (epu_align_to_event.h) */
