#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>


bool match_666(int i)
{
    return i == 666;
}
bool match_42(int i)
{
    return i == 42;
}

int main()
{
    // find_if on a plain old C array
    {
        int array[] = { 34, 45, 1, 3, 2, 666 };

        // find/search the number 666 (for example)

        // nobody wants index based iteration
        for (int i=0; i<6; i++) {
            if (array[i] == 666) {
                cout << "yay, found at position " << i << endl;
                break;
            }
        }

        // nobody wants pointer arithmetic done manually

        const int* run = array;
        const int* end = array + 6;

        while (run < end) {
            if (*run == 666) {
                cout << "yay, found at position " << run << endl;
                break;
            }
            run++;
        }
        cout << *run << endl;


        // some want to use std::find_if
        const int* found = std::find_if(array, array+6, match_666);
        cout << *found << endl;
    }

    // now for STL vector
    {
        // nobody wants old-style vector "initialize"
        {
            std::vector<int> array;
            array.push_back(34);
            array.push_back(45);
            array.push_back(1);
            array.push_back(3);
            array.push_back(2);
            array.push_back(666);
        }

        // everybody wants *brace initialization* (since C++11)
        std::vector<int> array = { 34, 45, 1, 3, 2, 666 };

        std::vector<int>::const_iterator found = std::find_if(array.begin(), array.end(), match_666);
        cout << *found << endl;

        found = std::find_if(array.begin(), array.end(), match_42);
        if (found == array.end())
            cout << "not found" << endl;
        else
            cout << *found << endl;
    }

    return 0;
}
