ADD_EXECUTABLE(hello-first hello-first.cpp)
TARGET_LINK_LIBRARIES(hello-first hello)
INSTALL(TARGETS hello-first DESTINATION bin)
ADD_TEST(
  NAME hello-first-runs 
  COMMAND hello-first)

ADD_TEST(
  NAME hello-first-has-version
  COMMAND hello-first)
SET_TESTS_PROPERTIES(
  hello-first-has-version
  PROPERTIES PASS_REGULAR_EXPRESSION "Hello World")

ADD_EXECUTABLE(hello-second hello-second.cpp)
TARGET_LINK_LIBRARIES(hello-second hello)
INSTALL(TARGETS hello-second DESTINATION bin)

ADD_EXECUTABLE(hello-third hello-third.cpp)
TARGET_LINK_LIBRARIES(hello-third hello)
INSTALL(TARGETS hello-third DESTINATION bin)
