cmake_minimum_required(VERSION 2.8.4)
project(GAEllipses)

# cmake variables
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin/")
set(CMAKE_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/")
set(CMAKE_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/")
set(CMAKE_TEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tests/")

# headers
include_directories("${CMAKE_INCLUDE_DIR}")

# source files
set(SOURCE_FILES main.cpp)
set(TEST_FILES main.cpp)

# executables
add_executable(GAEllipses ${SOURCE_FILES})
add_executable(GAEllipses-tests ${TEST_FILES})

# unit tests
add_custom_command(
    TARGET GAEllipses-tests
    POST_BUILD
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/GAEllipses-tests
)

enable_testing(true)
add_test(
    NAME all
    COMMAND GAEllipses-tests
)