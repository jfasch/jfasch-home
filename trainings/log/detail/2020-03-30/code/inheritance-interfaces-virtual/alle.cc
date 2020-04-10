#include "thermometer.h"

#include <iostream>
using namespace std;


void print_temperature(Thermometer* t)
{
    cout << t->get_temperature() << endl;
}

int main()
{
    Thermometer* th;

    {
        th = new SPIThermometer(1, 2, 3, 4);
        print_temperature(th);
        delete th;
    }
    {
        th = new I2CThermometer(1, 2, 3);
        print_temperature(th);
        delete th;
    }
    {
        MockThermometer* tth = new MockThermometer();
        tth->set_temperature(666.666);
        Thermometer* th = tth;
        print_temperature(th);
        delete th;
    }
}
