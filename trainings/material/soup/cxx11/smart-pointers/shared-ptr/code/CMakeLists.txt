add_executable(
  c++11-shared-ptr-suite

  basic_creation.cpp
  more_condensed_creation.cpp
  copy.cpp
  refcount_if.cpp
  raw_pointer_get.cpp
  reset.cpp
  reset_exchange.cpp
  custom_deleter.cpp
)
target_link_libraries(c++11-shared-ptr-suite gtest_main)
add_test(NAME c++11-shared-ptr-suite COMMAND c++11-shared-ptr-suite)

add_executable(c++11-shared-ptr-cyclic cyclic.cpp)
