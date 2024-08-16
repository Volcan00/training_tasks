cmake_minimum_required(VERSION 3.10)

project(QuickSort)

set(CXX_STANDARD_REQUIRED 17)
set(CXX_STANDARD_REQUIRED TRUE)

include_directories(.)

add_executable(main
    ../src/main.cpp
    ../src/Quicksort.cpp)

