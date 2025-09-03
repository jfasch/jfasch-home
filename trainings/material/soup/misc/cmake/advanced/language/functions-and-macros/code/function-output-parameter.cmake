function(reach_out ref_param)
  set(${ref_param} "callee's value" PARENT_SCOPE)
endfunction()  

set(some_variable "caller's value")
message("some_variable before call: >${some_variable}<")
reach_out(some_variable)
message("some_variable after call: >${some_variable}<")
