cmake_minimum_required(VERSION 2.6)

project(code_005)
set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 4.1 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(005_read_img read_img.cpp)
add_executable(005_read_video read_video.cpp)
target_link_libraries(005_read_img ${OpenCV_LIBS})
target_link_libraries(005_read_video ${OpenCV_LIBS})
