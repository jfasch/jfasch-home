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

    auto elem = my_map.find(1001);   // <--- points to valid tree element
    my_map.erase(elem);              // <--- removes that element

    std::cout << my_map.size() << std::endl;

    return 0;
}
