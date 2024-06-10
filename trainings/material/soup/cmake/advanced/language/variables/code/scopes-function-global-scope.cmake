set(global_variable "global value")

function(some_function)
  message("some_function: \${global_variable}: ${global_variable}")
endfunction()

some_function()
