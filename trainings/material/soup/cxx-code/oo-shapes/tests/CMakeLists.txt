ADD_EXECUTABLE(
  cxx-exercises-shapes--suite

#  initial-failure.cpp

  point_suite-ctor_and_getters.cpp
  point_suite-ctor_and_getters_const.cpp
  point_suite-default_ctor.cpp
  point_suite-equal_method.cpp
  point_suite-equal_method_const.cpp
  point_suite-operator_equals.cpp
  point_suite-operator_equals_const.cpp
  point_suite-move_method.cpp
  point_suite-operator_plus_equals.cpp
  point_suite-add_method.cpp
  point_suite-add_method_const.cpp
  point_suite-operator_plus.cpp
  point_suite-operator_plus_const.cpp
  
  circle_suite-ctor_and_getters.cpp
  circle_suite-ctor_and_getters_using_operator_equals.cpp
  circle_suite-area.cpp
  circle_suite-area_const.cpp
  
  square_suite-ctor_and_getters.cpp
  square_suite-ctor_and_getters_using_operator_equals.cpp
  square_suite-area.cpp
  square_suite-area_const.cpp
  
  shape_suite-circle_is_a_shape.cpp
  shape_suite-square_is_a_shape.cpp
  shape_suite-area_is_shape_functionality__circle.cpp
  shape_suite-area_is_shape_functionality__square.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-shapes--suite

  cxx-exercises-shapes
  gtest_main 
)
