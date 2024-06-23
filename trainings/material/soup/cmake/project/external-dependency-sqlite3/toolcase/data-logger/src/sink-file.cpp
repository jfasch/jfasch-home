#include "sink-file.h"


SinkFile::SinkFile(const std::string& filename) 
: _file(filename, std::ios::app)
{
    if (!_file)
        throw std::runtime_error("Unable to open file: " + filename);
}

SinkFile::~SinkFile()
{
    if (_file.is_open())
        _file.close();
}

void SinkFile::output(const Measurements& data)
{
    for (const auto& [name, value] : data)
        _file << name << "; " << value << std::endl;
}
