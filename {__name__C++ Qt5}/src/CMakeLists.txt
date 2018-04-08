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


#QT5
find_package(Qt5Widgets REQUIRED)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(${Qt5Widgets_INCLUDES})
add_definitions(${Qt5Widgets_DEFINITIONS})
add_compile_options("${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

## Generate rules for building resources
qt5_wrap_cpp(MOC_SOURCES ${PROJECT_SOURCE_DIR}/include/mainWindow.hpp)
qt5_wrap_ui(UI_HEADERS ${PROJECT_SOURCE_DIR}/res/mainWindow.ui)
qt5_add_resources(QRCS ${PROJECT_SOURCE_DIR}/res/resources.qrc)

#EXE
add_executable(main
               main.cpp
               mainWindow.cpp
               ${MOC_SOURCES}
               ${UI_HEADERS}
               ${QRCS})

target_link_libraries(main ${Qt5Widgets_LIBRARIES})   
target_link_libraries(main logger)     
