ADD_LIBRARY(
  cxx-exercises-sensors-duck

  sensor-const.h
  sensor-const.cpp

  sensor-random.h
  sensor-random.cpp
)  

TARGET_INCLUDE_DIRECTORIES(
  cxx-exercises-sensors-duck

  PUBLIC
  .
)
