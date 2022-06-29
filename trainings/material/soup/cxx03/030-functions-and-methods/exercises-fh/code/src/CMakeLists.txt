 add_library(
   c++03-exercises-fh-shapes STATIC 

   point.h
   point.cpp
   rectangle.h
   rectangle.cpp
   point3d.h
   point3d.cpp
   cuboid.h
   cuboid.cpp
)
target_include_directories(c++03-exercises-fh-shapes PUBLIC .)
