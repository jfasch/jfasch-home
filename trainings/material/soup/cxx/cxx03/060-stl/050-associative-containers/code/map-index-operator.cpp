#include <map>
#include <iostream>

int main()
{
    std::map<int, std::string> my_map;

    my_map[1] = "one";
    my_map[2] = "two";

    std::cout << ':' << my_map[1] << ":\n";
    std::cout << ':' << my_map[2] << ":\n";

    return 0;
}
