macro(simple)
  set(some_variable "value")            # <--- no PARENT_SCOPE
endmacro()

simple()

message("some_variable: >${some_variable}<")
