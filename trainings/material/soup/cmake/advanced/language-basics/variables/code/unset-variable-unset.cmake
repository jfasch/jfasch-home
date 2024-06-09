set(some_variable "value")
if (DEFINED some_variable)
  message("defined")
endif()

unset(some_variable)                                   # <--- dedicated unset()
if (NOT DEFINED some_variable)
  message("undefined")
endif()
