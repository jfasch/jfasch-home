set(some_string "Hello")
string(APPEND ${some_string} " ")
string(APPEND ${some_string} "String")

message("Variable 'some_string': >${some_string}<")
message("Variable 'Hello' created: >${Hello}<")
