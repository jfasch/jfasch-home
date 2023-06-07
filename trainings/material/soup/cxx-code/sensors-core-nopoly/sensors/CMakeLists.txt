ADD_LIBRARY(
  cxx-exercises-sensors-core-nopoly

  sensor-random.h
  sensor-random.cpp

  sensor-const.h
  sensor-const.cpp

  sensor-utils.h
)

TARGET_INCLUDE_DIRECTORIES(
  cxx-exercises-sensors-core-nopoly

  PUBLIC
  .
)
