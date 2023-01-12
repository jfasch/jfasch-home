#include <iostream>
using namespace std;

void copy(int *src_begin, int *src_end, int *dst_begin)
{
    while (src_begin != src_end)
        *dst_begin++ = *src_begin++;
}

int main()
{
    int a[3] = {100, 200, 300};
    int dst[3];
    copy(a, a+3, dst);

    for (int i: dst)                  // <--- "range based for" from C++11
        cout << i << endl;
    return 0;
}
