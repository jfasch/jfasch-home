ADD_EXECUTABLE(
  cxx-exercises-design-patterns-proxy--suite

  proxy-round-suite.cpp
  proxy-remote-suite.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-design-patterns-proxy--suite

  cxx-exercises-design-patterns-proxy-sensors
  gtest_main 
)

add_test(NAME cxx-exercises-design-patterns-proxy--suite COMMAND cxx-exercises-design-patterns-proxy--suite)



