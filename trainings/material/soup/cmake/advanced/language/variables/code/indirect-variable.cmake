set(some_variable "a value")
set(another_variable "another value")

set(name_of_variable "some_variable")
message("direct: ${name_of_variable}")
message("indirect: ${${name_of_variable}}") # <--- double expansion

set(name_of_variable "another_variable")
message("indirect: ${${name_of_variable}}") # <--- double expansion
