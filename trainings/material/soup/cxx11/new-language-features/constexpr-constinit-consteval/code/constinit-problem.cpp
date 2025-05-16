#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>

unsigned sequence;
std::mutex sequence_lock;                              // <-- initialized at runtim

int main()
{
    auto use_sequence = [](const char* name) {
        using namespace std::chrono_literals;
        while (true) {
            sequence_lock.lock();
            unsigned num = ++sequence;
            sequence_lock.unlock();
            std::cout << name << ": " << num << '\n';
            std::this_thread::sleep_for(500ms);
        }
    };

    std::thread t1(use_sequence, "thread 1");
    std::thread t2(use_sequence, "thread 2");

    t1.join();
    t2.join();

    return 0;
}
