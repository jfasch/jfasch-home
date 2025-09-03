ADD_EXECUTABLE(
  cxx-exercises-display-led-stripe-nopoly--suite

  display_led_stripe_nopoly_suite__somewhere_in_the_middle.cpp
  display_led_stripe_nopoly_suite__below_range.cpp
  display_led_stripe_nopoly_suite__above_range.cpp
  display_led_stripe_nopoly_suite__movement.cpp

  display_led_stripe_nopoly_suite__variations.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-display-led-stripe-nopoly--suite

  cxx-exercises-display-led-stripe-nopoly
  cxx-exercises-switches-core-nopoly
  cxx-exercises-sensors-core-nopoly
  gtest_main 
)

add_test(NAME cxx-exercises-display-led-stripe-nopoly--suite COMMAND cxx-exercises-display-led-stripe-nopoly--suite)
