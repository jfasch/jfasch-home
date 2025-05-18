#pragma once

#include "sensor-mock.h"

#include <iostream>
#include <chrono>

class Logger
{
public:
    Logger(MockSensor* sensor) : _sensor{sensor} {}
    void log_one()
    {
        // std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
        auto now = std::chrono::system_clock::now();   // <-- cool
        double value = _sensor->get_value();
        std::cout << now << ": " << value << std::endl;
    }
private:
    MockSensor* _sensor;
};
