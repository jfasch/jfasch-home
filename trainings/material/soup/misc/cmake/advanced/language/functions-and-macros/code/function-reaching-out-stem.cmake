function(reach_out stem)
  set(${stem}_one "one value" PARENT_SCOPE)
  set(${stem}_another "another value" PARENT_SCOPE)
endfunction()  

reach_out(some_variable)

message(${some_variable_one})
message(${some_variable_another})
