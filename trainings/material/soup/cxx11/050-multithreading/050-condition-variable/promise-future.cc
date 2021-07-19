#include <future>
#include <thread>
#include <iostream>


int main()
{
    // as promised *by worker*: will be ready in the future
    std::promise<int> promise;
    // a handle to the bright future; somebody can wait if he wants
    std::future<int> future = promise.get_future();

    std::thread([&promise]() {
            // countdown
            int i=5;
            while (i) {
                std::cout << i-- << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
            // fire
            std::cout << "fire!" << std::endl;
            promise.set_value(666);
        }).detach();

    std::cout << "waiting for future" << std::endl;
    std::cout << "result: " << future.get() << std::endl;
}
