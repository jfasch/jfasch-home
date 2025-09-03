ADD_LIBRARY(
  cxx-exercises-design-patterns-observer-code

  social-db-observable.h
  social-db-observable.cpp
)  

TARGET_INCLUDE_DIRECTORIES(
  cxx-exercises-design-patterns-observer-code

  PUBLIC
  .
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-design-patterns-observer-code

  cxx-exercises-socialdb
)
