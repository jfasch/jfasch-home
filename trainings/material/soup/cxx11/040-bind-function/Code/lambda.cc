#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

struct X
{
    X(const string& s)
    : s(s)
    {
        cout << "X(const string& s)" << endl;
    }
    X(string&& s)
    : s(s)
    {
        cout << "X(string&& s)" << endl;
    }

    string s;
};

int main()
{
    X x{"abc"};
    X y{x.s};
    X z{std::move(y)};

    cout << x.s << endl;
    cout << y.s << endl;
    cout << z.s << endl;

    return 0;
}
