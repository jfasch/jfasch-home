#ifndef CUBOID_H
#define CUBOID_H

#include "point3d.h"
#include <ostream>

class cuboid
{
public:
    cuboid() = default;
    cuboid(point3d front_bottom_left, int width, int height, int length)
    : _front_bottom_left{front_bottom_left},
      _width(width),
      _height(height),
      _length(length)
    {}

    bool operator==(const cuboid& other) const;
    bool operator!=(const cuboid& other) const { return !operator==(other); }

    cuboid& operator+=(const point3d& vec);
    cuboid& operator-=(const point3d& vec);

    cuboid operator+(const point3d& vec) const;
    cuboid operator-(const point3d& vec) const;

    point3d front_bottom_left() const { return _front_bottom_left; }
    int width() const { return _width; }
    int height() const { return _height; }
    int length() const { return _length; }

    unsigned int surface() const { return 2* _width * _height + 2* _width * _length + 2* _height * _length; }
    unsigned int volume() const { return _width * _height * _length; }

private:
    point3d _front_bottom_left;
    int _width{};
    int _height{};
    int _length{};
};

std::ostream& operator<<(std::ostream&, const cuboid&);

#endif
