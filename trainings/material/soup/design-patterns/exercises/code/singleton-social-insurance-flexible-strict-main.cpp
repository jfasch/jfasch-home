#include "social-insurance-flexible-strict.h"

// only there to deny compiability below
// #include "social-insurance-svs-strict.h"
// #include "social-insurance-oegk-strict.h"

#include <iostream>
#include <string>


int main()
{
    std::string id("1037190666");

    SocialInsurance::instance().charge(id, 1254.60);
    SocialInsurance::instance().charge(id, 231.34);

    std::cout << id << " owes \"" << SocialInsurance::instance().name() << "\" " << SocialInsurance::instance().debt(id) << " Euros" << std::endl;

    // MUST NOT COMPILE
    // ================

    // explicit instantiation (neither iface nor implementations)
    // ----------------------------------------------------------

    // SocialInsurance iface_instance("Another Insurance");
    // SVS svs_instance;
    // OEGK oegk_instance;

    // copy initialization
    // -------------------

    // SocialInsurance another_instance = SocialInsurance::instance();

    // copy assignment
    // ---------------

    // another_instance = SocialInsurance::instance();

    // and dynamic_cast?
    // -----------------

    // STOP HERE!!!

    return 0;
}
