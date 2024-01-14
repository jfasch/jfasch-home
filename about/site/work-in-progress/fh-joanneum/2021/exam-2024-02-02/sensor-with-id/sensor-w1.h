#pragma once

#include "sensor.h"
#include <cstdint>


class W1Sensor : public Sensor
{
public:
    W1Sensor(unsigned int id, uint64_t w1_address)
    : Sensor(id),
      _w1_address(w1_address) {}

    double get_temperature() override
    {
        // ... access physical sensor ...
        return 36.5;
    }

private:
    uint64_t _w1_address;
};
