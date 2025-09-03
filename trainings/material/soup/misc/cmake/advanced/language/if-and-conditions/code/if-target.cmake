set(libname "a-library-that-is-optionally-built")

if (NOT TARGET "${libname}")
  message("${libname} is not a known target")
endif()
