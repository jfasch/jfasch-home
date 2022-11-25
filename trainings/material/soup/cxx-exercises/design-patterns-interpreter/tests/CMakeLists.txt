ADD_EXECUTABLE(
  cxx-exercises-design-patterns-interpreter--suite

  interpreter-suite-literal.cpp
  interpreter-suite-addition.cpp
  interpreter-suite-subtraction.cpp
  interpreter-suite-multiplication.cpp
  interpreter-suite-division.cpp
  interpreter-suite-combined-arith.cpp
  interpreter-suite-variable-not-set.cpp
  interpreter-suite-variable-assignment.cpp
  interpreter-suite-variable-used-as-expression.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-design-patterns-interpreter--suite

  cxx-exercises-design-patterns-interpreter-expressions
  gtest_main 
)
