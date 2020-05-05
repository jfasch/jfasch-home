ADD_LIBRARY(c++-templates-vs-interfaces-thermometer 
  thermometer.h thermometer.cc
  histogram.h)

ADD_EXECUTABLE(c++-templates-vs-interfaces-spi-thermometer spi.cc)
TARGET_LINK_LIBRARIES(c++-templates-vs-interfaces-spi-thermometer c++-templates-vs-interfaces-thermometer)

ADD_EXECUTABLE(c++-templates-vs-interfaces-i2c-thermometer i2c.cc)
TARGET_LINK_LIBRARIES(c++-templates-vs-interfaces-i2c-thermometer c++-templates-vs-interfaces-thermometer)
