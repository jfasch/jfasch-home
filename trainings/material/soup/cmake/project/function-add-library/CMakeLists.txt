cmake_minimum_required(VERSION 3.20)
project(Gluehweinkochen)

if ("${CMAKE_COMPILER_IS_GNUCC}")
  string(APPEND CMAKE_C_FLAGS " -ggdb -Wall -Werror")
  string(APPEND CMAKE_CXX_FLAGS " -ggdb -Wall -Werror")
endif()

add_subdirectory(firmware)
add_subdirectory(toolcase)
