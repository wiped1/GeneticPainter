cmake_minimum_required(VERSION 2.8.4)
project(GeneticAlgorithm)

# CXX flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# CMake directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_SRC_DIR                  "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(CMAKE_INCLUDE_DIR              "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(CMAKE_TEST_DIR                 "${CMAKE_CURRENT_SOURCE_DIR}/test")

include_directories("${CMAKE_INCLUDE_DIR}")

# main file
#set(MAIN_FILE main.cpp)
set(MAIN_TEST_FILE ${CMAKE_TEST_DIR}/mainTest.cpp)

set(SOURCE_FILES
    ${CMAKE_SRC_DIR}/Genotype.cpp
)

set(TEST_FILES
    ${CMAKE_TEST_DIR}/GenotypeTest.cpp
)

add_executable(GeneticAlgorithmTest ${MAIN_TEST_FILE} ${TEST_FILES} ${SOURCE_FILES})

# Command used to execute unit tests after build
add_custom_command(
    TARGET GeneticAlgorithmTest
    POST_BUILD
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/GeneticAlgorithmTest
)

enable_testing(true)
add_test(
    NAME all
    COMMAND GeneticAlgorithmTest
)