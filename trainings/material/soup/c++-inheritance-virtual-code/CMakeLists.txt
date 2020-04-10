ADD_LIBRARY(c++-inheritance-virtual-thermometer 
  thermometer.h thermometer.cc
  histogram.h histogram.cc)

ADD_EXECUTABLE(c++-inheritance-virtual-spi-thermometer spi.cc)
TARGET_LINK_LIBRARIES(c++-inheritance-virtual-spi-thermometer c++-inheritance-virtual-thermometer)

ADD_EXECUTABLE(c++-inheritance-virtual-i2c-thermometer i2c.cc)
TARGET_LINK_LIBRARIES(c++-inheritance-virtual-i2c-thermometer c++-inheritance-virtual-thermometer)
