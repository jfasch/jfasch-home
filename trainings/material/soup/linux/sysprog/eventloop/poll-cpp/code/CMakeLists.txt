add_library(sysprog-eventloop-poll

  eventloop.h
  eventloop.cpp
)
add_executable(
  sysprog-eventloop-poll-tests

  basic.cpp
)
target_link_libraries(
  sysprog-eventloop-poll-tests

  sysprog-eventloop-poll
  gtest_main 
)
add_test(
  NAME sysprog-eventloop-poll-tests
  COMMAND sysprog-eventloop-poll-tests
)
