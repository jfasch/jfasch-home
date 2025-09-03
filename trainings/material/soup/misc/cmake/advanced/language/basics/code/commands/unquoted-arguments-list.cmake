set(some_variable "undesired;hello;world")
message(some_variable)
message(${some_variable})
message("${some_variable}")     # <--- MUCH preferred
