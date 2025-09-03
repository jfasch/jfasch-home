ADD_LIBRARY(
  cxx-exercises-switches-sysfs

  switch-sysfs.h
  switch-sysfs.cpp
  )

TARGET_INCLUDE_DIRECTORIES(
  cxx-exercises-switches-sysfs

  PUBLIC
  .
  )

TARGET_LINK_LIBRARIES(
  cxx-exercises-switches-sysfs

  cxx-exercises-switches-core
  hal
  )
