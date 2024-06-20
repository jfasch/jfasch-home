ADD_EXECUTABLE(gm-fail fail.cc)
TARGET_LINK_LIBRARIES(gm-fail gtest_main)
add_test(NAME gm-fail COMMAND gm-fail)
SET_TESTS_PROPERTIES(gm-fail PROPERTIES WILL_FAIL true)

ADD_EXECUTABLE(gm-non-fatal non-fatal.cc)
TARGET_LINK_LIBRARIES(gm-non-fatal gtest_main)
add_test(NAME gm-non-fatal COMMAND gm-non-fatal)
SET_TESTS_PROPERTIES(gm-non-fatal PROPERTIES WILL_FAIL true)

ADD_EXECUTABLE(gm-simple simple.cc)
TARGET_LINK_LIBRARIES(gm-simple gtest_main)
add_test(NAME gm-simple COMMAND gm-simple)

# here we use the *linker* to aggregate all tests and the *runner*
# into an exectuable. note that run.cc in no way references any of the
# tests!
ADD_EXECUTABLE(gm-run run.cc tests/fail.cc tests/non-fatal.cc tests/simple.cc)
TARGET_LINK_LIBRARIES(gm-run gtest_main)
add_test(NAME gm-run COMMAND gm-run)
SET_TESTS_PROPERTIES(gm-run PROPERTIES WILL_FAIL true)

# was that to quickly demonstrate the std::hex modifier?
ADD_EXECUTABLE(gm-std-hex std-hex.cc)

