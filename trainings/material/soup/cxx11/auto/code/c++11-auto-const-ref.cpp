#include <iostream>
using namespace std;

int main()
{
    int i = 42;
    const auto& ciref = i;

    cout << "i: " << i << ", &i: " << &i << endl;
    cout << "ciref: " << ciref << ", &ciref: " << &ciref << endl;

    return 0;
}

