#include "related-no-virtual.h"
#include <iostream>

using namespace std;
using namespace related_no_virtual;

int main()
{
    Sensor1 s1{37.15};
    Sensor2 s2{666.42};

    cout << s1.get_temperature() << endl;
    cout << s2.get_temperature() << endl;

    return 0;
}
