#include "file-util.h"

#include <string.h>
#include <fcntl.h>
#include <unistd.h>


OSError::OSError(int error /*errno*/, const std::string& prefix)
: _msg(prefix)
{
    char buf[64];
    strerror_r(error, buf, sizeof(buf));
    _msg += " (";
    _msg += std::to_string(error);
    _msg += "/\"";
    _msg += buf;
    _msg += "\")";
}

const char* OSError::what() const noexcept
{
    return _msg.c_str();
}

std::string read_sysfs_file(const std::string& name)
{
    int fd = open(name.c_str(), O_RDONLY);
    if (fd == -1)
        throw OSError(errno, "open(O_RDONLY)");
        
    char buffer[64];
    ssize_t nread = read(fd, buffer, sizeof(buffer));
    if (nread == -1) {
        close(fd);
        throw OSError(errno, "read");
    }

    close(fd);

    return std::string(buffer, nread);
}

void write_sysfs_file(const std::string& name, const std::string& content)
{
    int fd = open(name.c_str(), O_WRONLY);
    if (fd == -1)
        throw OSError(errno, "open(O_WRONLY)");
    ssize_t nwritten = write(fd, content.c_str(), content.size());
    if (nwritten == -1) {
        close(fd);
        throw OSError(errno, "write");
    }

    close(fd);
    
}
