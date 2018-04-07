find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories("${PROJECT_SOURCE_DIR}/include")

#TODO replace QuickStart with class being tested
set(SOURCES ${PROJECT_SOURCE_DIR}/src/QuickStart.cpp )
add_library(QuickStart STATIC ${SOURCES})

set(TEST_LIBS QuickStart)
set(TEST_SOURCES ${PROJECT_SOURCE_DIR}/test/QuickStartTest.cpp)

add_executable(test_main ${TEST_SOURCES})
target_link_libraries(test_main ${TEST_LIBS} ${Boost_LIBRARIES})
add_test(NAME QuickStartSuite COMMAND test_main)