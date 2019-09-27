cmake_minimum_required(VERSION 3.9)
project(Sobel-Operator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(
        Sobel-Operator main.cpp
        hands_methods.cpp
)

# linking
target_link_libraries(Sobel-Operator ${OpenCV_LIBS})