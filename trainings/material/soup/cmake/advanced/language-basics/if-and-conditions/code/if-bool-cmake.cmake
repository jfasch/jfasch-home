set(boolean_variable 1)

if (boolean_variable)                   # <--- unquoted variables 
                                        # <--- preferred for bool
  message("boolean_variable (${boolean_variable}) evaluated as boolean true")
endif()

set(boolean_variable 0)

if (NOT boolean_variable)               # <--- unquoted variables 
                                        # <--- preferred for bool
  message("boolean_variable (${boolean_variable}) evaluated as boolean false")
endif()
