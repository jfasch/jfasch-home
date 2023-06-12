#include <vector>
#include <cmath>
#include <iostream>

template <typename V>
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

    // glue to be usable with hypotenuse()
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
    std::vector<double> v = {3,4};
    std::cout << hypotenuse(v) << std::endl;

    point2d p{3,4};
    std::cout << hypotenuse(p) << std::endl;

    return 0;
}
