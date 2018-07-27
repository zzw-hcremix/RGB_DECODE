cmake_minimum_required(VERSION 2.8.12)

project(DECODE_ENCODE)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

FIND_PACKAGE(OpenCV)
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})

MESSAGE(STATUS "Project: ${PROJECT_NAME}")
MESSAGE(STATUS "OpenCV library status:")
MESSAGE(STATUS "version: ${OpenCV_VERSION}")
MESSAGE(STATUS "libraries: ${OpenCV_LIBS}")
MESSAGE(STATUS "include path: ${OpenCV_INCLUDE_DIRS}")

LINK_LIBRARIES(opencv_core)
LINK_LIBRARIES(opencv_imgcodecs)
LINK_LIBRARIES(opencv_highgui)
LINK_LIBRARIES(opencv_imgproc)

add_executable(${PROJECT_NAME} "main.cpp" "toolbox.cpp" "svjpeg.cpp" "svpng.cpp")

