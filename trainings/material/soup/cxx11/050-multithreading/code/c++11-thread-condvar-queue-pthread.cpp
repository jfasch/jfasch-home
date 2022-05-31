#include <thread>
#include <deque>
#include <iostream>
#include <pthread.h>


template <typename T>
class ThreadSafeQueue
{
public:
    ThreadSafeQueue(unsigned maxelem)
    : _maxelem(maxelem)
    {
        pthread_mutex_init(&_lock, nullptr);
        pthread_cond_init(&_not_empty, nullptr);
        pthread_cond_init(&_not_full, nullptr);
    }

    void push(T elem)
    {
        pthread_mutex_lock(&_lock);
        while (_queue.size() == _maxelem)
            pthread_cond_wait(&_not_full, &_lock);
        _queue.push_back(elem);
        pthread_mutex_unlock(&_lock);

        pthread_cond_signal(&_not_empty);
    }

    T pop()
    {
        pthread_mutex_lock(&_lock);
        while (_queue.size() == 0)
            pthread_cond_wait(&_not_empty, &_lock);
        T elem = _queue.front();
        _queue.pop_front();
        pthread_mutex_unlock(&_lock);

        pthread_cond_signal(&_not_full);
        return elem;
    };

private:
    std::deque<T> _queue;
    unsigned _maxelem;

    pthread_mutex_t _lock;
    pthread_cond_t _not_empty;
    pthread_cond_t _not_full;
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
