/*
 * epu_n_unit_lba_api.c
 *
 * Code generation for function 'epu_n_unit_lba_api'
 *
 * C source code generated on: Fri Aug 31 09:31:05 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_lba.h"
#include "epu_n_unit_lba_api.h"
#include "epu_n_unit_lba_emxutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRTEInfo o_emlrtRTEI = { 1, 1, "epu_n_unit_lba_api", "" };

/* Function Declarations */
static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static const mxArray *b_emlrt_marshallOut(emxArray_real_T *u);
static real_T c_emlrt_marshallIn(const mxArray *affTime, const char_T *identifier);
static real_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId);
static void e_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void emlrt_marshallIn(const mxArray *v, const char_T *identifier, emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(real_T u);
static real_T f_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId);

/* Function Definitions */

static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
    e_emlrt_marshallIn(emlrtAlias(u), parentId, y);
    emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(emxArray_real_T *u)
{
    const mxArray *y;
    const mxArray *m6;
    real_T (*pData)[];
    int32_T i1;
    int32_T i;
    int32_T b_i;
    y = NULL;
    m6 = mxCreateNumericArray(2, u->size, mxDOUBLE_CLASS, mxREAL);
    pData = (real_T (*)[])mxGetPr(m6);
    i1 = 0;
    for (i = 0; i < u->size[1]; i++) {
        for (b_i = 0; b_i < u->size[0]; b_i++) {
            (*pData)[i1] = u->data[b_i + u->size[0] * i];
            i1++;
        }
    }
    emlrtAssign(&y, m6);
    return y;
}

static real_T c_emlrt_marshallIn(const mxArray *affTime, const char_T *identifier)
{
    real_T y;
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    y = d_emlrt_marshallIn(emlrtAlias(affTime), &thisId);
    emlrtDestroyArray(&affTime);
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
    int32_T iv10[2];
    boolean_T bv0[2];
    int32_T i2;
    static const boolean_T bv1[2] = { FALSE, TRUE };
    for (i2 = 0; i2 < 2; i2++) {
        iv10[i2] = 1 + 999999 * i2;
        bv0[i2] = bv1[i2];
    }
    emlrtCheckVsBuiltInCtxR2011b(&emlrtContextGlobal, msgId, src, "double", FALSE, 2U, iv10, bv0, ret->size);
    i2 = ret->size[0] * ret->size[1];
    ret->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)ret, i2, (int32_T)sizeof(real_T), (emlrtRTEInfo *)NULL);
    emlrtImportArrayR2011b(src, ret->data, 8, FALSE);
    emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const mxArray *v, const char_T *identifier, emxArray_real_T *y)
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    b_emlrt_marshallIn(emlrtAlias(v), &thisId, y);
    emlrtDestroyArray(&v);
}

static const mxArray *emlrt_marshallOut(real_T u)
{
    const mxArray *y;
    const mxArray *m5;
    y = NULL;
    m5 = mxCreateDoubleScalar(u);
    emlrtAssign(&y, m5);
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

void epu_n_unit_lba_api(const mxArray * const prhs[7], const mxArray *plhs[2])
{
    emxArray_real_T *v;
    emxArray_real_T *theta;
    emxArray_real_T *pN;
    emxArray_real_T *iAT;
    emxArray_real_T *activation;
    real_T affTime;
    real_T effTime;
    real_T dMeth;
    real_T rt;
    emlrtHeapReferenceStackEnterFcn();
    emxInit_real_T(&v, 2, &o_emlrtRTEI, TRUE);
    emxInit_real_T(&theta, 2, &o_emlrtRTEI, TRUE);
    emxInit_real_T(&pN, 2, &o_emlrtRTEI, TRUE);
    emxInit_real_T(&iAT, 2, &o_emlrtRTEI, TRUE);
    emxInit_real_T(&activation, 2, &o_emlrtRTEI, TRUE);
    /* Marshall function inputs */
    emlrt_marshallIn(emlrtAliasP(prhs[0]), "v", v);
    emlrt_marshallIn(emlrtAliasP(prhs[1]), "theta", theta);
    affTime = c_emlrt_marshallIn(emlrtAliasP(prhs[2]), "affTime");
    effTime = c_emlrt_marshallIn(emlrtAliasP(prhs[3]), "effTime");
    emlrt_marshallIn(emlrtAliasP(prhs[4]), "pN", pN);
    dMeth = c_emlrt_marshallIn(emlrtAliasP(prhs[5]), "dMeth");
    emlrt_marshallIn(emlrtAliasP(prhs[6]), "iAT", iAT);
    /* Invoke the target function */
    epu_n_unit_lba(v, theta, affTime, effTime, pN, dMeth, iAT, &rt, activation);
    /* Marshall function outputs */
    plhs[0] = emlrt_marshallOut(rt);
    plhs[1] = b_emlrt_marshallOut(activation);
    emxFree_real_T(&activation);
    emxFree_real_T(&iAT);
    emxFree_real_T(&pN);
    emxFree_real_T(&theta);
    emxFree_real_T(&v);
    emlrtHeapReferenceStackLeaveFcn();
}
/* End of code generation (epu_n_unit_lba_api.c) */
