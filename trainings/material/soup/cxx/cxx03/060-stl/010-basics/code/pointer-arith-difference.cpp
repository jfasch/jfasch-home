#include <iostream>
using namespace std;

int main()
{
    int a[3] = {100, 200, 300};

    int *a_begin = a;                                     // <--- pointer to first element
    int *a_end = a + 3;                                   // <--- pointer *past* last element

    cout << "num.elements: " << a_end - a_begin << endl;  // <--- "distance" - number of elements

    return 0;
}
