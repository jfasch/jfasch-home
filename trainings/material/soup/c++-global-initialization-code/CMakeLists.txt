ADD_EXECUTABLE(01-global 01-global.cc)
ADD_EXECUTABLE(10-same-file 10-same-file.cc)

# ------------------------------------
# link files with no init dependencies
# ------------------------------------
ADD_EXECUTABLE(20-different-files

  20-different-files.cc 
  20-thing1.cc 
  20-thing2.cc
)

# same as above, but reversed link order
ADD_EXECUTABLE(20-different-files-reversed 
  20-different-files.cc
  20-thing2.cc
  20-thing1.cc
)

# -----------------------------------
# link files *with* init dependencies
# -----------------------------------
ADD_EXECUTABLE(30-different-files-bug

  30-different-files-bug.cc
  30-thing1.cc
  30-thing2.cc
)

# same as above, but reversed link order
ADD_EXECUTABLE(30-different-files-bug-reversed

  30-different-files-bug.cc
  30-thing2.cc
  30-thing1.cc
)
