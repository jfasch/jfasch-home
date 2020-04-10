ADD_EXECUTABLE(gm-c++-smartpointers ownership.cc employee.h)
TARGET_LINK_LIBRARIES(gm-c++-smartpointers GTest::Main)

ADD_EXECUTABLE(gm-lt-sort lt-sort.cc)
