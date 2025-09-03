#include <iostream>
#include <cstring>

class MyString
{
public:
    MyString()
    {
        _cstr = new char[1]{'\0'};                     // <-- allocation
    }
    MyString(const char* cstr)
    {
        _cstr = new char[strlen(cstr) + 1];
        strcpy(_cstr, cstr);                           // <-- allocation
    }
    ~MyString()
    {
        delete[] _cstr;                                // <-- deallocation
    }

private:
    char* _cstr;
};

int main()
{
    MyString orig("howdy");
    MyString copy1 = orig;                             // <-- compiler generated copy ctor: WRONG!!

    return 0;
}
