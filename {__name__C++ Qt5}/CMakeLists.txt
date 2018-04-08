cmake_minimum_required (VERSION 3.5)
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_C_COMPILER "cc")
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-std=c++17> $<$<COMPILE_LANGUAGE:C>:-std=c99>)
add_compile_options("-Wall")
add_compile_options("-Wextra")
add_compile_options("-g")


project(TestAPP C CXX)

set(QUICK_START_VERSION_MAJOR 1)
set(QUICK_START_VERSION_MINOR 0)
INCLUDE(CMakeToolsHelpers OPTIONAL)

include_directories("${PROJECT_SOURCE_DIR}/include")

add_subdirectory(src)

enable_testing()
add_subdirectory(test)