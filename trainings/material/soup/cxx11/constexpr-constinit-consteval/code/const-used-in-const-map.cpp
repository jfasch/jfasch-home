#include <map>
#include <iostream>

const int key = 7;
const int value = 42;
const std::map<int, int> the_map{{key, value}};

int main()
{
    std::cout << the_map.at(key) << '\n';
    return 0;
}
