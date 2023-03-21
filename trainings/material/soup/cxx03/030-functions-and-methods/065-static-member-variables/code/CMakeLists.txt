ADD_EXECUTABLE(
  c++-pure-c-extern

  main-extern-declaration.cpp
  extern-definition-plain.cpp
  )

#ADD_EXECUTABLE(
#  odr-duplicate
#
#  odr-duplicate-main.cpp
#  definition1.cpp
#  definition2.cpp
#  )

ADD_EXECUTABLE(
  odr-unused

  odr-unused-but-declared-main.cpp
  )

ADD_EXECUTABLE(
  c++-odr-used
  
  main-includes-extern-declaration-uses-global.cpp
  extern-declaration.h
  extern-definition.cpp
  )

ADD_EXECUTABLE(
  c++-static-class-member-good-old
  
  main-static-class-member-good-old.cpp
  class-good-old.h
  class-good-old.cpp
  )

ADD_EXECUTABLE(
  c++-static-inline-member
  
  main-static-inline-member.cpp
  class-static-inline.h
  )
