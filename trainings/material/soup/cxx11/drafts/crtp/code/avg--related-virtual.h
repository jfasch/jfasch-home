#include <cstddef>

namespace related_virtual
{

double average(auto& sensors)
{
    double sum = 0;
    std::size_t num = 0;
    for (auto s: sensors) {
        sum += s->get_temperature();
        ++num;
    }

    return sum/num;
}

}
