ADD_EXECUTABLE(gm-fail fail.cc)
TARGET_LINK_LIBRARIES(gm-fail GTest::GTest)
ADD_TEST(gm-fail gm-fail)
SET_TESTS_PROPERTIES(gm-fail PROPERTIES WILL_FAIL true)

ADD_EXECUTABLE(gm-non-fatal non-fatal.cc)
TARGET_LINK_LIBRARIES(gm-non-fatal GTest::GTest)
ADD_TEST(gm-non-fatal gm-non-fatal)
SET_TESTS_PROPERTIES(gm-non-fatal PROPERTIES WILL_FAIL true)

ADD_EXECUTABLE(gm-simple simple.cc)
TARGET_LINK_LIBRARIES(gm-simple GTest::GTest)
ADD_TEST(gm-simple gm-simple)

# here we use the *linker* to aggregate all tests and the *runner*
# into an exectuable. note that run.cc in no way references any of the
# tests!
ADD_EXECUTABLE(gm-run run.cc tests/fail.cc tests/non-fatal.cc tests/simple.cc)
TARGET_LINK_LIBRARIES(gm-run GTest::GTest)
ADD_TEST(gm-run gm-run)
SET_TESTS_PROPERTIES(gm-run PROPERTIES WILL_FAIL true)

# was that to quickly demonstrate the std::hex modifier?
ADD_EXECUTABLE(gm-std-hex std-hex.cc)

