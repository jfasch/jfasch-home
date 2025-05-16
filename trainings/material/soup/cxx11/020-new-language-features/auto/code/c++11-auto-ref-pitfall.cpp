#include <iostream>
using namespace std;

int main()
{
    int i = 42;
    int& iref = i;
    auto j = iref;   // <--- int j (not reference)

    j = 666;  // does *not* assign through to i

    cout << "i: " << i << ", &i: " << &i << endl;
    cout << "iref: " << iref << ", &iref: " << &iref << endl;
    cout << "j: " << j << ", &j: " << &j << endl;

    return 0;
}

