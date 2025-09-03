#include <mutex>
#include <condition_variable>
#include <deque>
#include <thread>
#include <chrono>
#include <iostream>


// message queue which can hold up to maxelem elements of type
// T. associated with the queue are two wait conditions:

// * a consumer has to wait if the queue is empty. he then waits for
//   the condition "not empty" which is made true by a producer.

// * a producer has to wait if the queue is full. he then waits for
//   the condition "not full" which is made true by a consumer.

// note that std::condition_variable must be used with
// std::unique_lock<std::mutex>, which is a moveable version of a lock
// guard. this is to guarantee that the mutex remains locked when a
// thread enters the wait and an exception is thrown inside the
// std::condition_variable
// implementation. std::condition_variable::wait(guard) moves the
// guard into the condition variable before suspending the thread, and
// moves it back out to the caller again after wakeup.
template <typename T> class MessageQueue
{
public:
    MessageQueue(size_t maxelem) : maxelem_(maxelem) {}

    void push(T elem)
    {
        {
            std::unique_lock<std::mutex> guard(lock_);
            // wait if the queue is full. (use while instead of if to
            // guard against spurious wakeups.)
            while (q_.size() == maxelem_)
                // atomically release the mutex and put the calling
                // thread to sleep until the condition becomes true
                // (not_full_ is notified).
                not_full_.wait(guard);
            q_.push_back(elem);
        }
        // notify a waiting consumer that there might is an item
        // available.
        not_empty_.notify_one();
    }

    T pop()
    {
        T rv;
        {
            std::unique_lock<std::mutex> guard(lock_);
            // wait if the queue is empty. (use while instead of if to
            // guard against spurious wakeups.)
            while (q_.size() == 0)
                // atomically release the mutex and put the calling
                // thread to sleep until the condition becomes true
                // (not_empty_ is notified).
                not_empty_.wait(guard);
            rv = q_.front();
            q_.pop_front();
        }
        // notify a waiting producer that there is room.
        not_full_.notify_one();
        return rv;
    }

private:
    std::mutex lock_;
    std::condition_variable not_empty_;
    std::condition_variable not_full_;

    size_t maxelem_;
    std::deque<T> q_;
};

void producer_func(MessageQueue<int>& mq, int nelem)
{
    for (int i=0; i<nelem; i++) {
        mq.push(i);
        std::cout << "produced " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

void consumer_func(MessageQueue<int>& mq, int threadno, int nelem)
{
    for (int i=0; i<nelem; i++) {
        int elem = mq.pop();
        std::cout << "consumer #" << threadno << " consumed " << elem << std::endl;
    }
}

int main()
{
    MessageQueue<int> mq(2);

    std::thread producer(producer_func, std::ref(mq), 10);
    std::thread consumers[5]{
        std::thread(consumer_func, std::ref(mq), 0, 2),
        std::thread(consumer_func, std::ref(mq), 1, 2),
        std::thread(consumer_func, std::ref(mq), 2, 2),
        std::thread(consumer_func, std::ref(mq), 3, 2),
        std::thread(consumer_func, std::ref(mq), 4, 2),
    };

    for (auto& thread: consumers)
        thread.join();
    producer.join();
}
