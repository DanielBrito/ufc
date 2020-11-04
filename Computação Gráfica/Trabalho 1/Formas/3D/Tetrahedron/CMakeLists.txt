cmake_minimum_required(VERSION 3.15)
project(Tetrahedron)

set(CMAKE_CXX_STANDARD 14)

add_executable(Tetrahedron main.cpp)

target_link_libraries(Tetrahedron -lglut -lGL -lGLU)