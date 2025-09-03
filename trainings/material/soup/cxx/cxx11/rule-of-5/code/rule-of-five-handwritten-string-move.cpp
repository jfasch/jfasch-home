#include <iostream>
#include <cstring>
#include <utility>

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

    MyString(const MyString& from)
    : MyString(from._cstr) {}
    MyString& operator=(const MyString& from)
    {
        if (this != &from) {
            delete[] _cstr;
            _cstr = new char[strlen(from._cstr) + 1];
            strcpy(_cstr, from._cstr);
        }
        return *this;
    }

    // move
    MyString(MyString&& from)
    : _cstr(std::exchange(from._cstr, new char[1]{'\0'})) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    MyString& operator=(MyString&& from)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        if (this != &from) {                           // <-- self move check
            delete[] _cstr;
            _cstr = std::exchange(from._cstr, new char[1]{'\0'});
        }
        return *this;
    }

private:
    char* _cstr;
};

int main()
{
    MyString orig("howdy");
    MyString copy1 = std::move(orig);                  // <-- calling move ctor
    copy1 = std::move(copy1);

    return 0;
}
