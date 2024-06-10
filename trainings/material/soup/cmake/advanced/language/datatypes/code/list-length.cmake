set(some_list "a" "b")
list(LENGTH some_list some_length)
message("${some_length}")

list(LENGTH "${some_list}" some_length)
message("${some_length}")
