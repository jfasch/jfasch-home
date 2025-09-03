#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    string s("abc");

    string reversed_s(s.size(), '*');
    std::reverse_copy(s.cbegin(), s.cend(), reversed_s.begin());
    cout << reversed_s << endl;

    return 0;
}
