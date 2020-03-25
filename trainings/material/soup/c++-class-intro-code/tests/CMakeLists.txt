ADD_EXECUTABLE(c++-class-intro-tests 
  run.cc

  c-point-tests.cc
  cc-point-tests.cc
)
TARGET_LINK_LIBRARIES(c++-class-intro-tests c-point GTest::GTest)
ADD_TEST(c++-class-intro-tests c++-class-intro-tests)
