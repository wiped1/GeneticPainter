cmake_minimum_required(VERSION 3.0.0)
project(GeneticPainter)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# CXX flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# CMake directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_SRC_DIR                  "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(CMAKE_INCLUDE_DIR              "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(CMAKE_TEST_DIR                 "${CMAKE_CURRENT_SOURCE_DIR}/tests")

include_directories("${CMAKE_INCLUDE_DIR}")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/lib/GeneticAlgorithm/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/lib/JSON/src")

set(MAIN_FILE main.cpp)
set(MAIN_TEST_FILE ${CMAKE_TEST_DIR}/runner.cpp)

aux_source_directory(${CMAKE_SRC_DIR} SOURCE_FILES)
aux_source_directory(${CMAKE_TEST_DIR} TEST_FILES)

add_executable(GeneticPainter
    ${MAIN_FILE}
    ${SOURCE_FILES})

add_executable(Tests
    ${MAIN_TEST_FILE}
    ${SOURCE_FILES}
    ${TEST_FILES})

target_link_libraries(GeneticPainter ${OpenCV_LIBS})
target_link_libraries(Tests ${OpenCV_LIBS})