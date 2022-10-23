#pragma once

#include "sensor-i2c.h"


class I2CSensor_Vendor2 : public I2CSensor
{
public:
    I2CSensor_Vendor2(unsigned int bus, uint8_t address) : I2CSensor(bus, address) {}

    double get_temperature() { return 42; }
};
