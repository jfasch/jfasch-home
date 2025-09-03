function(access_parent)
  message("inside function: ${some_variable}")
endfunction()

set(some_variable "outside value")
access_parent()
