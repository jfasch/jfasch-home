#include "uniq.h"

#include <set>
using namespace std;

vector<int> uniq(const vector<int>& input)
{
    vector<int> output;
    set<int> seen;
    for (int elem: input) {
        if (seen.contains(elem))
            continue;
        seen.insert(elem);
        output.push_back(elem);
    }

    return output;
}
