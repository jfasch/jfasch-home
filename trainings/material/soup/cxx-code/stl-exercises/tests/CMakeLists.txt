ADD_EXECUTABLE(
  cxx-exercises-stl--suite

  # initial-failure.cpp
  test-sensor-repo.cpp

  test-sort-in-place.cpp
  test-sorted.cpp

  test-uniq.cpp
  test-filter-odd.cpp
  test-filter-greater-10.cpp
  test-filter.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-stl--suite

  cxx-exercises-stl-code
  gtest_main 
)
