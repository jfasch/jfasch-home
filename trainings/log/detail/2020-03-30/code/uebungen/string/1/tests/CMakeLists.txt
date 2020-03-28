ADD_EXECUTABLE(string-tests
  run.cc

  string-basic.cc
)
TARGET_LINK_LIBRARIES(string-tests GTest::GTest)
