add_executable(cxx-inher-oo-destructor-nonvirtual-straightforward

  sensors.h
  main.cpp
)

add_executable(cxx-inher-oo-destructor-nonvirtual-base-delete

  sensors.h
  base-delete.cpp
)

target_compile_options(cxx-inher-oo-destructor-nonvirtual-base-delete

  PUBLIC -Wno-error -Wno-all
)
