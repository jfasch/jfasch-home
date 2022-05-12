ADD_EXECUTABLE(predef-environ predef-environ.cc)
TARGET_LINK_LIBRARIES(predef-environ gtest_main)

ADD_EXECUTABLE(isolated-environment isolated-environment.cc)
TARGET_LINK_LIBRARIES(isolated-environment gtest_main)

ADD_EXECUTABLE(setup-teardown setup-teardown.cc)
TARGET_LINK_LIBRARIES(setup-teardown gtest_main)
