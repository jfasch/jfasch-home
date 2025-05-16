#include <utility>
#include <vector>
#include <cmath>
#include <iostream>

template <typename V>
concept has_size = requires(V v) {
    v.size();
};

template <typename V>
concept coordinate_is_multipliable = requires(V v) {
    v[0]*v[0];                                         // <-- as a requirement, this must compile
};

template <typename V>
double hypotenuse(const V& v)
requires 
   has_size<V>
   &&                                                  // <-- combining requirements: &&
   coordinate_is_multipliable<V>
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
