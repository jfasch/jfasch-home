#pragma once

#include "sensor-mock.h"

#include <iostream>
#include <time.h>

class Logger
{
public:
    Logger(MockSensor* sensor) : _sensor{sensor} {}
    void log_one()
    {
        time_t now = time(nullptr);
        double value = _sensor->get_value();
        std::cout << now << ": " << value << std::endl;
    }
private:
    MockSensor* _sensor;
};
