#include <list>
#include <array>
#include <thread>
#include <mutex>
#include <iostream>

class spinlock
{
public:
    void lock()
    {
        while (true) {
            bool oldstate = _flag.test_and_set(std::memory_order::acquire);
            if (oldstate == false)                     // <-- flag changed to true -> **locked**
                break;
        }
    }
    void unlock()
    {
        _flag.clear(std::memory_order::release);       // <-- send "open" to reader
    }
private:
    std::atomic_flag _flag;
};

int main()
{
    const unsigned long numtimes = 1000*1000UL;
    std::list<int> ints;
    spinlock ints_lock;                                // <-- mutex replacement

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

