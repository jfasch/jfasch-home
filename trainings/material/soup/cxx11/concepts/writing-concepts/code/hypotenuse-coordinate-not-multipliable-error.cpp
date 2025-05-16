#include <string>
#include <vector>
#include <cmath>
#include <iostream>

template <typename V>
concept has_size = requires(V v) {
    v.size();
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

int main()
{
    std::vector v{"eins", "zwei"};                     // <-- std::string has no ``*``
    std::cout << hypotenuse(v) << std::endl;
    return 0;
}
