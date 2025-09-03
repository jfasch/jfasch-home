add_executable(
  cxx11-smartptr-introduction-bug-no-expect-ownership-xfer-but-yes
  main.cpp
  f.h f.cpp
  crunch.h crunch.cpp)
target_compile_options(cxx11-smartptr-introduction-bug-no-expect-ownership-xfer-but-yes PRIVATE -Wno-unused-variable)
