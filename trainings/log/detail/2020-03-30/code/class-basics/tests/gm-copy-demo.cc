#include <string>
#include <iostream>

using namespace std;


struct Trivial
{
    string str;
};

int main()
{
    Trivial t1; // default ctor

    cout << "t1 (before assignment): " << t1.str << endl;
    t1.str = "hallo";

    Trivial t2 = t1;  // initialization: copy ctor
    cout << "t2: " << t2.str << endl;

    Trivial t3(t1);  // same: initialization: copy ctor
    cout << "t3: " << t3.str << endl;

    Trivial t4;
    cout << "t4 (initially): " << t4.str << endl;

    t4 = t1; // assignment operator
    cout << "t4 (after assignment): " << t4.str << endl;

    return 0;
}
