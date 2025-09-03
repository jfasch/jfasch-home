#include <map>
#include <string>
#include <iostream>

using MyMap = std::map<int, std::string>;

int main()
{
    const MyMap my_map = {                    // <--- this is *initialization*, hence can be const
        { 2, "zwei" },                        // <--- value_type: std::pair<int, std::string>
        { 51, "einundfuenfzig" },             // <--- value_type: std::pair<int, std::string>
        { 54, "vierundfuenfzig" },            // <--- value_type: std::pair<int, std::string>
        { 346, "dreihundertsechsundvierzig" },// <--- value_type: std::pair<int, std::string>
        { 1001, "tausendeins" },              // <--- value_type: std::pair<int, std::string>
        { 1002, "tausendzwei" },              // <--- value_type: std::pair<int, std::string>
    };

    std::cout << my_map.size() << std::endl;

    return 0;
}
