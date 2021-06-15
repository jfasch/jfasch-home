# entry point for building C/C++ artifacts. has nothing to do with the
# website build itself; it builds the C/C++ code that is
# referenced/described from in the website.

CMAKE_MINIMUM_REQUIRED(VERSION 3.20)
PROJECT(JoergFaschingbauer)

ENABLE_TESTING()

FIND_PACKAGE(GTest REQUIRED)
FIND_PACKAGE(Threads REQUIRED)

# compiler options. (we only check for gcc)
if (${CMAKE_COMPILER_IS_GNUCC})
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g3 -Wall -Werror")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g3 -Wall -Werror -std=c++11")
endif()

ADD_SUBDIRECTORY(trainings/material/soup)
ADD_SUBDIRECTORY(trainings/log/detail/2020-03-30/code)
