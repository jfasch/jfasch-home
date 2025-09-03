ADD_EXECUTABLE(
  cxx-exercises-design-patterns-observer--suite

  observer-suite-register-one.cpp
  observer-suite-register-many.cpp
  observer-suite-register-duplicate.cpp
  observer-suite-unregister.cpp
  observer-suite-unregister-not-registered.cpp
)

TARGET_LINK_LIBRARIES(
  cxx-exercises-design-patterns-observer--suite

  cxx-exercises-design-patterns-observer-code
  gtest_main 
)

add_test(NAME cxx-exercises-design-patterns-observer--suite COMMAND cxx-exercises-design-patterns-observer--suite)




