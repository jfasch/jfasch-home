ADD_EXECUTABLE(
  c++11-filesystem-suite

  path_compose_compare.cpp
  path_compose_compare_2.cpp
  path_abs_rel.cpp
  path_iteration.cpp
  create_directory_error.cpp
  create_directory_single.cpp
  create_directory_multiple.cpp
  is_xxx.cpp
  directory_iterator.cpp
  recursive_directory_iterator.cpp
  )

TARGET_LINK_LIBRARIES(
  c++11-filesystem-suite

  gtest_main
  )

