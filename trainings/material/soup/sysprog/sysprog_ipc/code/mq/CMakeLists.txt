ADD_EXECUTABLE(010-mq-create 010-mq-create.cc msg.h)
TARGET_LINK_LIBRARIES(010-mq-create -lrt)

ADD_EXECUTABLE(020-mq-produce 020-mq-produce.cc msg.h)
TARGET_LINK_LIBRARIES(020-mq-produce -lrt)

ADD_EXECUTABLE(030-mq-consume 030-mq-consume.cc msg.h)
TARGET_LINK_LIBRARIES(030-mq-consume -lrt)

ADD_EXECUTABLE(099-mq-unlink 099-mq-unlink.cc msg.h)
TARGET_LINK_LIBRARIES(099-mq-unlink -lrt)


