#include <thread>


int main()
{
    std::thread t1([](){for(;;);});
    std::thread t2([](){for(;;);});

    t1.join();
    t2.join();

    return 0;
}
