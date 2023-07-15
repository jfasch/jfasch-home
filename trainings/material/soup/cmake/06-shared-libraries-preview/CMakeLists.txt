CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
PROJECT(Demo)

ADD_LIBRARY(hello hello.c hello-name.c)
SET_PROPERTY(TARGET hello PROPERTY VERSION "1")

ADD_EXECUTABLE(hello-first hello-first.c)
TARGET_LINK_LIBRARIES(hello-first hello)

ADD_EXECUTABLE(hello-second hello-second.c)
TARGET_LINK_LIBRARIES(hello-second hello)
