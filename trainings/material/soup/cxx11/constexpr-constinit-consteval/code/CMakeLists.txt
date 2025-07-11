# --- const
add_executable(c++11-const-global-variable const-global-variable.cpp)
add_executable(c++11-const-used-in-const-map const-used-in-const-map.cpp)
add_executable(c++11-const-used-in-const-array const-used-in-const-array.cpp)

# --- constexpr
add_executable(c++11-constexpr-motivation constexpr-motivation.cpp)
add_executable(c++11-constexpr-add-simple-function constexpr-add-simple-function.cpp)
add_executable(c++11-constexpr-add-simple-function-static constexpr-add-simple-function-static.cpp)
add_executable(c++11-constexpr-add-constexpr-function constexpr-add-constexpr-function.cpp)
add_executable(c++11-constexpr-add-constexpr-function-request-constexpr constexpr-add-constexpr-function-request-constexpr.cpp)
add_executable(c++11-constexpr-add-constexpr-function-runtime-call constexpr-add-constexpr-function-runtime-call.cpp)
# add_executable(c++11-constexpr-immutable-variable-uncool constexpr-immutable-variable-uncool.cpp)
add_executable(c++11-constexpr-callchain constexpr-callchain.cpp)
add_executable(c++11-constexpr-recursion constexpr-recursion.cpp)
add_executable(c++11-constexpr-class constexpr-class.cpp)

# --- consteval
add_executable(c++11-consteval-add-function consteval-add-function.cpp)
# add_executable(c++11-consteval-add-function-error consteval-add-function-error.cpp)
add_executable(c++11-consteval-constexpr-callchain consteval-constexpr-callchain.cpp)

# --- constinit
add_subdirectory(siof-mutex)
add_subdirectory(siof-string)
add_subdirectory(siof-foo)
add_subdirectory(siof-foo-solution)

# --- const{expr,eval} if
add_executable(c++11-constexpr-if-problem constexpr-if-problem.cpp)
add_executable(c++11-constexpr-if-solution constexpr-if-solution.cpp)
