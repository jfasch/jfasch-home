#include <iostream>
#include <string>
#include <vector>

class Something
{
public:
    std::string s;
    std::vector<int> ints;
};

int main()
{
    Something sth;
    std::cout << "sth.s: \"" << sth.s << '"' << std::endl;
    std::cout << "sth.ints.size(): " << sth.ints.size() << std::endl;
    return 0;
}
