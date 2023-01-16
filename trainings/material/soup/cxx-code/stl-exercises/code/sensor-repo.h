#pragma once

#include "sensor.h"

#include <map>
#include <string>


class SensorRepository
{
public:
    ~SensorRepository();

    size_t size() const { return _repo.size(); }
    bool add_sensor(const std::string& name, Sensor*);
    bool remove_sensor(const std::string& name);
    Sensor* get_sensor(const std::string& name);

private:
    using Repo = std::map<std::string, Sensor*>;
    Repo _repo;
};
