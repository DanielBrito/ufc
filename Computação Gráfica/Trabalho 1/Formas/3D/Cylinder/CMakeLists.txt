cmake_minimum_required(VERSION 3.15)
project(Cylinder)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cylinder main.cpp)

target_link_libraries(Cylinder -lglut -lGL -lGLU)