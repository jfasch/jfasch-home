#include "social-insurance-inflexible.h"

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

    // explicit instantiation
    // ----------------------

    // SocialInsurance another_instance("Another Insurance");

    // copy initialization
    // -------------------

    // SocialInsurance another_instance = SocialInsurance::instance();

    // copy assignment
    // ---------------

    // another_instance = SocialInsurance::instance();

    return 0;
}
