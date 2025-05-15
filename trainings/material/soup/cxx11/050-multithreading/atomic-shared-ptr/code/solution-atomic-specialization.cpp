#include <memory>
#include <thread>

int main()
{
    std::atomic<std::shared_ptr<int>> p = std::make_shared<int>(42);
    auto threadfunc = [&p](){
        while (true)
            p = std::make_shared<int>(666);
    };
    std::thread t1(threadfunc);
    std::thread t2(threadfunc);
    t1.join();
    t2.join();
    return 0;
}
