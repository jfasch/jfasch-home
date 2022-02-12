#include <algorithm>
#include <string>
#include <vector>
#include <cassert>

#include <iostream>
using namespace std;


static bool greater_than(int l, int r)
{
    return l > r;
}

int main()
{
    {
        int array[] = { 34, 45, 1, 3, 2, 666 };
        std::sort(array, array+6);
        
        for (int i=0; i<6; i++)
            cout << array[i] << endl;
    }

    {
        std::vector<std::string> array;
        array.push_back("Joerg");
        array.push_back("Philipp");
        array.push_back("Caro");
        array.push_back("Johanna");

        // '<' is defined on strings (this is why sort() works with
        // strings)
        assert(array[2] < array[0]);
        
        std::sort(array.begin(), array.end());

        for (size_t i=0; i<array.size(); i++)
            cout << array[i] << endl;
    }

    // reverse sort
    {
        int array[] = { 34, 45, 1, 3, 2, 666 };

        std::sort(array, array+6, greater_than);
        
        for (int i=0; i<6; i++)
            cout << array[i] << endl;
    }

    return 0;
}
