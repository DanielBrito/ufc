cmake_minimum_required(VERSION 3.15)
project(Square)

set(CMAKE_CXX_STANDARD 14)

add_executable(Square main.cpp)

target_link_libraries(Square -lglut -lGL -lGLU)