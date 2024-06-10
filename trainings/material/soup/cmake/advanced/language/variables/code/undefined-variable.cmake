if (NOT DEFINED some_variable)
  message("not defined")
endif()

if ("${some_variable}" STREQUAL "")
  message("... although \"some_variable\" has an empty value")
endif()
