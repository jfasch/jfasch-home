ADD_EXECUTABLE(
  cxx-exercises-design-patterns-composite--suite

  composite-suite-basic.cpp
  composite-suite-initializer-list.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-design-patterns-composite--suite

  cxx-exercises-design-patterns-composite-sensors
  gtest_main 
)

add_test(NAME cxx-exercises-design-patterns-composite--suite COMMAND cxx-exercises-design-patterns-composite--suite)




