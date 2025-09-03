#include <iostream>
using namespace std;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"

int main()
{
    int a[3] = {100, 200, 300};
    int *pa = a;

    pa += 3;                                // <--- ERROR: out of range: pa points behind last element!!

    cout << "[3]: " << *pa << endl;

    pa -= 4;                                // <--- ERROR: out of range: pa points before first element!!
    cout << "[-1]: " << *pa << endl;

    return 0;
}

#pragma GCC diagnostic pop
