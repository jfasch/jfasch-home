#include "sensor-repo.h"

bool SensorRepository::add_sensor(const std::string& name, Sensor* s)
{
    auto [iter, inserted] = _repo.insert(std::make_pair(name, s));
    return inserted;
}

bool SensorRepository::remove_sensor(const std::string& name)
{
    size_t nremoved = _repo.erase(name);
    return nremoved == 1;
}

Sensor* SensorRepository::get_sensor(const std::string& name)
{
    Repo::iterator found = _repo.find(name);
    if (found == _repo.end())
        return nullptr;
    return found->second;
}
