# Minimal CMakeLists.txt for a project using GoogleTest:
# https://google.github.io/googletest/quickstart-cmake.html

# Configure: cmake -S . -B build
# Build: cmake --build build
# Test: ctest

cmake_minimum_required(VERSION 3.28)
project(my_project)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# https://gcovr.com/en/stable/cookbook.html#oos-cmake
# https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html

# These flags are used if cmake is called with -DCMAKE_BUILD_TYPE=PROFILE:
set(CMAKE_C_FLAGS_PROFILE "--coverage")
set(CMAKE_CXX_FLAGS_PROFILE "--coverage")

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git GIT_TAG v1.17.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# https://cmake.org/cmake/help/latest/module/CTest.html#module:CTest
include(CTest)

add_executable(
  hello_test
  ${CMAKE_SOURCE_DIR}/src/code.cpp
  ${CMAKE_SOURCE_DIR}/test/test.cpp
)

target_link_libraries(
  hello_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)

get_directory_property(compile_options COMPILE_OPTIONS)
message(STATUS "COMPILE_OPTIONS=${compile_options}")
