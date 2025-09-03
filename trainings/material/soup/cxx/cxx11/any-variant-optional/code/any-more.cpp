#include <any>
#include <iostream>


int main()
{
    std::string s = "howdy";
    std::string& r = s;

    std::any a = r;
    std::cout << std::any_cast<std::string>(a) << std::endl;

    s = "joerg";
    std::cout << std::any_cast<std::string>(a) << std::endl;

    std::string& evil = std::any_cast<std::string&>(a);
    evil = "harhar";
    std::cout << std::any_cast<std::string>(a) << std::endl;
    
    return 0;
}
