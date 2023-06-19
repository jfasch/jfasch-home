ADD_LIBRARY(
  cxx-exercises-sensors-core-nopoly

  sensor-random-nopoly.h
  sensor-random-nopoly.cpp

  sensor-const-nopoly.h
  sensor-const-nopoly.cpp

  sensor-mock-nopoly.h
  sensor-mock-nopoly.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  cxx-exercises-sensors-core-nopoly

  PUBLIC
  .
)
