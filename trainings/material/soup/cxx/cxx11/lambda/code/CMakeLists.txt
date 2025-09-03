add_executable(c++11-lambda-capture c++11-lambda-capture.cpp)
add_executable(c++11-lambda-capture-handwritten c++11-lambda-capture-handwritten.cpp)
add_executable(c++11-lambda-capture-reference c++11-lambda-capture-reference.cpp)
add_executable(c++11-lambda-capture-handwritten-reference c++11-lambda-capture-handwritten-reference.cpp)
add_executable(c++11-lambda-capture-handwritten-reference-gosh c++11-lambda-capture-handwritten-reference-gosh.cpp)
add_executable(c++11-lambda-capture-handwritten-reference-gosh-boom c++11-lambda-capture-handwritten-reference-gosh-boom.cpp)

add_executable(c++11-lambda-generic-lambda generic-lambda.cpp)
add_executable(c++11-lambda-abbreviated-function-template abbreviated-function-template.cpp)
add_executable(c++11-lambda-template-lambda template-lambda.cpp)

add_executable(
  c++11-lambda-suite

  c++11-lambda_capture_suite--explicit_by_copy.cpp
  c++11-lambda_capture_suite--explicit_by_reference.cpp
  c++11-lambda_capture_suite--explicit_mixed.cpp
  c++11-lambda_capture_suite--initialized_capture.cpp
  c++11-lambda_capture_suite--all_by_reference.cpp
  c++11-lambda_capture_suite--all_by_copy.cpp
  c++11-lambda_capture_suite--all_by_copy_except.cpp
  c++11-lambda_capture_suite--this_capture.cpp
)
target_link_libraries(c++11-lambda-suite gtest_main)
add_test(NAME c++11-lambda-suite COMMAND c++11-lambda-suite)

