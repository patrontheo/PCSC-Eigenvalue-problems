cmake_minimum_required(VERSION 3.0)
project(PCSC-EIGENVALUE-PROBLEM)
include_directories(eigen)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_FLAGS "-DNDEBUG")

add_executable(main src/main.cpp src/abstract_linalg_solver.cpp src/power.cpp src/load_csv.cpp src/write_csv.cpp src/inv_power.cpp src/qr.cpp) 

# add_subdirectory(googletest)
# add_executable(test_pcsc test/test.cc)
# target_link_libraries(test_pcsc gtest_main gtest)

# include(GoogleTest)
# gtest_discover_tests(test_pcsc)
# add_custom_target(test ./test_pcsc DEPENDS test_pcsc)