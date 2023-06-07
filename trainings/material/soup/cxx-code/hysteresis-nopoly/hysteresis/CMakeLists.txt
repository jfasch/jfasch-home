ADD_LIBRARY(
  cxx-exercises-hysteresis-nopoly

  hysteresis.h
  hysteresis.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  cxx-exercises-hysteresis-nopoly

  PUBLIC
  .
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-hysteresis-nopoly

  cxx-exercises-sensors-core-nopoly  
  cxx-exercises-switches-core-nopoly
)
