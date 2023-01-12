#include "filter-odd.h"

using namespace std;

vector<int> filter_odd(const vector<int>& input)
{
    vector<int> output;

    for (int elem: input)
        if (elem % 2 == 1)
            output.push_back(elem);

    return output;
}
