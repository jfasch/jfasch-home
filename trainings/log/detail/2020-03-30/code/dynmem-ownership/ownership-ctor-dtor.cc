#include <unistd.h>
#include <iostream>

using namespace std;


class Allocates
{
public:
    Allocates(const string& name, size_t n)
    : _name(name), _mem(new char[n])
    {
        cout << _name << " ctor" << endl;
    }

    ~Allocates()
    {
        delete[] _mem;
        cout << _name << " dtor" << endl;
    }

private:
    string _name;
    char* _mem;
};

int main()
{
    Allocates allocs1("eins", 28);
    Allocates allocs2("zwei", 28);
    Allocates allocs3("drei", 28);
    Allocates* allocs4 = new Allocates("vier", 28);
    (void)allocs4; // shutup compiler "unused" warning
    cout << "return" << endl;
    delete allocs4;
    return 0;
}
