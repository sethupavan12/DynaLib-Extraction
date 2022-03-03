//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: compile.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 02-Mar-2022 16:57:21
//

// Include Files
#include "compile.h"
#include "coder_array.h"

// Function Definitions
//
// compile - Description
//
//  Syntax: output = compile(input)
//
//  Long description
//
// Arguments    : int a
//                coder::array<int, 2U> &output
// Return Type  : void
//
void compile(int a, coder::array<int, 2U> &output)
{
  coder::array<signed char, 2U> sieve;
  int i;
  //  Generate C++ code for the this function
  //  find nth prime number using the sieve of Eratosthenes and store in output
  sieve.set_size(1, a);
  for (i = 0; i < a; i++) {
    sieve[i] = 1;
  }
  sieve[0] = 0;
  sieve[1] = 0;
  //  store the primes in output
  output.set_size(1, 0);
  for (int b_i{0}; b_i < a; b_i++) {
    if (sieve[b_i] == 1) {
      i = output.size(1);
      output.set_size(output.size(0), output.size(1) + 1);
      output[i] = b_i + 1;
    }
  }
}

//
// File trailer for compile.cpp
//
// [EOF]
//
