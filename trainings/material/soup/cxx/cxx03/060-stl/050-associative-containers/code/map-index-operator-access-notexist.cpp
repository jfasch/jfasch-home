#include <map>
#include <iostream>

int main()
{
    std::map<int, std::string> my_map;
    std::cout << ':' << my_map[666] << ":\n";
    return 0;
}
