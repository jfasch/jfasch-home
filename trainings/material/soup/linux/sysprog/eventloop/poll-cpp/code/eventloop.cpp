#include "eventloop.h"

#include <vector>
#include <format>
#include <cassert>

#include <string.h>
#include <poll.h>


void Eventloop::register_input(int fd, InputHandler* h)
{
    const auto& [_, inserted] = _inputs.insert(std::make_pair(fd, h));
    assert(inserted);
}

void Eventloop::run()
{
    bool quit = false;
    while (!quit) {
        std::vector<struct pollfd> watches(_inputs.size());
        for (auto [fd, _]: _inputs)
            watches.push_back({
                    .fd = fd,
                    .events = POLLIN,
                });

        int nready = poll(&watches[0], watches.size(), -1);
        if (nready == -1) {
            auto msg = std::format("poll error ({}, {})", errno, strerror(errno));
            throw std::runtime_error(msg);
        }
        if (nready == 0)
            throw std::runtime_error("poll returns 0 though no timeout requested");

        for (const auto& watch: watches)
            if (watch.revents & POLLIN)
                switch (_inputs[watch.fd]->ready(watch.fd)) {
                    case EventAction::Quit: 
                        quit = true;
                        break;
                    case EventAction::Continue:
                        break;
                }
    }
}
