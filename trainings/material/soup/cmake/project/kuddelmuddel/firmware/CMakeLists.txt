add_executable(app-boiling-pot boiling-pot.cpp)
target_link_libraries(app-boiling-pot base boiling-pot)
install(TARGETS app-boiling-pot DESTINATION bin)

add_executable(app-data-logger data-logger.cpp)
target_link_libraries(app-data-logger base data-logger)
install(TARGETS app-data-logger DESTINATION bin)
