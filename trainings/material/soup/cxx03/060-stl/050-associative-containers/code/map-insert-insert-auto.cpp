#include <map>
#include <string>
#include <iostream>

using MyMap = std::map<int, std::string>;

int main()
{
    MyMap my_map = {
        { 2, "zwei" },
        { 51, "einundfuenfzig" },
        { 54, "vierundfuenfzig" },
        { 346, "dreihundertsechsundvierzig" },
        { 1001, "tausendeins" },
        { 1002, "tausendzwei" },
    };

    auto retval = my_map.insert(std::make_pair(7, "sieben"));       // <--- not so clumsy 
    if (retval.second) {
        std::cout << "7 is in" << std::endl;
        std::cout << "key: " << retval.first->first << std::endl;
        std::cout << "value: " << retval.first->second << std::endl;
    }

    return 0;
}
