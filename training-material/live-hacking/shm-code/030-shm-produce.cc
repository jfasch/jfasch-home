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
    int fd = shm_open("mein-shared-dings", O_RDWR, /*mode unused without O_CREAT*/0);
    if (fd == -1) {
        perror("shm_open");
        return 1;
    }

    void* addr = mmap(NULL, 4096, PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    uint64_t* counter_location = (uint64_t*)addr;

    uint64_t counter = 0;
    while (true) {
        cout << counter << endl;
        *counter_location = counter++;
        sleep(1);
    }

    return 0;
}
