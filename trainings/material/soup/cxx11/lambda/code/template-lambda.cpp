#include <iostream>

int main()
{
    auto add = []<typename LHS, typename RHS>(LHS lhs, RHS rhs) {
        return lhs + rhs;
    };

    std::cout << add(1, 2) << '\n';
    return 0;
}
