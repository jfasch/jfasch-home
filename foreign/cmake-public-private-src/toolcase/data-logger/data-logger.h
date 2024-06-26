#pragma once

#include "sink.h"
#include "sensor-config.h"


class DataLogger
{
public:
    DataLogger(const SensorConfig& sensors, std::unique_ptr<Sink>&& sink, unsigned interval_ms);

    void start_logging();
    void start_logging(unsigned count);
    
private:
    std::unique_ptr<Sink> _sink;
    const SensorConfig& _sensors;
    unsigned _interval_ms;

    std::string timeBuffer;
};
