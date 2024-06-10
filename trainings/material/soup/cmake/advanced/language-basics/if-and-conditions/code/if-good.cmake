set(some_variable "value1")

if ("${some_variable}" STREQUAL "value1")
  message("case 1")
elseif ("${some_variable}" STREQUAL "value2")
  message("case 2")
else()
  message("default")
endif()

