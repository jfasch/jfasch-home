set(some_list "a" "b")
message("some_list as string: >${some_list}<")
message("some_list as string: >" ${some_list} "<")

set(some_string "a b")
message("some_string, interpolated: >${some_list}<")
message("some_string, unquoted: >" ${some_list} "<")
