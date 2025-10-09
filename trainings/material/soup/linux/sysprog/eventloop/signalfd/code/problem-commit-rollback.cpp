#include <unistd.h>
#include <signal.h>
#include <string>
#include <regex>
#include <print>

static volatile sig_atomic_t quit = false;
static volatile sig_atomic_t commit = false;
static volatile sig_atomic_t rollback = false;


static void handler(int signal)
{
    switch (signal) {
        case SIGTERM:
        case SIGINT:
            quit = true;
            break;
        case SIGUSR1:
            commit = true;
            break;
        case SIGUSR2:
            rollback = true;
            break;
        default:
            abort();                                   // <-- signal not expected
    }
}

struct Database
{
    void insert(unsigned id, const std::string& firstname, const std::string& lastname) {
        std::println("insert id={}, firstname={}, lastname={}", id, firstname, lastname);
    }
    void commit() {
        std::println("commit");
    }
    void rollback() {
        std::println("rollback");
    }
};

int main()
{
    struct sigaction sa = { 0 };
    sa.sa_handler = handler;

    int rv = sigaction(SIGTERM, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction(SIGTERM)");
        return 1;
    }
    rv = sigaction(SIGINT, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction(SIGINT)");
        return 1;
    }
    rv = sigaction(SIGUSR1, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction(SIGUSR1)");
        return 1;
    }
    rv = sigaction(SIGUSR2, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction(SIGUSR2)");
        return 1;
    }
    
    static const std::regex re_line("^(\\d+)\\s+(\\w+)\\s+(\\w+)\\s*$");
    Database db;

    while (true) {                                     // <-- quit?
        char line[64];
        ssize_t nread = read(STDIN_FILENO,
                             line, sizeof(line)-1);
        if (nread == -1) {
            if (errno == EINTR) {
                if (quit)
                    break;
                else if (commit) {
                    db.commit();
                    commit = false;
                    continue;
                }
                else if (rollback) {
                    db.rollback();
                    rollback = false;
                    continue;
                }
                                                       // <-- and else?
            }
            else {
                perror("read");
                return 1;
            }
        }
        if (nread == 0)
            break;

        std::string sline(line, nread);
        std::smatch match;
        if (std::regex_search(sline, match, re_line))
            db.insert(std::stoi(match[1].str()), match[2].str(), match[3].str());
    }

    db.commit();

    return 0;
};
