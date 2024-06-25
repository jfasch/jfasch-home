cmake_minimum_required(VERSION 3.20)
project(Gluehweinkochen VERSION 42.666)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include("my_add_library")
include("compiler")
include("sqlite3")
include("mosquitto")

configure_file(project-config.h.in project-config.h)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(firmware)
add_subdirectory(toolcase)
