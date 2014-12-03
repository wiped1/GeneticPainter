cmake_minimum_required(VERSION 2.8.4)
project(GeneticPainter)

# cmake variables
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin/")
set(CMAKE_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(CMAKE_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(CMAKE_TEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tests")

# headers
include_directories("${CMAKE_INCLUDE_DIR}")

# main file
set(MAIN_FILE
    main.cpp
)

# source files
set(SOURCE_FILES
    ${CMAKE_SRC_DIR}/Genotype.cpp
)
set(TEST_FILES
    ${CMAKE_TEST_DIR}/main-tests.cpp
    ${CMAKE_TEST_DIR}/ColorTests.cpp
    ${CMAKE_TEST_DIR}/EllipseTests.cpp
    ${CMAKE_TEST_DIR}/GenotypeTests.cpp
    ${CMAKE_TEST_DIR}/Vector2Tests.cpp
)

# executables
add_executable(GeneticPainter ${MAIN_FILE} ${SOURCE_FILES})
add_executable(GeneticPainter-tests ${TEST_FILES} ${SOURCE_FILES})

# unit tests
add_custom_command(
    TARGET GeneticPainter-tests
    POST_BUILD
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/GeneticPainter-tests
)

enable_testing(true)
add_test(
    NAME all
    COMMAND GeneticPainter-tests
)