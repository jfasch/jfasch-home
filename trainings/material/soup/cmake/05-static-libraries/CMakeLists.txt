CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
PROJECT(Demo)

ADD_LIBRARY(hello                             # <--- target "hello"
  hello.h hello.c 
  hello-name.h hello-name.c)

ADD_EXECUTABLE(hello-first hello-first.c)     # <--- target "hello-first"
TARGET_LINK_LIBRARIES(hello-first hello)      # <--- "hello-first" depends on "hello"

ADD_EXECUTABLE(hello-second hello-second.c)   # <--- target "hello-second"
TARGET_LINK_LIBRARIES(hello-second hello)     # <--- "hello-second" depends on "hello"
