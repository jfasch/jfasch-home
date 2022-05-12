ADD_EXECUTABLE(c++-lambda tests.cc)
TARGET_LINK_LIBRARIES(c++-lambda gtest_main)

ADD_EXECUTABLE(c++-lambda-thread thread.cc)
TARGET_LINK_LIBRARIES(c++-lambda-thread Threads::Threads)
