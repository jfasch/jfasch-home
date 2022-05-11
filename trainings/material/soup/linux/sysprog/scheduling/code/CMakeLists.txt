ADD_EXECUTABLE(embedded-app-1-irq embedded-app-1-irq.cpp)
TARGET_LINK_LIBRARIES(embedded-app-1-irq Threads::Threads rt)

ADD_EXECUTABLE(embedded-app-2-irq embedded-app-2-irq.cpp)
TARGET_LINK_LIBRARIES(embedded-app-2-irq Threads::Threads rt)

ADD_EXECUTABLE(embedded-app-more-tasks-buggy embedded-app-more-tasks-buggy.cpp)
TARGET_LINK_LIBRARIES(embedded-app-more-tasks-buggy Threads::Threads rt)

ADD_EXECUTABLE(embedded-app-more-tasks embedded-app-more-tasks.cpp)
TARGET_LINK_LIBRARIES(embedded-app-more-tasks Threads::Threads rt)

ADD_EXECUTABLE(embedded-app-tasks embedded-app-tasks.cpp)
TARGET_LINK_LIBRARIES(embedded-app-tasks Threads::Threads rt)

ADD_EXECUTABLE(flash-terminal flash-terminal.cpp)
TARGET_LINK_LIBRARIES(flash-terminal Threads::Threads rt)

