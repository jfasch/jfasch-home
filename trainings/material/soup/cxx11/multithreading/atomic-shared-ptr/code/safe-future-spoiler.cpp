#include <iostream>
#include <memory>
#include <thread>

int main()
{
    auto p = std::make_shared<int>(42);
    auto threadfunc = [p](){
        while (true)
            auto local_p = p;
    };
    std::thread t1(threadfunc);
    std::thread t2(threadfunc);

    std::cout << p.use_count() << std::endl;           // <-- moving target but safe

    t1.join();
    t2.join();
    return 0;
}
