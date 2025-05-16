ADD_EXECUTABLE(
  c++11-new-language-features-suite

  c++11-structured_binding_suite--struct_copy.cpp
  c++11-structured_binding_suite--struct_reference.cpp
  c++11-structured_binding_suite--struct_const_reference.cpp
  c++11-structured_binding_suite--tuple_copy.cpp
  c++11-structured_binding_suite--tuple_reference.cpp
  c++11-structured_binding_suite--tuple_const_reference.cpp
  c++11-structured_binding_suite--array_copy.cpp
  c++11-structured_binding_suite--array_reference.cpp
  c++11-structured_binding_suite--array_const_reference.cpp

  c++11-lambda_capture_suite--explicit_by_copy.cpp
  c++11-lambda_capture_suite--explicit_by_reference.cpp
  c++11-lambda_capture_suite--explicit_mixed.cpp
  c++11-lambda_capture_suite--initialized_capture.cpp
  c++11-lambda_capture_suite--all_by_reference.cpp
  c++11-lambda_capture_suite--all_by_copy.cpp
  c++11-lambda_capture_suite--all_by_copy_except.cpp
  c++11-lambda_capture_suite--this_capture.cpp

  initializer-list.cpp
)
TARGET_LINK_LIBRARIES(c++11-new-language-features-suite gtest_main)
add_test(NAME c++11-new-language-features-suite COMMAND c++11-new-language-features-suite)

# ----------------------------------------
# lambda
# ----------------------------------------
ADD_EXECUTABLE(c++11-lambda-capture c++11-lambda-capture.cpp)
ADD_EXECUTABLE(c++11-lambda-capture-handwritten c++11-lambda-capture-handwritten.cpp)
ADD_EXECUTABLE(c++11-lambda-capture-reference c++11-lambda-capture-reference.cpp)
ADD_EXECUTABLE(c++11-lambda-capture-handwritten-reference c++11-lambda-capture-handwritten-reference.cpp)
ADD_EXECUTABLE(c++11-lambda-capture-handwritten-reference-gosh c++11-lambda-capture-handwritten-reference-gosh.cpp)
ADD_EXECUTABLE(c++11-lambda-capture-handwritten-reference-gosh-boom c++11-lambda-capture-handwritten-reference-gosh-boom.cpp)

