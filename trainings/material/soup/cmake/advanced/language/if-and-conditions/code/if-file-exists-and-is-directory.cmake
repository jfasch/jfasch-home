set(filename "/etc/passwd")

if (EXISTS "${filename}")
  message("${filename} exists")
  if (NOT IS_DIRECTORY "${filename}")
    message("${filename} is not a directory")
  endif()
endif()
