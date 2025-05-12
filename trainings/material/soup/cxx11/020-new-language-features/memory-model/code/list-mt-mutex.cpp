#include <list>
#include <array>
#include <thread>
#include <mutex>
#include <iostream>

int main()
{
    const unsigned long numtimes = 1000*1000UL;
    std::list<int> ints;
    std::mutex ints_lock;

    auto threadfunc = [&ints, &ints_lock](){
        unsigned long n = numtimes;
        while (n--) { 
            ints_lock.lock();                          // <-- acquire
            ints.push_back(666);
            ints_lock.unlock();                        // <-- release
        }
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
