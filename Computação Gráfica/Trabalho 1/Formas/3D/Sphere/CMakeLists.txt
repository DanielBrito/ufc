cmake_minimum_required(VERSION 3.15)
project(Sphere)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sphere main.cpp)

target_link_libraries(Sphere -lglut -lGL -lGLU)