cmake_minimum_required(VERSION 3.15)
project(Triangle)

set(CMAKE_CXX_STANDARD 14)

add_executable(Triangle main.cpp)

target_link_libraries(Triangle -lglut -lGL -lGLU)