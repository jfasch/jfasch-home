# --- library ---
add_library(
  sysprog-eventloop-graceful-term

  graceful-term.h
  graceful-term.cpp
)
target_include_directories(
  sysprog-eventloop-graceful-term
  PUBLIC
  .
)
target_link_libraries(
  sysprog-eventloop-graceful-term
  sysprog-eventloop-poll
)

# --- program ---
add_executable(
  sysprog-eventloop-db-graceful-termination 
  main.cpp
)
target_link_libraries(
  sysprog-eventloop-db-graceful-termination
  sysprog-eventloop-poll
  sysprog-eventloop-graceful-term
  sysprog-eventloop-db
)
