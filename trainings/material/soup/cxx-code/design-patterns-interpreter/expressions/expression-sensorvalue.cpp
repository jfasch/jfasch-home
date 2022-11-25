#include "expression-sensorvalue.h"


int SensorValueExpression::evaluate()
{
    return _sensor->get_temperature();
}
