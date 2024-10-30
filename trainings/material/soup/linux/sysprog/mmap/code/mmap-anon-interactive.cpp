#include <sys/mman.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    cout << getpid() << '\n';

    void* memory = mmap(
        NULL,
        16*1024*1024,
        PROT_READ|PROT_WRITE,
        MAP_ANONYMOUS|MAP_PRIVATE,
        -1,
        0
    );
    if (memory == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    cin.get();
    *(((char*)memory)+16) = 'a';
    cin.get();

    munmap(memory, 16*1024*1024);

    return 0;
}
