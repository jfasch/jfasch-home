set(foo "bar")
if ("${foo}")                           # <--- unquoted bar -> undefined
  message("true")
else()
  message("false")
endif()
