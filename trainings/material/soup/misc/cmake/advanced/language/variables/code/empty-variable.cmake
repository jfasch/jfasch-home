set(some_variable "")                                  # <--- empty value

if ("${some_variable}" STREQUAL "")                    # <--- check if empty
  message("some_variable is empty")
endif()

if (DEFINED some_variable)                             # <--- check if defined
  message("some_variable is defined")
endif()
