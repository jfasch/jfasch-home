#include <iostream>
#include <memory>
#include <thread>

int main()
{
    auto p = std::make_shared<int>(42);
    auto threadfunc = [p](){                           // <-- copy
        while (true)
            auto local_p = p;                          // <-- copy
    };
    std::thread t1(threadfunc);
    std::thread t2(threadfunc);
    t1.join();
    t2.join();
    return 0;
}
