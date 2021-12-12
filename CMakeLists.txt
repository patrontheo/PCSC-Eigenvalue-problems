cmake_minimum_required(VERSION 3.0)
project(PCSC-EIGENVALUE-PROBLEM)
include_directories(eigen)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_FLAGS "-DNDEBUG")

add_executable(main main.cpp abstract_linalg_solver.cpp power.cpp load_csv.cpp write_csv.cpp inv_power.cpp qr.cpp) 
