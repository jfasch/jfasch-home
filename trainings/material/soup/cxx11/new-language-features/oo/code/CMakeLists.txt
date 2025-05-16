# ----------------------------------------
# override
# ----------------------------------------
add_executable(c++11-override-ok c++11-override-ok.cpp)

set_source_files_properties(c++11-override-omit-const.cpp PROPERTIES COMPILE_FLAGS -Wno-overloaded-virtual)
add_executable(c++11-override-omit-const c++11-override-omit-const.cpp)
# add_executable(c++11-override-keyword c++11-override-keyword.cpp)

# ----------------------------------------
# final
# ----------------------------------------
#add_executable(c++11-final-class c++11-final-class.cpp)
#add_executable(c++11-final-method c++11-final-method.cpp)

# ----------------------------------------
# = delete
# ----------------------------------------
add_executable(c++11-delete-bogus-copy c++11-delete-bogus-copy.cpp)
#add_executable(c++11-delete-private-copy c++11-delete-private-copy.cpp)
#add_executable(c++11-delete-delete-copy c++11-delete-delete-copy.cpp)

# ----------------------------------------
# = default
# ----------------------------------------
# add_executable(c++11-default-missing c++11-default-missing.cpp)
add_executable(c++11-default-explicit c++11-default-explicit.cpp)
add_executable(c++11-default-default c++11-default-default.cpp)
