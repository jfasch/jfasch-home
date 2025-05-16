#include <atomic>
#include <thread>
#include <array>
#include <iostream>
#include <cassert>

int main()
{
    const unsigned long numtimes = 1000*1000*1000UL;
    std::atomic<unsigned long> counter = 0;

    auto threadfunc = [&counter]() {
        unsigned long n = numtimes;
        while (n--)
            counter++;
    };

    std::array threads{
        std::thread(threadfunc),
        std::thread(threadfunc),
    };
    for (auto& t: threads)
        t.join();

    std::cout << "expected " << threads.size()*numtimes << ", real " <<  counter << '\n';

    return 0;
}
