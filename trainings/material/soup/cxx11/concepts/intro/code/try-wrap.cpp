#include <concepts>
#include <vector>
#include <iostream>

template <typename CONTAINER>
concept begin_is_copyable = requires(CONTAINER c) {
    requires std::copyable<decltype(std::begin(c))>;
};

template <typename T>
requires begin_is_copyable<T>
bool foo(T t)
{
    return true;
}

int main()
{
    std::vector<int> v;
    std::cout << foo(v) << std::endl;
    return 0;
}
