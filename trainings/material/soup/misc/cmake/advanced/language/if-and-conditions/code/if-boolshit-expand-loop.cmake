set(boolean_variable 0)
set(another_variable "boolean_variable")  # <--- name of boolean_variable

if ("${another_variable}")                # <--- evaluates to unquoted boolean_variable
                                          #      which evaluates to 0
  message("quoted: true")
else()
  message("quoted: false")
endif()
