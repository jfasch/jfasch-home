#include <iostream>
#include <string.h>
#include <string>

class String
{
public:
    String(const char* s)
    {
        _str = new char[strlen(s)+1];
        strcpy(_str, s);
    }

    String(const String& s)
    {
        _str = new char[strlen(s._str) + 1];
        strcpy(_str, s._str);
    }

    String(String&& s) // move ctor
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        _str = s._str;
        s._str = nullptr;
    }

    String& operator=(const String& s)
    {
        if (this != &s) {
            delete[] _str;
            _str = new char[strlen(s._str) + 1];
            strcpy(_str, s._str);
        }
        return *this;
    }

    ~String()
    {
        delete[] _str;
    }
    const char* c_str() const { return _str; }

private:
    char* _str;
};


int main()
{
    String orig("hallo");
    // std::cout << orig.c_str() << std::endl;
    // String copy(orig);
    // std::cout << copy.c_str() << std::endl;

    // String another_copy("weg damit");
    // another_copy = copy;
    // std::cout << another_copy.c_str() << std::endl;

    // another_copy = another_copy;

    String moved(std::move(orig));

    std::cout << orig.c_str() << std::endl;
    std::cout << moved.c_str() << std::endl;

    return 0;
}
