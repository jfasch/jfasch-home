#include "social-insurance-svs-strict.h"


void SVS::charge(const std::string& id, double euros)
{
    _database[id] += euros * (110.0L / 100);
}

double SVS::debt(const std::string& id) const
{
    auto found = _database.find(id);
    if (found == _database.end())
        throw std::runtime_error("not found");
    return found->second;
}
