add_executable(c++11-thread-atomic-shared-ptr-safe safe.cpp)
add_executable(c++11-thread-atomic-shared-ptr-safe-future-spoiler safe-future-spoiler.cpp)
add_executable(c++11-thread-atomic-shared-ptr-safe-future safe-future.cpp)
add_executable(c++11-thread-atomic-shared-ptr-problem problem.cpp)

add_executable(c++11-thread-atomic-shared-ptr-solution-atomic-function-specialization solution-atomic-function-specialization.cpp)
# upgrade to gcc 15.1.1:
# /home/jfasch/My-Projects/jfasch-home/trainings/material/soup/cxx11/multithreading/atomic-shared-ptr/code/solution-atomic-function-specialization.cpp:9:30: error: ‘void std::atomic_store(shared_ptr<_Tp>*, shared_ptr<_Tp>) [with _Tp = int]’ is deprecated: use 'std::atomic<std::shared_ptr<T>>' instead [-Werror=deprecated-declarations]
#     9 |             std::atomic_store(&p, std::make_shared<int>(666));  // <-- ugly
#       |             ~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# In file included from /usr/include/c++/15/memory:83,
#                  from /home/jfasch/My-Projects/jfasch-home/trainings/material/soup/cxx11/multithreading/atomic-shared-ptr/code/solution-atomic-function-specialization.cpp:1:
# /usr/include/c++/15/bits/shared_ptr_atomic.h:183:5: note: declared here
#   183 |     atomic_store(shared_ptr<_Tp>* __p, shared_ptr<_Tp> __r)
#       |     ^~~~~~~~~~~~
# cc1plus: all warnings being treated as errors
target_compile_options(c++11-thread-atomic-shared-ptr-solution-atomic-function-specialization PRIVATE -Wno-deprecated-declarations)

add_executable(c++11-thread-atomic-shared-ptr-solution-atomic-specialization solution-atomic-specialization.cpp)
