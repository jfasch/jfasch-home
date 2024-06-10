set(some_number "Faschingbauer")

if ("${some_number}" LESS 8)
  message("yes")
else()
  message("no")
endif()

if ("${some_number}" GREATER 8)
  message("yes")
else()
  message("no")
endif()
