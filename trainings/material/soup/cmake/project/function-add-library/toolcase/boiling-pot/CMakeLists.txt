my_add_library(
  NAME boiling-pot

  PUBLIC_HEADERS

    boiling-pot.h

  SOURCES

    boiling-pot.cpp
)

target_link_libraries(boiling-pot base)
