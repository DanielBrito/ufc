cmake_minimum_required(VERSION 3.15)
project(Mesh)

set(CMAKE_CXX_STANDARD 14)

add_executable(Mesh main.cpp)

target_link_libraries(Mesh -lglut -lGL -lGLU)