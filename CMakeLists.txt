cmake_minimum_required(VERSION 3.0)

project(mymuduo)

set(LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

aux_source_directory(. SRC_LIST)

add_library(mymuduo SHARED ${SRC_LIST})

