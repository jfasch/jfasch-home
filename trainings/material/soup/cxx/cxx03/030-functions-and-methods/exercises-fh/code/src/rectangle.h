#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.h"

class rectangle
{
public:
    rectangle() = default;

    rectangle(point bottom_left, point top_right)
    : _bottom_left{bottom_left}, _top_right{top_right} {}

    bool operator==(const rectangle& other) const;
    bool operator!=(const rectangle& other) const { return !operator==(other); }
    rectangle& operator+=(point vec);
    rectangle operator+(point vec) const;

    point bottom_left() const { return _bottom_left; }
    point top_right() const { return _top_right; }
    point top_left() const { return point{_bottom_left.x(), _top_right.y()}; }
    point bottom_right() const { return point{_top_right.x(), _bottom_left.y()}; }

    int width() const { return _top_right.x() - _bottom_left.x(); }
    int height() const { return _top_right.y() - _bottom_left.y(); }

    int area() const { return width() * height(); }

private:
    point _bottom_left{};
    point _top_right{};
};

std::ostream& operator<<(std::ostream& s, const rectangle&);

#endif
