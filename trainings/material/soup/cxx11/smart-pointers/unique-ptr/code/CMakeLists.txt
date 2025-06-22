add_executable(
  c++11-unique-ptr-suite

  basic_leak_prevention.cpp
  more_condensed_creation.cpp
  # copy_inhibited.cpp
  # pass_by_copy_inhibited.cpp
  temporary_object_moved.cpp
  pass_by_copy_explicit_move.cpp
  is_a_pointer.cpp
  raw_pointer_get.cpp
  raw_pointer_release.cpp
  reset.cpp
  reset_exchange.cpp
  custom_deleter.cpp
)
target_link_libraries(c++11-unique-ptr-suite gtest_main)
add_test(NAME c++11-unique-ptr-suite COMMAND c++11-unique-ptr-suite)
