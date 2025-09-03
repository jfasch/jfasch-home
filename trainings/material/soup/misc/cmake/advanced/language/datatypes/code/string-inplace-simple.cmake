set(some_string "Hello")
string(APPEND some_string " ")
string(APPEND some_string "String")
message("${some_string}")
