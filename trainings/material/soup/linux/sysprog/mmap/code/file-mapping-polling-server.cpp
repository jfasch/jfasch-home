#include "data.h"

#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <cassert>


int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " FILENAME\n";
        return 1;
    }

    const char* filename = argv[1];
    int fd = open(filename, O_RDWR|O_CREAT|O_EXCL, 0666);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    int error = ftruncate(fd, sizeof(struct Data));    // <-- make room for struct Data
    if (error) {
        perror("ftruncate");
        return 1;
    }

    struct Data* data = (Data*)mmap(NULL, sizeof(struct Data), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

    data->valid = 0;                                   // <-- not valid, initially

    pthread_mutexattr_t mutex_attr;
    pthread_mutexattr_init(&mutex_attr);
    pthread_mutexattr_setpshared(&mutex_attr, 1);
    pthread_mutex_init(&data->lock, &mutex_attr);      // <-- put mutex in shared memory

    while (1) {
        struct Data consumed_data = {};
        int error = pthread_mutex_lock (&data->lock);
        assert(!error);
        {
            if (data->valid) {
                consumed_data = *data;
                data->valid = 0;
            }
        }
        error = pthread_mutex_unlock(&data->lock);
        assert(!error);

        if (consumed_data.valid)
            std::cout << consumed_data.name << ':' << consumed_data.value << std::endl;

        sleep(1);
    }
    
    munmap(data, sizeof(struct Data));
    return 0;
}
