 add_library(
   c++03-exercises-fh-shapes STATIC 

   point.h
   point.cpp

   rectangle.h
   rectangle.cpp
)
target_include_directories(c++03-exercises-fh-shapes PUBLIC .)
