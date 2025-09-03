set(some_variable "value")

if (DEFINED some_variable)
  message("some_variable is a defined variable")
endif()
if (NOT DEFINED another_variable)
  message("another_variable is not a defined variable")
endif()
