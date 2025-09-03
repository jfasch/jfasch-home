#include <hal.h>

#include <iostream>
#include <unistd.h>
#include <semaphore.h>
#include <assert.h>


class MyBlocker : public jf::hal::Timer::User
{
public:
    MyBlocker(size_t expected)
    : _expected(expected), _current(0)
    {
        int error = sem_init(&_sem, 0, 0);
        assert(!error);
    }

    void wait()
    {
        int error = sem_wait(&_sem);
        assert(!error);
    }

private:
    void expired() override
    {
        std::cout << _current++ << std::endl;
        if (_current == _expected) {
            int error = sem_post(&_sem);
            assert(error);
        }
    }

private:
    sem_t _sem;
    size_t _expected, _current;
};


int main(int argc, char** argv)
{
    MyBlocker b(10);

    jf::hal::PeriodicTimer t(500, &b);
    t.start();
    b.wait();
    std::cout << "pooh" << std::endl;
    
    return 0;
}
