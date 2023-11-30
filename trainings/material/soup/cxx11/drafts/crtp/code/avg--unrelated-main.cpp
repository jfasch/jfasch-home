#include "unrelated.h"
#include "avg--unrelated.h"

#include <iostream>

using namespace unrelated;
using namespace std;

int main()
{
    Sensor1 s1{37.1};
    Sensor2 s2{42.666};

    SensorVariant sensors[] = {SensorVariant{&s1}, SensorVariant{&s2}};
    
    cout << average(sensors) << endl;
    return 0;
}
