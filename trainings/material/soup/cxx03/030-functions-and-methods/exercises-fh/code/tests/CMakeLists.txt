ADD_EXECUTABLE(
  c++03-exercises-fh-suite

  point-default-ctor.cpp
  point-xy.cpp
  point-operator-eq-ne.cpp
  point-operator-pluseq.cpp
  point-operator-plus.cpp
  point-operator-unary-minus.cpp
  point-operator-ostream.cpp

  rectangle-default-ctor.cpp
  rectangle-coordinates.cpp
  rectangle-area.cpp
  rectangle-operator-eq-ne.cpp
  rectangle-operator-plus-equal-vec.cpp
  rectangle-plus-vec.cpp
  rectangle-operator-ostream.cpp
)

TARGET_LINK_LIBRARIES(
  c++03-exercises-fh-suite 

  PUBLIC

  c++03-exercises-fh-shapes
  gtest_main
)

