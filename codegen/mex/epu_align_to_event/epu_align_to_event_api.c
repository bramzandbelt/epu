/*
 * epu_align_to_event_api.c
 *
 * Code generation for function 'epu_align_to_event_api'
 *
 * C source code generated on: Fri Aug 31 09:30:57 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_align_to_event.h"
#include "epu_align_to_event_api.h"
#include "epu_align_to_event_emxutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRTEInfo i_emlrtRTEI = { 1, 1, "epu_align_to_event_api", "" };

/* Function Declarations */
static real_T b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId);
static void c_emlrt_marshallIn(const mxArray *outputTimeFrame, const char_T *identifier, real_T y[2]);
static void d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, real_T y[2]);
static void e_emlrt_marshallIn(const mxArray *trajectories, const char_T *identifier, emxArray_real_T *y);
static real_T emlrt_marshallIn(const mxArray *rt, const char_T *identifier);
static const mxArray *emlrt_marshallOut(emxArray_real_T *u);
static void f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static real_T g_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId);
static void h_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, real_T ret[2]);
static void i_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, emxArray_real_T *ret);

/* Function Definitions */

static real_T b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId)
{
    real_T y;
    y = g_emlrt_marshallIn(emlrtAlias(u), parentId);
    emlrtDestroyArray(&u);
    return y;
}

static void c_emlrt_marshallIn(const mxArray *outputTimeFrame, const char_T *identifier, real_T y[2])
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    d_emlrt_marshallIn(emlrtAlias(outputTimeFrame), &thisId, y);
    emlrtDestroyArray(&outputTimeFrame);
}

static void d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, real_T y[2])
{
    h_emlrt_marshallIn(emlrtAlias(u), parentId, y);
    emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const mxArray *trajectories, const char_T *identifier, emxArray_real_T *y)
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    f_emlrt_marshallIn(emlrtAlias(trajectories), &thisId, y);
    emlrtDestroyArray(&trajectories);
}

static real_T emlrt_marshallIn(const mxArray *rt, const char_T *identifier)
{
    real_T y;
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    y = b_emlrt_marshallIn(emlrtAlias(rt), &thisId);
    emlrtDestroyArray(&rt);
    return y;
}

static const mxArray *emlrt_marshallOut(emxArray_real_T *u)
{
    const mxArray *y;
    const mxArray *m3;
    real_T (*pData)[];
    int32_T i2;
    int32_T i;
    y = NULL;
    m3 = mxCreateNumericArray(2, u->size, mxDOUBLE_CLASS, mxREAL);
    pData = (real_T (*)[])mxGetPr(m3);
    i2 = 0;
    for (i = 0; i < u->size[1]; i++) {
        (*pData)[i2] = u->data[u->size[0] * i];
        i2++;
    }
    emlrtAssign(&y, m3);
    return y;
}

static void f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
    i_emlrt_marshallIn(emlrtAlias(u), parentId, y);
    emlrtDestroyArray(&u);
}

static real_T g_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId)
{
    real_T ret;
    emlrtCheckBuiltInCtxR2011b(&emlrtContextGlobal, msgId, src, "double", FALSE, 0U, 0);
    ret = *(real_T *)mxGetData(src);
    emlrtDestroyArray(&src);
    return ret;
}

static void h_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, real_T ret[2])
{
    int32_T iv9[2];
    int32_T i3;
    for (i3 = 0; i3 < 2; i3++) {
        iv9[i3] = 1 + i3;
    }
    emlrtCheckBuiltInCtxR2011b(&emlrtContextGlobal, msgId, src, "double", FALSE, 2U, iv9);
    for (i3 = 0; i3 < 2; i3++) {
        ret[i3] = (*(real_T (*)[2])mxGetData(src))[i3];
    }
    emlrtDestroyArray(&src);
}

static void i_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
    int32_T iv10[2];
    boolean_T bv0[2];
    int32_T i4;
    static const boolean_T bv1[2] = { FALSE, TRUE };
    for (i4 = 0; i4 < 2; i4++) {
        iv10[i4] = 1 + 999999 * i4;
        bv0[i4] = bv1[i4];
    }
    emlrtCheckVsBuiltInCtxR2011b(&emlrtContextGlobal, msgId, src, "double", FALSE, 2U, iv10, bv0, ret->size);
    i4 = ret->size[0] * ret->size[1];
    ret->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)ret, i4, (int32_T)sizeof(real_T), (emlrtRTEInfo *)NULL);
    emlrtImportArrayR2011b(src, ret->data, 8, FALSE);
    emlrtDestroyArray(&src);
}

void epu_align_to_event_api(const mxArray * const prhs[4], const mxArray *plhs[1])
{
    emxArray_real_T *trajectories;
    emxArray_real_T *alignedArray;
    real_T rt;
    real_T outputTimeFrame[2];
    real_T minTrialTime;
    emlrtHeapReferenceStackEnterFcn();
    emxInit_real_T(&trajectories, 2, &i_emlrtRTEI, TRUE);
    emxInit_real_T(&alignedArray, 2, &i_emlrtRTEI, TRUE);
    /* Marshall function inputs */
    rt = emlrt_marshallIn(emlrtAliasP(prhs[0]), "rt");
    c_emlrt_marshallIn(emlrtAliasP(prhs[1]), "outputTimeFrame", outputTimeFrame);
    minTrialTime = emlrt_marshallIn(emlrtAliasP(prhs[2]), "minTrialTime");
    e_emlrt_marshallIn(emlrtAliasP(prhs[3]), "trajectories", trajectories);
    /* Invoke the target function */
    epu_align_to_event(rt, outputTimeFrame, minTrialTime, trajectories, alignedArray);
    /* Marshall function outputs */
    plhs[0] = emlrt_marshallOut(alignedArray);
    emxFree_real_T(&alignedArray);
    emxFree_real_T(&trajectories);
    emlrtHeapReferenceStackLeaveFcn();
}
/* End of code generation (epu_align_to_event_api.c) */
