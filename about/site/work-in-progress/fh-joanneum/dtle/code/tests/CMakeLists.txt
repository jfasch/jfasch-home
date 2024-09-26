ADD_EXECUTABLE(
  dtle-hysteresis-suite

  hysteresis-nop_when_within_range.cpp
  hysteresis-falls_below_range.cpp
  hysteresis-rises_above_range.cpp
  hysteresis-rises_above_range_when_on.cpp
)


TARGET_LINK_LIBRARIES(
  dtle-hysteresis-suite

  dtle-toolcase
  gtest_main 
)

ADD_TEST(NAME dtle-hysteresis-suite COMMAND dtle-hysteresis-suite)
