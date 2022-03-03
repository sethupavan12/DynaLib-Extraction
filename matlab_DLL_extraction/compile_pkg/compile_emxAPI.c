/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 * File: compile_emxAPI.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 02-Mar-2022 16:50:06
 */

/* Include Files */
#include "compile_emxAPI.h"
#include "compile_emxutil.h"
#include "compile_types.h"
#include <stdlib.h>

/* Function Definitions */
/*
 * Arguments    : int numDimensions
 *                const int *size
 * Return Type  : emxArray_int32_T *
 */
emxArray_int32_T *emxCreateND_int32_T(int numDimensions, const int *size)
{
  emxArray_int32_T *emx;
  int i;
  int numEl;
  emxInit_int32_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }
  emx->data = (int *)calloc((unsigned int)numEl, sizeof(int));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

/*
 * Arguments    : int *data
 *                int numDimensions
 *                const int *size
 * Return Type  : emxArray_int32_T *
 */
emxArray_int32_T *emxCreateWrapperND_int32_T(int *data, int numDimensions,
                                             const int *size)
{
  emxArray_int32_T *emx;
  int i;
  int numEl;
  emxInit_int32_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }
  emx->data = data;
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

/*
 * Arguments    : int *data
 *                int rows
 *                int cols
 * Return Type  : emxArray_int32_T *
 */
emxArray_int32_T *emxCreateWrapper_int32_T(int *data, int rows, int cols)
{
  emxArray_int32_T *emx;
  emxInit_int32_T(&emx, 2);
  emx->size[0] = rows;
  emx->size[1] = cols;
  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = rows * cols;
  emx->canFreeData = false;
  return emx;
}

/*
 * Arguments    : int rows
 *                int cols
 * Return Type  : emxArray_int32_T *
 */
emxArray_int32_T *emxCreate_int32_T(int rows, int cols)
{
  emxArray_int32_T *emx;
  int numEl;
  emxInit_int32_T(&emx, 2);
  emx->size[0] = rows;
  numEl = rows * cols;
  emx->size[1] = cols;
  emx->data = (int *)calloc((unsigned int)numEl, sizeof(int));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

/*
 * Arguments    : emxArray_int32_T *emxArray
 * Return Type  : void
 */
void emxDestroyArray_int32_T(emxArray_int32_T *emxArray)
{
  emxFree_int32_T(&emxArray);
}

/*
 * Arguments    : emxArray_int32_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInitArray_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxInit_int32_T(pEmxArray, numDimensions);
}

/*
 * File trailer for compile_emxAPI.c
 *
 * [EOF]
 */
