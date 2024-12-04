add_executable(c++-intro-overview-oo-todolist-orig todolist-orig.cpp)
add_executable(c++-intro-overview-oo-todolist-item-def-ctor-wtf todolist-item-def-ctor-wtf.cpp)
add_executable(c++-intro-overview-oo-todolist-const todolist-const.cpp)
#add_executable(c++-intro-overview-oo-todolist-items-non-compiling todolist-items-non-compiling.cpp)
add_executable(c++-intro-overview-oo-todolist-items-non-working todolist-items-non-working.cpp)
add_executable(c++-intro-overview-oo-todolist-sideway-slicing todolist-sideway-slicing.cpp)
add_executable(c++-intro-overview-oo-todolist-sideway-pointer-type-conversion todolist-sideway-pointer-type-conversion.cpp)
add_executable(c++-intro-overview-oo-todolist-sideway-virtual todolist-sideway-virtual.cpp)

add_executable(c++-intro-overview-oo-todolist-sideway-false-override todolist-sideway-false-override.cpp)
# workaround: gcc is smart enough to warn in such cases
target_compile_options(c++-intro-overview-oo-todolist-sideway-false-override PRIVATE -Wno-overloaded-virtual)

# add_executable(c++-intro-overview-oo-todolist-sideway-override todolist-sideway-override.cpp)
add_executable(c++-intro-overview-oo-todolist-sideway-pure-virtual todolist-sideway-pure-virtual.cpp)

add_executable(c++-intro-overview-oo-todolist-sideway-nonvirtual-dtor todolist-sideway-nonvirtual-dtor.cpp)
add_executable(c++-intro-overview-oo-todolist-sideway-virtual-dtor todolist-sideway-virtual-dtor.cpp)

add_executable(c++-intro-overview-oo-todolist-polymorphic todolist-polymorphic.cpp)
# add_executable(c++-intro-overview-oo-todolist-unique-ptr todolist-unique-ptr.cpp)
add_executable(c++-intro-overview-oo-todolist-shared-ptr todolist-shared-ptr.cpp)
add_executable(c++-intro-overview-oo-todolist-auto-wrong todolist-auto-wrong.cpp)
add_executable(c++-intro-overview-oo-todolist-auto-right todolist-auto-right.cpp)
add_executable(c++-intro-overview-oo-todolist-structured-binding todolist-structured-binding.cpp)
add_executable(c++-intro-overview-oo-todolist-range-for todolist-range-for.cpp)
