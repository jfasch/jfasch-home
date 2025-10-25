# --- library ---
add_library(
  sysprog-eventloop-commit-rollback

  commit-rollback.h
  commit-rollback.cpp
)
target_include_directories(
  sysprog-eventloop-commit-rollback
  PUBLIC
  .
)
target_link_libraries(
  sysprog-eventloop-commit-rollback

  sysprog-eventloop-poll
)

# --- program ---
add_executable(
  sysprog-eventloop-db-commit-rollback
  main.cpp
)
target_link_libraries(
  sysprog-eventloop-db-commit-rollback

  sysprog-eventloop-poll
  sysprog-eventloop-graceful-term
  sysprog-eventloop-commit-rollback
  sysprog-eventloop-db
)

