#include "crunch.h"

double f()
{
    BigData* data = new BigData{1.2, 2.3, 3.4};
    std::optional<double> answer = crunch(data);
    if (! answer.has_value())
        return 666.0;                                  // <-- MEMORY LEAK!
    delete data;
    return answer.value();
}
