#include <iostream>
using namespace std;

int sum(int *begin, int *end)        // <--- pass in *range delimiters* [begin, end)
{
    int sum = 0;
    while (begin != end)
        sum += *begin++;
    return sum;
}

int main()
{
    int a[3] = {100, 200, 300};
    cout << sum(a, a+3) << endl;
    return 0;
}
