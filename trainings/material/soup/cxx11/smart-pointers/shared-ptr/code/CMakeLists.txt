add_executable(
  c++11-shared-ptr-suite

  basic_creation.cpp
  more_condensed_creation.cpp
  copy.cpp
  refcount-if.cpp

#   shared-ptr-basic.cpp
#   shared-ptr-basic-make_shared.cpp
#   shared-ptr-cyclic.cpp
)
target_link_libraries(c++11-shared-ptr-suite gtest_main)
add_test(NAME c++11-shared-ptr-suite COMMAND c++11-shared-ptr-suite)
