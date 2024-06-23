cmake_minimum_required(VERSION 3.20)
project(Gluehweinkochen)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include("my_add_library")
include("compiler")

find_package(SQLite3)

add_subdirectory(firmware)
add_subdirectory(toolcase)
