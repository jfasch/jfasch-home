function(takes_fancy_parameters)
  cmake_parse_arguments(MYPARAMS
    "VERBOSE;COOL"         # options/flags
    "FANCY1;FANCY2"        # single-value parameters
    "FANCIES1;FANCIES2"    # multi-value parameters

    ${ARGV}
  )

  if (MYPARAMS_VERBOSE)
    message("being verbose")
  endif()
  if (MYPARAMS_COOL)
    message("being cool")
  endif()

  if (DEFINED MYPARAMS_FANCY1)
    message("FANCY1: >${MYPARAMS_FANCY1}<")
  else()
    message("FANCY1: undefined")
  endif()

  if (DEFINED MYPARAMS_FANCY2)
    message("FANCY2: >${MYPARAMS_FANCY2}<")
  else()
    message("FANCY2: undefined")
  endif()

  if (DEFINED MYPARAMS_FANCIES1)
    message("FANCIES1: >${MYPARAMS_FANCIES1}<")
  else()
    message("FANCIES1: undefined")
  endif()

  if (DEFINED MYPARAMS_FANCIES2)
    message("FANCIES2: >${MYPARAMS_FANCIES2}<")
  else()
    message("FANCIES2: undefined")
  endif()
endfunction()

takes_fancy_parameters(FANCIES1 "one-fancy" "two-fancy" VERBOSE FANCY2 "fancy")
