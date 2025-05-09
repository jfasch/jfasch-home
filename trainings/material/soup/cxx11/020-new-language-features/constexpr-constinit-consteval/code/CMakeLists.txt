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
add_executable(c++11-constexpr-callchain constexpr-callchain.cpp)
add_executable(c++11-constexpr-recursion constexpr-recursion.cpp)
add_executable(c++11-constexpr-class constexpr-class.cpp)

# --- consteval
add_executable(c++11-consteval-function-ok consteval-function-ok.cpp)
#add_executable(c++11-consteval-function-error consteval-function-error.cpp)
add_executable(c++11-consteval-function-uses-constexpr-function consteval-function-uses-constexpr-function.cpp)
