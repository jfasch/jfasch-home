ADD_LIBRARY(gm-thermometer thermometer.h thermometer.cc histogram.h histogram.cc)

ADD_EXECUTABLE(gm-spi-thermometer spi.cc)
TARGET_LINK_LIBRARIES(gm-spi-thermometer gm-thermometer)

ADD_EXECUTABLE(gm-i2c-thermometer i2c.cc)
TARGET_LINK_LIBRARIES(gm-i2c-thermometer gm-thermometer)

ADD_EXECUTABLE(gm-alle-thermometer alle.cc)
TARGET_LINK_LIBRARIES(gm-alle-thermometer gm-thermometer)

