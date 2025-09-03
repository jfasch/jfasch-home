#include <hal.h>

#include <iostream>
#include <assert.h>
#include <semaphore.h>


class MyUser : public jf::hal::Timer::User
{
public:
    MyUser(sem_t& sem)
    : _sem(sem) {}

    void expired() override
    {
        sem_post(&_sem);
    }

private:
    sem_t& _sem;
};

int main(int argc, char** argv)
{
    sem_t sem;
    sem_init(&sem, 0, 0);

    MyUser u(sem);

    jf::hal::OneshotTimer t1(1500, &u);
    t1.start();

    int error = sem_wait(&sem);  assert(!error);
    std::cout << "first wakeup" << std::endl;
    
    jf::hal::OneshotTimer t2(3000, &u);
    t2.start();

    error = sem_wait(&sem);  assert(!error);
    std::cout << "second wakeup" << std::endl;
    
    return 0;
}
