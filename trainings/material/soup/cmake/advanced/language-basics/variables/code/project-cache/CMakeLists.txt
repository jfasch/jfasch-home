cmake_minimum_required(VERSION 3.20)
project(cache-demo)

if (NOT DEFINED some_variable)
  message("setting some_variable the first time")
  set(some_variable "value" CACHE STRING "Some variable")
endif()

message("Normal variable: ${some_variable}")
message("Cache variable: $CACHE{some_variable}")
