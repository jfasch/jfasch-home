# --- [[noreturn]]
add_executable(c++11-attributes-noreturn noreturn.cpp)

# --- [[deprecated]]
#add_executable(c++11-attributes-deprecated deprecated.cpp)

# --- [[fallthrough]]
add_executable(c++11-attributes-fallthrough-warn fallthrough-warn.cpp)
#target_compile_options(c++11-attributes-fallthrough-warn PRIVATE "-Wimplicit-fallthrough")
add_executable(c++11-attributes-fallthrough-warn-suppress fallthrough-warn-suppress.cpp)

# --- [[nodiscard]]
add_executable(c++11-attributes-nodiscard-problem nodiscard-problem.cpp)
#add_executable(c++11-attributes-nodiscard-warning nodiscard-warning.cpp)
add_executable(c++11-attributes-nodiscard-fix nodiscard-fix.cpp)
add_executable(c++11-attributes-nodiscard-entire-type nodiscard-entire-type.cpp)

# --- [[maybe_unused]]
#add_executable(c++11-attributes-maybe-unused-problem maybe-unused-problem.cpp)
add_executable(c++11-attributes-maybe-unused-solution maybe-unused-solution.cpp)

# --- [[likely,unlikely]]
add_executable(c++11-attributes-likely-if likely-if.cpp)
add_executable(c++11-attributes-likely-switch likely-switch.cpp)
