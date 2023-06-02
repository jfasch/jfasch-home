#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <string>
#include <iostream>


int main(int argc, char** argv)
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " FILENAME HOLD_TIME_S" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    int hold_time = std::stoi(argv[2]);

    int fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        perror("open()");
        return 1;
    }

    struct flock my_lock;
    memset(&my_lock, 0, sizeof(my_lock));
    my_lock.l_start = 0;
    my_lock.l_whence = SEEK_SET;
    my_lock.l_len = 0;
    my_lock.l_type = F_WRLCK;

    std::cout << "locking ..." << std::endl;
    int error = fcntl(fd, F_SETLKW, &my_lock);
    if (error) {
        perror("fcntl(F_SETLKW/F_WRLCK)");
        return 1;
    }
    std::cout << "... done" << std::endl;

    sleep(hold_time);

    my_lock.l_type = F_UNLCK;

    std::cout << "releasing ..." << std::endl;
    error = fcntl(fd, F_SETLK, &my_lock);
    if (error) {
        perror("fcntl(F_SETLK/F_UNLCK)");
        return 1;
    }
    std::cout << "... done" << std::endl;

    return 0;
}
