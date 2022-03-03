/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 * File: compile.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 02-Mar-2022 16:50:06
 */

/* Include Files */
#include "compile.h"
#include "compile_emxutil.h"
#include "compile_types.h"

/* Function Definitions */
/*
 * compile - Description
 *
 *  Syntax: output = compile(input)
 *
 *  Long description
 *
 * Arguments    : int a
 *                emxArray_int32_T *output
 * Return Type  : void
 */
void compile(int a, emxArray_int32_T *output)
{
  emxArray_int8_T *sieve;
  int b_i;
  int i;
  int i1;
  emxInit_int8_T(&sieve, 2);
  /*  Generate C++ code for the this function */
  /*  find nth prime number using the sieve of Eratosthenes and store in output
   */
  i = sieve->size[0] * sieve->size[1];
  sieve->size[0] = 1;
  sieve->size[1] = a;
  emxEnsureCapacity_int8_T(sieve, i);
  for (i = 0; i < a; i++) {
    sieve->data[i] = 1;
  }
  sieve->data[0] = 0;
  sieve->data[1] = 0;
  /*  store the primes in output */
  output->size[0] = 1;
  output->size[1] = 0;
  for (b_i = 0; b_i < a; b_i++) {
    if (sieve->data[b_i] == 1) {
      i = output->size[1];
      i1 = output->size[0] * output->size[1];
      output->size[1]++;
      emxEnsureCapacity_int32_T(output, i1);
      output->data[i] = b_i + 1;
    }
  }
  emxFree_int8_T(&sieve);
}

/*
 * File trailer for compile.c
 *
 * [EOF]
 */
