#ifndef __HAVE_DATA_H__
#define __HAVE_DATA_H__

#include <unistd.h>


// take ownership of a chunk of bytes
class Data
{
public:
    Data(char* data, size_t size) : _data(data), _size(size) {}
    ~Data() { delete[] _data; }

    const char* data() const { return _data; }
    size_t size() const { return _size; }

private:
    char* _data;
    size_t _size;
};

#endif
