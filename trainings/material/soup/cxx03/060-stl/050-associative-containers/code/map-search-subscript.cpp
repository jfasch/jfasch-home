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

    std::cout << "# before 1001 " << my_map.size() << std::endl;
    std::string found_value_1001 = my_map[1001];                // <--- 1001 is an element
    std::cout << "1001 string: >" << found_value_1001 << '<' << std::endl;

    std::cout << "# before 666 " << my_map.size() << std::endl;
    std::string found_value_666 = my_map[666];                  // <--- 666 is *not* an element
    std::cout << "666 string: >" << found_value_666 << '<' << std::endl;

    std::cout << "# after 666 " << my_map.size() << std::endl;  // <--- inserted one element!!!

    return 0;
}
