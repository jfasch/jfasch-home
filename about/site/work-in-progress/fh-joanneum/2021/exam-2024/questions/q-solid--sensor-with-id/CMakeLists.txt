ADD_EXECUTABLE(fh2021-q-solid--sensor-with-id-main sensor-with-id-main.cpp)
ADD_EXECUTABLE(fh2021-q-solid--sensor-with-id-suite sensor-with-id-suite.cpp)

TARGET_LINK_LIBRARIES(
  fh2021-q-solid--sensor-with-id-suite

  gtest_main 
)

add_test(NAME fh2021-q-solid--sensor-with-id-suite COMMAND fh2021-q-solid--sensor-with-id-suite)
