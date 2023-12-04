cmake_minimum_required(VERSION 3.23)
project(polymorphism_practical)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_DEBUG
  "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Wall -Wextra -Werror -DDEBUG -g")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY build)

add_subdirectory(src)
