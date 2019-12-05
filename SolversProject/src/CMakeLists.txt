cmake_minimum_required(VERSION 2.8.12)
project(Solvers CXX)

add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory("MinimizersSubproject")
add_subdirectory("RootsolversSubproject")