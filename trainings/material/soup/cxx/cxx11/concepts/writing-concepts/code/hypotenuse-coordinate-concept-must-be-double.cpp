#include <vector>
#include <cmath>
#include <iostream>


template <typename V>
concept contains_double_likes = requires(V v)
{
    { v[0] } -> std::same_as<double>;
};

template <typename V>
double hypotenuse(const V& v)
requires contains_double_likes<V>
{
    double sumsq = 0;
    for (size_t i=0; i<v.size(); ++i)
        sumsq += v[i]*v[i];
    return std::sqrt(sumsq);
}

int main()
{
    std::vector v{"eins", "zwei"};
    std::cout << hypotenuse(v) << std::endl;
    return 0;
}
