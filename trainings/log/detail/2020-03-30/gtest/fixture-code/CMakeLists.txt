ADD_EXECUTABLE(predef-environ predef-environ.cc)
TARGET_LINK_LIBRARIES(predef-environ GTest::GTest)

ADD_EXECUTABLE(isolated-environment isolated-environment.cc)
TARGET_LINK_LIBRARIES(isolated-environment GTest::GTest)

ADD_EXECUTABLE(setup-teardown setup-teardown.cc)
TARGET_LINK_LIBRARIES(setup-teardown GTest::GTest)
