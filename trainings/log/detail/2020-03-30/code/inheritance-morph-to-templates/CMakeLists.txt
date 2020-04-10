ADD_LIBRARY(gm-thermometer-templatified thermometer.h thermometer.cc histogram.h)

ADD_EXECUTABLE(gm-spi-thermometer-templatified spi.cc)
TARGET_LINK_LIBRARIES(gm-spi-thermometer-templatified gm-thermometer-templatified)

ADD_EXECUTABLE(gm-i2c-thermometer-templatified i2c.cc)
TARGET_LINK_LIBRARIES(gm-i2c-thermometer-templatified gm-thermometer-templatified)

