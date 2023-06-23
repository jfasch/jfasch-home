ADD_LIBRARY(
  cxx-exercises-display-led-stripe-nopoly

  display-led-stripe-nopoly.h
  display-led-stripe-nopoly.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  cxx-exercises-display-led-stripe-nopoly

  PUBLIC
  .
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-display-led-stripe-nopoly

  cxx-exercises-switches-core-nopoly
  cxx-exercises-sensors-core-nopoly
)
