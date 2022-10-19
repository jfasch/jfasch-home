#include "social-insurance-flexible-strict.h"

#include "social-insurance-svs-strict.h"
#include "social-insurance-oegk-strict.h"

#include <stdexcept>
#include <cstdlib>


std::unique_ptr<SocialInsurance> SocialInsurance::_instance;

SocialInsurance& SocialInsurance::instance()
{
    if (_instance == nullptr) {
        char* socinsur = std::getenv("SOCINSUR");
        if (socinsur == nullptr)
            throw std::runtime_error("Environment variable \"SOCINSUR\" is not set");
    
        std::string ssocinsur = socinsur;
        if (ssocinsur == "SVS")
            _instance = std::unique_ptr<SocialInsurance>(new SVS);
        else if (ssocinsur == "OEGK")
            _instance = std::unique_ptr<SocialInsurance>(new OEGK);
        else 
            throw std::runtime_error("Environment variable \"SOCINSUR\" has invalid value");
    }

    return *_instance;
}
