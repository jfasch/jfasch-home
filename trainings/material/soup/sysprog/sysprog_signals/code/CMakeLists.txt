ADD_EXECUTABLE(010-signal-basics 010-signal-basics.cc)

ADD_EXECUTABLE(020-signal-handler 020-signal-handler.cc)

ADD_EXECUTABLE(030-signal-termination-alarm 030-signal-termination-alarm.cc)

ADD_EXECUTABLE(035-synchronous-delivery 035-synchronous-delivery.c)

ADD_EXECUTABLE(040-mt-pipe 040-mt-pipe.cc)
TARGET_LINK_LIBRARIES(040-mt-pipe Threads::Threads)

ADD_EXECUTABLE(050-mt-pipe-alarm 050-mt-pipe-alarm.cc)
TARGET_LINK_LIBRARIES(050-mt-pipe-alarm Threads::Threads)

ADD_EXECUTABLE(051-st-pipe-alarm 051-st-pipe-alarm.cc)
