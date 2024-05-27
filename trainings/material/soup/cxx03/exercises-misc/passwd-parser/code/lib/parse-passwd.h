#pragma once

#include "user.h"

#include <vector>
#include <string>


User parse_passwd_line(std::string line);
std::vector<User> parse_passwd_file(std::string filename);
