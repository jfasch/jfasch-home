#include <variant>
#include <cstdint>
#include <iostream>

int main()
{
    {
        std::variant<uint8_t, uint8_t> v;
        std::cout << sizeof(v) << std::endl;
    }
    return 0;
}
