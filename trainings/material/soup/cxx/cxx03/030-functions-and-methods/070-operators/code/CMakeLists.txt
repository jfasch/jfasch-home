ADD_EXECUTABLE(
  c++03-operator-suite

  eq-global.cpp
  eq-object.cpp

  add-global.cpp
  add-object.cpp

  int-plus-equal.cpp
  plus-equal.cpp

  basic.cpp
)
TARGET_LINK_LIBRARIES(c++03-operator-suite gtest_main)
add_test(NAME c++03-operator-suite COMMAND c++03-operator-suite)

ADD_EXECUTABLE(c++03-ostream-shift-operator c++03-ostream-shift-operator.cpp)
