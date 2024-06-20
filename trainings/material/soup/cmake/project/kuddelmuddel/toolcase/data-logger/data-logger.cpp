#include "data-logger.h"

#include "sensor-values.h"

#include <chrono>
#include <thread>  
#include <iostream>


DataLogger::DataLogger(SensorConfig* sensors, SinkLogger* sink, unsigned interval)
{
    _sink = sink;
    _sensors = sensors;
    _interval = interval;
}

void DataLogger::startLogging()
{
    std::string buffer;

    while (1)
    {
        _measurements = _sensors->getAllMeasurements();
        _sink->output(_measurements);
        std::this_thread::sleep_for(std::chrono::milliseconds(_interval));
    }
}


void DataLogger::startLogging(unsigned count)
{
    std::string buffer;

    while (count--)
    {
        _measurements = _sensors->getAllMeasurements();
        _sink->output(_measurements);
        std::this_thread::sleep_for(std::chrono::milliseconds(_interval));
    }
}
