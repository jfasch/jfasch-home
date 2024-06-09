set(some_variable "")                                  # <--- empty value

if ("${some_variable}" STREQUAL "")                    # <--- check if empty
  message("empty")
endif()

if (DEFINED some_variable)                             # <--- check if defined
  message("defined")
endif()
