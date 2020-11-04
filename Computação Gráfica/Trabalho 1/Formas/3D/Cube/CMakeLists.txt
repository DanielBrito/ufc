cmake_minimum_required(VERSION 3.15)
project(Cube)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cube main.cpp)

target_link_libraries(Cube -lglut -lGL -lGLU)