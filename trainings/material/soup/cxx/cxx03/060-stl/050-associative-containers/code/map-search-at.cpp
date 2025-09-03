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

    try {
        std::string found_value = my_map.at(1001);
        std::cout << "1001 found, value is " << found_value << std::endl;
    } catch (const std::out_of_range&) {
        std::cout << "1001 not found" << std::endl;
    }

    return 0;
}
