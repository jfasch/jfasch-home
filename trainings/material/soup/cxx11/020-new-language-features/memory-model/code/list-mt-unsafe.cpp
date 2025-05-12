#include <list>
#include <array>
#include <thread>
#include <iostream>

int main()
{
    const unsigned long numtimes = 1000*1000UL;
    std::list<int> ints;

    auto threadfunc = [&ints](){
        unsigned long n = numtimes;
        while (n--)
            ints.push_back(666);                       // <-- non-atomic two-pointer update
    };

    std::array threads{
        std::thread(threadfunc),
        std::thread(threadfunc),
    };
    for (auto& t: threads)
        t.join();

    std::cout << "#elements: " << ints.size() << '\n';

    return 0;
}
