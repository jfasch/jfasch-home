set(filename "/etc/passwd")

if (IS_ABSOLUTE "${filename}")
  message("${filename} is an absolute path")
endif()

cmake_policy(SET CMP0139 NEW)           # <--- argh!

set(alternative_filename "/etc/blah/../passwd")
if ("${alternative_filename}" PATH_EQUAL "${filename}")
  message("${alternative_filename} and ${filename} are the same path")
endif()
