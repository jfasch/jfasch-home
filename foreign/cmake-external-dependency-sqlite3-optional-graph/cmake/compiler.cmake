if ("${CMAKE_COMPILER_IS_GNUCC}")
  string(APPEND CMAKE_C_FLAGS " -ggdb -Wall -Werror")
  string(APPEND CMAKE_CXX_FLAGS " -ggdb -Wall -Werror")
endif()
