function(reach_out)
  set(caller_variable "ha, I modified parent scope" PARENT_SCOPE)
endfunction()  

reach_out()

message("caller_variable magically appeared: >${caller_variable}<")
