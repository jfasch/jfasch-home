#include "crunch.h"

double f()
{
    BigData* data = new BigData(100, 'a');
    std::optional<double> answer = crunch(data);
    if (! answer.has_value())
        return 666.0;                                  // <-- MEMORY LEAK!
    delete data;
    return answer.value();
}
