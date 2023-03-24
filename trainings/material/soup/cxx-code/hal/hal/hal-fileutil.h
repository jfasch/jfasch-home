#pragma once

#include <string>


namespace jf::hal {

void write_to_file(const std::string& path, const std::string& content);
void write_to_file_int(const std::string& path, int i);

std::string read_from_file(const std::string& path);
int read_from_file_int(const std::string& path);

}
