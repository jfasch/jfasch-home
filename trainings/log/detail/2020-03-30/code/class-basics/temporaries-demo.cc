#include <string>
#include <iostream>

using namespace std;


void print_a_string(string s)
{
    cout << s << endl;
}

int main()
{
    const char* s = "hallo";
    print_a_string(s); // temporary string("hallo")

    string a("a");
    string b("b");
    string c(a+b); // temporary holding a+b

    cout << c << endl;

    return 0;
}
