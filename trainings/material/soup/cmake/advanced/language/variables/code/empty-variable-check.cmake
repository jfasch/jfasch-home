set(some_variable "")                                  #  <--- empty value

if (DEFINED some_variable)
  message("defined")
  if ("${some_variable}" STREQUAL "")
    message("... although empty")
  endif()
endif()
