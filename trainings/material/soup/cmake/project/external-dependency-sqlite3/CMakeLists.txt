cmake_minimum_required(VERSION 3.20)
project(Gluehweinkochen)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include("my_add_library")
include("compiler")

find_package(SQLite3 REQUIRED)

message("SQLite3_INCLUDE_DIRS ${SQLite3_INCLUDE_DIRS}")
message("SQLite3_LIBRARIES ${SQLite3_LIBRARIES}")
message("SQLite3_VERSION ${SQLite3_VERSION}")
message("SQLite3_FOUND ${SQLite3_FOUND}")

add_subdirectory(firmware)
add_subdirectory(toolcase)
