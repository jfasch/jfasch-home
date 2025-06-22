#include "crunch.h"

double f()
{
    BigData* data = new BigData(1000, 'a');
    double answer = crunch(data);                      // <-- expected to free but doesn't
    return answer;                                     // <-- MEMORY LEAK!
}
