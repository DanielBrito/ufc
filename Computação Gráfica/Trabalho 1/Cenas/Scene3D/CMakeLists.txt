cmake_minimum_required(VERSION 3.15)
project(Scene3D)

set(CMAKE_CXX_STANDARD 14)

add_executable(Scene3D main.cpp)

target_link_libraries(Scene3D -lglut -lGL -lGLU)