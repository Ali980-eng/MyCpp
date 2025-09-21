cmake_minimum_required(VERSION 3.10)
project(CXXLite LANGUAGES CXX)
add_library(CXXLite INTERFACE)
target_include_directories(CXXLite INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_compile_features(CXXLite INTERFACE cxx_std_17)