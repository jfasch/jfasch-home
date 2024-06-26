function(my_add_library)
  cmake_parse_arguments(MY_ADD_LIBRARY "SHARED;STATIC;DEBUG" "NAME" "PRIVATE_HEADERS;PUBLIC_HEADERS;SOURCES" ${ARGN})

  if (MY_ADD_LIBRARY_DEBUG)
    message("MY_ADD_LIBRARY_SHARED: >${MY_ADD_LIBRARY_SHARED}<")
    message("MY_ADD_LIBRARY_STATIC: >${MY_ADD_LIBRARY_STATIC}<")
    message("MY_ADD_LIBRARY_NAME: >${MY_ADD_LIBRARY_NAME}<")
    message("MY_ADD_LIBRARY_PRIVATE_HEADERS: >${MY_ADD_LIBRARY_PRIVATE_HEADERS}<")
    message("MY_ADD_LIBRARY_PUBLIC_HEADERS: >${MY_ADD_LIBRARY_PUBLIC_HEADERS}<")
    message("MY_ADD_LIBRARY_SOURCES: >${MY_ADD_LIBRARY_SOURCES}<")
    message("ARGC: ${ARGC}")
    message("ARGV: ${ARGV}")
    message("ARGN: >${ARGN}<")
  endif()

  if (MY_ADD_LIBRARY_SHARED AND MY_ADD_LIBRARY_STATIC)
    message(FATAL_ERROR "STATIC *and* SHARED is not possible")
  endif()

  foreach (f ${MY_ADD_LIBRARY_PUBLIC_HEADERS})
    list(APPEND public_headers "include/public/${f}")
  endforeach()
  foreach (f ${MY_ADD_LIBRARY_PRIVATE_HEADERS})
    list(APPEND public_headers "include/private/${f}")
  endforeach()
  foreach (f ${MY_ADD_LIBRARY_SOURCES})
    list(APPEND sources "src/${f}")
  endforeach()

  if (MY_ADD_LIBRARY_SHARED)
    set(how "SHARED")
  elseif (MY_ADD_LIBRARY_STATIC)
    set(how "STATIC")
  endif()

  add_library(
    ${MY_ADD_LIBRARY_NAME}
    ${how}
    ${public_headers}
    ${private_headers}
    ${sources}
  )

  target_include_directories(${MY_ADD_LIBRARY_NAME} PUBLIC ./include/public)
  target_include_directories(${MY_ADD_LIBRARY_NAME} PRIVATE ./include/private)

  install(TARGETS ${MY_ADD_LIBRARY_NAME} DESTINATION lib)
  install(FILES ${MY_ADD_LIBRARY_PUBLIC_HEADERS} DESTINATION include)
   
endfunction()
