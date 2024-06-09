set(some_variable "value")
if (DEFINED some_variable)
  message("defined")
endif()

set(some_variable)                                     # <--- unset as side-effect
                                                       # <--- of set
if (NOT DEFINED some_variable)
  message("undefined")
endif()
