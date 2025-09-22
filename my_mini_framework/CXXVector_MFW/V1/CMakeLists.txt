cmake_minimum_required(VERSION 3.15)
project(CXXVector_MFW VERSION 1.0 LANGUAGES CXX)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# === Header-only Library ===
add_library(CXXVector INTERFACE)

# Expose main include directory
target_include_directories(CXXVector INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/MFW
)

# === Testing ===
file(GLOB TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/testing_files/utest/*.cpp
)

add_executable(CXXVectorTests ${TEST_SOURCES})

target_link_libraries(CXXVectorTests PRIVATE CXXVector)

# Add helper headers for tests
target_include_directories(CXXVectorTests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/testing_files/test_help_files
)

# === Options ===
enable_testing()
add_test(NAME RunCXXVectorTests COMMAND CXXVectorTests)