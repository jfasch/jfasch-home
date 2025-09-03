add_executable(
  c++11-structured-binding-suite

  c++11-structured_binding_suite--struct_copy.cpp
  c++11-structured_binding_suite--struct_reference.cpp
  c++11-structured_binding_suite--struct_const_reference.cpp
  c++11-structured_binding_suite--tuple_copy.cpp
  c++11-structured_binding_suite--tuple_reference.cpp
  c++11-structured_binding_suite--tuple_const_reference.cpp
  c++11-structured_binding_suite--array_copy.cpp
  c++11-structured_binding_suite--array_reference.cpp
  c++11-structured_binding_suite--array_const_reference.cpp
)
target_link_libraries(c++11-structured-binding-suite gtest_main)
add_test(NAME c++11-structured-binding-suite COMMAND c++11-structured-binding-suite)
