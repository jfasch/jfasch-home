#ifndef STRING_H
#define STRING_H

#include <cstring>

class String
{
public:
    String() : _c_str(nullptr) {}
    String(const char* s)
    : _c_str(new char[strlen(s)+1])
    {
        strcpy(_c_str, s);
    }
    ~String()
    {
        delete[] _c_str;
    }

    String(const String&) = delete;             // <--- delete copy ctor
    String& operator=(const String&) = delete;  // <--- delete copy assignment operator

    const char* c_str() const { return _c_str; }
    size_t size() const { return (_c_str == nullptr)? 0 : strlen(_c_str); }

private:
    char* _c_str;
};

#endif
