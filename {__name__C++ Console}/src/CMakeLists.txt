set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


#Boost
find_package(Boost COMPONENTS log REQUIRED)
link_directories( ${Boost_LIBRARY_DIRS} )
include_directories(  ${Boost_INCLUDE_DIRS}  )
add_definitions( -DBOOST_ALL_NO_LINK
                 -DBOOST_ALL_DYN_LINK
                 -DBOOST_LOG_DYN_LINK )

add_library(logger logger.cpp)
target_link_libraries(logger  ${Boost_LIBRARIES})

FIND_PACKAGE(Threads)

#create exe
add_executable(main 
               main.cpp)
target_link_libraries(main ${CMAKE_THREAD_LIBS_INIT} )
target_link_libraries(main logger)

                    


