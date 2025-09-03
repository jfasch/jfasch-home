#include <thread>
#include <mutex>
#include <condition_variable>
#include <deque>
#include <chrono>
#include <iostream>


template <typename T>
class ThreadSafeQueue
{
public:
    ThreadSafeQueue(unsigned maxelem)
    : _maxelem(maxelem)
    {}

    void push(T elem)
    {
        {
            std::unique_lock<std::mutex> guard(_lock);
            _not_full.wait(guard, [this](){return _queue.size() < _maxelem;});
            _queue.push_back(elem);
        } // scoped locking: unlock before signal
        _not_empty.notify_one();
    }

    T pop()
    {
        T elem;
        {
            std::unique_lock<std::mutex> guard(_lock);
            _not_empty.wait(guard, [this](){return _queue.size() > 0;});
            elem = _queue.front();
            _queue.pop_front();
        }
        _not_full.notify_one();

        return elem;
    };

private:
    std::deque<T> _queue;
    unsigned _maxelem;

    std::mutex _lock;
    std::condition_variable _not_empty;
    std::condition_variable _not_full;
};


using namespace std::chrono_literals;

int main()
{
    ThreadSafeQueue<int> queue(10);
    std::thread producer([&queue](){
        int i = 0;
        while (true) {
            queue.push(i++);
            std::this_thread::sleep_for(1ms);
        }
    });
    std::thread consumer1([&queue](){
        while (true)
            std::cout << "1: " << queue.pop() << std::endl;
    });
    std::thread consumer2([&queue](){
        while (true)
            std::cout << "2: " << queue.pop() << std::endl;
    });

    producer.join();
    consumer1.join();
    consumer2.join();

    return 0;
}
