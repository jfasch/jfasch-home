ADD_EXECUTABLE(
  heating-demo-v1

  heating-demo-v1.cpp
  )
TARGET_LINK_LIBRARIES(heating-demo-v1 design-patterns-trainer)

ADD_EXECUTABLE(
  heating-demo-v2

  heating-demo-v2.cpp
  )
TARGET_LINK_LIBRARIES(heating-demo-v2 design-patterns-trainer)

ADD_EXECUTABLE(
  heating-demo-v3

  heating-demo-v3.cpp
  )
TARGET_LINK_LIBRARIES(heating-demo-v3 design-patterns-trainer)

ADD_EXECUTABLE(
  heating-tests

  sensor-reader-suite.cpp
  )
TARGET_LINK_LIBRARIES(heating-tests

  gtest_main
  design-patterns-trainer
  )
