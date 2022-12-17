ADD_EXECUTABLE(
  cxx-exercises-shapes--suite

  point-suite.cpp
  circle-suite.cpp
  square-suite.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-shapes--suite

  cxx-exercises-shapes
  gtest_main 
)
