ADD_LIBRARY(
  cxx-exercises-fixtures

  fixture-tmpdir.h
  fixture-tmpdir.cpp

  fixture-tmpdir-cwd.h
  fixture-tmpdir-cwd.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  cxx-exercises-fixtures

  PUBLIC
  .
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-fixtures

  gtest
)  
