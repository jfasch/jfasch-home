#pragma once

class Point
{
public:
    Point() : _x(0), _y(0) {}
    Point(int x, int y) : _x(x), _y(y) {}

    int x() const { return _x; }
    int y() const { return _y; }

    void move(const Point&);
    Point& operator+=(const Point&);

    static Point add(const Point& lhs, const Point& rhs);
    Point operator+(const Point& rhs) const;

    static bool equal(const Point& lhs, const Point& rhs);
    bool operator==(const Point& rhs) const;

private:
    int _x;
    int _y;
};
