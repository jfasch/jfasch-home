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

# add_executable(sysprog-eventloop-db-two-sources-eventloop db-two-sources-eventloop.cpp)
# target_link_libraries(sysprog-eventloop-db-two-sources-eventloop 
#   sysprog-eventloop-poll sysprog-eventloop-db)
