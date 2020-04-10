#pragma once


// this is the result of the straightforward translation of the
// *concrete class* from an earlier example into a *template class*,
// parameterized by its member/coordinate type.
template <typename T> class Point
{
public:
    Point() : _x(0), _y(0) {}

    Point(int x, int y)
    : _x(x), _y(y) {}

    Point(const Point& rhs)
    : _x(rhs._x), _y(rhs._y) {}

    Point& operator=(const Point& rhs)
    {
        _x = rhs._x;
        _y = rhs._y;
        return *this;
    }

    T x() const { return _x; }
    T y() const { return _y; }

    void move(const Point& by)
    {
        _x += by.x();
        _y += by.y();
    }

    const Point& operator+=(const Point& rhs)
    {
        _x += rhs.x();
        _y += rhs.y();
        return *this;
    }

    static Point add(const Point& lhs, const Point& rhs)
    {
        return Point(lhs._x+rhs._x, lhs._y+rhs._y);
    }

private:
    T _x;
    T _y;
};

template <typename T> Point<T> operator+(const Point<T>& lhs, const Point<T>& rhs)
{
    return Point<T>::add(lhs, rhs);
}

template <typename T> bool operator==(const Point<T>& lhs, const Point<T>& rhs)
{
    return lhs.x() == rhs.x() && lhs.y() == rhs.y();
}
template <typename T> bool operator!=(const Point<T>& lhs, const Point<T>& rhs)
{
    return !operator==(lhs, rhs);
}
