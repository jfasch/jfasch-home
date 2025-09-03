function(simple)
  set(some_variable "value")
endfunction()

simple()

if (NOT DEFINED some_variable)
  message("pooh, not seeing function side effect")
endif()
