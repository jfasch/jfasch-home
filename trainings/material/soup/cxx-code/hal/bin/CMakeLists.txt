ADD_EXECUTABLE(oneshot-timer oneshot-timer.cpp)
TARGET_LINK_LIBRARIES(oneshot-timer hal)

ADD_EXECUTABLE(periodic-timer periodic-timer.cpp)
TARGET_LINK_LIBRARIES(periodic-timer hal)
