cmake_minimum_required(VERSION 2.6)
project(code_002)
set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 4.1 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(002 init_mat.cpp)
target_link_libraries(002 ${OpenCV_LIBS})