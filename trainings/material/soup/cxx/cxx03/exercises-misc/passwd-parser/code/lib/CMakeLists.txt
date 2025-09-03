ADD_LIBRARY(
  cxx03--exercises-misc--passwd-parser--code--lib

  parse-passwd.h
  parse-passwd.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  cxx03--exercises-misc--passwd-parser--code--lib

  PUBLIC
  .
)
