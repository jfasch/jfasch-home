#include <iostream>
using namespace std;

int main()
{
    int a[3] = {100, 200, 300};

    int *a_begin = a;
    int *a_end = a + 3;

    int *run = a_begin;
    while (run != a_end)
        cout << *run++ << endl;       // <--- explicit precedence: *(run++)

    return 0;
}
