ADD_EXECUTABLE(simple simple.cc)
TARGET_LINK_LIBRARIES(simple GTest::GTest)

ADD_EXECUTABLE(self-contained self-contained.cc)
TARGET_LINK_LIBRARIES(self-contained GTest::GTest)

ADD_EXECUTABLE(fail fail.cc)
TARGET_LINK_LIBRARIES(fail GTest::GTest)

ADD_EXECUTABLE(assert assert.cc)
TARGET_LINK_LIBRARIES(assert GTest::GTest)

ADD_EXECUTABLE(expect expect.cc)
TARGET_LINK_LIBRARIES(expect GTest::GTest)

ADD_EXECUTABLE(run-tests 
  run-tests.cc
  tests/self-contained.cc
  tests/fail.cc
  tests/assert.cc
  tests/expect.cc
  )
TARGET_LINK_LIBRARIES(run-tests GTest::GTest)
