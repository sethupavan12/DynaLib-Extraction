cmake_minimum_required(VERSION 3.14)
project(matlabDLLCoder CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
endif()

add_library(matlabDLLCoder SHARED compile.c)
set_target_properties(matlabDLLCoder PROPERTIES PREFIX "")