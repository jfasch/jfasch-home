ADD_EXECUTABLE(gm-stl-container

  vector.cc
  list.cc
  map.cc
)
TARGET_LINK_LIBRARIES(gm-stl-container gtest_main)
add_test(NAME gm-stl-container COMMAND gm-stl-container)

ADD_EXECUTABLE(gm-lambda-threads threads.cc)
TARGET_LINK_LIBRARIES(gm-lambda-threads Threads::Threads)

ADD_EXECUTABLE(gm-sort-is-n-log-n sort-is-n-log-n.cc)
