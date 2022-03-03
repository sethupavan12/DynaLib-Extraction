cmake_minimum_required(VERSION 3.14)
project(CdllProject C)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
endif()

add_library(Cdll SHARED compile.c)
set_target_properties(Cdll PROPERTIES PREFIX "")