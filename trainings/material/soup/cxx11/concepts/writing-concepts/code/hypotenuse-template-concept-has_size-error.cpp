#include <vector>
#include <cmath>
#include <iostream>

template <typename V>
concept has_size = requires(V v) {
    v.size();                                          // <-- ok if this compiles
};

template <typename V>
double hypotenuse(const V& v)
requires has_size<V>
{
    double sumsq = 0;
    for (size_t i=0; i<v.size(); ++i)
        sumsq += v[i]*v[i];
    return std::sqrt(sumsq);
}

class point2d
{
public:
    point2d(double x, double y) : _x{x}, _y{y} {}
private:
    double _x, _y;
};

int main()
{
    point2d p{3,4};
    std::cout << hypotenuse(p) << std::endl;
    return 0;
}
