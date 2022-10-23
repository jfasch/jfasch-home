#pragma once

#include "sensor.h"

#include <cstdint>


class I2CSensor : public Sensor
{
public:
    I2CSensor(unsigned int bus, uint8_t address) : _bus(bus), _address(address) {}

    unsigned int bus() const { return _bus; }
    uint8_t address() const { return _address; }

private:
    unsigned int _bus;
    uint8_t _address;
};
