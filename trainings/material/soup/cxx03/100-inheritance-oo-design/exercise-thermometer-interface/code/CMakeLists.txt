ADD_LIBRARY(
  thermometers

  thermometer-const.cpp
  thermometer-random.cpp
)

ADD_EXECUTABLE(thermometer-const-test thermometer-const-test.cpp)
TARGET_LINK_LIBRARIES(thermometer-const-test thermometers)
ADD_EXECUTABLE(thermometer-random-test thermometer-random-test.cpp)
TARGET_LINK_LIBRARIES(thermometer-random-test thermometers)

# ADD_EXECUTABLE(thermometer-avg thermometer-avg.cpp)
# TARGET_LINK_LIBRARIES(thermometer-avg thermometers)
