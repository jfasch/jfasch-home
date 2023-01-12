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

    std::pair<MyMap::iterator, bool> retval_7 =                        // <--- clumsy
        my_map.insert(std::make_pair(7, "sieben"));
    if (retval_7.second) {                                             // <--- inserted? (yes) 
        std::cout << "7 is in" << std::endl;
        std::cout << "key: " << retval_7.first->first << std::endl;    // <--- retval's "first" points to element
        std::cout << "value: " << retval_7.first->second << std::endl; // <--- retval's "first" points to element
    }

    std::pair<MyMap::iterator, bool> retval_2 =                        // <--- clumsy
        my_map.insert(std::make_pair(7, "sieben"));
    if (! retval_2.second)                                             // <--- inserted? (no)
        std::cout << "2 is not in" << std::endl;

    return 0;
}
