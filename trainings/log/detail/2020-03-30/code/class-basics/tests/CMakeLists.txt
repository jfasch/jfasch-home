ADD_EXECUTABLE(gm-point-tests run.cc c-point-tests.cc cc-point-tests.cc)
TARGET_LINK_LIBRARIES(gm-point-tests gm-point gtest_main)
add_test(NAME gm-point-tests COMMAND gm-point-tests)

ADD_EXECUTABLE(gm-copy-demo gm-copy-demo.cc)
