add_executable(c++11-memory-model-load-modify-store load-modify-store.cpp)
target_compile_options(c++11-memory-model-load-modify-store PUBLIC -O0)

add_executable(c++11-memory-model-list-mt-unsafe list-mt-unsafe.cpp)
target_compile_options(c++11-memory-model-list-mt-unsafe PUBLIC -O0)

add_executable(c++11-memory-model-list-mt-mutex list-mt-mutex.cpp)
target_compile_options(c++11-memory-model-list-mt-mutex PUBLIC -O0)

add_executable(c++11-memory-model-list-mt-spinlock list-mt-spinlock.cpp)
target_compile_options(c++11-memory-model-list-mt-spinlock PUBLIC -O0)

add_executable(c++11-memory-model-load-modify-store-seq-cst load-modify-store-seq-cst.cpp)
target_compile_options(c++11-memory-model-load-modify-store-seq-cst PUBLIC -O0)
