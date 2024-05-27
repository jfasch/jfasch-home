ADD_EXECUTABLE(
  cxx03--exercises-misc--passwd-parser--code--tests

  suite-passwd.cpp
)

TARGET_LINK_LIBRARIES(
  cxx03--exercises-misc--passwd-parser--code--tests

  cxx03--exercises-misc--passwd-parser--code--lib
  cxx-exercises-fixtures
  gtest_main 
  )

