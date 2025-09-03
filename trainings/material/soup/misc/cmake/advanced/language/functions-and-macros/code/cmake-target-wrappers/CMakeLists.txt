# boilerplate
cmake_minimum_required(VERSION 3.20)
project(Demo)

#function(my_add_library)
  

# build
add_library(
  hello

  hello.h hello.c
  hello-name.h hello-name.c
)
set_property(TARGET hello PROPERTY VERSION 2)
install(TARGETS hello DESTINATION lib)

add_executable(
  hello-first hello-first.c
)
target_link_libraries(
  hello-first 
  hello
)
install(TARGETS hello-first DESTINATION bin)

add_executable(
  hello-second hello-second.c 
)
target_link_libraries(
  hello-second 
  hello
)
install(TARGETS hello-second DESTINATION bin)
