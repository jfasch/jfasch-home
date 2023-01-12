#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[3] = {100, 200, 300};
    int dst[3];
    copy(a, a+3, dst);           // <--- std::copy<>() from <algorithm>

    for (int i: dst)
        cout << i << endl;
    return 0;
}
