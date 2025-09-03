#include "filter.h"

using namespace std;

vector<int> filter(const vector<int>& input, bool(*func)(int))
{
    vector<int> output;

    for (int elem: input)
        if (func(elem))
            output.push_back(elem);

    return output;
}
