#include <map>
#include <string>
#include <iostream>

using MyMap = std::map<int, std::string>;    // <--- pre C++11 has no "using"

int main()
{
    MyMap my_map;                            // <--- pre C++11, there is only default initialization
    my_map[2] = "zwei";
    my_map[51] = "einundfuenfzig";
    my_map[54] = "vierundfuenfzig";
    my_map[346] = "dreihundertsechsundvierzig";
    my_map[1001] = "tausendeins";
    my_map[1002] = "tausendzwei";

    std::cout << my_map.size() << std::endl;

    return 0;
}
