#ifndef STRING_H
#define STRING_H

#include <cstring>

class String
{
public:
    String(const char* s)
    : _c_str(new char[strlen(s)+1])
    {
        strcpy(_c_str, s);
    }

    String(const String& other)    // <--- duplicate of String(const char*)
    : _c_str(new char[strlen(other._c_str)+1])
    {
        strcpy(_c_str, other._c_str);
    }

    ~String()
    {
        delete[] _c_str;
    }

private:
    char* _c_str;
};

#endif
