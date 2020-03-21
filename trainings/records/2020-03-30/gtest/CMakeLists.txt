ADD_EXECUTABLE(simple simple.cc)
ADD_EXECUTABLE(self-contained self-contained.cc)
ADD_EXECUTABLE(fail fail.cc)
ADD_EXECUTABLE(assert assert.cc)
ADD_EXECUTABLE(expect expect.cc)


TARGET_LINK_LIBRARIES(simple GTest::GTest)
TARGET_LINK_LIBRARIES(self-contained GTest::GTest)
TARGET_LINK_LIBRARIES(fail GTest::GTest)
TARGET_LINK_LIBRARIES(assert GTest::GTest)
TARGET_LINK_LIBRARIES(expect GTest::GTest)
