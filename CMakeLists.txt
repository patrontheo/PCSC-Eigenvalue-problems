cmake_minimum_required(VERSION 3.0)
project(PCSC-EIGENVALUE-PROBLEM)
include_directories(eigen)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_FLAGS "-DNDEBUG")

add_executable(main main.cpp abstract_linalg_solver.cpp power.cpp load_csv.cpp write_csv.cpp inv_power.cpp qr.cpp) 

add_subdirectory(googletest)
add_executable(test_pcsc test/test.cc)
target_link_libraries(test_pcsc gtest_main gtest pthread pcsc)
add_custom_target(test ./test_pcsc DEPENDS test_pcsc)