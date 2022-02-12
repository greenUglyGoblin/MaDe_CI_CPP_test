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
include(FetchContent)
FetchContent_Declare(gtest
    QUIET
    URL https://github.com/google/googletest/archive/release-1.10.0.tar.gz
)
# configure build of googletest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(gtest)

enable_testing()
include(GoogleTest)

add_executable(UTests
    # unit tests
    test/ut_main.cpp
)

target_link_libraries(
    UTests
    gtest_main
)

gtest_discover_tests(UTests)
