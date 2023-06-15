#include <coroutine>
#include <generator>
#include <iostream>
#include <vector>


stdL::generator<int> cycle(const std::vector<int>& elems)
{
    auto the_elems = elems;
    while (true)
        for (const auto& e: the_elems)
            co_yield e;
}

int main()
{
    auto c = cycle({1,2,3,4});

    for (;;) {
        std::cout << c.next() << std::endl;
        c.resume();
    }

    return 0;
}
