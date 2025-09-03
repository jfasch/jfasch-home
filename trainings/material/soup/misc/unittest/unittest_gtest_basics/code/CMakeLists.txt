ADD_EXECUTABLE(simple simple.cc)
TARGET_LINK_LIBRARIES(simple gtest_main)
ADD_TEST(simple simple)

ADD_EXECUTABLE(self-contained self-contained.cc)
TARGET_LINK_LIBRARIES(self-contained gtest_main)
ADD_TEST(self-contained self-contained)

ADD_EXECUTABLE(fail fail.cc)
TARGET_LINK_LIBRARIES(fail gtest_main)
ADD_TEST(fail fail)

ADD_EXECUTABLE(assert assert.cc)
TARGET_LINK_LIBRARIES(assert gtest_main)
ADD_TEST(assert assert)

ADD_EXECUTABLE(expect expect.cc)
TARGET_LINK_LIBRARIES(expect gtest_main)
ADD_TEST(expect expect)

ADD_EXECUTABLE(fail-with-message fail-with-message.cc)
TARGET_LINK_LIBRARIES(fail-with-message gtest_main)
ADD_TEST(fail-with-message fail-with-message)

ADD_EXECUTABLE(
  run-tests

  tests/self-contained.cc
  tests/fail.cc
  tests/assert.cc
  tests/expect.cc
  )

TARGET_LINK_LIBRARIES(run-tests gtest_main)
ADD_TEST(run-tests run-tests)

# these will fail. they are only demos, so don't fail the entire
# build.
SET_TESTS_PROPERTIES(
  fail assert expect fail-with-message run-tests 
  PROPERTIES WILL_FAIL true)

