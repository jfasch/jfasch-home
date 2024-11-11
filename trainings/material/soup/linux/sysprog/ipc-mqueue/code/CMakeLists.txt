add_executable(sysprog-ipc-mq-create create.cpp)
target_link_libraries(sysprog-ipc-mq-create -lrt)

add_executable(sysprog-ipc-mq-produce produce.cpp)
target_link_libraries(sysprog-ipc-mq-produce -lrt)

add_executable(sysprog-ipc-mq-consume consume.cpp)
target_link_libraries(sysprog-ipc-mq-consume -lrt)

add_executable(sysprog-ipc-mq-unlink unlink.cpp)
target_link_libraries(sysprog-ipc-mq-unlink -lrt)
