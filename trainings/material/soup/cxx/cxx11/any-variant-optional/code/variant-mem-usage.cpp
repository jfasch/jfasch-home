#include <variant>
#include <cstdint>
#include <iostream>

struct T1
{
    uint32_t m1;
    char m2;
};

struct T2
{
    uint16_t m1;
    char m2;
};

int main()
{
    {
        std::variant<uint8_t, uint8_t> v;
        std::cout << "std::variant<uint8_t, uint8_t>: " << sizeof(v) << std::endl;
    }
    {
        std::variant<uint32_t, uint32_t> v;
        std::cout << "std::variant<uint32_t, uint32_t>: " << sizeof(v) << std::endl;
    }
    {
        std::variant<uint32_t, uint64_t> v;
        std::cout << "std::variant<uint32_t, uint64_t>: " << sizeof(v) << std::endl;
    }
    {
        std::variant<T1, T2> v;
        std::cout << sizeof(T2) << std::endl;
        std::cout << "std::variant<T1, T2>: " << sizeof(v) << std::endl;
    }
    return 0;
}
