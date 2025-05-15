add_executable(c++11-constinit-pre-siof-error 

  main.cpp 

  point.h

  global-point-depends.h
  global-point-depends.cpp 

  global-point-standalone.h
  global-point-standalone.cpp
)

add_executable(c++11-constinit-pre-siof-ok

  main.cpp 

  point.h

  global-point-standalone.h
  global-point-standalone.cpp

  global-point-depends.h
  global-point-depends.cpp 
)
