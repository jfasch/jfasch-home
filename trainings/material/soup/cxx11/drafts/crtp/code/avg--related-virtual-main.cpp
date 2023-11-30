#include "related-virtual.h"
#include "avg--related-virtual.h"

#include <iostream>

using namespace related_virtual;
using namespace std;

int main()
{
    Sensor1 s1{37.1};
    Sensor2 s2{42.666};

    Sensor* sensors[] = {&s1, &s2};
    
    cout << average(sensors) << endl;
    return 0;
}
