#pragma once

#include "sensor-i2c-factory.h"

class I2CSensorFactory_Vendor1 : public I2CSensorFactory
{
public:
    virtual I2CSensor* create(unsigned int bus, uint8_t address) override;
};
