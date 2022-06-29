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


  point3d-default_ctor.cpp
  point3d-coordinates_ctor.cpp
  point3d-operator_eq_ne.cpp
  point3d-operator_pluseq.cpp
  point3d-operator_minuseq.cpp
  point3d-operator_plus.cpp
  point3d-operator_minus.cpp
  point3d-operator_unary_minus.cpp
  point3d-operator_ostream.cpp
  point3d-abs.cpp
  point3d-distance.cpp

  cuboid-default_ctor.cpp
  cuboid-point_whl_ctor.cpp
  cuboid-operator_eq_ne.cpp
  cuboid-operator_pluseq.cpp
  cuboid-operator_minuseq.cpp
  cuboid-operator_plus.cpp
  cuboid-operator_minus.cpp
  cuboid-operator_ostream.cpp
  cuboid-surface.cpp
  cuboid-volume.cpp
)

TARGET_LINK_LIBRARIES(
  c++03-exercises-fh-suite 

  PUBLIC

  c++03-exercises-fh-shapes
  gtest_main
)

