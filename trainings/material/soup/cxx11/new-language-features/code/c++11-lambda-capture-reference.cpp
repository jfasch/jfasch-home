#include <functional>
#include <string>
#include <iostream>


static std::function<void()> create_print_function(const std::string& message)
{
    auto print_message = [&message](){    // <--- message is 'captured into the closure of function object "print_message"'
        std::cout << message << std::endl;
    };
    return print_message;
}

int main()
{
    auto p = create_print_function("howdy");
    p();
    return 0;
}
