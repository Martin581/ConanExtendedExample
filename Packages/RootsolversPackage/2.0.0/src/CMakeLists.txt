cmake_minimum_required(VERSION 2.8)

project(RootSolverPack CXX)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories("headers")
add_subdirectory(definitions)