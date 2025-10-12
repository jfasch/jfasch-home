#include "database.h"

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <poll.h>
#include <assert.h>
#include <regex>

class ReceiveLineAndInsertRecord : public InputHandler
{
public:
    ReceiveLineAndInsertRecord(int fd, Database& db) : _fd(fd), _db(db) {}
    
    EventAction ready(int fd)
    {
        
    }
};

int main()
{
    Database db;

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

    bool quit = false;
    while (!quit) {
        struct pollfd watches[] = {
            {
                .fd = STDIN_FILENO,                    // <-- watch STDIN_FILENO
                .events = POLLIN,                      //     for input
            },
            {
                .fd = sock,                            // <-- watch UDP socket
                .events = POLLIN,                      //     for input
            },
        };

        int nready = poll(watches, 2, -1);             // <-- wait for either to become ready
        if (nready == -1) {                            //     (-1 ... no timeout)
            perror("poll");
            return 1;
        }
        assert(nready != 0);                           // <-- no timeout requested
        
        std::vector<std::string> lines;                // <-- possibly reading multiple lines in one swoop

        if (watches[0].revents & POLLIN) {             // <-- only if STDIN_FILENO has something
            char line[64];
            ssize_t nread = read(STDIN_FILENO, line, sizeof(line)-1);
            if (nread == -1) {
                perror("read(stdin)");
                return 1;
            }
            else if (nread == 0)                       // <-- EOF on stdin quits us
                quit = true;
            else 
                lines.push_back(std::string(line, nread));
        }
        if (watches[1].revents & POLLIN) {             // <-- only if USP socket has something
            char line[64];
            ssize_t nread = read(sock, line, sizeof(line)-1);
            if (nread == -1) {
                perror("read(udp)");
                return 1;
            }
            assert(nread > 0);                         // <-- no EOF over UDP
            lines.push_back(std::string(line, nread));
        }

        for (const auto& line: lines)
            if (Record r = split_line(line))
                db.insert(r);
            else
                std::println(stderr, "invalid line: \"{}\"", line);
    }

    db.commit();
    return 0;
};
