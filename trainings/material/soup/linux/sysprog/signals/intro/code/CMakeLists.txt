add_executable(sysprog-signals-stupid stupid.cpp)
add_executable(sysprog-signals-segv segv.cpp)
add_executable(sysprog-signals-fpe fpe.cpp)
target_compile_options(sysprog-signals-fpe PRIVATE -Wno-div-by-zero)
