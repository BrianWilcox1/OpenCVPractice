cmake_minimum_required(VERSION 3.1)

project(opencv_practice)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INLCUDE_DIRS} include)

add_library(image_ops SHARED src/image_operations.cpp)
target_link_libraries(image_ops ${OpenCV_LIBS})

add_executable(dft examples/core/dft.cpp)
target_link_libraries(dft ${OpenCV_LIBS} image_ops)
