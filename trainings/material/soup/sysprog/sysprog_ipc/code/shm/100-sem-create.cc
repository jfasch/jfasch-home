#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <stdio.h>


int main()
{
    sem_t* sem = sem_open("meine-semaphore", O_CREAT|O_RDWR|O_EXCL, 0666, 7);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        return 1;
    }

    return 0;
}
