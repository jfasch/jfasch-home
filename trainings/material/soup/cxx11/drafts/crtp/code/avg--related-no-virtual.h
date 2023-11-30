#include <cstddef>

namespace related_no_virtual
{

double average(auto& sensors)
{
    double sum = 0;
    std::size_t num = 0;
    for (auto s: sensors) {
        switch (s->type) {
            case DerivedType::SENSOR1: {
                Sensor1* s1 = static_cast<Sensor1*>(s);
                sum += s1->get_temperature();
                break;
            }
            case DerivedType::SENSOR2: {
                Sensor2* s2 = static_cast<Sensor2*>(s);
                sum += s2->get_temperature();
                break;
            }
        }
    }
    return sum/num;
}

}
