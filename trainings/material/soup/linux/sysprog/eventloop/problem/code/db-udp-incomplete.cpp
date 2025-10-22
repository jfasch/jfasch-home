#include "database.h"

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <print>

int main()
{
    Database db;


    // <setup UDP socket>
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock == -1) {
        perror("socket");
        return 1;
    }
    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(1234),
        .sin_addr = INADDR_ANY,
    };
    int error = bind(sock, (struct sockaddr *)&addr, sizeof(addr));
    if (error == -1) {
        perror("bind");
        return 1;
    }
    // </setup UDP socket>


    bool quit = false;
    while (!quit) {
        char line[64];
        ssize_t nread = read(STDIN_FILENO,             // <-- and now? how read from socket?
                             line, sizeof(line)-1);
        if (nread == -1) {
            perror("read");
            return 1;
        }
        if (nread == 0) {
            quit = true;
            continue;
        }

        std::string sline(line, nread);
        if (Record r = split_line(sline))
            db.insert(r);
        else
            std::println(stderr, "invalid line: \"{}\"", sline);
    }

    db.commit();
    return 0;
};
