ADD_EXECUTABLE(
  c++11-thread-suite

  creation.cpp
  promise-future.cpp
)
TARGET_LINK_LIBRARIES(c++11-thread-suite gtest_main)

# ------------------------------------------------------------------
# promise/future
# ------------------------------------------------------------------
ADD_EXECUTABLE(
  c++11-thread-produce-answer-polling-unlocked
  c++11-thread-produce-answer-polling-unlocked.cpp)
TARGET_LINK_LIBRARIES(c++11-thread-produce-answer-polling-unlocked Threads::Threads)

ADD_EXECUTABLE(
  c++11-thread-produce-answer-polling-unlocked-chrono
  c++11-thread-produce-answer-polling-unlocked-chrono.cpp)
TARGET_LINK_LIBRARIES(c++11-thread-produce-answer-polling-unlocked-chrono Threads::Threads)

ADD_EXECUTABLE(
  c++11-thread-produce-answer-polling-mutex
  c++11-thread-produce-answer-polling-mutex.cpp)
TARGET_LINK_LIBRARIES(c++11-thread-produce-answer-polling-mutex Threads::Threads)

ADD_EXECUTABLE(
  c++11-thread-produce-answer-polling-lockguard
  c++11-thread-produce-answer-polling-lockguard.cpp)
TARGET_LINK_LIBRARIES(c++11-thread-produce-answer-polling-lockguard Threads::Threads)

ADD_EXECUTABLE(
  c++11-thread-produce-answer-polling-encapsulated
  c++11-thread-produce-answer-polling-encapsulated.cpp)
TARGET_LINK_LIBRARIES(c++11-thread-produce-answer-polling-encapsulated Threads::Threads)

ADD_EXECUTABLE(
  c++11-thread-produce-answer-polling-atomic-struct
  c++11-thread-produce-answer-polling-atomic-struct.cpp)
TARGET_LINK_LIBRARIES(c++11-thread-produce-answer-polling-atomic-struct Threads::Threads)

ADD_EXECUTABLE(
  c++11-thread-produce-answer-semaphore
  c++11-thread-produce-answer-semaphore.cpp)
TARGET_LINK_LIBRARIES(c++11-thread-produce-answer-semaphore Threads::Threads)

ADD_EXECUTABLE(
  c++11-thread-produce-answer-promise-future
  c++11-thread-produce-answer-promise-future.cpp)
TARGET_LINK_LIBRARIES(c++11-thread-produce-answer-promise-future Threads::Threads)

ADD_EXECUTABLE(
  c++11-thread-produce-answer-promise-future-exception
  c++11-thread-produce-answer-promise-future-exception.cpp)
TARGET_LINK_LIBRARIES(c++11-thread-produce-answer-promise-future-exception Threads::Threads)










ADD_EXECUTABLE(
  c++11-thread-producer-consumer-queue-polling 
  c++11-thread-producer-consumer-queue-polling.cpp)
TARGET_LINK_LIBRARIES(c++11-thread-producer-consumer-queue-polling Threads::Threads)

