set(some_string "Mississippi")
string(FIND "${some_string}" "ss" position_found REVERSE)
message("${position_found}")
