function(takes_any_number_args)
  message("${ARGV0}")
  message("${ARGV1}")
endfunction()

takes_any_number_args("one" "two")
