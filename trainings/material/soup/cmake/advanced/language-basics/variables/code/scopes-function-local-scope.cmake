function(some_function)
  set(local_variable "local value")
endfunction()

some_function()

if (NOT DEFINED local_variable)
  message("behavior as usual")
endif()
