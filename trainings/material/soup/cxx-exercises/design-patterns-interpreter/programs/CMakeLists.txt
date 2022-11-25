ADD_EXECUTABLE(
  dynamic-measurement-language

  dynamic-measurement-language.cpp  
)

TARGET_LINK_LIBRARIES(
  dynamic-measurement-language

  cxx-exercises-design-patterns-interpreter-expressions
  cxx-exercises-design-patterns-proxy-sensors
)
