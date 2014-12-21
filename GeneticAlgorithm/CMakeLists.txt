cmake_minimum_required(VERSION 2.8.4)
project(GeneticAlgorithm)

# CXX flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# CMake directories
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_SRC_DIR                  "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(CMAKE_INCLUDE_DIR              "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(CMAKE_TEST_DIR                 "${CMAKE_CURRENT_SOURCE_DIR}/test")

include_directories("${CMAKE_INCLUDE_DIR}")

# main file
#set(MAIN_FILE main.cpp)
set(MAIN_TEST_FILE ${CMAKE_TEST_DIR}/mainTest.cpp)

# include all files from directory ${CMAKE_SRC_DIR}
aux_source_directory(${CMAKE_SRC_DIR} SOURCE_FILES)
# include all files from directory ${CMAKE_TEST_DIR}
aux_source_directory(${CMAKE_TEST_DIR} TEST_FILES)

add_executable(GeneticAlgorithmTest ${MAIN_TEST_FILE} ${SOURCE_FILES} ${TEST_FILES})

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