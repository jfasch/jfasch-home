#include "sorted.h"

#include <algorithm>
using namespace std;


vector<int> sorted(const vector<int>& input)
{
    vector<int> copy = input;
    sort(copy.begin(), copy.end());
    return copy;
}
