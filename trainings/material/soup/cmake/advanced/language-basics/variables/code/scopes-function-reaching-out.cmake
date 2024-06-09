set(global_variable "global value")

function(some_function)
  message("some_function: \${global_variable}: ${global_variable}")
  set(global_variable "new global value" PARENT_SCOPE)
  message("some_function: \${global_variable}: ${global_variable} (STILL THE OLD VALUE)")
endfunction()

some_function()

message("global scope: \${global_variable}: ${global_variable}")
