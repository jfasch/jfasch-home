#include "unrelated.h"
#include <vector>
#include <variant>

int main()
{
    using Sensor = std::variant<unrelated::Sensor1, unrelated::Sensor2>;
    // Sensor a{unrelated::Sensor1{42}};
    // Sensor b{unrelated::Sensor1{37}};

    using Sensors = std::vector<Sensor>;
    Sensors sensors;
    sensors.push_back(unrelated::Sensor1{42});

    return 0;
}
