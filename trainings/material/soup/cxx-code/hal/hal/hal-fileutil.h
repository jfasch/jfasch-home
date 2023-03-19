#pragma once

#include <string>


namespace jf::hal {

void write_to_file(const std::string& path, const std::string& content);
std::string read_from_file(const std::string& path);

}
