add_executable(
  cxx11-smartptr-introduction-bug-expect-ownership-xfer-but-no
  main.cpp
  f.h f.cpp
  crunch.h crunch.cpp
)
target_compile_options(cxx11-smartptr-introduction-bug-expect-ownership-xfer-but-no PRIVATE -Wno-unused-variable)

