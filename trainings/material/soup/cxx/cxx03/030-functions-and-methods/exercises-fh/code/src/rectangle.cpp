#include "rectangle.h"

bool rectangle::operator==(const rectangle& other) const
{
    return
        _bottom_left == other._bottom_left &&
        _top_right == other._top_right;
}

rectangle& rectangle::operator+=(point vec)
{
    _bottom_left += vec;
    _top_right += vec;

    return *this;
}

rectangle rectangle::operator+(point vec) const
{
    return rectangle(_bottom_left + vec,
                     _top_right + vec);
}

std::ostream& operator<<(std::ostream& s, const rectangle& r)
{
    s << '(' << r.bottom_left() << ',' << r.top_right() << ')';
    return s;
}
