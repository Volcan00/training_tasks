cmake_minimum_required(VERSION 3.10)

# Set the project name
project(EulersTotientFunction)

set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories(.)

add_executable(main 
    ../src/main.cpp
    ../src/Functions.cpp)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(main_tests 
    ../tests/main_tests.cpp
    ../src/Functions.cpp)

target_link_libraries(main_tests ${GTEST_LIBRARIES} pthread)

add_test(NAME main_tests COMMAND main_tests)