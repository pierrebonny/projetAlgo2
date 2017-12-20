cmake_minimum_required(VERSION 3.8)
project(projet)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES source/main.cpp source/Bin.cpp source/Bin.h)
set(EXECUTABLE_OUTPUT_PATH ../)
add_executable(projet ${SOURCE_FILES})
