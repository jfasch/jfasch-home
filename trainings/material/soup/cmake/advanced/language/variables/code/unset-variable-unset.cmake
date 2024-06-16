set(some_variable "value")
if (DEFINED some_variable)
  message("some_variable is defined")
endif()

unset(some_variable)                                   # <--- dedicated unset()
if (NOT DEFINED some_variable)
  message("some_variable undefined")
endif()
