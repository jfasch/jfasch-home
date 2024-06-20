ADD_EXECUTABLE(
  c++11-thread-suite

  creation.cpp
  mutex.cpp
  promise-future.cpp
)
TARGET_LINK_LIBRARIES(c++11-thread-suite gtest_main)
add_test(NAME c++11-thread-suite COMMAND c++11-thread-suite)

# ------------------------------------------------------------------
# promise/future
# ------------------------------------------------------------------
ADD_EXECUTABLE(
  c++11-thread-future-polling-unlocked
  c++11-thread-future-polling-unlocked.cpp)
TARGET_LINK_LIBRARIES(c++11-thread-future-polling-unlocked Threads::Threads)

ADD_EXECUTABLE(
  c++11-thread-future-polling-unlocked-chrono
  c++11-thread-future-polling-unlocked-chrono.cpp)
TARGET_LINK_LIBRARIES(c++11-thread-future-polling-unlocked-chrono Threads::Threads)

ADD_EXECUTABLE(
  c++11-thread-future-polling-mutex
  c++11-thread-future-polling-mutex.cpp)
TARGET_LINK_LIBRARIES(c++11-thread-future-polling-mutex Threads::Threads)

ADD_EXECUTABLE(
  c++11-thread-future-polling-lockguard
  c++11-thread-future-polling-lockguard.cpp)
TARGET_LINK_LIBRARIES(c++11-thread-future-polling-lockguard Threads::Threads)

ADD_EXECUTABLE(
  c++11-thread-future-polling-encapsulated
  c++11-thread-future-polling-encapsulated.cpp)
TARGET_LINK_LIBRARIES(c++11-thread-future-polling-encapsulated Threads::Threads)

ADD_EXECUTABLE(
  c++11-thread-future-polling-atomic-struct
  c++11-thread-future-polling-atomic-struct.cpp)
TARGET_LINK_LIBRARIES(c++11-thread-future-polling-atomic-struct Threads::Threads)

ADD_EXECUTABLE(
  c++11-thread-future-semaphore
  c++11-thread-future-semaphore.cpp)
TARGET_LINK_LIBRARIES(c++11-thread-future-semaphore Threads::Threads)

ADD_EXECUTABLE(
  c++11-thread-future-promise-future
  c++11-thread-future-promise-future.cpp)
TARGET_LINK_LIBRARIES(c++11-thread-future-promise-future Threads::Threads)

ADD_EXECUTABLE(
  c++11-thread-future-promise-future-exception
  c++11-thread-future-promise-future-exception.cpp)
TARGET_LINK_LIBRARIES(c++11-thread-future-promise-future-exception Threads::Threads)



# ------------------------------------------------------------------
# condition variable
# ------------------------------------------------------------------
ADD_EXECUTABLE(
  c++11-thread-condvar-queue-polling
  c++11-thread-condvar-queue-polling.cpp)
TARGET_LINK_LIBRARIES(c++11-thread-condvar-queue-polling Threads::Threads)

ADD_EXECUTABLE(
  c++11-thread-condvar-queue-pthread
  c++11-thread-condvar-queue-pthread.cpp)
TARGET_LINK_LIBRARIES(c++11-thread-condvar-queue-pthread Threads::Threads)

ADD_EXECUTABLE(
  c++11-thread-condvar-queue-condvar
  c++11-thread-condvar-queue-condvar.cpp)
TARGET_LINK_LIBRARIES(c++11-thread-condvar-queue-condvar Threads::Threads)

