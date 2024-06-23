#include "sensor-config.h"


void SensorConfig::add_sensor(const std::string& name, std::unique_ptr<Sensor>&& sensor)
{
    _sensors.emplace(name, std::move(sensor));
}

Measurements SensorConfig::take_measurements() const
{
    Measurements measurements;
    for (const auto& [name, sensor]: _sensors)
    {
        measurements.add_measurement(name, sensor->get_temperature());
    }
    return measurements;
}
