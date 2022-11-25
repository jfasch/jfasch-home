ADD_EXECUTABLE(
  cxx-exercises-socialdb--suite

  social-db-suite.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-socialdb--suite

  gtest_main 
  cxx-exercises-socialdb
)
