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

    auto [iter, inserted] = my_map.insert(std::make_pair(7, "sieben"));  // <--- even less clumsy 
    if (inserted) {                                                      // <--- cool
        std::cout << "7 is in" << std::endl;
        std::cout << "key: " << iter->first << std::endl;                // <--- cool
        std::cout << "value: " << iter->second << std::endl;             // <--- cool
    }

    return 0;
}
