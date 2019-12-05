cmake_minimum_required(VERSION 2.8)

project(MinimizersPack CXX)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories("headers")
add_subdirectory(definitions)