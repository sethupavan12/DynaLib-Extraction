// C++ file that uses the dylib class:
// Include Files

#include <iostream>
#include "dylib.hpp"

DYLIB_API void print_hello()
{
    std::cout << "Hello" << std::endl;
}

// function to print n even numbers
DYLIB_API void print_even(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            std::cout << i << std::endl;
    }
}

DYLIB_API int main(){

    std::cout << "Printing 9 even numbers" << std::endl;
    int n = 9;
    print_even(n);
    return 0;
}