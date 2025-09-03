if (NOT DEFINED some_variable)
  message("some_variable is not defined")
endif()

if ("${some_variable}" STREQUAL "")
  message("... although some_variable has an empty value")
endif()
