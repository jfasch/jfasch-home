cmake_minimum_required(VERSION 3.20)
project(Gluehweinkochen VERSION 42.666)

message("Major: ${Gluehweinkochen_VERSION_MAJOR}")
message("Major: ${Gluehweinkochen_VERSION_MINOR}")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include("my_add_library")
include("compiler")

find_package(SQLite3)

if (SQLite3_FOUND)
  set(CONFIG_HAVE_SQLITE3 1)
else()
  set(CONFIG_HAVE_SQLITE3 0)
endif()
configure_file(project-config.h.in project-config.h)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(firmware)
add_subdirectory(toolcase)
