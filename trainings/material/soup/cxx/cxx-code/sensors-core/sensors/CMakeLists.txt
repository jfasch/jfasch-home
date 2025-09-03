ADD_LIBRARY(
  cxx-exercises-sensors-core

  sensor.h

  sensor-random.h
  sensor-random.cpp

  sensor-const.h
  sensor-const.cpp

  sensor-mock.h
  sensor-mock.cpp

  sensor-utils.h
)

TARGET_INCLUDE_DIRECTORIES(
  cxx-exercises-sensors-core

  PUBLIC
  .
)
