#include <iostream>
using namespace std;

class HasDefaultConstructor
{
public:
    HasDefaultConstructor() {} // <---- HMPF!
    HasDefaultConstructor(const std::string& s) : _s{s} {}
    const std::string& str() const { return _s; }
private:
    const std::string _s;
};

int main()
{
    HasDefaultConstructor hdc;
    cout << hdc.str() << endl;;
    return 0;
}
