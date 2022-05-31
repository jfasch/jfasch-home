#include <iostream>
using namespace std;

class LackingDefaultConstructor
{
public:
    LackingDefaultConstructor(const std::string& s) : _s{s} {}
    const std::string& str() const { return _s; }
private:
    const std::string _s;
};

int main()
{
    LackingDefaultConstructor ldc;
    cout << ldc.str() << endl;;
    return 0;
}
