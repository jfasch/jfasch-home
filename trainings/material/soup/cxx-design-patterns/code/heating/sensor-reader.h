#pragma once

#include <sensor.h>

#include <vector>
#include <string>


// * reads a configured list of sensors
// * writes name/sensor-value pairs into a value store of some kind
// * logs messages as it goes
class SensorReader
{
public:
    using NamedSensor = std::pair<std::string, Sensor*>;
    using Sensors = std::vector<NamedSensor>;

    // Aspects of a logger that I need: get rid of messages
    class Logger
    {
    public:
        virtual ~Logger() {}
        virtual void log(const std::string& msg) = 0;
    };

    // Aspects of a value-store that I need: store double value under
    // a name
    class ValueStore
    {
    public:
        virtual ~ValueStore() {}
        virtual void set(const std::string& name, double temperature) = 0;
    };

public:
    SensorReader(
        const Sensors& sensors,
        Logger& logger,
        ValueStore& store)
    : _sensors(sensors),
      _logger(logger),
      _value_store(store) {}

    void doit()
    {
        for (auto [name, sensor]: _sensors){
            _logger.log(name);
            double temperature = sensor->get_temperature();
            _value_store.set(name, temperature);
        }
    }
    
private:
    std::vector<NamedSensor> _sensors;    
    Logger& _logger;
    ValueStore& _value_store;
};
