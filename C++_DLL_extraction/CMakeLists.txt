cmake_minimum_required(VERSION 3.14)
project(matlab_loader CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
endif()

add_library(matlab_lib SHARED main.cpp)
set_target_properties(matlab_lib PROPERTIES PREFIX "")
