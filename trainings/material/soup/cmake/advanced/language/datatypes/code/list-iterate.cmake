list(APPEND some_list "a" "b" "c")
foreach (loop_var ${some_list})
  message("${loop_var}")
endforeach()
