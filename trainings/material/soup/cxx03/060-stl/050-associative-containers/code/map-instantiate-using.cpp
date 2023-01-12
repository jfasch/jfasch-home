#include <map>
#include <string>
#include <iostream>

using MyMap = std::map<int, std::string>;

int main()
{
    MyMap my_map;         // <--- more readable, at least
    std::cout << my_map.size() << std::endl;
    return 0;
}
