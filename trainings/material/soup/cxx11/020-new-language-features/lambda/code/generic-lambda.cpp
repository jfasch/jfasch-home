#include <iostream>

int main()
{
    auto add = [](auto lhs, auto rhs) {
        return lhs + rhs;
    };

    std::cout << add(1, 2) << '\n';
    return 0;
}
