ADD_EXECUTABLE(
  cxx-exercises--hysteresis-nopoly--suite

  hysteresis-nopoly-suite-nop_when_within_range.cpp
  hysteresis-nopoly-suite-falls_below_range.cpp
  hysteresis-nopoly-suite-rises_above_range.cpp

)

TARGET_LINK_LIBRARIES(
  cxx-exercises--hysteresis-nopoly--suite

  cxx-exercises-hysteresis-nopoly
  cxx-exercises-sensors-core-nopoly  
  cxx-exercises-switches-core-nopoly

  gtest_main 
)
