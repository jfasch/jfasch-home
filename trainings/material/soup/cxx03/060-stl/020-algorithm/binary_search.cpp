#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>


int main()
{
    std::vector<int> array = { 34, 45, 1, 3, 2, 666 };

    // binary search requires the array to be sorted
    std::sort(array.begin(), array.end());

    // now we are prepared to search binarily
    bool is_element = std::binary_search(array.begin(), array.end(), 666);
    cout << "666 is an element: " << is_element << endl;

    return 0;
}
