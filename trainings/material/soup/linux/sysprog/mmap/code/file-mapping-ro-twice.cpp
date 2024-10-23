#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <iostream>

using namespace std;


int main(int argc, char** argv)
{
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " FILENAME\n";
        return 1;
    }

    const char* filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct stat stat;
    int error = fstat(fd, &stat);
    if (error) {
        perror("fstat");
        return 1;
    }

    void* content = mmap(
        NULL,
        stat.st_size,
        PROT_READ,
        MAP_PRIVATE,
        fd,
        0
    );
    if (content == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    close(fd);

    write(STDOUT_FILENO, content, stat.st_size);
    cin.peek();
    write(STDOUT_FILENO, content, stat.st_size);

    munmap(content, stat.st_size);

    return 0;
}
