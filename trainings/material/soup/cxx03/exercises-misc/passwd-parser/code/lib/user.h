#pragma once

#include <string>


struct User
{
    std::string name;
    std::string passwd;
    int uid;
    int gid;
    std::string descr;
    std::string homedir;
    std::string shell;
};
