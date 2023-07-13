ADD_EXECUTABLE(hello-first hello-first.cpp)
TARGET_LINK_LIBRARIES(hello-first hello)
INSTALL(TARGETS hello-first DESTINATION bin)

ADD_EXECUTABLE(hello-second hello-second.cpp)
TARGET_LINK_LIBRARIES(hello-second hello)
INSTALL(TARGETS hello-second DESTINATION bin)
