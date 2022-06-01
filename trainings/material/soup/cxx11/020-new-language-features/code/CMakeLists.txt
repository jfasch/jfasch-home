ADD_EXECUTABLE(
  c++11-new-language-features-suite

  auto-decltype.cpp
)
TARGET_LINK_LIBRARIES(c++11-new-language-features-suite gtest_main)


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
