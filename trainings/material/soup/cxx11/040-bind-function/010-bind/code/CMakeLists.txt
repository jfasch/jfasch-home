ADD_EXECUTABLE(
  c++11-bind-suite

  c++11-bind-null-adaptation.cpp
  c++11-bind-one-to-zero-adaptation.cpp
  c++11-bind-minus-hardcoded.cpp
  c++11-bind-minus-swap-params.cpp
  c++11-bind-minus-hardcode-first.cpp
  c++11-bind-functor.cpp
  c++11-bind-lambda.cpp
)
TARGET_LINK_LIBRARIES(c++11-bind-suite gtest_main)

ADD_EXECUTABLE(c++11-bind-distances-origin-manual c++11-bind-distances-origin-manual.cpp)
ADD_EXECUTABLE(c++11-bind-distances-origin-transform c++11-bind-distances-origin-transform.cpp)
ADD_EXECUTABLE(c++11-bind-distances-origin-transform-bind c++11-bind-distances-origin-transform-bind.cpp)
