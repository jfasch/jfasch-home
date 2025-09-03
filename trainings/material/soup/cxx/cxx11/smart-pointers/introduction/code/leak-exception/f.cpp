#include "crunch.h"

double f()
{
    auto data = new BigData(100, 'a');
    double answer = crunch(data);                      // <-- throws -> MEMORY LEAK!
    delete data;
    return answer;
}
