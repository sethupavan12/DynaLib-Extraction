#ifndef SHARED_LIB_H
#define SHARED_LIB_H

#include <stdio.h>
#include<string>
#include<iostream>
#include<cstdlib>
#include<array>
#include<cstdio>


using namespace std;

#ifdef __cplusplus 
    extern "C" { 
#endif

#ifdef BUILD_MY_DLL
    #define SHARED_LIB __declspec(dllexport)
#else
    #define SHARED_LIB __declspec(dllimport)
#endif 

// This is where you define the functions that you want to export

void SHARED_LIB print_hello();
void SHARED_LIB print_even(int);

#ifdef __cplusplus 
    }
#endif


#endif