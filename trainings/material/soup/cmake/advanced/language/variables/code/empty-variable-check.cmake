set(some_variable "")                                  #  <--- empty value

if (DEFINED some_variable)
  message("some_variable is defined")
  if ("${some_variable}" STREQUAL "")
    message("... although some_variable is empty")
  endif()
endif()
