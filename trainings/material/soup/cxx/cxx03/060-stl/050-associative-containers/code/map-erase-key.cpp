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

    size_t n_removed = my_map.erase(1001);
    std::cout << "Number of elements removed: " << n_removed << std::endl;
    std::cout << "Numer of elements remaining: " << my_map.size() << std::endl;

    return 0;
}
