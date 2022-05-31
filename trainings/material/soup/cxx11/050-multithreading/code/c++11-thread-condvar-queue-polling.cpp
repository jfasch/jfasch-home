#include <thread>
#include <mutex>
#include <deque>
#include <chrono>
#include <iostream>


template <typename T>
class ThreadSafeQueue
{
public:
    ThreadSafeQueue(unsigned maxelem) : _maxelem(maxelem) {}

    template<typename dur>
    void push(T elem, dur d)
    {
        while (true) {
            {
                std::scoped_lock guard(_lock);
                if (_queue.size() <= _maxelem) {
                    _queue.push_back(elem);
                    return;
                }
            }
            std::this_thread::sleep_for(d);
        }
    }

    template <typename dur>
    T pop(dur d)
    {
        while (true) {
            {
                std::scoped_lock guard(_lock);
                if (_queue.size() > 0) {
                    T elem = _queue.front();
                    _queue.pop_front();
                    return elem;
                }
            }
            std::this_thread::sleep_for(d);
        }            
    };

private:
    std::deque<T> _queue;
    unsigned _maxelem;
    std::mutex _lock;
};


using namespace std::chrono_literals;

int main()
{
    ThreadSafeQueue<int> queue(10);
    std::thread producer([&queue](){
        int i = 0;
        while (true) {
            queue.push(i++, 2ms);
            std::this_thread::sleep_for(1ms);
        }
    });
    std::thread consumer1([&queue](){
        while (true)
            std::cout << "1: " << queue.pop(1ms) << std::endl;
    });
    std::thread consumer2([&queue](){
        while (true)
            std::cout << "2: " << queue.pop(2ms) << std::endl;
    });

    producer.join();
    consumer1.join();
    consumer2.join();

    return 0;
}
