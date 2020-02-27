#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;


int main()
{
    int fd = shm_open("mein-shared-dings", O_RDONLY, /*mode unused without O_CREAT*/0);
    if (fd == -1) {
        perror("shm_open");
        return 1;
    }

    void* addr = mmap(NULL, 4096, PROT_READ, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    uint64_t* counter_location = (uint64_t*)addr;

    while (true) {
        cout << *counter_location << endl;
        sleep(1);
    }

    return 0;
}
