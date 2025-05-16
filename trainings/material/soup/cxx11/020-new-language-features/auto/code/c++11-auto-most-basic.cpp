#include <iostream>
using namespace std;

int main()
{
    int i = 42;
    auto j = i; // int j

    cout << "i: " << i << ", &i: " << &i << endl;
    cout << "j: " << j << ", &j: " << &j << endl;

    return 0;
}

