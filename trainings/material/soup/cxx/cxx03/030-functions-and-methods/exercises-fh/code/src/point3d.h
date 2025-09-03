#ifndef POINT3D_H
#define POINT3D_H

#include <ostream>

class point3d
{
public:
    point3d() = default;
    point3d(int x, int y, int z) : _x{x}, _y{y}, _z{z} {}

    bool operator==(const point3d& other) const { return _x==other._x && _y==other._y && _z==other._z; }
    bool operator!=(const point3d& other) const { return !operator==(other); }
    point3d& operator+=(const point3d& other);
    point3d& operator-=(const point3d& other);
    point3d operator+(const point3d& other) const;
    point3d operator-(const point3d& other) const;
    point3d operator-() const { return point3d{-_x,-_y,-_z}; }

    int x() const { return _x; }
    int y() const { return _y; }
    int z() const { return _z; }

    double abs() const;
    double distance(const point3d& other) const { return (other - *this).abs(); }


private:
    int _x{0};
    int _y{0};
    int _z{0};
};

std::ostream& operator<<(std::ostream& s, const point3d& r);

#endif
