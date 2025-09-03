#include "sensor-repo.h"

SensorRepository::~SensorRepository()
{
    for (auto& [key, value]: _repo)
        delete value;
}

bool SensorRepository::add_sensor(const std::string& name, Sensor* s)
{
    auto [iter, inserted] = _repo.insert(std::make_pair(name, s));
    return inserted;
}

bool SensorRepository::remove_sensor(const std::string& name)
{
    auto found = _repo.find(name);
    if (found == _repo.end())
        return false;
    delete found->second;
    _repo.erase(found);
    return true;
}

Sensor* SensorRepository::get_sensor(const std::string& name)
{
    Repo::iterator found = _repo.find(name);
    if (found == _repo.end())
        return nullptr;
    return found->second;
}
