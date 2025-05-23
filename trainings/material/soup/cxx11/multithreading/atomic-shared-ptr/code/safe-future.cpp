#include <iostream>
#include <memory>
#include <thread>
#include <future>

int main()
{
    std::promise<void> started_promise;
    auto started_future = started_promise.get_future();

    auto p = std::make_shared<int>(42);
    auto threadfunc = [p, &started_promise](){
        started_promise.set_value();                   // <-- kick waiter loose
        while (true)
            auto local_p = p;
    };
    std::thread t(threadfunc);

    started_future.get();                              // <-- wait until kicked
    std::cout << p.use_count() << std::endl;

    t.join();
    return 0;
}
