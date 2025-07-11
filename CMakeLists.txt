# entry point for building C/C++ artifacts. has nothing to do with the
# website build itself; it builds the C/C++ code that is
# referenced/described from in the website.

cmake_minimum_required(VERSION 3.20)
project(JoergFaschingbauer)

enable_testing()

#FIND_PACKAGE(GTest REQUIRED)
find_package(Threads REQUIRED)
#set(CMAKE_CXX_STANDARD 23)

# compiler options. (we only check for gcc)
if (${CMAKE_COMPILER_IS_GNUCC})
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -ggdb -Wall -Werror")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -ggdb -Wall -Werror")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++26")
endif()

add_subdirectory(googletest)
add_subdirectory(googlebenchmark)
add_subdirectory(trainings/material/soup)
add_subdirectory(trainings/log/detail)

add_subdirectory(about/site/work-in-progress/fh-joanneum/2020/code)
add_subdirectory(about/site/work-in-progress/fh-joanneum/2021)
add_subdirectory(about/site/work-in-progress/fh-joanneum/dtle/code)
add_subdirectory(about/site/work-in-progress/fh-joanneum/2023/ss2025/2025-06-26/code)
