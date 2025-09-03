#include <iostream>
#include <cstring>

class MyString
{
public:
    MyString()
    {
        _cstr = new char[1]{'\0'};
    }
    MyString(const char* cstr)
    {
        _cstr = new char[strlen(cstr) + 1];
        strcpy(_cstr, cstr);
    }
    ~MyString()
    {
        delete[] _cstr;
    }

    // copy
    MyString(const MyString& from)                     // <-- copy constructor
    : MyString(from._cstr) {}                          // <-- delegating constructor
    MyString& operator=(const MyString& from)          // <-- copy assignment operator
    {
        delete[] _cstr;
        _cstr = new char[strlen(from._cstr) + 1];
        strcpy(_cstr, from._cstr);
        return *this;
    }

private:
    char* _cstr;
};

int main()
{
    MyString orig("howdy");
    MyString copy1 = orig;                             // <-- compiler generated copy ctor: RIGHT!!

    copy1 = copy1;                                     // <-- self assignment: WRONG!!

    return 0;
}
