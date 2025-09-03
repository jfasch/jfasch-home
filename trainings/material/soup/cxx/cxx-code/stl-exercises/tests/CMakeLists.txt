ADD_EXECUTABLE(
  cxx-exercises-stl--suite

  # initial-failure.cpp

  test-vector-append.cpp
  test-vector-join.cpp

  test-map-insert.cpp
  test-map-insert_check_duplicate.cpp
  test-map-insert_remove_by_key.cpp
  test-map-find.cpp

  test-algo-copy_into_vector.cpp
  test-algo-find_in_vector.cpp
  test-algo-sort-in-place.cpp
  test-algo-sorted.cpp

  test-uniq.cpp
  test-filter-odd.cpp
  test-filter-greater-10.cpp
  test-filter-generic.cpp

  test-sensor_repository_insert.cpp
  test-sensor_repository_lookup_positive.cpp
  test-sensor_repository_lookup_negative.cpp
  test-sensor_repository_remove.cpp
  test-sensor_repository_size_const.cpp
  test-sensor_repository_insert_duplicate.cpp
  test-sensor_repository_remove_nonexisting.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-stl--suite

  cxx-exercises-stl-code
  gtest_main 
)

add_test(NAME cxx-exercises-stl--suite COMMAND cxx-exercises-stl--suite)
