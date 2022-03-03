/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 * File: compile_emxAPI.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 02-Mar-2022 16:50:06
 */

#ifndef COMPILE_EMXAPI_H
#define COMPILE_EMXAPI_H

/* Include Files */
#include "compile_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern emxArray_int32_T *emxCreateND_int32_T(int numDimensions,
                                             const int *size);

extern emxArray_int32_T *
emxCreateWrapperND_int32_T(int *data, int numDimensions, const int *size);

extern emxArray_int32_T *emxCreateWrapper_int32_T(int *data, int rows,
                                                  int cols);

extern emxArray_int32_T *emxCreate_int32_T(int rows, int cols);

extern void emxDestroyArray_int32_T(emxArray_int32_T *emxArray);

extern void emxInitArray_int32_T(emxArray_int32_T **pEmxArray,
                                 int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for compile_emxAPI.h
 *
 * [EOF]
 */
