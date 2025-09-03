#include <string>
#include <iostream>

using namespace std;



int main()
{
    string s;
    cin >> s;

    string reversed_s;

    for (int i=s.size()-1; i>=0; i--)
        reversed_s += s[i];

    cout << reversed_s << endl;

    return 0;
}
