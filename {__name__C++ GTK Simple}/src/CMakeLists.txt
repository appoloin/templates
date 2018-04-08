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

#GTKmm
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)
link_directories( ${GTKMM_LIBRARY_DIRS}  )
include_directories( ${GTKMM_INCLUDE_DIRS}  )

#create exe
add_executable(main 
               main.cpp 
               mainWindow.cpp)
target_link_libraries(main ${GTKMM_LIBRARIES})
target_link_libraries(main logger)

#copy res to bin
file(GLOB resFiles ${PROJECT_SOURCE_DIR}/res/gui.glade)
file(MAKE_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}/res)

foreach(resFiles ${resFiles})
    add_custom_command(TARGET main POST_BUILD
                        COMMAND ${CMAKE_COMMAND} -E
                        copy ${resFiles} ${EXECUTABLE_OUTPUT_PATH}/res/)
endforeach()