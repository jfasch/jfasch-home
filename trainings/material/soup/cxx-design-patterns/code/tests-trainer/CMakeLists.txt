ADD_EXECUTABLE(
  design-patterns-c++-trainer-exercises-suite

  server-thread-suite.cpp
  social-db-suite.cpp
)

TARGET_LINK_LIBRARIES(
  design-patterns-c++-trainer-exercises-suite

  gtest_main 
  design-patterns-trainer
  Threads::Threads
)
