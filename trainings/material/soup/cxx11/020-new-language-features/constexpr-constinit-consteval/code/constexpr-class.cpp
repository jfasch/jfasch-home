#include <cmath>
#include <iostream>

class point
{
public:
    constexpr point(int x, int y) : _x(x), _y(y) {}
    constexpr double abs() const
    {
        return std::sqrt(_x*_x + _y*_y);               // <-- constexpr
    }
private:
    int _x;
    int _y;
};

int main()
{
    constexpr point p(3, 4);
    constexpr auto abs = p.abs();
    std::cout << abs << '\n';
    // std::cout << p.abs() << '\n';        // defeats constexpr somewhat
    return 0;
}
