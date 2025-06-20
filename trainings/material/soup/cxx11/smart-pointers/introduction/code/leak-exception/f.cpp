#include "crunch.h"

double f()
{
    auto data = new BigData{1.2, 2.3, 3.4};
    double answer = crunch(data);                      // <-- throws -> MEMORY LEAK!
    delete data;
    return answer;
}
