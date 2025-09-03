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

    MyMap::iterator found = my_map.find(1001);
    if (found != my_map.end())
        std::cout << "1001 found, value is " << found->second << std::endl;
    else
        std::cout << "1001 not found" << std::endl;

    return 0;
}
