#include <iostream>
using namespace std;

int main()
{
    int array[] = { 1, 2, 3 };
    auto p = array;

    cout << "array: " << array << ", &array: " << &array << endl;
    cout << "p: " << p << endl;

    return 0;
}
