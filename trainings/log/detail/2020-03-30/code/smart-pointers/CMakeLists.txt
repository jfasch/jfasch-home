ADD_EXECUTABLE(gm-c++-smartpointers ownership.cc employee.h)
TARGET_LINK_LIBRARIES(gm-c++-smartpointers gtest_main)
add_test(NAME gm-c++-smartpointers COMMAND gm-c++-smartpointers)

ADD_EXECUTABLE(gm-lt-sort lt-sort.cc)
