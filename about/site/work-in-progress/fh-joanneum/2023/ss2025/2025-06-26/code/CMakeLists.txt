add_executable(fh-2023--2023-06-26-exam-bad-pointer-access bad-pointer-access.cpp)
target_compile_options(fh-2023--2023-06-26-exam-bad-pointer-access PRIVATE -Wno-array-bounds)

add_executable(fh-2023--2023-06-26-exam-bad-cpu-consumption bad-cpu-consumption.cpp)
target_compile_options(fh-2023--2023-06-26-exam-bad-cpu-consumption PRIVATE -Wno-uninitialized -O0)
