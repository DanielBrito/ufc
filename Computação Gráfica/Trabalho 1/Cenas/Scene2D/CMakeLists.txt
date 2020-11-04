cmake_minimum_required(VERSION 3.15)
project(Scene2D)

set(CMAKE_CXX_STANDARD 14)

add_executable(Scene2D main.cpp)

target_link_libraries(Scene2D -lglut -lGL -lGLU)