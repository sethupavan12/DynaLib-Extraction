Dynamic Library Extraction Tool
=======
RAT takes a dynamic library which contains user's custom function and extracts the function from the library so that it can be used in RAT and perhaps dynamically load a function from the library.

You must be either of the following to use this tool:
1. A user who wants to create a dynamic lib from a C++ source code.
2. A user who wants to create a dynamic lib from a MATLAB source code.

**Note** : Loading a function from a dynamic lib that was created with Matlab source code is not yet supported by RAT.

Inorder to make it easy for the users to create a DLL/.so, this repository has been created

Requirements:
=======
As a basic requirement, user must have CMake installed on their machine.
Download CMake from [here](https://cmake.org/download/)

## Windows Users
1. Windows 10 or higher
2. Visual Studio C++ compiler
3. CMake. Download CMake from [here](https://cmake.org/download/) 
4. `Dylib.hpp`. This is a header file that lets us export our functions. Download it from [here](https://github.com/martin-olivier/dylib/releases/download/v1.8.2/dylib.hpp) or you can find it in the repository.


## Unix Users
1. GCC compiler or Clang compiler
2. CMake. Download CMake from [here](https://cmake.org/download/)
3. `Dylib.hpp`. This is a header file that lets us export our functions. Download it from [here](https://github.com/martin-olivier/dylib/releases/download/v1.8.2/dylib.hpp) or you can find it in the repository.


How to Use:
=======
## Extracting a function from a dynamic library made with C++
The following example shows how to use the tool.
1. Download the repository and open `C++_DLL_extraction` folder.
2. For the example, `main.cpp` is used. This should user's custom model function. This is the file that will contain a function that will be extracted and used in RAT. 

**NOTE**: Make sure you put `"DYLIB_API"` infront of the function you want to export or use (see example). It enables a function to be exported.

The example `main.cpp `should look like this:
``` C++
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

```

3. Create a dynamic library from the `main.cpp` file. This is done by using CMake. 
A template has been made to make it easy. The template is called `CMakeLists.txt`.

**NOTE**: It is important that you name CMakeLists.txt as CMakeLists.txt. This is because CMake looks for CMakeLists.txt when it is run. 

CMakeLists.txt should look like this:
``` CMake
cmake_minimum_required(VERSION 3.14)
project(matlab_loader CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
endif()
#[replace main.cpp with ur custom file but for example, it is fine to use main.cpp]
#[matlab_lib.dll is generated]
add_library(matlab_lib SHARED main.cpp) 
set_target_properties(matlab_lib PROPERTIES PREFIX "")
```

4. Now that we have `CMakeLists.txt` and `main.cpp` setup, we can run CMake commands to generate the dynamic library.

Open terminal and navigate to the directory where you have the `CMakeLists.txt` file and it is suggested for users unfamiliar with CMake to place `CMakeLists.txt` in the same directory as `main.cpp`.

Run the following command to make a build folder in current directory:
```
cmake . -B build 
```
Now, you should see a build folder in the current directory if everything went well.

Then, run the following command to generate the dynamic library.
```
cmake --build build
```
Now, you should see a matlab_lib.dll (or matlab_lib.so depending on the OS) in the `build/Debug` folder.
```
    Directory of C:\Users\C++_DLL_extraction\build\Debug

02/03/2022  17:02    <DIR>          .
02/03/2022  17:02    <DIR>          ..
02/03/2022  17:02            69,632 matlab_lib.dll
02/03/2022  17:02            12,257 matlab_lib.exp
02/03/2022  17:02            20,736 matlab_lib.lib
02/03/2022  17:02           987,136 matlab_lib.pdb
```

5. Thats it! Now, you can input the dynamic library into RAT and use the function.



## Extracting a function from a dynamic library made with MATLAB

**NOTE**: This is not yet supported.

Currently, the only way to extract a function from a dynamic library made with MATLAB is to use the MATLAB Coder/Libray compiler but there seems to be some issues with function names. 

Current workflow is `Matlab code  - > C++ code - > dynamic library - > RAT`.