cmake_minimum_required(VERSION 3.21)
project(testCPP)

set(CMAKE_CXX_STANDARD 14)

add_executable(CppAD_demo CppAD_demo.cpp)

add_executable(cppad_ipopt_demo cppad_ipopt_demo.cpp)
target_link_libraries(cppad_ipopt_demo ipopt)
