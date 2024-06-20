add_library(
  boiling-pot

  boiling-pot.cpp
  boiling-pot.h
)
target_include_directories(boiling-pot INTERFACE .)
target_link_libraries(boiling-pot base)
install(TARGETS boiling-pot DESTINATION lib)
install(
  FILES

  boiling-pot.h

  DESTINATION include)
