ADD_EXECUTABLE(basic basic.cc)
TARGET_LINK_LIBRARIES(basic GTest::GTest)
ADD_TEST(basic basic)
