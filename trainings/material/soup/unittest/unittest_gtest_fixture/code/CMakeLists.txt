ADD_EXECUTABLE(predef-environ predef-environ.cc)
TARGET_LINK_LIBRARIES(predef-environ gtest_main)
add_test(NAME predef-environ COMMAND predef-environ)

ADD_EXECUTABLE(isolated-environment isolated-environment.cc)
TARGET_LINK_LIBRARIES(isolated-environment gtest_main)
add_test(NAME isolated-environment COMMAND isolated-environment)

ADD_EXECUTABLE(setup-teardown setup-teardown.cc)
TARGET_LINK_LIBRARIES(setup-teardown gtest_main)
add_test(NAME setup-teardown COMMAND setup-teardown)
