cmake_minimum_required (VERSION 3.5)
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -g -fexceptions")

project(TestAPP C CXX)

set(QUICK_START_VERSION_MAJOR 1)
set(QUICK_START_VERSION_MINOR 0)
INCLUDE(CMakeToolsHelpers OPTIONAL)

include_directories("${PROJECT_SOURCE_DIR}/include")

add_subdirectory(src)

enable_testing()
add_subdirectory(test)