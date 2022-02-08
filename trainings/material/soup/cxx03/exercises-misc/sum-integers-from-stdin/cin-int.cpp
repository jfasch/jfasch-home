#include <iostream>

using namespace std;


int main()
{
    int i;

    while (true) {
        cin >> i;
        if (cin.eof())
            break;
        cout << i << endl;
    }
    
    return 0;
}
