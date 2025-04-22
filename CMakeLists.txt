# entry point for building C/C++ artifacts. has nothing to do with the
# website build itself; it builds the C/C++ code that is
# referenced/described from in the website.

CMAKE_MINIMUM_REQUIRED(VERSION 3.20)
PROJECT(JoergFaschingbauer)

enable_testing()

#FIND_PACKAGE(GTest REQUIRED)
FIND_PACKAGE(Threads REQUIRED)
SET(CMAKE_CXX_STANDARD 23)

# compiler options. (we only check for gcc)
if (${CMAKE_COMPILER_IS_GNUCC})
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -ggdb -Wall -Werror")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -ggdb -Wall -Werror")
endif()

ADD_SUBDIRECTORY(googletest)
ADD_SUBDIRECTORY(googlebenchmark)
ADD_SUBDIRECTORY(trainings/material/soup)

message("jjjjjjjjjjjjjjjjjjjjjjjjjjj in trainings/log/detail/* sind noch vielmehr cmake verloren gegangen")
ADD_SUBDIRECTORY(trainings/log/detail/2020-03-30/code)
ADD_SUBDIRECTORY(trainings/log/detail/2025-04-14/)

ADD_SUBDIRECTORY(about/site/work-in-progress/fh-joanneum/2020/code)
ADD_SUBDIRECTORY(about/site/work-in-progress/fh-joanneum/2021)

ADD_SUBDIRECTORY(about/site/work-in-progress/fh-joanneum/dtle/code)
