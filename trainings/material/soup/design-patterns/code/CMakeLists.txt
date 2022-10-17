ADD_EXECUTABLE(
  design-patterns-c++-exercises-suite

  singleton.cpp
)

TARGET_LINK_LIBRARIES(design-patterns-c++-exercises-suite gtest_main Threads::Threads)
