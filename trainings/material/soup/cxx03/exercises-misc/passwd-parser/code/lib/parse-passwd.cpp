#include "parse-passwd.h"

#include <iostream>


User parse_passwd_line(std::string line)
{
    User user;

    size_t cur = 0, next;

    next = line.find_first_of(':', cur);
    user.name = line.substr(cur, next-cur);

    cur = next + 1;
    next = line.find_first_of(':', cur);
    user.passwd = line.substr(cur, next-cur);

    cur = next + 1;
    next = line.find_first_of(':', cur);
    user.uid = std::stoi(line.substr(cur, next-cur));

    cur = next + 1;
    next = line.find_first_of(':', cur);
    std::cout << line.substr(cur, next-cur) << std::endl;
    user.gid = std::stoi(line.substr(cur, next-cur));

    cur = next + 1;
    next = line.find_first_of(':', cur);
    user.descr = line.substr(cur, next-cur);

    cur = next + 1;
    next = line.find_first_of(':', cur);
    user.homedir = line.substr(cur, next-cur);

    cur = next + 1;
    user.shell = line.substr(cur);

    return user;
}

std::vector<User> parse_passwd_file(std::string filename)
{
    std::vector<User> users;
    return users;
}
