add_executable(
  cxx11-smartptr-introduction-bug-leak-exception
  main.cpp
  f.h f.cpp
  crunch.h crunch.cpp)
target_compile_options(cxx11-smartptr-introduction-bug-leak-exception PRIVATE -Wno-unused-variable)
