#pragma once

#include "sensor-i2c.h"


class I2CSensorFactory
{
public:
    virtual ~I2CSensorFactory() {}
    virtual I2CSensor* create(unsigned int bus, uint8_t address) = 0;
};
