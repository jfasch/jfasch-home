#include <iostream>
using namespace std;

int main()
{
    int a[3] = {100, 200, 300};             // <--- holds 3 integers
    int *pa = a;                            // <--- a "decays" to pointer to zeroth element
    cout << "[0]: " << *pa << endl;

    pa++;                                   // <--- advance to next element ([1])
    cout << "[1]: " << *pa << endl;

    pa++;                                   // <--- advance to next element ([2])
    cout << "[2]: " << *pa << endl;         // <--- last element; still well

    pa--;
    cout << "[1] again: " << *pa << endl;   // <--- back to [1]

    return 0;
}
