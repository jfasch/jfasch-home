#include <functional>
#include <string>
#include <cstring>
#include <iostream>

struct String
{
    String(const char* s)
    : s(new char[strlen(s)+1])
    {
        strcpy(this->s, s);
        std::cout << "ctor" << std::endl;
    }
    ~String()
    { 
        std::cout << "dtor" << std::endl;        
        delete[] s;
    }
    char* s;
};

class print_message_func
{
public:
    print_message_func(const String& message) : _message(message) {}
    void operator()()
    {
        std::cout << _message.s << std::endl;  // using reference! STILL VALID?
    }
private:
    const String& _message;
};


static std::function<void()> create_print_function(const String& message)
{
    auto print_message = print_message_func(message);
    return print_message;
}

int main()
{
    auto p = create_print_function("howdy");  // <--- temporary std::string object; LIFETIME?
    p();
    return 0;
}
