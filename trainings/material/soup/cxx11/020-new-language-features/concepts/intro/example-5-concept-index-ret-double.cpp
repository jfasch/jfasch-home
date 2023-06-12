#include <vector>
#include <cmath>
#include <iostream>

template <typename V>
concept has_size = requires(V v) {
    v.size();
};

template <typename V>
concept index_returns_double = requires(V v) {
    { v[0] } -> std::common_reference_with<double>;
};

template <typename V>
requires has_size<V> && index_returns_double<V>        // <--- not possible with abbreviated function templates
double hypotenuse(const V& v)
{
    double sumsq = 0;
    for (size_t i=0; i<v.size(); ++i)
        sumsq += v[i]*v[i];
    return std::sqrt(sumsq);
}

class point2d
{
public:
    point2d(double x, double y)
    : _x{x}, _y{y} {}

    size_t size() const { return 2; }
    double operator[](size_t i) const
    {
        if (i==0) return _x;
        if (i==1) return _y;
        return 666;
    }

private:
    double _x, _y;
};

int main()
{
    std::vector<double> v = {3.5, 4.5};
    std::cout << hypotenuse(v) << std::endl;

    point2d p{3.5, 4.5};
    std::cout << hypotenuse(p) << std::endl;

    return 0;
}
