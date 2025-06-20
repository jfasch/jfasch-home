#include "crunch.h"

double f()
{
    BigData* data = new BigData{1.2, 2.3, 3.4};
    double answer = crunch(data);                      // <-- unexpectedly frees data
    delete data;                                       // <-- DOUBLE FREE!
    return answer;
}
