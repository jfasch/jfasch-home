# entry point for building C/C++ artifacts. has nothing to do with the
# website build itself; it builds the C/C++ code that is
# referenced/described from in the website.

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(JoergFaschingbauer)

ENABLE_TESTING()
FIND_PACKAGE(GTest REQUIRED)

ADD_SUBDIRECTORY(trainings/material/soup)
