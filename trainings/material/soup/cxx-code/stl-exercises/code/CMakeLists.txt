ADD_LIBRARY(
  cxx-exercises-stl-code

  dummy.cpp

  vector-exercises.cpp
  map-exercises.cpp
  algo-exercises.cpp

  sensor-repo.cpp

  sort-in-place.cpp
  sorted.cpp

  uniq.cpp
  filter.cpp
  filter-odd.cpp
  filter-greater-10.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  cxx-exercises-stl-code

  PUBLIC
  .
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-stl-code

  cxx-exercises-sensors-core
  )
