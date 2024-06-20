SET(GROUPNAME "trainer-solution")

ADD_LIBRARY(gm-mystring-${GROUPNAME} mystring.h mystring.cpp)
TARGET_INCLUDE_DIRECTORIES(gm-mystring-${GROUPNAME} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

ADD_EXECUTABLE(gm-mystring-${GROUPNAME}-tests ../test.cc)
TARGET_LINK_LIBRARIES(gm-mystring-${GROUPNAME}-tests gm-mystring-${GROUPNAME} gtest_main)
add_test(NAME gm-mystring-${GROUPNAME}-tests COMMAND gm-mystring-${GROUPNAME}-tests)
