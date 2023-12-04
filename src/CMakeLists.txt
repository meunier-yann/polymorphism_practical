cmake_minimum_required(VERSION 3.1.3)
project(conversion)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Character.cpp)

add_executable(main ${SOURCE_FILES})
