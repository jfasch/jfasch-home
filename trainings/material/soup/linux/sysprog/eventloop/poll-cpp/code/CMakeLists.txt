# --- library ---
add_library(
  sysprog-eventloop-poll

  eventloop.h
  eventloop.cpp
  udp-db.h
  udp-db.cpp
  stdin-db.h
  stdin-db.cpp
)
target_include_directories(
  sysprog-eventloop-poll
  PUBLIC
  .
)
target_link_libraries(
  sysprog-eventloop-poll
  sysprog-eventloop-db
)

# --- program ---
add_executable(
  sysprog-eventloop-db-two-sources-eventloop 

  main.cpp
)
target_link_libraries(
  sysprog-eventloop-db-two-sources-eventloop 

  sysprog-eventloop-poll 
  sysprog-eventloop-db
)

# --- tests ---
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
