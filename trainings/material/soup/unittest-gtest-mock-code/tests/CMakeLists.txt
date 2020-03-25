ADD_EXECUTABLE(range-check range-check.cc)
TARGET_LINK_LIBRARIES(range-check GTest::GTest)
ADD_TEST(range-check range-check)
