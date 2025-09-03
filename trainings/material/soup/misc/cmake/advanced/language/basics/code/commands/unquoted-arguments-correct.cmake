set(some_variable "some value")
message(some_variable)
message(${some_variable})
message("${some_variable}")     # <--- MUCH preferred
