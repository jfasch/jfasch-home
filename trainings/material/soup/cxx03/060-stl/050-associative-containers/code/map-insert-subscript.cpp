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

    my_map[7] = "sieben";                // <--- create new entry
    my_map[2] = "two";                   // <--- overwrites existing entry

    std::cout << my_map[2] << std::endl; // <--- will print "two"

    return 0;
}
