#include <iostream>
using namespace std;

#include <algorithm>


int main()
{
    int original[] = { 34, 45, 1, 3, 2, 666 };
    int copy[6];

    // for (int i=0; i<6; i++)
    //     copy[i] = original[i];

    const int* original_begin = original;
    const int* original_end = original + 6;

    // int* copy_run = copy;
    // const int* original_run = original_begin;
    // while (original_run != original_end)
    //     *copy_run++ = *original_run++;

    std::copy(original_begin, original_end, copy);

    for (int i=0; i<6; i++)
        cout << copy[i] << endl;

    return 0;
}
