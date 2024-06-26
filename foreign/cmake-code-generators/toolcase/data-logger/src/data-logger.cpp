#include "data-logger.h"

#include "measurements.h"

#include <chrono>
#include <thread>  
#include <iostream>


DataLogger::DataLogger(const SensorConfig& sensors, std::unique_ptr<Sink>&& sink, unsigned interval_ms)
: _sink(std::move(sink)),
  _sensors(sensors),
  _interval_ms(interval_ms) {}

void DataLogger::start_logging()
{
    std::string buffer;

    while (1)
    {
        auto measurements = _sensors.take_measurements();
        _sink->output(measurements);
        std::this_thread::sleep_for(std::chrono::milliseconds(_interval_ms));
    }
}

void DataLogger::start_logging(unsigned count)
{
    std::string buffer;

    while (count--)
    {
        auto measurements = _sensors.take_measurements();
        _sink->output(measurements);
        std::this_thread::sleep_for(std::chrono::milliseconds(_interval_ms));
    }
}
