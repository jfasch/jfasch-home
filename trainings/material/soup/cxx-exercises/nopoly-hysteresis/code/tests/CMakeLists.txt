ADD_EXECUTABLE(
  cxx-exercises--hysteresis-nopoly--suite

  hysteresis-nopoly-nop_when_within_range.cpp
  hysteresis-nopoly-falls_below_range.cpp
  hysteresis-nopoly-rises_above_range.cpp
  hysteresis-nopoly-rises_above_range_when_on.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises--hysteresis-nopoly--suite

  cxx-exercises-hysteresis-nopoly
  cxx-exercises-sensors-core-nopoly  
  cxx-exercises-switches-core-nopoly

  gtest_main 
)

add_test(NAME cxx-exercises--hysteresis-nopoly--suite COMMAND cxx-exercises--hysteresis-nopoly--suite)
