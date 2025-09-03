function(argv_etc first_param second_param)
  message("${ARGC}")
endfunction()

argv_etc("one" "two")
argv_etc("one" "two" "three")
