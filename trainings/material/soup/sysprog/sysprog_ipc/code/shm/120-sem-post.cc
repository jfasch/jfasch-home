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

    int error = sem_post(sem);
    if (error) {
        perror("sem_post");
        return 1;
    }

    return 0;
}
