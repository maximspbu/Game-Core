cmake_minimum_required(VERSION 3.12)
project(lab2 VERSION 1.0 LANGUAGES C CXX)
set(CMAKE_VERBOSE_MAKEFILE ON)
file(GLOB SOURCES CONFIGURE_DEPENDS
    ./*.h
    ./*.cpp 
)
add_executable(lab2  ${SOURCES})
