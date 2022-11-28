ADD_LIBRARY(
  cxx-exercises-fixtures

  fixture-tmpdir.h

  dummy.c     # must have at least one compliation unit in a library
)

TARGET_INCLUDE_DIRECTORIES(
  cxx-exercises-fixtures

  PUBLIC
  .
)
