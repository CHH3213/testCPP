cmake_minimum_required(VERSION 3.21)
project(testCPP)

set(CMAKE_CXX_STANDARD 14)


add_executable(cppad_ipopt_demo cppad_ipopt_demo.cpp osqp_eigen_demo.cpp)
target_link_libraries(cppad_ipopt_demo ipopt)

find_package(osqp REQUIRED)
add_executable(osqp_demo osqp_demo.cpp)
target_link_libraries(osqp_demo PRIVATE osqp::osqp)

find_package(OsqpEigen REQUIRED)
add_executable(osqp_eigen_demo osqp_eigen_demo.cpp)
target_link_libraries(osqp_eigen_demo OsqpEigen::OsqpEigen)