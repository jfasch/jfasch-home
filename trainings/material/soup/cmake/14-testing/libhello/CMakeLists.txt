ADD_LIBRARY(hello greeter-simple.cpp greeter-name.cpp greeter-alias-db.cpp)
SET_PROPERTY(TARGET hello PROPERTY VERSION "1")
INSTALL(TARGETS hello DESTINATION lib)

TARGET_INCLUDE_DIRECTORIES(hello PUBLIC .)

TARGET_LINK_LIBRARIES(hello blacklist)
TARGET_LINK_LIBRARIES(hello SQLite::SQLite3)
