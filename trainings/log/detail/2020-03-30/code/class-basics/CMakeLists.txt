# TDD (see tests/): see what a point needs, implement it, and slowly
# morph it into an equivalent C++ class
ADD_LIBRARY(gm-point c-point.h c-point.c point.h)
ADD_SUBDIRECTORY(tests)


ADD_EXECUTABLE(temporaries-demo temporaries-demo.cc)
