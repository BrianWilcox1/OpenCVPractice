cmake_minimum_required(VERSION 3.1)

project(opencv_practice)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INLCUDE_DIRS} include)

add_library(draw_ops SHARED src/drawing.cpp)
target_link_libraries(draw_ops ${OpenCV_LIBS})

add_executable(draw examples/imgproc/draw.cpp)
target_link_libraries(draw ${OpenCV_LIBS} draw_ops)
