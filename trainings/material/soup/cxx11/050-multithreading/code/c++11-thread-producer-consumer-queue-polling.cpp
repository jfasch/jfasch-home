#include <thread>
#include <mutex>
#include <chrono>
#include <deque>
#include <iostream>


static const int PRODUCE_INTERVAL_MS = 500;
static const int POLL_INTERVAL_MS = 2;

int main()
{
    std::mutex lock;
    std::deque<int> queue;

    std::thread producer([&lock, &queue]() {
        int i = 0;
        while (true) {
            lock.lock();
            queue.push_back(i++);
            lock.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(PRODUCE_INTERVAL_MS));
        }
    });

    std::thread consumer([&lock, &queue]() {
        while (true) {
            lock.lock();
            while (queue.size() > 0) {
                int i = queue.front();
                queue.pop_front();
                std::cout << i << std::endl;
            }
            lock.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(POLL_INTERVAL_MS));
        }
    });

    producer.join();
    consumer.join();

    return 0;
}
