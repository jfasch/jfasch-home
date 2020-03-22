#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <stdio.h>


int main()
{
    sem_t* sem = sem_open("meine-semaphore", O_RDWR);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        return 1;
    }

    int error = sem_wait(sem);
    if (error) {
        perror("sem_wait");
        return 1;
    }

    return 0;
}
