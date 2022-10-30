ADD_EXECUTABLE(
  design-patterns-c++-trainee-exercises-suite

  trainee-dummy-suite.cpp

  adapter-suite.cpp

  decorator-suite-starting-point.cpp
  decorator-suite-const-sensor-added-functionality.cpp
  decorator-suite-random-sensor-added-functionality.cpp
  decorator-suite-const-sensor-is-a-sensor.cpp
  decorator-suite-random-sensor-is-a-sensor.cpp
  decorator-suite-decorated-used-in-legacy.cpp

  proxy-round-suite.cpp
  proxy-remote-suite.cpp

  composite-suite-basic.cpp
  composite-suite-initializer-list.cpp

  command-suite-insert.cpp
  command-suite-insert-by-base.cpp
  command-suite-find.cpp
  command-suite-drop.cpp
  command-suite-notfound.cpp
  command-suite-notinserted.cpp
  command-suite-bulk-insert.cpp
  command-suite-bulk-insert--std_initializer_list.cpp

  interpreter-suite-literal.cpp
  interpreter-suite-addition.cpp
  interpreter-suite-subtraction.cpp
  interpreter-suite-multiplication.cpp
  interpreter-suite-division.cpp
  interpreter-suite-combined-arith.cpp
  interpreter-suite-variable-not-set.cpp
  interpreter-suite-variable-assignment.cpp
  interpreter-suite-variable-used-as-expression.cpp

  observer-suite-register-one.cpp
  observer-suite-register-many.cpp
  observer-suite-register-duplicate.cpp
  observer-suite-unregister.cpp
  observer-suite-unregister-not-registered.cpp

  abstract-factory-suite-vendor1.cpp
  abstract-factory-suite-vendor2.cpp
)

TARGET_LINK_LIBRARIES(
  design-patterns-c++-trainee-exercises-suite

  gtest_main 
  design-patterns-trainee
  design-patterns-trainer
  Threads::Threads
)
