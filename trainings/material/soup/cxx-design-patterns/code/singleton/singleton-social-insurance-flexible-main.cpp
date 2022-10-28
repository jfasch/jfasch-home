#include "social-insurance-svs.h"
#include "social-insurance-oegk.h"

#include <iostream>
#include <string>
#include <memory>


int main()
{
    // setup phase, next to program startup
    SocialInsurance::set_instance(std::make_unique<SVS>());

    std::string id("1037190666");

    SocialInsurance::instance().charge(id, 1254.60);
    SocialInsurance::instance().charge(id, 231.34);
    
    std::cout << id << " owes \"" << SocialInsurance::instance().name() << "\" " << SocialInsurance::instance().debt(id) << " Euros" << std::endl;

    // can only be a runtime error: trying to overwrite singleton
    // instance
    SocialInsurance::set_instance(std::make_unique<OEGK>());

    return 0;
}
