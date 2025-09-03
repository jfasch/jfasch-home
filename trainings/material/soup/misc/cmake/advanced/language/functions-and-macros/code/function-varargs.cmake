function(takes_any_number_args)
  message("number of args passed: ${ARGC}")
  message("args passed: ${ARGV}")
endfunction()

takes_any_number_args("one" "two")
