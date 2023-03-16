#include <hal.h>

#include <iostream>
#include <assert.h>
#include <semaphore.h>


static void wakeup(void* vsem)
{
    sem_t* sem = (sem_t*)vsem;
    int error = sem_post(sem);
    assert(!error);
}

int main(int argc, char** argv)
{
    jf::hal::init();

    sem_t sem;
    sem_init(&sem, 0, 0);

    jf::hal::start_timer_ms(3000, wakeup, &sem);

    int error = sem_wait(&sem);  assert(!error);
    std::cout << "wakeup" << std::endl;
    
    jf::hal::deinit();
    return 0;
}
