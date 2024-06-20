cmake_minimum_required(VERSION 3.20)
project(Gluehweinkochen)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake")
find_package(Mosquitto)

add_subdirectory(firmware)
add_subdirectory(toolcase)
