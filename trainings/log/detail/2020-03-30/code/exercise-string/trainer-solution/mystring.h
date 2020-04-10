#ifndef __HAVE_MYSTRING_H__
#define __HAVE_MYSTRING_H__

#include <unistd.h>


class MyString
{
public:
    MyString();
    MyString(const char* rhs);
    MyString(const MyString& rhs);
    MyString& operator=(const MyString&);
    ~MyString();

    const char* str() const { return _size? _str: ""; }
    size_t size() const { return _size; }

private:
    char* _str;
    size_t _size;
};

#endif
