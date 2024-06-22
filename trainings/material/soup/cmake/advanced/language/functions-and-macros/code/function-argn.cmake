function(argv_etc first_param second_param)
  message("${ARGN}")
endfunction()

argv_etc("one" "two" "three" "four")
