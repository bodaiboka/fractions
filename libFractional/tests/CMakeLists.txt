set(GOOGLE_TEST_ROOT $ENV{GOOGLE_TEST})

if (WIN32)
  string(REGEX REPLACE "\\\\" "/" GOOGLE_TEST_ROOT "${GOOGLE_TEST_ROOT}")
endif()

set(GTEST_LIBRARY "${GOOGLE_TEST_ROOT}/lib/libgtest.a")
set(GTEST_INCLUDE_DIR "${GOOGLE_TEST_ROOT}/include/")
set(GTEST_MAIN_LIBRARY "${GOOGLE_TEST_ROOT}/lib/libgtest_main.a")

# Find Google Test
find_package(GTest REQUIRED)

# Include your library's headers
include_directories(${CMAKE_SOURCE_DIR}/../include)
include_directories(${GTEST_INCLUDE_DIRS})

# Add test executable
add_executable(Fractional_Tests fractional_tests.cpp)

# Link test executable against gtest & gtest_main (important)
target_link_libraries(Fractional_Tests ${GTEST_BOTH_LIBRARIES})
target_link_libraries(Fractional_Tests fractional)

# This is used to run the tests (e.g. via 'make test' or 'ctest')
add_test(NAME runUnitTests COMMAND Fractional_Tests)