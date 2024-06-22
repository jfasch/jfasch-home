#pragma once

#pragma once

#include <string>
#include <exception>


class OSError : public std::exception
{
public:
    OSError(int error /*errno*/, const std::string& prefix);
    virtual const char* what() const noexcept;
private:
    std::string _msg;
};

std::string read_sysfs_file(const std::string& name);
void write_sysfs_file(const std::string& name, const std::string& content);
