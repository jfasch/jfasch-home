ADD_EXECUTABLE(
  cxx-exercises-design-patterns-abstract-factory--suite

  abstract-factory-suite-vendor1.cpp
  abstract-factory-suite-vendor2.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-design-patterns-abstract-factory--suite

  cxx-exercises-design-patterns-abstract-factory-sensors
  gtest_main 
)

add_test(NAME cxx-exercises-design-patterns-abstract-factory--suite COMMAND cxx-exercises-design-patterns-abstract-factory--suite)
