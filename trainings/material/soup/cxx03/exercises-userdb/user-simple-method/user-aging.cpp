#include "user.h"
#include <iostream>
#include <cassert>

using namespace std;



int main()
{
    User joerg("Joerg Trittsicher", "Faschingbauer", 55);

    joerg.age_by_n_years(10);
    assert(joerg.age == 65);

    return 0;
}
