function(access_parent)
  set(some_variable "inside value")
endfunction()

set(some_variable "outside value")
access_parent()
message("caller's variable after call: >${some_variable}<")
