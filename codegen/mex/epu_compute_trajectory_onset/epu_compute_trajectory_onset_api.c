/*
 * epu_compute_trajectory_onset_api.c
 *
 * Code generation for function 'epu_compute_trajectory_onset_api'
 *
 * C source code generated on: Fri Aug 31 09:24:09 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_compute_trajectory_onset.h"
#include "epu_compute_trajectory_onset_api.h"
#include "epu_compute_trajectory_onset_emxutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRTEInfo cc_emlrtRTEI = { 1, 1, "epu_compute_trajectory_onset_api", "" };

/* Function Declarations */
static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static real_T c_emlrt_marshallIn(const mxArray *Z, const char_T *identifier);
static real_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId);
static void e_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void emlrt_marshallIn(const mxArray *X, const char_T *identifier, emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(emxArray_real_T *u);
static real_T f_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId);

/* Function Definitions */

static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
    e_emlrt_marshallIn(emlrtAlias(u), parentId, y);
    emlrtDestroyArray(&u);
}

static real_T c_emlrt_marshallIn(const mxArray *Z, const char_T *identifier)
{
    real_T y;
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    y = d_emlrt_marshallIn(emlrtAlias(Z), &thisId);
    emlrtDestroyArray(&Z);
    return y;
}

static real_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId)
{
    real_T y;
    y = f_emlrt_marshallIn(emlrtAlias(u), parentId);
    emlrtDestroyArray(&u);
    return y;
}

static void e_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
    int32_T iv29[2];
    boolean_T bv0[2];
    int32_T i4;
    static const boolean_T bv1[2] = { FALSE, TRUE };
    for (i4 = 0; i4 < 2; i4++) {
        iv29[i4] = 1 + 999999 * i4;
        bv0[i4] = bv1[i4];
    }
    emlrtCheckVsBuiltInCtxR2011b(&emlrtContextGlobal, msgId, src, "double", FALSE, 2U, iv29, bv0, ret->size);
    i4 = ret->size[0] * ret->size[1];
    ret->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)ret, i4, (int32_T)sizeof(real_T), (emlrtRTEInfo *)NULL);
    emlrtImportArrayR2011b(src, ret->data, 8, FALSE);
    emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const mxArray *X, const char_T *identifier, emxArray_real_T *y)
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    b_emlrt_marshallIn(emlrtAlias(X), &thisId, y);
    emlrtDestroyArray(&X);
}

static const mxArray *emlrt_marshallOut(emxArray_real_T *u)
{
    const mxArray *y;
    const mxArray *m11;
    real_T (*pData)[];
    int32_T i3;
    int32_T i;
    y = NULL;
    m11 = mxCreateNumericArray(2, u->size, mxDOUBLE_CLASS, mxREAL);
    pData = (real_T (*)[])mxGetPr(m11);
    i3 = 0;
    for (i = 0; i < u->size[1]; i++) {
        (*pData)[i3] = u->data[u->size[0] * i];
        i3++;
    }
    emlrtAssign(&y, m11);
    return y;
}

static real_T f_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId)
{
    real_T ret;
    emlrtCheckBuiltInCtxR2011b(&emlrtContextGlobal, msgId, src, "double", FALSE, 0U, 0);
    ret = *(real_T *)mxGetData(src);
    emlrtDestroyArray(&src);
    return ret;
}

void epu_compute_trajectory_onset_api(const mxArray * const prhs[3], const mxArray *plhs[1])
{
    emxArray_real_T *X;
    emxArray_real_T *Y;
    emxArray_real_T *t;
    real_T Z;
    emlrtHeapReferenceStackEnterFcn();
    emxInit_real_T(&X, 2, &cc_emlrtRTEI, TRUE);
    emxInit_real_T(&Y, 2, &cc_emlrtRTEI, TRUE);
    emxInit_real_T(&t, 2, &cc_emlrtRTEI, TRUE);
    /* Marshall function inputs */
    emlrt_marshallIn(emlrtAliasP(prhs[0]), "X", X);
    emlrt_marshallIn(emlrtAliasP(prhs[1]), "Y", Y);
    Z = c_emlrt_marshallIn(emlrtAliasP(prhs[2]), "Z");
    /* Invoke the target function */
    epu_compute_trajectory_onset(X, Y, Z, t);
    /* Marshall function outputs */
    plhs[0] = emlrt_marshallOut(t);
    emxFree_real_T(&t);
    emxFree_real_T(&Y);
    emxFree_real_T(&X);
    emlrtHeapReferenceStackLeaveFcn();
}
/* End of code generation (epu_compute_trajectory_onset_api.c) */
