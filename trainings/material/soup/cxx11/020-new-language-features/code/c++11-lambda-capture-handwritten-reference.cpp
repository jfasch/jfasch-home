#include <functional>
#include <string>
#include <iostream>

class print_message_func
{
public:
    print_message_func(const std::string& message) : _message(message) {}
    void operator()()
    {
        std::cout << _message << std::endl;  // using reference! STILL VALID?
    }
private:
    const std::string& _message;
};


static std::function<void()> create_print_function(const std::string& message)
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
