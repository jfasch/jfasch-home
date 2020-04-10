#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;


int main()
{
    string s;

    // string size and capacity
    {
        cout << "1: size " << s.size() << ", capacity " << s.capacity() << endl;

        s += "hallo";
        cout << "2: size " << s.size() << ", capacity " << s.capacity() << endl;

        s += "hallohallo";
        cout << "3: size " << s.size() << ", capacity " << s.capacity() << endl;

        s += "1";
        cout << "4: size " << s.size() << ", capacity " << s.capacity() << endl;
    }

    // don't do this:
    {
        const char* strings_content = s.c_str();
        printf("content: %s\n", strings_content);

        delete[] strings_content;
    }
    
    return 0;
}
