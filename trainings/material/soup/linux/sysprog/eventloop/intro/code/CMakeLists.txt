add_executable(sysprog-eventloop-db-simple db-simple.cpp)
target_link_libraries(sysprog-eventloop-db-simple sysprog-eventloop-db)

add_executable(sysprog-eventloop-db-udp-incomplete db-udp-incomplete.cpp)
target_link_libraries(sysprog-eventloop-db-udp-incomplete sysprog-eventloop-db)
