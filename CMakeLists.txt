cmake_minimum_required(VERSION 3.0.0)
project(MaDe_CI_CPP_test VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

# project part
include_directories(inc)

add_executable(MaDe_CI_CPP_test
    # src
    src/main.cpp
    src/functions.cpp

    # headers
    inc/macros.h
)


# GTest part
enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

include_directories(/usr/local/include) # gtest header

add_executable(UTests
    # unit tests
    test/ut_main.cpp
)

target_link_libraries(
    UTests
    /usr/local/lib/libgtest.a      # gtest lib
    /usr/local/lib/libgtest_main.a # gtest lib
)

gtest_discover_tests(UTests)
