ADD_EXECUTABLE(
  cxx-exercises-utilities--suite

  server-thread-suite.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-utilities--suite

  gtest_main 
  cxx-exercises-utilities
  Threads::Threads
)
