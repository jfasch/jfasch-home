ADD_EXECUTABLE(c++-dynamic-memory 
  run.cc

  c-vs-c++.cc
  valgrind.cc
)
TARGET_LINK_LIBRARIES(c++-dynamic-memory gtest_main)
ADD_TEST(c++-dynamic-memory c++-dynamic-memory)

