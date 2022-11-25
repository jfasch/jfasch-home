#include "social-insurance-oegk.h"


void OEGK::charge(const std::string& id, double euros)
{
    _database[id] += euros;
}

double OEGK::debt(const std::string& id) const
{
    auto found = _database.find(id);
    if (found == _database.end())
        throw std::runtime_error("not found");
    return found->second;
}
