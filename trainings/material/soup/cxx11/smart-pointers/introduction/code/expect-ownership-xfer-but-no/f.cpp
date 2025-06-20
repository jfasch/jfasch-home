#include "crunch.h"

double f()
{
    BigData* data = new BigData{1.2, 2.3, 3.4};
    double answer = crunch(data);                      // <-- expected to free but doesn't
    return answer;                                     // <-- MEMORY LEAK!
}
