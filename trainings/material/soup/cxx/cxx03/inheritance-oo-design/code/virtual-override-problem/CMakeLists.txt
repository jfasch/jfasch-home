add_executable(cxx-inher-oo-virtual-override-problem

  sensors.h
  main.cpp
)

target_compile_options(cxx-inher-oo-virtual-override-problem
  
  PUBLIC -Wno-error -Wno-all
)
