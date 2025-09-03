#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    string s;
    cin >> s;

    std::reverse(s.begin(), s.end());

    cout << s << endl;

    return 0;
}
