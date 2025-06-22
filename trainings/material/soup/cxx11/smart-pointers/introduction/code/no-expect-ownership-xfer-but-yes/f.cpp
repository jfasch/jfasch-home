#include "crunch.h"

double f()
{
    BigData* data = new BigData(100, 'a');
    double answer = crunch(data);                      // <-- unexpectedly frees data
    delete data;                                       // <-- DOUBLE FREE!
    return answer;
}
