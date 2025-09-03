#include <iostream>

auto add(auto lhs, auto rhs) {
    return lhs + rhs;
};

int main()
{
    std::cout << add(1, 2) << '\n';
    return 0;
}
