add_executable(
  cxx11-smartptr-introduction-bug-leak-early-return
  main.cpp
  f.h f.cpp
  crunch.h crunch.cpp)
target_compile_options(cxx11-smartptr-introduction-bug-leak-early-return PRIVATE -Wno-unused-variable)

