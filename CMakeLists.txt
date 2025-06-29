# entry point for building C/C++ artifacts. has nothing to do with the
# website build itself; it builds the C/C++ code that is
# referenced/described from in the website.

cmake_minimum_required(VERSION 3.20)
project(JoergFaschingbauer)

enable_testing()

#FIND_PACKAGE(GTest REQUIRED)
find_package(Threads REQUIRED)
set(CMAKE_CXX_STANDARD 23)

# compiler options. (we only check for gcc)
if (${CMAKE_COMPILER_IS_GNUCC})
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -ggdb -Wall -Werror")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -ggdb -Wall -Werror")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23")
endif()

add_subdirectory(googletest)
add_subdirectory(googlebenchmark)
add_subdirectory(trainings/material/soup)

add_subdirectory(trainings/log/detail/2020-03-30/code)

add_subdirectory(about/site/work-in-progress/fh-joanneum/2020/code)
add_subdirectory(about/site/work-in-progress/fh-joanneum/2021)
add_subdirectory(about/site/work-in-progress/fh-joanneum/dtle/code)
