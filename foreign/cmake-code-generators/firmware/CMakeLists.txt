add_executable(app-boiling-pot boiling-pot.cpp)
target_link_libraries(app-boiling-pot base boiling-pot)
install(TARGETS app-boiling-pot DESTINATION bin)

add_executable(app-data-logger data-logger.cpp)
target_link_libraries(app-data-logger base data-logger)
install(TARGETS app-data-logger DESTINATION bin)

add_executable(
  app-data-logger-deeply-embedded-2024-06-20-manual 

  data-logger-deeply-embedded.cpp 
  2024-06-20-manual.cpp                      # <--- handwritten

)
target_link_libraries(app-data-logger-deeply-embedded-2024-06-20-manual base data-logger)
install(TARGETS app-data-logger-deeply-embedded-2024-06-20-manual DESTINATION bin)

add_executable(
  app-data-logger-deeply-embedded-2024-06-20 

  data-logger-deeply-embedded.cpp
  ${CMAKE_CURRENT_BINARY_DIR}/2024-06-20.cpp # <--- generated

)
target_link_libraries(app-data-logger-deeply-embedded-2024-06-20 base data-logger)
install(TARGETS app-data-logger-deeply-embedded-2024-06-20 DESTINATION bin)
target_include_directories(app-data-logger-deeply-embedded-2024-06-20 PRIVATE .)

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/2024-06-20.cpp
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/config-generator.py ${CMAKE_CURRENT_SOURCE_DIR}/2024-06-20.conf ${CMAKE_CURRENT_BINARY_DIR}/2024-06-20.cpp
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/config-generator.py ${CMAKE_CURRENT_SOURCE_DIR}/2024-06-20.conf
) 
