#include <vector>
#include <cmath>
#include <iostream>

double hypotenuse(const std::vector<double>& v)
{
    double sumsq = 0;
    for (size_t i=0; i<v.size(); ++i)                  // <--- vector has .size()
        sumsq += v[i]*v[i];                            // <--- vector has []
    return std::sqrt(sumsq);
}

int main()
{
    std::vector<double> v = {3,4};
    std::cout << hypotenuse(v) << std::endl;
}
