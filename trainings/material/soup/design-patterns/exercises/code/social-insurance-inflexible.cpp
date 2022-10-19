#include "social-insurance-inflexible.h"

#include <stdexcept>


SocialInsurance SocialInsurance::_instance("Die einzige Sozialversicherung");

void SocialInsurance::charge(const std::string& id, double euros)
{
    _database[id] += euros;
}

double SocialInsurance::debt(const std::string& id) const
{
    auto found = _database.find(id);
    if (found == _database.end())
        throw std::runtime_error("not found");
    return found->second;
}

SocialInsurance& SocialInsurance::instance()
{
    return _instance;
}
