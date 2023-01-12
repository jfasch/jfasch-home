#include <map>
#include <string>
#include <iostream>

int main()
{
    std::map<int, std::string> my_map;         // <--- much typing (if done repeatedly)
    std::cout << my_map.size() << std::endl;
    return 0;
}
