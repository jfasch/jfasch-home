add_subdirectory(base)
add_subdirectory(derived)
add_subdirectory(virtual-rudimentary)
add_subdirectory(virtual-wrong)
add_subdirectory(virtual-override-problem)
add_subdirectory(virtual-override-solution)
add_subdirectory(pure-virtual-methods)
add_subdirectory(destructor-nonvirtual)
add_subdirectory(destructor-virtual-nonempty)



ADD_EXECUTABLE(inher-oo-polymorphic inher-oo-polymorphic.cpp)
ADD_EXECUTABLE(inher-oo-polymorphic-not-pure inher-oo-polymorphic-not-pure.cpp)
# ADD_EXECUTABLE(inher-oo-polymorphic-pure inher-oo-polymorphic-pure.cpp)         compiler error, purposely

ADD_EXECUTABLE(inher-oo-dtor-base inher-oo-dtor-base.cpp)
ADD_EXECUTABLE(inher-oo-dtor-derived-novirtual inher-oo-dtor-derived-novirtual.cpp)
ADD_EXECUTABLE(inher-oo-dtor-derived-novirtual-base-conversion inher-oo-dtor-derived-novirtual-base-conversion.cpp)
ADD_EXECUTABLE(inher-oo-dtor-derived-virtual inher-oo-dtor-derived-virtual.cpp)
# ADD_EXECUTABLE(inher-oo-dtor-pure-virtual inher-oo-dtor-pure-virtual.cpp)       compiler error, purposely
