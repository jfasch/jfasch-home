#include "mystring.h"

#include <string.h>


MyString::MyString()
: _str(new char[1]), _size(0)
{
    *_str = 0;
}

MyString::MyString(const char* rhs)
: _str(new char[strlen(rhs)+1]),
  _size(strlen(rhs))
{
    memcpy(_str, rhs, _size+1);
}

MyString::MyString(const MyString& rhs)
: _str(new char[rhs._size+1]),
  _size(rhs._size)
{
    memcpy(_str, rhs._str, rhs._size+1);
}

MyString& MyString::operator=(const MyString& rhs)
{
    if (this == &rhs) // self assignment?
        return *this;

    delete[] _str;
    _str = new char[rhs._size+1];
    _size = rhs._size;
    memcpy(_str, rhs._str, _size+1);
    return *this;
}

MyString::~MyString()
{
    delete[] _str;
}
