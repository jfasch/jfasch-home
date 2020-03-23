ADD_EXECUTABLE(010-mmap 010-mmap.cc)

ADD_EXECUTABLE(020-shm-create 020-shm-create.cc)
TARGET_LINK_LIBRARIES(020-shm-create -lrt)

ADD_EXECUTABLE(030-shm-produce 030-shm-produce.cc)
TARGET_LINK_LIBRARIES(030-shm-produce -lrt)

ADD_EXECUTABLE(040-shm-consume 040-shm-consume.cc)
TARGET_LINK_LIBRARIES(040-shm-consume -lrt)

ADD_EXECUTABLE(100-sem-create 100-sem-create.cc)
TARGET_LINK_LIBRARIES(100-sem-create Threads::Threads)

ADD_EXECUTABLE(110-sem-wait 110-sem-wait.cc)
TARGET_LINK_LIBRARIES(110-sem-wait Threads::Threads)

ADD_EXECUTABLE(120-sem-post 120-sem-post.cc)
TARGET_LINK_LIBRARIES(120-sem-post Threads::Threads)
