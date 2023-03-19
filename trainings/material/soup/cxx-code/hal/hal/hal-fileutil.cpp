#include "hal-fileutil.h"

#include <stdexcept>
#include <fstream>

#include <fcntl.h>
#include <unistd.h>
#include <string.h>


namespace jf::hal {

void write_to_file(const std::string& path, const std::string& content)
{
    std::ofstream f(path);
    if (f.fail())
        throw std::runtime_error(path + " does not exist");

    f.write(content.c_str(), content.size()); // fix that: error check
}

std::string read_from_file(const std::string& path)
{
    int fd = open(path.c_str(), O_RDONLY);
    if (fd == -1)
        throw std::runtime_error(strerror(errno));

    char buffer[64]; // fix that: determine file size
    ssize_t nread = read(fd, buffer, sizeof(buffer));
    if (nread == -1) {
        close(fd);
        throw std::runtime_error(strerror(errno));
    }

    return std::string(buffer, nread);
}

}
