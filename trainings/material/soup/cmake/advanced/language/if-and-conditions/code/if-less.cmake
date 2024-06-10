set(some_number 7)                      # <--- unquoted is ok for numbers :-)

if ("${some_number}" LESS 8)
  message("yes")
endif()
