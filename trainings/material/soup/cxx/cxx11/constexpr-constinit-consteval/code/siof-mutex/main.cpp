#include <mutex>
#include <thread>
#include <iostream>

extern std::mutex the_mutex;

std::thread the_thread([](){
    the_mutex.lock();
    std::cout << "inside critical section" << std::endl;
    the_mutex.unlock();
});

int main()
{
    the_thread.join();
    return 0;
}
