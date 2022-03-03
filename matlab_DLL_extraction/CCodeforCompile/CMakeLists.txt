cmake_minimum_required(VERSION 3.14)
project(cCompile C)

#[set library output directory to the directory above the project]
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
endif()
#[add the "CCodeforCompile" subdirectory to the source list so that compile.c is recognized as a source file]
add_library(cCompile SHARED compile.c)
set_target_properties(cCompile PROPERTIES PREFIX "")