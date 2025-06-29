#include <print>
#include <format>
#include <iostream>
#include <type_traits>

int main()
{
    // https://learnmoderncpp.com/2021/03/24/a-unicode-primer/
    {
        auto cp = u8"\u20AC";  // <-- since C++20

        // iostream has no specialization for char8_t*
        std::cout << (const char*)cp << std::endl; // <-- terminal supports utf-8

        std::cout << sizeof(cp) << std::endl;  // <-- 8
        std::cout << std::is_pointer_v<decltype(cp)> << std::endl; // <-- yes

        std::u8string s = cp;
        // std::cout << s << std::endl; // nix
        // std::format("{}", s); // nix
    }

    // https://learnmoderncpp.com/2024/11/15/additional-unicode-support-in-c/
    {
        
    }

    return 0;
}
