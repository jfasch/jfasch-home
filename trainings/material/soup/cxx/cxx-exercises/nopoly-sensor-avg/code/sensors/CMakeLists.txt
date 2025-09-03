ADD_LIBRARY(
  cxx-exercises-sensor-avg-nopoly

  sensor-avg-nopoly.h
  sensor-avg-nopoly.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  cxx-exercises-sensor-avg-nopoly

  PUBLIC
  .
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-sensor-avg-nopoly

  cxx-exercises-sensors-core-nopoly
)
