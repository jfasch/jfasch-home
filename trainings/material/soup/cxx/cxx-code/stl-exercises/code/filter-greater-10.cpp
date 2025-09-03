#include "filter-greater-10.h"

using namespace std;

vector<int> filter_greater_10(const vector<int>& input)
{
    vector<int> output;

    for (int elem: input)
        if (elem > 10)
            output.push_back(elem);

    return output;
}
