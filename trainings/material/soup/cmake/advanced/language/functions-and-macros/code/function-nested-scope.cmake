function(inner_function)
  message("inner_function: \${outer_variable}: ${outer_variable}")
endfunction()

function(outer_function)
  set(outer_variable "outer value")
  inner_function()
endfunction()

outer_function()
