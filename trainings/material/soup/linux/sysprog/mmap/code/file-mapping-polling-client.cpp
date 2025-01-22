#include "data.h"

#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <string>
#include <cassert>


int main(int argc, char** argv)
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " FILENAME NAME VALUE\n";
        return 1;
    }

    const char* name = argv[2];
    if (strlen(name) > DATA_NAME_SIZE-1) {
        std::cerr << "Name too long (max. " << DATA_NAME_SIZE-1 << ')' << std::endl;
        return 1;
    }
    int value = std::stoi(argv[3]);

    const char* filename = argv[1];
    int fd = open(filename, O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct Data* data = (Data*)mmap(NULL, sizeof(struct Data), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

    int error = pthread_mutex_lock(&data->lock);
    assert(!error);
    {
        strcpy(data->name, name);
        data->value = value;
        data->valid = 1;
    }    
    pthread_mutex_unlock(&data->lock);

    munmap(data, sizeof(struct Data));
    return 0;
}
