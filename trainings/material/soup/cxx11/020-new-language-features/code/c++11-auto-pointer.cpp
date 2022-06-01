#include <iostream>
using namespace std;

int main()
{
    int i = 42;
    auto* pi = &i;

    *pi = 666;

    cout << "i: " << i << ", &i: " << &i << endl;
    cout << "pi: " << pi << endl;

    return 0;
}

