#include "social-insurance-flexible.h"

#include <stdexcept>


std::unique_ptr<SocialInsurance> SocialInsurance::_instance;

SocialInsurance& SocialInsurance::instance()
{
    if (_instance == nullptr)
        throw std::runtime_error("SocialInsurance singleton not in place");
    return *_instance;
}

void SocialInsurance::set_instance(std::unique_ptr<SocialInsurance> obj)
{
    if (_instance != nullptr)
        throw std::runtime_error("SocialInsurance singleton already in place");
    _instance = std::move(obj);
}
