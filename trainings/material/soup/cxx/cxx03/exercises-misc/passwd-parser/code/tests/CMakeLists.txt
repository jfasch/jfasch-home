ADD_EXECUTABLE(
  cxx03--exercises-misc--passwd-parser--code--tests

  suite-passwd-line.cpp
  suite-passwd-error.cpp
  suite-passwd-user.cpp
)

TARGET_LINK_LIBRARIES(
  cxx03--exercises-misc--passwd-parser--code--tests

  cxx03--exercises-misc--passwd-parser--code--lib
  gtest_main 
  )

add_test(NAME cxx03--exercises-misc--passwd-parser--code--tests COMMAND cxx03--exercises-misc--passwd-parser--code--tests)
