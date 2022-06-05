ADD_EXECUTABLE(
  c++11-new-language-features-suite

  c++11-range-based-for-suite--map-pre-11.cpp
  c++11-range-based-for-suite--map-basic.cpp
  c++11-range-based-for-suite--map-basic-const-auto-reference.cpp
  c++11-range-based-for-suite--map-unpack-copy.cpp
  c++11-range-based-for-suite--map-unpack-reference.cpp
  c++11-range-based-for-suite--map-unpack-const-reference.cpp

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

# ----------------------------------------
# lambda
# ----------------------------------------
ADD_EXECUTABLE(c++11-lambda-capture c++11-lambda-capture.cpp)
ADD_EXECUTABLE(c++11-lambda-capture-handwritten c++11-lambda-capture-handwritten.cpp)
ADD_EXECUTABLE(c++11-lambda-capture-reference c++11-lambda-capture-reference.cpp)
ADD_EXECUTABLE(c++11-lambda-capture-handwritten-reference c++11-lambda-capture-handwritten-reference.cpp)
ADD_EXECUTABLE(c++11-lambda-capture-handwritten-reference-gosh c++11-lambda-capture-handwritten-reference-gosh.cpp)
ADD_EXECUTABLE(c++11-lambda-capture-handwritten-reference-gosh-boom c++11-lambda-capture-handwritten-reference-gosh-boom.cpp)

# ----------------------------------------
# auto, decltype
# ----------------------------------------
ADD_EXECUTABLE(c++11-auto-most-basic c++11-auto-most-basic.cpp)
ADD_EXECUTABLE(c++11-auto-ref-pitfall c++11-auto-ref-pitfall.cpp)
ADD_EXECUTABLE(c++11-auto-ref c++11-auto-ref.cpp)
ADD_EXECUTABLE(c++11-auto-const-ref c++11-auto-const-ref.cpp)
ADD_EXECUTABLE(c++11-auto-pointer c++11-auto-pointer.cpp)
ADD_EXECUTABLE(c++11-auto-array c++11-auto-array.cpp)

# ----------------------------------------
# override
# ----------------------------------------
ADD_EXECUTABLE(c++11-override-ok c++11-override-ok.cpp)
ADD_EXECUTABLE(c++11-override-omit-const c++11-override-omit-const.cpp)
# ADD_EXECUTABLE(c++11-override-keyword c++11-override-keyword.cpp)

# ----------------------------------------
# final
# ----------------------------------------
#ADD_EXECUTABLE(c++11-final-class c++11-final-class.cpp)
#ADD_EXECUTABLE(c++11-final-method c++11-final-method.cpp)

# ----------------------------------------
# = delete
# ----------------------------------------
ADD_EXECUTABLE(c++11-delete-bogus-copy c++11-delete-bogus-copy.cpp)
#ADD_EXECUTABLE(c++11-delete-private-copy c++11-delete-private-copy.cpp)
#ADD_EXECUTABLE(c++11-delete-delete-copy c++11-delete-delete-copy.cpp)

# ----------------------------------------
# = default
# ----------------------------------------
# ADD_EXECUTABLE(c++11-default-missing c++11-default-missing.cpp)
ADD_EXECUTABLE(c++11-default-explicit c++11-default-explicit.cpp)
ADD_EXECUTABLE(c++11-default-default c++11-default-default.cpp)
